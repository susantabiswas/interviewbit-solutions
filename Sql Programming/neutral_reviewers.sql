/*
    https://www.interviewbit.com/problems/neutral-reviewers/
*/

SELECT reviewers.reviewer_name AS reviewer_name from 
    ratings JOIN reviewers
    ON ratings.reviewer_id = reviewers.reviewer_id
    WHERE ratings.reviewer_stars IS NULL;
