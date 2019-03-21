/*
  Generate a permutation for a given sequence of constraints
  https://www.interviewbit.com/problems/find-permutation/
*/

/*
    D means the next should be smaller than current and I means
    next should be greater than current, meaning as we move ahead we should
    have the next greater or smaller number, so towards the end we will
    have all the greater and smaller numbers taking the positions. 
    So we start with filling position from end, and take the largest and smallest
    numbers for each I and D position.
*/
vector<int> Solution::findPerm(const string str, int n) {
    // since we start with end, we start filling with smallest and
    // largest number
    int smaller = 1;
    int greater = n;
    
    vector<int> result(n);
    for(int i = str.size() - 1; i >= 0; i--) {
        // add the greatest number
        if(str[i] == 'I') {
            result[i + 1] = greater--;
        }
        else
        // add the smallest number
            result[i + 1] = smaller++;
    }
    
    // add the last number left
    result[0] = smaller;
    
    return result;
}
