#include <iostream>
#include <string>
#include <sstream>
#include <map>

int main() {
    std::string sentence;
    std::map<std::string, int> wordFrequency;

    // Read a full sentence from the user
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    // Use stringstream to extract individual words
    std::stringstream ss(sentence);
    std::string word;

    while (ss >> word) {
        // Increment frequency for each word found
        wordFrequency[word]++;
    }

    // Display the unique words and their counts
    std::cout << "\nWord Frequencies:\n";
    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
