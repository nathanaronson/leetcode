class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            /*
            The task at hand is to find the maximum difference between two values,
            where the smaller value is on the left and the larger is on the right.
            This approach is greedy, where we assume that the current value is the sell,
            and we compare it to the buy value, which is going to be the minimum value
            of every element seen before it. This allows it to be done in O(n) time
            complexity and O(1) space complexity in a surprisingly elegant solution.
            */

            int profit = 0, buy = prices[0];
            for(int i : prices) {
                // Update the profit to be the largest.
                profit = max(profit, i - buy);

                // Update the buy to be the smallest.
                buy = min(buy, i);
            }
    
            // Return the profit.
            return profit;
        }
    };