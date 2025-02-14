/**
 * max_uncrossed_lines - Finds maximum number of uncrossed lines
 *
 * @nums1: First array of integers
 * @nums1size: Size of the first array
 * @nums2: Second array of integers
 * @nums2size: Size of the second array
 *
 * Return: maximum number of uncrossed lines possible
 */

int maxUncrossedLines(int* nums1, int nums1_size, int* nums2, int nums2_size)
{
	int dp[501][501] = {0};
	int i, j;

	for (i = 1; i <= nums1_size; i++)
	{
		for (j = 1; j <= nums2_size; j++)
		{
			if (nums1[i - 1] == nums2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ?
					   dp[i - 1][j] : dp[i][j - 1];
		}
	}

	return (dp[nums1_size][nums2_size]);
}
