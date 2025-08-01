class Solution {
    public:
        int search(vector<int>& nums, int target) {
            // Two pointer solution.
            int l = 0, r = nums.size() - 1;
            
            // Continue iterating until the pointers cross.
            while(l <= r) {
                // Consider the middle of the two pointers.
                int m = l + ((r - l) / 2);

                // If its too large, then we shift down the upper bound to below it.
                if(nums[m] > target) {
                    r = m - 1;
                } else if (nums[m] < target) {
                    // If its too small, then we shift up the lower bound to above it.
                    l = m + 1;
                } else {
                    // We've found the value, so we return its index.
                    return m;
                }
            }
    
            // We can't find the value so we return -1.
            return -1;
        }
    };
    