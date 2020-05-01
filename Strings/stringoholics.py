"""
    https://www.interviewbit.com/problems/stringoholics/
"""
from math import gcd

class Solution:
    # LCM of two numbers
    def LCM(self, a, b):
        return a * b / gcd(a, b)
    
    # finds the LCM of numbers
    # TC: O(nlogm), m: largest number, n: length of array
    def lcm_numbers(self, arr):
        lcm = arr[0]
        for t in arr[1:]:
            lcm = (lcm * t) // gcd(lcm, t)
        
        return lcm
    
    
    def orig_rotation_time(self, s):
        t = 1
        curr_shifts = 0
        
        # every time i * (i+1)/2 shifts are for time: i
        # so for whichever time i we get shifts divisible by N,
        # makes it equal to original string
        while(True):
            curr_shifts += t
            if(curr_shifts % len(s)) == 0:
                break
            t += 1
            
        return t
        
    # @param A : list of strings
    # @return an integer
    def solve(self, A):
        time_req = []
        
        # find the min time to get back to original
        for i in range(len(A)):
            time_req += [self.orig_rotation_time(A[i])]
            
        # LCM of all the min times
        lcm = self.lcm_numbers(time_req)
        
        return int(lcm % (pow(10, 9) + 7))
