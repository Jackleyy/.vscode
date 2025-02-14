#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

// Define a struct to store student information
struct Student {
    string firstName;
    string lastName;
    string studentID;
};

// Function to parse a line of text into a Student object
Student parseStudent(const string &line) {
    Student student;
    stringstream ss(line);
    ss >> student.firstName >> student.lastName >> student.studentID;
    return student;
}

// Function to read students from a file and store them in a vector
vector<Student> readStudentsFromFile(const string &filename) {
    vector<Student> students;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return students;
    }

    while (getline(file, line)) {
        Student student = parseStudent(line);
        students.push_back(student);
    }

    file.close();
    return students;
}

// Function to display students
void displayStudents(const vector<Student>& students, const string& header) {
    cout << header << ":\n";
    for (const auto& student : students) {
        cout << student.firstName << " " << student.lastName << " (" << student.studentID << ")\n";
    }
    cout << endl;
}

int main() {
    // Read data from files
    vector<Student> previousYearStudents = readStudentsFromFile("C:\\Users\\rhawk\\OneDrive\\Documents\\Comsc 200\\meet1.txt");
    vector<Student> currentYearStudents = readStudentsFromFile("C:\\Users\\rhawk\\OneDrive\\Documents\\Comsc 200\\meet2.txt");

    // Use unordered maps to store students by their ID for quick lookup
    unordered_map<string, Student> previousStudentsMap;
    unordered_map<string, Student> currentStudentsMap;

    for (const auto &student : previousYearStudents) {
        previousStudentsMap[student.studentID] = student;
    }
    for (const auto &student : currentYearStudents) {
        currentStudentsMap[student.studentID] = student;
    }

    // Vectors to store new, returning, and non-returning members
    vector<Student> newMembers;
    vector<Student> returningMembers;
    vector<Student> nonReturningMembers;

    // Identify returning and new members
    for (const auto &student : currentYearStudents) {
        if (previousStudentsMap.find(student.studentID) != previousStudentsMap.end()) {
            returningMembers.push_back(student);
        } else {
            newMembers.push_back(student);
        }
    }

    // Identify non-returning members
    for (const auto &student : previousYearStudents) {
        if (currentStudentsMap.find(student.studentID) == currentStudentsMap.end()) {
            nonReturningMembers.push_back(student);
        }
    }

    // Display results
    displayStudents(returningMembers, "Returning Members");
    displayStudents(newMembers, "New Members");
    displayStudents(nonReturningMembers, "Non-Returning Members");

    return 0;
}

