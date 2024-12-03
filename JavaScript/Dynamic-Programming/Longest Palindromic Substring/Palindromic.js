/**
 * Longest Palindromic Substring
 * Given a string s, return the longest palindromic substring in s.
 * 
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * Constraints:
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 */

const assert = require("assert");

var longestPalindrome = function(s) {
	let n = s.length;
	let maxLength = 0;
	let start = 0;

	// A 2D boolean array to store the palindrome.
	let dp = Array.from({ length: n }, () => Array(n).fill(false));

	// Initialize the diagonal elements to true.
	for (let i = 0; i < n; i++) {
		dp[i][i] = true;
		maxLength = 1;
		start = i;
	}

	// Iterate the string from the end to the beginning.
	for (let l = 2; l <= n; l++) {
		for (let i = 0; i < n - l + 1; i++) {
			let j = i + l - 1;

			if (l === 2) {
				dp[i][j] = (s[i] === s[j]);
			} else {
				dp[i][j] = (s[i] === s[j]) && dp[i + 1][j - 1];
			}

			if (dp[i][j] && l > maxLength) {
				maxLength = l;
				start = i;
			}
		}
	}

	return s.substring(start, start + maxLength);
}

// Test Cases
const testCases = [
	{input: "babad", expected: "bab"},
	{input: "cbbd", expected: "bb"},
]

testCases.forEach(({ input, expected }) => {
	const result = longestPalindrome(input);
	assert.strictEqual(result, expected, `Input: ${input}, Expected: ${expected}, Actual: ${result}`);
});

console.log("All tests passed!");
