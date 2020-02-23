/*
    https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/
    
    When we connect two points, then the circle gets divided into two halves.
    If we know the no. of ways to get chords in each half, then the total
    no. of chords is just:
    no. of ways in first half * no. of ways in second half .
    The series is 1, 1, 2, 5, 14 ...
    Which is also nth catalan number.
*/
int Solution::chordCnt(int N) {
    const long long MOD = pow(10, 9) + 7;
    // dp(i): nth catalan number
    vector<long long> dp(N+1, 0);
    // 0th and 1st is 1
    dp[0] = dp[1] = 1;
    
    for(int i = 2; i <= N; i++) {
        // find the ith catalan number
        for(int k = 0; k < i; k++)
            dp[i] = (dp[i] + ((dp[k] * dp[i - 1 - k]) % MOD)) % MOD;
    }
    return dp[N];
}
