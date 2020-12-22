// Smallest Range II

class Solution {
    public int smallestRangeII(int[] arr, int k) {
        int n = arr.length;
        Arrays.sort(arr);
        int ans = arr[n - 1] - arr[0];
        int left = arr[0] + k;
        int right = arr[n - 1] - k;
        for(int i = 0; i < n - 1; i++) {
            int currMax = Math.max(arr[i] + k, right);
            int currMin = Math.min(arr[i + 1] - k, left);
            ans = Math.min(ans, currMax - currMin);
        }
        return ans;
    }
}