// Game page logic - receives deck data from landing page and runs the matching game
document.addEventListener('DOMContentLoaded', function() {
  // Get the deck data from localStorage (sent by landing page)
  const deckData = JSON.parse(localStorage.getItem('flashmatch.pendingDeck') || 'null');
  const options = JSON.parse(localStorage.getItem('flashmatch.pendingOptions') || '{"hard": false}');
  
  // Clear the stored data after retrieving it
  localStorage.removeItem('flashmatch.pendingDeck');
  localStorage.removeItem('flashmatch.pendingOptions');

  // If no deck data, redirect back to landing page
  if (!deckData) {
    alert('No deck selected. Redirecting to main page.');
    window.location.href = 'index.html';
    return;
  }

  // Game variables
  let numPairs = 4;  // change this number to control difficulty
  let cards = [];
  let selectedCards = [];
  let score = 0;
  let timer = 0;
  let intervalId;
  let lockBoard = false;

  // DOM elements
  const board = document.getElementById("game-board");
  const scoreDisplay = document.getElementById("score");
  const timerDisplay = document.getElementById("timer");
  const restartBtn = document.getElementById("restart");
  const backToMenuBtn = document.getElementById("backToMenu");

  // Update page title to show selected deck
  document.title = `FlashMatch - ${deckData.topic}`;

  function setupGame() {
    // Reset state
    cards = [];
    selectedCards = [];
    score = 0;
    timer = 0;
    clearInterval(intervalId);

    // Use the deck data from landing page
    const pairs = deckData.pairs;
    
    // Adjust numPairs based on available pairs and hard mode
    const maxPairs = Math.min(pairs.length, options.hard ? 8 : 4);
    numPairs = Math.min(numPairs, maxPairs);

    // Shuffle pairs and pick only numPairs
    const chosenPairs = pairs
      .sort(() => Math.random() - 0.5)
      .slice(0, numPairs);

    // Create cards for chosen pairs
    chosenPairs.forEach(pair => {
      cards.push({ text: pair.term, match: pair.def, type: "term" });
      cards.push({ text: pair.def, match: pair.term, type: "definition" });
    });

    // Shuffle cards on the board
    cards.sort(() => Math.random() - 0.5);

    // Render
    board.innerHTML = "";
    cards.forEach((card, index) => {
      const div = document.createElement("div");
      div.classList.add("card");
      div.dataset.index = index;
      div.innerText = card.text;
      div.addEventListener("click", () => selectCard(div, card));
      board.appendChild(div);
    });

    // Update UI
    scoreDisplay.innerText = "Score: 0";
    timerDisplay.innerText = "Time: 0s";

    // Start timer
    intervalId = setInterval(() => {
      timer++;
      timerDisplay.innerText = `Time: ${timer}s`;
    }, 1000);
  }

  function selectCard(div, card) {
    if (lockBoard) return;
    if (div.classList.contains("correct") || div.classList.contains("selected")) return;

    div.classList.add("selected");
    selectedCards.push({ div, card });

    if (selectedCards.length === 2) {
      lockBoard = true;
      checkMatch();
    }
  }

  function checkMatch() {
    const [first, second] = selectedCards;

    if (first.card.match === second.card.text && second.card.match === first.card.text) {
      // Match
      first.div.classList.remove("selected");
      second.div.classList.remove("selected");
      first.div.classList.add("correct");
      second.div.classList.add("correct");
      score++;
      scoreDisplay.innerText = "Score: " + score;

      // Check win condition
      if (score === numPairs) {
        clearInterval(intervalId);
        setTimeout(() => {
          alert(`🎉 You matched all ${numPairs} pairs in ${timer} seconds!`);
        }, 300);
      }

      selectedCards = [];
      lockBoard = false;
    } else {
      // Wrong
      first.div.classList.add("wrong");
      second.div.classList.add("wrong");

      setTimeout(() => {
        first.div.classList.remove("selected", "wrong");
        second.div.classList.remove("selected", "wrong");
        selectedCards = [];
        lockBoard = false;
      }, 1000);
    }
  }

  // Event listeners
  restartBtn.addEventListener("click", setupGame);
  
  if (backToMenuBtn) {
    backToMenuBtn.addEventListener("click", function() {
      window.location.href = 'index.html';
    });
  }

  // Start the game
  setupGame();
});
