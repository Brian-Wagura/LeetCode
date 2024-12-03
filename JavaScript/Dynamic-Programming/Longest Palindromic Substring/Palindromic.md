# 5. Longest Palindromic Substring

Palindromic Substring - When it reads the same read backwards or forward.

Question:
    - Given a string s, return the longest palindromic substring in s.

Constraints:
    - 1 <= s.length <= 1000

Examples:
    Input: s = "babad"
    Output: "bab" or "aba"

    Input: "cbbd"
    Output: "bb"


## Solution

- Use of dynamic programming approach.

### Solution Explanation.
#### 1. Variable Initialization.
* *n* - length of the input string s.
* *maxLength* - length of the longest palindromic substring.
* *start* - starting index of the longest palindromic substring.

#### 2. A 2D boolean array *dp* to store the palindromic information.
* *dp[i][j]* will be **True** if the substring from index *i* to index *j* is a       palindrome, *false* otherwise.
* Initialize the diagonal elements *dp[i][i]* to be **True** - a single character is always a palindrome.

#### 3. Iterate the string from the end to the beginning.
* For each length *l* of the substring, from 1 to *n*, iterate through the string from index 0 to *n - l*.
* For each starting index *i*, we calculate the ending index *j = i + l - 1*.
* If *l* is 2 or 3, check if the characters at indices *i* and *j* are the same and set *dp[i][j]* accordingly.
* If *l* is greater than 3 check if the characters at indices *i* and *j* are the same and if the substring from *i + 1* to *j - 1* is a palindrome *(dp[i + 1][j - 1]) = **True***, set dp[i][j] accordingly.

#### 4. Update maxLength and start variables accordingly.
* If dp[i][j] is **True**, check the length of the current palindromic substring (*j = i + 1*) is greater than the current *maxLength*. If so, update *maxLength* and *start*.

#### 5. Return the substring from *start* to *start + maxLength - 1*.
* Represents the longest palindromic substring in the input string *s*.

## Time Complexity
* O(n ^ 2) - where *n* is the length of the string of the input *s*.
* We iterate through all possible substrings and check if there exist palindromes which takes O(n) time for each substring.

## Space Complexity
* O(n ^ 2) - use of a 2D boolean array to store the palindromic information.




