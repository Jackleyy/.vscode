#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
using namespace std;

//
// This file provides a starting point for the shortest paths program.  It
// reads the input file (.csv), builds a graph from the adjacencies (and weights)
// in the file, and will print the friends list for any node requested.
//

const string FILENAME = "fb_weighted.csv";      // Input filename
const int MAX_ID = 201;                         // Valid IDs are 1-200

// Each edge in the adjacency list consists of an (id, weight) pair.
// The 'id' is the other end of the edge and 'weight' is the cost of the edge.
struct adjacency {
    int nodeId;
    int weight;
};

// The adjacency lists.  Each person in the csv file has one vector in
// this array.  The vector lists the (id, weight) of people to whom they are
// connected.  Use the 'names' array to map from a string to an index into
// this table.
vector<adjacency> adjacencies[MAX_ID];

// If bestPathCost[id] is not equal to -1, the node has been added to
// PATHS and the value is the best sum of edge weights to this node.
int bestPathCost[MAX_ID];

// If bestParent[id] is not equal to -1, the node has been added to
// PATHS and the value is the best sum of edge weights to this node.
int bestParent[MAX_ID];

// This data structure represents a (node, weight, parent) item
// in either the TENT vertex set or the PATHS set.
struct pathElement {
    int nodeId;
    int weight;
    int parent;

    // This allows pathElements to be compared inside the
    // priority_queue.
    bool operator< (const pathElement &rhs) const {
        return weight > rhs.weight;
    }
};


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
bool shortestPaths(int nodeId, int targetId) {
    pathElement p;
    priority_queue<pathElement> tent;

    // First, add the starting node to TENT
    p.weight = 0;
    p.parent = -1;
    p.nodeId = nodeId;
    tent.push(p);

    // While TENT is not empty, take the lowest cost node out of
    // TENT and add it to PATHS.  The STL priority queue will 
    // give us this lowest cost node.
    while (!tent.empty()) {

        // Get the lowest cost node (sum of all edges leading to it)
        p = tent.top();
        tent.pop();

        // Make sure it was not previously added to PATHS
        // (this is a higher cost path).  If it was, skip this entry.
        if (bestPathCost[p.nodeId] != -1)
            continue;

        // Add the entry to PATHS.
        bestPathCost[p.nodeId] = p.weight;
        bestParent[p.nodeId] = p.parent;

        // Is this the target node?  If it is, we can stop at this point.
        // (remaining paths are not needed)
        if (p.nodeId == targetId)
            return true;

        // Examine each neighbor and add to TENT, with this node as the parent.
        for (int i = 0; i < (int)adjacencies[p.nodeId].size(); i++) {
            adjacency thisFriend = adjacencies[p.nodeId][i];
            pathElement np;

            // Add this entry to the priority queue.
            // The cost is "our cost" (p.best_weight) + "the edge to this node cost"
            np.weight = p.weight + thisFriend.weight;
            np.parent = p.nodeId;
            np.nodeId = thisFriend.nodeId;

            // Uncomment this line to see each entry added
            //cout << "adding node " << np.nodeId << " weight " << np.weight
            //     << " parent " << np.parent << endl;

            tent.push(np);
        }
    }
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
            // A non-zero value means we have an edge to this node.
            int adj_status = atoi(row[j].c_str());

            // Add the node and weight to the adjacency list.
            if (adj_status != 0) {
                adjacency newAdj;
                newAdj.nodeId = j;          // The "other end" of the edge
                newAdj.weight = adj_status; // The cost of the edge
                adjacencies[id].push_back(newAdj);
            }
        }
        // Move to the next adjacency list
        id += 1;
    }
    //cout << "Finished reading graph of " << id - 1 << " entries"; ==== Commented out this line ======

    
    for (;;) {
        /*======Also commented this out bc its a testing function======
        cout << endl << "Enter the name "
             << "and I'll tell you their friends (blank line to quit): ";
        getline(cin, inputLine);
        if (inputLine == "")
            break;

        // Find this person in the names array
        int foundIndex = -1;
        for (int i = 0; i < (int)names.size(); i++)
            if (names[i] == inputLine)
                foundIndex = i;

        if (foundIndex == -1) {
            cout << "Person not found." << endl;
            continue;
        }

        // Look up the adjacency list of this person.
        // Each entry is a pair:  (id, weight)
        // Output all their friends
        cout << inputLine << " is friends with: " << endl;
        for (int i = 0;  i < (int)adjacencies[foundIndex].size(); i++) {
            adjacency thisFriend = adjacencies[foundIndex][i];
            string thisFriendName = names[thisFriend.nodeId];
            cout << "\t" << thisFriendName << " (weight: " << thisFriend.weight << ")" << endl;
        }
         */

        // Reset the previous state
        for (int i = 0; i < MAX_ID; i++) {
            bestPathCost[i] = -1;
        }
        for (int i = 0; i < MAX_ID; i++) {
            bestParent[i] = -1;
        }

        ///////////////////////////////////////////////////////////////
        // Add your code here                                        //
        // - Call the shortestPaths function to run the Dijkstra alg.//
        // - See the Canvas page for details                         //
        ///////////////////////////////////////////////////////////////
        string dest, start;
        cout << "Enter the starting name (or blank to quit)" << endl;
        getline(cin, start);
        // Find this person in the names array
        int startIndex = -1;
        for (int i = 0; i < (int)names.size(); i++)
            if (names[i] == start)
                startIndex = i;

        if (startIndex == -1) {
            cout << "Person not found." << endl;
            continue;
        }
        
        cout << "Enter the ending name (or X to quit)" << endl;
        getline(cin, dest);

        cout << start[0];

        if (start == "" || dest == "") { //checks if they want to exit
            cout << "Exiting program" << endl;
            break;
        }

        //finds index of person
        int destIndex = -1; 
        for (int i = 0; i < (int)names.size(); ++i)
            if (names[i] == dest)
                destIndex = i;

        if (destIndex == -1) {
            cout << "Person not found." << endl;
            continue;
        }

        bool reachable = shortestPaths(startIndex, destIndex);//is it reachable

        //no?
        if(!reachable){
            cout << "There is no path between these two people" << endl;
            continue;
        }

        //yes? lets find the path by working backwards
        vector<int> path;
        for(int i = destIndex; i != -1; i = bestParent[i]){
            path.push_back(i);
        }

        cout << "The best path between these two people is: " << endl;

        for(int i = path.size() -1; i >=0; --i){
            cout << "      " << names[path[i]] << endl;
        }

        cout << "the cost of this path is : " << bestPathCost[destIndex] << endl;


    }

    cout << "Exiting..." << endl;
    return (0);
}
