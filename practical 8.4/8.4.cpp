#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

/**
 * Problem: Read file line-by-line, validate, and compute sum.
 * Handles file errors (retry) and invalid data (skip).
 */

int main() {
    std::string filename;
    std::ifstream file;
    bool fileOpened = false;

    // --- 1. Retry Mechanism for File Opening ---
    while (!fileOpened) {
        std::cout << "Enter the path to the text file (or 'exit' to quit): ";
        std::cin >> filename;

        if (filename == "exit") return 0;

        file.open(filename);
        if (file.is_open()) {
            fileOpened = true;
        } else {
            std::cerr << "Error: Could not open file '" << filename << "'. Please try again.\n";
            file.clear(); // Clear error flags
        }
    }

    std::string line;
    double totalSum = 0;
    int lineNumber = 0;
    int validLines = 0;

    std::cout << "Processing file...\n-------------------\n";

    // --- 2. Process File Line-by-Line ---
    while (std::getline(file, line)) {
        lineNumber++;

        // Skip empty lines
        if (line.empty()) continue;

        std::stringstream ss(line);
        double value;

        // --- 3. Validate Data (Non-numeric check) ---
        if (ss >> value) {
            // Check if there's trailing junk data on the same line
            if (ss >> std::ws && !ss.eof()) {
                std::cerr << "Line " << lineNumber << ": Warning - Ignoring trailing invalid data.\n";
            }
            totalSum += value;
            validLines++;
        } else {
            // --- 4. Handle Corrupted Data Gracefully ---
            std::cerr << "Line " << lineNumber << ": Error - Invalid data format ('" << line << "'). Skipping.\n";
        }
    }

    file.close();

    // --- 5. Report Results ---
    std::cout << "-------------------\nProcessing Complete.\n";
    std::cout << "Valid lines processed: " << validLines << "\n";
    std::cout << "Total Sum: " << totalSum << "\n";

    return 0;
}
