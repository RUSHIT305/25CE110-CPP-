#include <iostream>
using namespace std;

// Recursive function to find super digit
long long superDigit(long long num)
{
    if (num < 10)
        return num;

    long long sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return superDigit(sum);
}

int main()
{
    string n;
    int k;

    cout << "Enter number: ";
    cin >> n;

    cout << "Enter k (number of concatenations): ";
    cin >> k;

    long long sum = 0;

    // Sum digits of n
    for (char c : n)
        sum += c - '0';

    sum = sum * k;

    cout << "Super Digit: " << superDigit(sum) << endl;

    return 0;
}
