"""
    https://www.interviewbit.com/problems/power-of-2/
"""

from math import log2
class Solution:
    # @param A : string
    # @return an integer
    def power(self, A):
        two_pow = log2(int(A))
        return 1 if two_pow - int(two_pow) < 0.00000000001 * two_pow else 0
