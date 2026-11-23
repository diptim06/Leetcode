class Solution {
    private int total = 0;

    public int subsetXORSum(int[] nums) {
        total = 0;

        backtrack(0, nums, 0);
        return total;
    }

    void backtrack(int i, int[] nums, int curr)
    {
        if(i == nums.length)
        {
            total += curr;
            return;
        }

        backtrack(i+1, nums, curr ^ nums[i]);
        backtrack(i+1, nums, curr);
    }
}