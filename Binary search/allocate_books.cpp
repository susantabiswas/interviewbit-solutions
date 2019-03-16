/*
    Painter's partition problem
    https://www.interviewbit.com/problems/allocate-books/
*/

int findOptimalPages(vector<int>& books, int students) {
    if(books.size() < students)
        return -1;
    
    // find the upper limit for optimal pages
    int h = accumulate(books.begin(), books.end(), 0);
    // lower limit for optimal pages will be the max no. of pages
    // for a single book
    int l = *max_element(books.begin(), books.end());
    int max_pages = -1;
    while(l <= h) {
        // max limit of pages for a student
        int mid = l + (h - l)  / 2;
        // now we check if current mid is optimal or not
        // by checking if this max number of pages is given 
        // then how many students will have it
        int students_c = 1, page_c = 0;
        for(int i = 0; i < books.size(); i++) {
           // if number of pages is lesser than decided limit we can still
           // assign current book to a student
           if(page_c + books[i] <= mid) {
               page_c += books[i];
           }
           else {   // no. of pages for current book has exceeded
                    // the limit, so we give the current book to next student
               ++students_c;
               page_c = books[i];
           }
        } 
        
        // check how many students got the books
        // when max limit for no.of pages was more
        // than what could be given
        if(students_c <= students) {
            max_pages = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return max_pages;
}

int Solution::books(vector<int> &books, int students) {
    return findOptimalPages(books, students);
}
