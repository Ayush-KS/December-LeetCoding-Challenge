# Pairs of Songs With Total Durations Divisible by 60

class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        freq = [0]*60
        ans = 0
        for t in time:
            ans += freq[(60 - (t % 60)) % 60]
            freq[t%60] += 1
        return ans