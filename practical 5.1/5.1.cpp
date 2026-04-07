#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string paragraph;
    string words[100];
    int freq[100] = {0};
    int count = 0;

    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);

    // Convert paragraph to lowercase
    for(int i = 0; i < paragraph.length(); i++)
        paragraph[i] = tolower(paragraph[i]);

    string word = "";

    // Extract words manually
    for(int i = 0; i <= paragraph.length(); i++)
    {
        if(paragraph[i] != ' ' && paragraph[i] != '\0')
        {
            word += paragraph[i];
        }
        else
        {
            int found = -1;

            for(int j = 0; j < count; j++)
            {
                if(words[j] == word)
                {
                    found = j;
                    break;
                }
            }

            if(found != -1)
                freq[found]++;
            else
            {
                words[count] = word;
                freq[count] = 1;
                count++;
            }

            word = "";
        }
    }

    cout << "\nWord Frequencies:\n";
    for(int i = 0; i < count; i++)
        cout << words[i] << " : " << freq[i] << endl;

    return 0;
}
