class Solution:
    def longestSubstring(self, s: str) -> int:
        l = []
        digit = 0
        sl = []
        sl[:] = s
        for c in sl:
            if c in l:
                return digit
            else:
                l.append(c)
                digit += 1
                
        return digit
        
        
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        for i, v in enumerate(s):
            ans = max(ans, self.longestSubstring(s[i:]))
            
        return ans
        
