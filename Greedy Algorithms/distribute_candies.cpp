/*
    https://www.interviewbit.com/problems/distribute-candy/
*/

// Solution 1
int Solution::candy(vector<int> &ratings) {
    if(ratings.empty())
        return 0;
        
    vector<int> candies(ratings.size(), 1);
    // decide the candies based on left side rating
    for(int i = 1; i < ratings.size(); i++)
        if(ratings[i] > ratings[i-1])
            candies[i] = candies[i-1] + 1;
    
    int total = candies.back();
    // decide the candies based on right side ratings as well
    for(int i = (int)ratings.size()-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1])
            // we give the current candies more than the right counterpart
            // only when it is assigned lesser candies, as the candies
            // already assigned are based on left counterpart
            candies[i] = max(candies[i], candies[i+1] + 1);
    
        total += candies[i];
    }
    return total;
}


// Solution 2
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
