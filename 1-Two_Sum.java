class Solution {
    public int[] twoSum(int[] nums, int target) {

        for (int i = 0;  i < nums.length;  i++){
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[] {i, j};
                }
            }
        }

        return new int[] {-1, -1};
        
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {3, 2, 4};
        int target = 6;
        int[] result = solution.twoSum(nums, target);
        System.out.println("Indices: " + result[0] + ", " + result[1]);
    }
}