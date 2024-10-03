// SelectionAndRepetitionProjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Merges two pre-sorted input files into one sorted output file.
// Reads lines from both, compares, and writes in order.
// Remaining lines from either file are appended.
//
// Input: Two sorted files.
// Output: Merged sorted file.
//
// Programmer: Aslihan Celik

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to merge two ordered files into one output file
void mergeFiles(const string& file1, const string& file2, const string& outputFile) {

    ifstream inFile1(file1);
    ifstream inFile2(file2);
    ofstream outFile(outputFile);

    if (!inFile1.is_open() || !inFile2.is_open() || !outFile.is_open()) {
        cerr << "Error opening one or more files." << endl;
        return;
    }

    string input1, input2;

    // Read the first line from both files
    getline(inFile1, input1);
    getline(inFile2, input2);

    
    // Merge the files until one of them reaches the end
    while (inFile1 && inFile2) {
     
        if (input1 < input2) {
            outFile << input1 << endl; // Write line from file1
            getline(inFile1, input1);   // Read next line from file1
        }
        else {
            outFile << input2 << endl; // Write line from file2
            getline(inFile2, input2);   // Read next line from file2
        }
    }

    
    // Write remaining lines from file1 if any
    if (inFile1) {
        outFile << input1 << endl; // Write the last read line
        while (getline(inFile1, input1)) {
            outFile << input1 << endl; // Write the current line
        }
    }
    
 
    // Write remaining lines from file1 if any
    if (inFile2) {
        outFile << input2 << endl; // Write the last read line
        while (getline(inFile2, input2)) {
            outFile << input2 << endl; // Write the current line
        }
    }


    // Close all files
    inFile1.close();
    inFile2.close();
    outFile.close();
}

int main()
{
    
    string inputFile1 = "file1.txt"; // Input file 1
    string inputFile2 = "file2.txt"; // Input file 2
    string outputFile = "mergedOutput.txt"; // Output file

    mergeFiles(inputFile1, inputFile2, outputFile);
    cout << "Files merged successfully into " << outputFile << endl;

    return 0;

}


