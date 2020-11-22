class Solution:    
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        start = 0
        end = 0
        strSet = set()
        sl = []
        sl[:] = s
        for i, c in enumerate(s):
            if c in strSet:
                ans = max(ans, end - start)
                
                for subIdx in range(start, end):
                    subChar = s[subIdx]
                    if subChar in strSet:
                        strSet.remove(subChar)
                    if c == subChar:
                        strSet.add(c)
                        start = subIdx + 1
                        end = i + 1
                        break
            else:
                strSet.add(c)
                end += 1
        
        ans = max(ans, end - start)
            
        return ans
        
