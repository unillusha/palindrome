#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to find the lexicographically smallest palindrome
string findSmallestPalindrome(string s) {
    int n = s.length();

    if(n == 1){
        return s;
    }

    if(n == 2){
        if (s[0] == s[1]) {
            return s;  // Return the string as is because both characters are the same (e.g., "bb").
        } else {
            return ""; // Return an empty string because the characters are different (e.g., "ba").
        }

    }

    if (n == 3) {
        // Sort the string first to get a consistent order
        sort(s.begin(), s.end());

        // Check if it can form a palindrome
        // After sorting, for three characters, the first and the last must be the same for it to be a palindrome
        if (s[0] == s[2]) {
            // All characters are the same
            return s;
        } else if (s[0] == s[1] || s[1] == s[2]) {
            // Make the middle character the different one if possible to form a symmetrical palindrome
            if (s[0] == s[1]) {
                return string(1, s[0]) + string(1, s[2]) + string(1, s[0]); // e.g., "abb" -> "bab"
            } else {
                return string(1, s[2]) + string(1, s[0]) + string(1, s[2]); // e.g., "aab" -> "aba"
            }
        } else {
            return ""; // No palindrome can be formed
        }
    }

    return "";
}

int main() {

    while (true) {
        string input;
        cout << "Enter the string (or type 'exit' to quit): ";
        cin >> input;

        // Exit condition
        if (input == "exit") {
            break;
        }

        string result = findSmallestPalindrome(input);

        if (result.empty()) {
            cout << "No palindrome can be formed." << endl;
        } else {
            cout << "The lexicographically smallest palindrome is: " << result << endl;
        }
    }

    return 0;
}
