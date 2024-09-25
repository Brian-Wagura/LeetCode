#include <string.h>
#include <stdio.h>

/* Accepted solution */
int lastStoneWeightII(int* stones, int stonesSize) {
    int totalSum = 0;

    for (int i = 0; i < stonesSize; i++) {
        totalSum += stones[i];
    }

    int dp[totalSum + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for (int i = 0; i < stonesSize; i++) {
        for (int j = totalSum; j >= stones[i]; j--) {
            dp[j] |= dp[j - stones[i]];
        }
    }

    for (int i = totalSum / 2; i >= 0; i--) {
        if (dp[i]) {
            return totalSum - 2 * i;
        }
    }
    return 0;
}

int main() {
    int stones[] = {2,7,4,1,8,1};
    // int stones[] = {31, 26, 33, 21, 40};
    int size = sizeof(stones) / sizeof(stones[0]);
    int result = lastStoneWeightII(stones, size);
    printf("The smallest possible weight of the last stone is: %d\n", result);
    return 0;
}