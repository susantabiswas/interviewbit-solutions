/*
    https://www.interviewbit.com/problems/majority-element/

    Given an array, find the majority element. Majority element has an occurence count 
    of atleast floor(n/2).
*/
// TC: O(n)
int Solution::majorityElement(const vector<int> &arr) {
    // ini value for majority
    int majority = numeric_limits<int>::max();
    // initial count
    int c = 0;

    for(int i = 0; i < arr.size(); i++){
        // if the current element is not the current majority element
        // decrement count
        if(arr[i] != majority){
            --c;
        }
        // change majority element if current candidate count is zero
        if(c <= 0){
            majority = arr[i];
        }
        // increment count for current candidate
        ++c;
    }

    return majority;
}
