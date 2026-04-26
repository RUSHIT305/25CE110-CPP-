#include<iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("input.txt"); // Change filename if needed

    // Error handling
    if (!file) {
        cout << "Error: File could not be opened!" << endl;
        return 1;
    }

    string line;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    while (getline(file, line)) {
        lineCount++;

        bool inWord = false;

        for (int i = 0; i < line.length(); i++) {
            charCount++;

            // Check if current character is space or tab
            if (line[i] == ' ' || line[i] == '\t') {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }

        // If line ends while still inside a word
        if (inWord) {
            wordCount++;
        }
    }

    file.close();

    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters: " << charCount << endl;

    return 0;
}
