# https://leetcode.com/problems/longest-substring-without-repeating-characters/

# Solved with a sliding window algorithm

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        longest = 0
        myset = set()
        
        for j in range(len(s)):
            while s[j] in myset:
                myset.remove(s[i])
                i += 1
            myset.add(s[j])
            longest = max(longest, j-i+1)
        
        return longest