// Test driver with instructions for filling in specific
//  information
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// #include file containing class to be tested


//precondition: there is an empty outfile
//postcondition:The grade is outputed to the file
void outputLetterGrade(int command, ofstream& outFile);


int main()
{
    ifstream inFile;     // file containing operations
    ofstream outFile;    // file containing output
    string inFileName = "numbersIn.txt";   // input file external name
    string outFileName = "lettersOut.txt";  // output file external name
    int command;    // operation to be executed
    int numCommands;

    //sets the file varribles to a file location
    inFile.open(inFileName);
    outFile.open(outFileName);
    if (!inFile)
        cout << "inFile not found" << endl;
    if (!outFile)
        cout << "outFile not found" << endl;

    inFile >> command;
    numCommands = 0;
    while (inFile)
    {
        outputLetterGrade(command,outFile);
        numCommands++;
        cout << "Command number " << numCommands << " completed."
            << endl;
        inFile >> command;
    }

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}


void outputLetterGrade(int command,ofstream& outFile)
{
    
    if (command > 100 || command < 0)
        outFile << "invalid number" << endl;
    else if (command >= 90)
        outFile << "The grade you got was an A." << endl;
    else if (command >= 80)
        outFile << "The grade you got was a B." << endl;
    else if (command >= 70)
        outFile << "The grade you got was a C." << endl;
    else if (command >= 60)
        outFile << "The grade you got was a D." << endl;
    else
        outFile << "The grade you got was a F." << endl;
}