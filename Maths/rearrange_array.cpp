/*
    https://www.interviewbit.com/problems/rearrange-array/
    TC: O(n)
*/  

/*
    The objective is to have :
     A[i] = A[A[i]] but with O(1) space.
     So for each location we need to know the current and final value it wants

     We can encode both the information:
     A[i] = A[i] + (A[A[i]] % n) * n

     old value: A[i] % n : we have added a term to original which is a multiple of n, so
                on doing modulo with n, that term becomes 0 and the original term is left
     new value : A[i] / n
                The added term is basically the number we want multiplied by n, and since
                all the numbers lie in [0,n-1] range, original value of a[i] / n = 0, 
                so on dividing by n, original gets zero, and new added value being a multiple of 'n'
                gives the desired value we wanted
*/
void Solution::arrange(vector<int> &arr) {
    int n = arr.size();
    
    for(int i = 0; i < arr.size(); i++)
        arr[i] = arr[i] + (arr[arr[i]] % n) * n;
        
    // get the new values
    for(int i = 0; i < arr.size(); i++)
        arr[i] = arr[i] / n;
}
