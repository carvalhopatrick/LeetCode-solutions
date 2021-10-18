# https://leetcode.com/problems/longest-substring-without-repeating-characters/

# Solved with a sliding window algorithm

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        longest = 0
        myset = set()
        for j in range(len(s)):
            c = s[j]
            if str(c) in myset:
                while str(s[i]) != str(c):
                    myset.remove(str(s[i]))
                    i += 1
                i += 1
            else:
                myset.add(str(c))
                if longest < j-i:
                    longest = j-i
        if len(s) > 0:
            return longest+1
        else:
            return 0