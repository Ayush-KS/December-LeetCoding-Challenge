// 4Sum II

class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int n = A.length;
        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                Integer cnt = freq.get(C[i] + D[j]);
                freq.put(C[i] + D[j], (cnt == null) ? 1 : cnt + 1);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                Integer cnt = freq.get(-A[i] - B[j]);
                if(cnt != null)
                    ans += cnt;
            }
        }
        return ans;
    }
}