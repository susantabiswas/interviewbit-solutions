/*
    Sort colors
    https://www.interviewbit.com/problems/sort-by-color/

    TC: O(n)
*/

void Solution::sortColors(vector<int> &arr) {
    int red = 0, white = 0, blue = arr.size();
    
    // we maintain three ptrs:
    // 0 - (red-1): contains red
    // red - (white-1): contains white
    // blue - (n-1): contains blue
    while(white < blue) {
        if(arr[white] == 0)
            swap(arr[red++], arr[white++]);
        else if(arr[white] == 1)
            ++white;
        else {
            --blue;
            swap(arr[blue], arr[white]);
        }
    }
}
