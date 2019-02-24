/*
    https://www.interviewbit.com/problems/distribute-candy/
*/

int Solution::candy(vector<int> &rating) {
    vector<int> candies(rating.size(), 1);
    // forward pass
    for(int i = 1; i < rating.size(); i++) {
        // if previous neighbour has lower rating, current should have atleast + 1 more candy
        candies[i] = rating[i-1] < rating[i] ? candies[i-1] + 1 : candies[i];
    }
    // backward pass
    int total_candies = candies[rating.size() - 1];
    for(int j = rating.size() - 2; j >= 0; j--) {
        // for current kid, he should get +1 more candy than
        // the kid with max rating amongst his neighbours but lesser than current kid
        if(j == 0)
            candies[j] = rating[j+1] < rating[j] ? candies[j+1] + 1 : candies[j];
        else {
            if(rating[j + 1] < rating[j] && rating[j-1] < rating[j]) {
                candies[j] = max(candies[j+1], candies[j-1]) + 1;
            }
            else {
               candies[j] = rating[j+1] < rating[j] ? candies[j+1] + 1 : candies[j]; 
            }
        }
        total_candies += candies[j];
    }
   
    return total_candies;
}
