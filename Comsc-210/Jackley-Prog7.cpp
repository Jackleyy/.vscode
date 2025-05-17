#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib>
using namespace std;

//
// This file provides a starting point for the program.  It reads the 
// input file (.csv), builds a graph from the adjacencies in the file,
// and will print the friends list for any node requested.
//
// The graph is a simple adjacency list format -- each vertex
// is represented by an index into an array of vectors (the 'adjacencies
// array below).   Each entry in this array is a vector of integers,
// which are indices into the 'names' array.
//

const string FILENAME = "facebook.csv";     // Input filename
const int MAX_ID = 201;                     // Valid IDs are 1-200

// The adjacency lists.  Each person in the csv file has one vector in
// this array.  The vector lists the indices of people to whom they are
// connected.  Use the 'names' array to map from a string to an index into
// this table.
vector<int> adjacencies[MAX_ID];

// If visited[id] is true for a node, the node has been visited in this
// search.
int visited[MAX_ID] = {  0  };

// Process a line from the file and return a vector of fields.
// For example:  if the line contains a,b,c this function
// returns a vector where v[0] = a, v[1] = b, v[2] = c
void parse_line(const string &str,
                vector<string> &line) {
    istringstream istr(str);
    string tmp;
    while (getline(istr, tmp, ',')) {
        line.push_back(tmp);
    }
}

// Depth-first search function
bool DFS(int nodeId, int targetId) {

    ////////////////////////////////////////////////////////
    // Add your code here if doing DFS                    //
    ////////////////////////////////////////////////////////

    // Steps to complete DFS:
    //
    // - Mark this node as visited
    // - Loop through each friend of adjacencies[nodeId]
    // - If this friend was visited, skip
    // - If this friend is the one we are seeking (targetId), return true
    // - Else, check the value of a DFS on this friend
    // - If it returned successful (true), return true to the caller

    //mark visited
    visited[nodeId] = 1;

    if (nodeId == targetId)
        return true;


    for(int friendID : adjacencies[nodeId]){
        if(!visited[friendID]){//if not explored yet, we call recursive to explore next
            if(DFS(friendID, targetId)){
                return true;
            }
        }
    }

    return false;
}

// (OR)
// Breadth-first search function
bool BFS(int nodeId, int targetId) {

    ////////////////////////////////////////////////////////
    // Add your code here if doing BFS                    //
    ////////////////////////////////////////////////////////

    // Steps to complete BFS:
    // 
    // - Add this node to the queue to start
    // - While the queue is not empty:
    //  - Get the next entry from the queue
    //  - See if it has been visited.  If so, skip.
    //  - Mark it as visited.
    //  - If this is the one we are seeking (targetId), return true to the caller
    //  - Else, add each unvisited friend to the queue

    return false;
}

int main() {
    ifstream inFile(FILENAME);
    vector<string> row;
    vector<string> names;
    string inputLine;
    int id = 1;

    // Verify that the file open was OK
    if (!inFile.good()) {
        cerr << "Invalid file." << endl;
        return (-1);
    }

    // Read the header line of the file (first line, contains column labels).
    // 
    // This line is saved as a vector that is used to find which row of
    // adjacencies belongs to a person.  It "maps" a name (string) to 
    // an index (integer) into the adjTable.
    //
    getline(inFile, inputLine);
    // Remove any newline/return characters
    if (inputLine.back() == '\r' ||
        inputLine.back() == '\n')
            inputLine.pop_back();
    parse_line(inputLine, names);

    // Reach each subsequent entry
    for (int i = 0; i < MAX_ID - 1; i++) {
        vector<string> row;

        // Read a line from the file.
        getline(inFile, inputLine);

        // Returns each value in a vector (comma-separated)
        parse_line(inputLine, row);

        // Start at 1 (the 0'th entry is our name)
        for (int j = 1; j < (int)row.size(); j++) {

            // Get the adjacency status.
            // A '1' indicates an adjacency, so skip if we get a '0'.
            int adj_status = atoi(row[j].c_str());

            // If there is an adjacency to this person, add the integer
            // index of that person to the friends vector.
            if (adj_status == 1)
                adjacencies[id].push_back(j);
        }
        // Move to the next adjacency list
        id += 1;
    }
    cout << "Finished reading graph of " << id - 1 << " entries";

    for (;;) {
        cout << endl << "Enter the name "
             << "and I'll tell you their friends (blank line to quit): ";
        getline(cin, inputLine);
        if (inputLine == "")
            break;

        // Find this person in the map
        int foundIndex = -1;
        for (int i = 0; i < (int)names.size(); i++)
            if (names[i] == inputLine)
                foundIndex = i;

        if (foundIndex == -1) {
            cout << "Person not found." << endl;
            continue;
        }

        // Look up the adjacency list of this person in the map
        // Output all their friends
        cout << inputLine << " is friends with: " << endl;
        for (int i = 0;  i < (int)adjacencies[foundIndex].size(); i++) {
            string fullName = names[adjacencies[foundIndex][i]];
            cout << "\t" << fullName << endl;
        }

        ////////////////////////////////////////////////////////
        // Add your code here                                 //
        // - Reset the 'visited' state to 0 for all nodes     //
        // - Call your DFS or BFS function                    //
        // /////////////////////////////////////////////////////

        string targetID;
        for (int i = 0; i < MAX_ID; i++) visited[i] = 0;

        
        cout << "Enter the ending name: "<< endl;
        getline(cin, targetID);
        
        int targeti = -1;
        for (int i = 0; i < (int)names.size(); i++)
            if (names[i] == targetID){
                targeti = i;
            }

            if (targeti == -1) {
                cout << "Person not found." << endl;
                continue;
        }


        if(DFS(foundIndex, targeti)){
            cout << "There IS a path between these two people." <<endl;
        }
        else{
            cout << "There is NOT a path between these two people "<< endl;
        }

        
    }

    cout << "Exiting..." << endl;
    return (0);
}
