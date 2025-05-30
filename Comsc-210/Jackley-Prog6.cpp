#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;

//
// Starter file for hashing Netflix catalog titles.
//

// Constants

// Starting number of buckets, adjust as needed -- should be a prime number.
const int HASH_SIZE = 1051;

const string INFILE = "nflix.csv";       // Input file (CSV)
const int NFIELDS = 6;                     // Number of fields in
                                           // each line of the input file
const char DELIMITER = ',';                // The field separator for the file.
                                           // For a CSV, this is a comma.


// This holds a single Netflix entry.  Each line in the file should
// correspond to one of these structs.  If you use separate chaining, each bucket
// will have a linked list.
//
// Note: this structure is not yet ready to be part of a linked list.  It
// needs an additional pointer to the 'next' entry.
//
struct netflixEntry {
    string type;       // The type of entry (movie or tv show)
    string title;      // Title
    string director;   // Director's full name
    string country;    // Country of release
    int year;          // Year of release
    string duration;   // Duration (minutes for movie, num. seasons for show)
    netflixEntry* next = 0; //pointer to next entry of potentail linked list
};

// Hash table for all of the entries
netflixEntry *entryHash[HASH_SIZE] = { 0 };

// Generate a hash key, given a string (this would come from the
// string the user typed to find).  your hash function goes here.
//
// Don't use this one, it's bad! (everything will hash to only a few buckets).

/*
unsigned int getHashIndex(string hashInput) {
    unsigned int sum = 0;

    // Use the first letter of the supplied string
    sum = (int)hashInput[0];

    // for debugging -- add a statement like this to
    // see the hash key generated for an entry.
    //
    // cout << "title: " << hashInput
    //      << " hash index: " << sum % HASH_SIZE << endl;

    // Return the index into entryHash.  This determines the
    // hash "bucket".
    return (sum % HASH_SIZE);
}
*/


unsigned int getHashIndex(string hashInput) {
    unsigned int sum = 3851;
    for(int i = 0; i < hashInput.length(); i++){
        sum += (int)hashInput[i];
    }

    cout << "title: " << hashInput //for debugging purposes
         << " hash index: " << sum % HASH_SIZE << endl;

    return (sum % HASH_SIZE); //this is the actual key
                            //remainder so it never exceeds list size
}


// Using a single line from the file, this function allocates a
// new netflixEntry.  The new entry will be filled-in from the file info (title, etc.).
// Returns a pointer to the new entry, or 0 if one could not be created;
netflixEntry *readSingleEntry(const string &lineFromFile) {
    istringstream istr(lineFromFile);
    string fields[NFIELDS];
    string tmp, dstr;
    netflixEntry *np = 0;
    int i = 0;

    // Read each field separated by a comma
    while (getline(istr, tmp, DELIMITER) && i < NFIELDS) {
        fields[i++] = tmp;
    }
    if (i < NFIELDS) {
        // Uncomment this for more information about any skipped lines
        // cout << "Warning:  skipping malformed line: " << lineFromFile << endl;
        return 0;
    }

    np = new netflixEntry;

    // Make a new Netflix entry based on the
    // fields just read from the file.
    np->type = fields[0];
    np->title = fields[1];
    np->director = fields[2];
    np->country = fields[3];
    np->year = atoi(fields[4].c_str()); // Convert the string to an int

    // Remove any extra linefeeds from the last field
    dstr = fields[5];
    if (dstr.size() != 0 && dstr[dstr.size() - 1] == '\r')
        dstr.erase(dstr.size() - 1);
    np->duration = dstr;

    return np;                          // Return the new entry to the caller
}


//MY WORK
// Insert a new entry into the hash table
void entryInsert(netflixEntry *newEnt, unsigned int hashIndex) {

    //
    // Complete this function.
    //
    // Accepts a new entry 'newEnt' which hashes to index 'hashIndex' in the
    // hash table.  Adds the entry to the bucket (adding to the linked list).
    //
    // Steps:
    //
    // 1) Using the supplied index, go to hashTable[hashIndex].  This will be a pointer value.
    // 2) Check to see if the hashTable[hashIndex] is zero.
    //    If it is, the bucket is empty.  Set hashTable[hashIndex] to be equal to the new entry.
    // 3) If hashTable[hashIndex] is non-zero, there is a linked list at this index.  Insert
    //    the new entry into the list at the front or at the end.
    //


    if(entryHash[hashIndex] != 0){
        netflixEntry* temp = 0; //temp to hold pointer to move
        cout << "\nCollision occured\n";

        //swapping the first entry with the new entry in the LL
        temp = entryHash[hashIndex];
        entryHash[hashIndex] = newEnt;
        entryHash[hashIndex]->next = temp;
    }
    else{
        cout << "\nNo collision! :) \n";
        entryHash[hashIndex] = newEnt;
    }

}

// This function accepts a string title and a reference
// to an empty entry.
//
// - The function will return a pointer to a netflixEntry if
//   the entry was found, 0 otherwise.
// - The 'ncmp' parameter tracks the number of comparisons required.  This
//   is a pass-by-reference parameter.
//
netflixEntry *entryFind(const string &title, unsigned int hashIndex, int &ncmp) {
    netflixEntry *foundPtr = 0;

    //
    // Complete this function.
    //
    // Accepts a string from the user, its resulting hash, and reference to
    // number of comparisons.  Return a pointer to the found entry or 0.
    //
    // Steps:
    //
    // 1) Using the provided index 'hashIndex', go to hashTable[hashIndex], which is a
    //    pointer value.
    // 2) Keep track of comparisons past this point.  Increment 'ncmp' for each
    //    comparison made in the table.
    // 3) Check to see if the hashTable[hashIndex] is zero.
    //    If it is, the bucket is empty.  The entry was not found.
    // 4) If hashTable[hashIndex] is non-zero, there is a linked list at this index.  Using a loop,
    //    compare the title of each entry in the list to 'title'.
    // 5) If there is a match, return a pointer to that entry.  If the end of the list is
    //    reached, the entry was not found.

    netflixEntry* cur = entryHash[hashIndex]; //pointer to keep track while in the while loop
                                              //set to given hashIndex for a given movie
    while(cur != nullptr){//as long as we arent looking at a nullptr, we can do a comparison. 
        ncmp++;
        if(cur->title == title){//if the titles match, return whatever pointer we have
            return cur;
        }
        cur = cur->next;        //sets pointer to next one in linked list
    }

    return nullptr;
}

//
// Sample main().
//
int main() {
    ifstream inFile(INFILE);
    string inputLine, inputStr;
    netflixEntry *np = 0;
    int linesRead = 0;

    if (!inFile.good()) {
        cerr << "Cannot open the input file!" << endl;
        exit(-1);
    } 

    // Read in each entry
    while (getline(inFile, inputLine)) {
        // Keep a counter of read lines.
        linesRead++;

        // Read the next line from the file, returning a pointer
        // to the newly allocated entry.
        np = readSingleEntry(inputLine);
        if (!np)
            continue;

        // Now we have a complete entry, find where it goes
        // in the hash table and add it.
        entryInsert(np, getHashIndex(np->title));

        // Extra debugging statement: uncomment this to
        // see how many lines are being read from the file
        // in real-time.
        //
        // if (linesRead % 25 == 0)
        //    cerr << "Inserted " << linesRead << " entries"
        //         << endl;
    }

    // Handle errors and/or summarize the read
    if (linesRead == 0) {
        cerr << "Nothing was read from the file!" << endl;
        return (-1);
    } else {
        cout << "Read " << linesRead << " entries." << endl;
        cout << "Last entry added: " << np->title
             << " (" << np->director << ", " << np->year << ")" << endl;
    }



    // (example) Forever loop until the user requests an exit
    for (;;) {
        string user_title; //user inputed tile
        int num = 0;

        int filled = 0;
        for (int i = 0; i < HASH_SIZE; i++) {
            if (entryHash[i] != nullptr) {
                filled++;
            }
        }
        cout << "\n--- Hash Table Usage Stats ---\n";
        cout << "Filled buckets: " << filled << endl;
        cout << "Empty buckets: " << HASH_SIZE - filled << endl;
        cout << "Load factor: " << (float)filled / HASH_SIZE << endl;
        
        
        cout << "Please enter a movie title: ";
        getline(cin, user_title);

        

        if(user_title.empty()){
            break;
        }

        np = entryFind(user_title, getHashIndex(user_title), num);

        if(np != nullptr){
            cout << "Comparisons: " << num << endl;
            cout << "Type: " << np->type << endl;
            cout << "Movie: " << np->title << endl;
            cout << "Director: " << np->director << endl;
            cout << "Country: " << np->country << endl;
            cout << "Year of Release: " << np->year << endl;
            cout << "Duration: " << np->duration << endl;
        }
        else{
            cout << "invalid input" << endl;
        }
    }

    // And we're done!
    cout << "Exiting..." << endl;

    return (0);
}
