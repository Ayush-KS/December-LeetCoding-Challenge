# Palindrome Partitioning

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = list()
        
        def isPalindrome(s):
            return s == s[::-1]
        
        palin = [[False]*(len(s) + 1) for i in range(len(s) + 1)]
        
        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                if(isPalindrome(s[i : j])):
                    palin[i][j] = True
        
        def helper(s, curr, i):
            if(i == len(s)):
                ans.append(list(curr))
                return
            for j in range(i + 1, len(s) + 1):
                if(palin[i][j]):
                    curr.append(s[i : j])
                    helper(s, curr, j)
                    curr.pop()
        
        helper(s, [], 0)
        return ans