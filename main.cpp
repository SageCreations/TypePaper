#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile;

    char name1[5], name2[2];
    int sentence, inMon, inYear, inAge;
    int outMon, outYear, outAge;

    inFile.open("/Users/SageCreations/CLionProjects/TypePaper/prison.dat");
    if (!inFile)
        cout << "\n\t\tCan't open data file: prison.dat\n";
    else {
        cout << "\n\n\t\t\t\tBlinn  Prison  Report";
        cout << "\n\n\n\tName\t   Sentence\t\tEntered    Prison    Released\t Prison";
        cout << "\n\t\t\t   Months\t    Age  YR     Month    Age   YR     Month";
        while (inFile >> name1 >> name2 >> sentence >> inMon >> inYear >> inAge) {
            outAge = inAge + (sentence + inMon) / 12;
            outYear = inYear + sentence / 12;
            outMon = inMon + sentence % 12;
            if (outMon > 12)
            {
                outMon = outMon - 12;
                outYear = outYear + 1;
            }
            cout << "\n\t" << name1 << " " << name2 << setw(10) << sentence
                 << setw(10) << inAge << setw(5) << inYear << setw(7)
                 << inMon << setw(10) << outAge << setw(5) << outYear << setw(8)
                 << outMon;
        }
        cout << "\n\n\n\t\t\t\t        Programming is FUN!!\n\n\n";
    }
    return 0;
}