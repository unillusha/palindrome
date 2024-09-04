#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if the input string is a palindrome
bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to find the lexicographically smallest palindrome from a given palindrome input
string findSmallestPalindrome(string s) {
    if (!isPalindrome(s)) {
        return "";  // Return empty string if input is not a palindrome
    }

    // Sort the string to get the lexicographically smallest arrangement
    sort(s.begin(), s.end());

    // Initialize variables for constructing the palindrome
    string firstHalf = "", middle = "";

    // Array to count frequencies of each character (assuming only 'a' to 'z')
    int freq[26] = {0};

    // Count frequencies of characters in the string
    for (char c = 'a'; c <= 'z'; ++c) {
        freq[c - 'a'] = count(s.begin(), s.end(), c);
    }

    // Check if the characters can still form a palindrome
    int oddCount = 0;

    // Iterate over the frequency array to build firstHalf and determine the middle character
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            oddCount++;
            middle = string(1, 'a' + i);  // Middle character for the palindrome
        }
        firstHalf += string(freq[i] / 2, 'a' + i);  // Add half of the characters to the first half
    }

    // If more than one character has an odd frequency, it cannot be rearranged into a palindrome
    if (oddCount > 1) {
        return "";
    }

    // Form the full palindrome
    string secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());
    return firstHalf + middle + secondHalf;
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    string result = findSmallestPalindrome(input);

    if (result.empty()) {
        cout << "No palindrome can be formed." << endl;
    } else {
        cout << "The lexicographically smallest palindrome is: " << result << endl;
    }

    return 0;
}
