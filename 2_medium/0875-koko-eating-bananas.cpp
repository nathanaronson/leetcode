class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            // Slowest possible rate is 1 per hour, fastest rate is one pile per hour.
            int min_rate = 1, max_rate = *max_element(piles.begin(), piles.end());

            // Binary search of fastest rate.
            while(min_rate < max_rate) {
                int mid_rate = (min_rate + max_rate) / 2;

                // Determine hours to eat all piles with mid_rate.
                int hours = 0;
                for(int i : piles) {
                    hours += (i + mid_rate - 1) / mid_rate;
                }
    
                // If too slow, increase min_rate.
                if(hours > h) {
                    min_rate = mid_rate + 1;

                // If too fast, try slowing down.
                } else {
                    max_rate = mid_rate;
                }
            }
    
            // Return the slowest possible rate.
            return min_rate;

            // O(n) time to calculate total hours for each rate and maximum element
            // log m time for calculating minimum rate of binary search
        }
    };