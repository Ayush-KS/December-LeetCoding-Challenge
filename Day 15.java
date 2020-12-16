// Squares of a Sorted Array

class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int si = 0;
        int ei = n - 1;
        int k = n - 1;
        while(k >= 0) {
            if(nums[ei]*nums[ei] > nums[si]*nums[si]) {
                ans[k--] = nums[ei]*nums[ei--];
            } else {
                ans[k--] = nums[si]*nums[si++];
            }
        }
        return ans;
    }
}