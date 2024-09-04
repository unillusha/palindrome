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

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    if (isPalindrome(input)) {
        sort(input.begin(), input.end());
        cout << "Sorted palindrome string: " << input << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
