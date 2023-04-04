"""
https://leetcode.com/problems/one-edit-distance/
"""

def isOneEditDistance(s: str, t: str) -> bool:
    if len(s) < len(t):
        s, t = t, s
    if len(s) - len(t) > 1:
        return False

    # find the first difference
    i, j, found = 0, 0
    found = False
    while i < len(s) and j < len(t):
        if s[i] != t[j]:
            if found:
                return False
            found = True
            
            i += 1
            if len(s) == len(t):
                j += 1
        else:
            i += 1
            j += 1

    # check if there's an extra character in one of the strings
    return (found and i == len(s) and j == len(t)) or (not found and (len(s) - len(t) == 1)
