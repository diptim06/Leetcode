class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();

        boolean[] visited = new boolean[nums.length];
        List<Integer> curr = new ArrayList<>();

        backtrack(ans, nums, visited, curr);
        return ans;
    }

    private void backtrack(List<List<Integer>> ans, int[] nums, boolean[] visited , List<Integer> curr)
    {
        if(curr.size() == nums.length)
        {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for(int i = 0; i<nums.length; i++)
        {
            if(visited[i])
                continue;

            visited[i] = true;
            curr.add(nums[i]);

            backtrack(ans, nums, visited, curr);

            curr.remove(curr.size()-1);
            visited[i] = false;
        }
    }
}