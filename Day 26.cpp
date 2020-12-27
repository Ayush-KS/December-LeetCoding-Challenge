// Decode Ways

class Solution {
public:
    
    int helper(string& s, int* dp, int i) {
        if(i == s.size()) 
            return 1;
        if(dp[i + 1] != -1)
            return dp[i + 1];
        if(s[i] == '0')
            return 0;
        dp[i + 1] = helper(s, dp, i + 1);
        int num = 0;
        if(i < s.size() - 1)
            num = 10*(s[i] - '0') + (s[i + 1] - '0');
        if(num >= 10 && num <= 26)
            dp[i + 1] += helper(s, dp, i + 2);
        return dp[i + 1];
    }
    
    int numDecodings(string s) {
        int n = s.size();
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        return helper(s, dp, 0);
    }
};