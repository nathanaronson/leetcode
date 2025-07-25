class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();

        // If there are no children, no candies need to be allocated.
        if(length == 0) return length;

        // Create two lists for each children
        vector<int> left(length, 1), right(length, 1);

        // For the left list, count the number of consecutive candies required left-to-right.
        // Increase by one sequentially otherwise default to 1.
        for(int i = 1; i < length; ++i) {
            if(ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Follows analogously but counting downwards.
        for(int i = length - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i  +1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        int num_candies = 0;

        /* 
        The minimum quantity of candy required for each
        child is the greater value of the two lists. We
        then aggregate.
        */
        for(int i = 0; i < length; ++i) {
            num_candies += max(left[i], right[i]);
        }

        return num_candies;
    }
};