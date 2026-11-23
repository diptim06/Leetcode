class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();

        backtrack(0, nums, ans, curr);
        return ans;
    }

    void backtrack(int i, int[] nums, List<List<Integer>> ans, List<Integer> curr)
    {
        if(i == nums.length)
        {
            ans.add(new ArrayList<>(curr));
            return;
        }

        curr.add(nums[i]);
        backtrack(i+1, nums, ans, curr);

        curr.remove(curr.size()-1);
        backtrack(i+1, nums, ans, curr);
    }
}