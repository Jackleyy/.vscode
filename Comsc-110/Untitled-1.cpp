#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char shiftChar(char ch, int shift) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (ch - base + shift + 26) % 26 + base;
    }
    return ch;
}

void processFile(string inputFile, string outputFile, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    
    if (!inFile || !outFile) {
        cout << "Error opening files!" << endl;
        return;
    }
    
    char ch;
    while (inFile.get(ch)) {
        outFile.put(shiftChar(ch, shift));
    }
    
    inFile.close();
    outFile.close();
}

int main() {
    string inputFile, outputFile;
    char choice;
    
    cout << "Do you want to (e)ncrypt or (d)ecrypt a file? ";
    cin >> choice;
    
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    
    cout << "Enter the name for the output file: ";
    cin >> outputFile;
    
    if (choice == 'e' || choice == 'E') {
        processFile(inputFile, outputFile, 1);
        cout << "Encryption complete. Encrypted file: " << outputFile << endl;
    } else if (choice == 'd' || choice == 'D') {
        processFile(inputFile, outputFile, -1);
        cout << "Decryption complete. Decrypted file: " << outputFile << endl;
        
        // Display decrypted contents on console
        ifstream outFileStream(outputFile);
        if (outFileStream) {
            cout << "\nDecrypted contents:\n";
            string line;
            while (getline(outFileStream, line)) {
                cout << line << endl;
            }
            outFileStream.close();
        } else {
            cout << "Error opening output file for reading!" << endl;
        }
    } else {
        cout << "Invalid choice. Please run the program again and choose 'e' or 'd'." << endl;
    }
    
    return 0;
}