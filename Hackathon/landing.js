// Landing page logic: categories -> options modal -> proceed to game.html
// Also includes a stub "create your own" flow you can later replace with a real API call.

const createBtn = document.querySelector("#createBtn");
const promptModal = document.querySelector("#promptModal");
const optionsModal = document.querySelector("#optionsModal");
const promptInput = document.querySelector("#promptInput");
const promptNextBtn = document.querySelector("#promptNextBtn");
const pairCountEl = document.querySelector("#pairCount");
const difficultyEl = document.querySelector("#difficulty");
const hardToggle = document.querySelector("#hardToggle");
const proceedBtn = document.querySelector("#proceedBtn");
const toastEl = document.querySelector("#toast");

let pendingConfig = {
  mode: null,          // 'preset' | 'custom'
  deckId: null,        // preset id OR generated id
  hard: false,
  deckData: null       // normalized deck JSON we store for game.html
};

// --- helpers ---
function openModal(node){ node.classList.remove("hidden"); }
function closeModal(node){ node.classList.add("hidden"); }
function toast(msg, ms=1600){
  toastEl.textContent = msg;
  toastEl.classList.remove("hidden");
  setTimeout(()=> toastEl.classList.add("hidden"), ms);
}

// Close buttons with data-close attr
document.querySelectorAll("[data-close]").forEach(btn => {
  btn.addEventListener("click", () => {
    const target = btn.getAttribute("data-close");
    const node = document.querySelector(target);
    if (node) closeModal(node);
  });
});

// Toggle hard mode
hardToggle.addEventListener("click", () => {
  const pressed = hardToggle.getAttribute("aria-pressed") === "true";
  const next = !pressed;
  hardToggle.setAttribute("aria-pressed", String(next));
  hardToggle.textContent = next ? "ON" : "OFF";
  pendingConfig.hard = next;
});

// Handle preset category selection
document.querySelectorAll(".tile[data-type='preset']").forEach(btn => {
  btn.addEventListener("click", async () => {
    const deckId = btn.getAttribute("data-deck-id");
    pendingConfig = { mode: "preset", deckId, hard: false, deckData: null };
    // Load preset deck data (minimal) — you can expand these later
    const deck = getPresetDeck(deckId);
    pendingConfig.deckData = normalizeDeck(deck);
    openModal(optionsModal);
  });
});

// Create-your-own flow
createBtn.addEventListener("click", () => {
  pendingConfig = { mode: "custom", deckId: null, hard: false, deckData: null };
  promptInput.value = "";
  pairCountEl.value = "8";
  difficultyEl.value = "easy";
  openModal(promptModal);
});

promptNextBtn.addEventListener("click", async () => {
  const prompt = promptInput.value.trim();
  const pairCount = clamp(parseInt(pairCountEl.value, 10) || 8, 4, 24);
  const difficulty = difficultyEl.value;

  if (!prompt) {
    toast("Please describe your topic.");
    return;
  }

  // Stub: pretend to call your backend and get a deck
  // Replace generateDeckFromPrompt() later with a fetch to your Python API.
  try {
    const genDeck = await generateDeckFromPrompt({ prompt, pairCount, difficulty });
    pendingConfig.deckId = genDeck.id;
    pendingConfig.deckData = normalizeDeck(genDeck);
    closeModal(promptModal);
    openModal(optionsModal);
  } catch (e) {
    console.error(e);
    toast("Failed to generate deck.");
  }
});

// Proceed to game page
proceedBtn.addEventListener("click", () => {
  if (!pendingConfig.deckData) {
    toast("No deck selected.");
    return;
  }
  // Save deck & config for the game page
  localStorage.setItem("flashmatch.pendingDeck", JSON.stringify(pendingConfig.deckData));
  localStorage.setItem("flashmatch.pendingOptions", JSON.stringify({ hard: pendingConfig.hard }));

  // Navigate with simple query params your teammate can read, too
  const params = new URLSearchParams({
    deck: pendingConfig.deckId || pendingConfig.deckData.id,
    hard: pendingConfig.hard ? "1" : "0",
    source: pendingConfig.mode || "preset"
  });
  window.location.href = `./game.html?${params.toString()}`;
});

// --- data + stubs ---

// Minimal preset decks (you or your teammate managing “lists” can expand these)
function getPresetDeck(deckId){
  if (deckId === "bio101") {
    return {
      id: "bio101",
      topic: "Biology 101",
      pairs: [
        { term: "Cell", definition: "Basic unit of life" },
        { term: "DNA", definition: "Molecule carrying genetic information" },
        { term: "Mitosis", definition: "Cell division producing identical cells" },
        { term: "Osmosis", definition: "Water diffusion across semipermeable membrane" },
        { term: "ATP", definition: "Cellular energy currency" },
        { term: "Homeostasis", definition: "Maintenance of internal stability" },
        { term: "Enzyme", definition: "Protein catalyst of reactions" },
        { term: "Ribosome", definition: "Site of protein synthesis" }
      ]
    };
  }
  if (deckId === "cpp-basics") {
    return {
      id: "cpp-basics",
      topic: "C++ Basics",
      pairs: [
        { term: "Pointer", definition: "Variable storing a memory address" },
        { term: "Reference", definition: "Alias for another variable" },
        { term: "Header", definition: "File containing declarations (.h/.hpp)" },
        { term: "Template", definition: "Generic programming mechanism" },
        { term: "RAII", definition: "Resource Acquisition Is Initialization" },
        { term: "Stack", definition: "Automatic storage duration" },
        { term: "Heap", definition: "Dynamic storage via new/delete" },
        { term: "Namespace", definition: "Logical scope grouping names" }
      ]
    };
  }
  // us-history
  return {
    id: "us-history",
    topic: "US History",
    pairs: [
      { term: "Bill of Rights", definition: "First ten amendments to the Constitution" },
      { term: "Civil War", definition: "1861–1865 conflict over secession & slavery" },
      { term: "New Deal", definition: "FDR programs addressing Great Depression" },
      { term: "Louisiana Purchase", definition: "1803 US acquisition from France" },
      { term: "Emancipation Proclamation", definition: "1863 Lincoln order freeing enslaved persons in rebelling states" },
      { term: "Marshall Plan", definition: "Post-WWII European aid program" },
      { term: "Cold War", definition: "US–USSR geopolitical tension" },
      { term: "Brown v. Board", definition: "1954 desegregation Supreme Court case" }
    ]
  };
}

// Normalize a deck to what the game page expects (simple term/def records)
function normalizeDeck(deck){
  // Give each pair an id if missing
  const pairs = deck.pairs.map((p, idx) => ({
    id: `p${idx+1}`,
    term: String(p.term),
    def: String(p.def)
  }));
  return {
    id: deck.id || `deck-${Math.random().toString(36).slice(2,8)}`,
    topic: deck.topic || "Custom Deck",
    pairs
  };
}

// Simple clamp
function clamp(n, lo, hi){ return Math.max(lo, Math.min(hi, n)); }

// --- STUB: replace with real backend later ---
async function generateDeckFromPrompt({ prompt, pairCount, difficulty }){
  // 1) For your demo now: make a deterministic pseudo deck so UI flow is testable.
  // 2) Later: replace with fetch('/api/generate-deck', { method:'POST', body: JSON.stringify({...}) })
  await sleep(350); // tiny delay to feel real
  const pairs = Array.from({ length: pairCount }, (_, i) => ({
    term: titleCase(`${prompt} — term ${i+1}`),
    def: `Definition ${i+1} (${difficulty}) for ${prompt}`
  }));
  return { id: `auto-${Date.now()}`, topic: prompt, pairs };
}
function sleep(ms){ return new Promise(r=>setTimeout(r,ms)); }
function titleCase(s){ return s.replace(/\w\S*/g, w=>w[0].toUpperCase()+w.slice(1)); }
