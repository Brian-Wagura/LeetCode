int maximumLength(int* nums, int numsSize, int k) {

    /* Dynamically allocate memory */
    int* dp = (int*)malloc((numsSize + 1) * sizeof(int));

    /* Initialize the array with zeros */
    memset(dp, 0, (numsSize + 1) * sizeof(int));

    int count = 0;
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < numsSize; right++) {
        if (right > 0 && nums[right] != nums[right - 1]) {
            count++;
        }

        while (count > k) {
            if (left > 0 && nums[left] != nums[left - 1]) {
                count--;
            }
            left++;
        }


    }

}

