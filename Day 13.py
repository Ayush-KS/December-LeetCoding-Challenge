# Burst Balloons

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0]*n for i in range(n)]
        
        for gap in range(2, n):
            for left in range(n - gap):
                right = left + gap
                for mid in range(left + 1, right):
                    dp[left][right] = max(dp[left][right], dp[left][mid] + nums[left] * nums[mid] * nums[right] 
                                         + dp[mid][right])
                    
        return dp[0][len(nums) - 1]