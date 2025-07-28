class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // Sort the values in non-descending order O(log n) for invariants
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; ++i) {
            // If the left-most pointer is the same as before, skip.
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = size - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                /* 
                If we are undershooting, we can increase the middle pointer.
                We can follow this invariants because we know its sorted.
                */
                if(sum < 0) left++;
                // The same logic applies if we are overshooting.
                else if(sum > 0) right--;
                else {
                    // If the three values add to zero, we append it.
                    int l = nums[left], r = nums[right];
                    result.push_back({nums[i], l, r});

                    /* 
                    To guarantee that we do not add in the same triple, we skip all duplicates.
                    We skip duplicates for both the middle and right pointer. We skip duplicates
                    of the left pointer in the boolean condition on line 11.
                    */
                    while(left < right && nums[left] == l) left++;
                    while(left < right && nums[right] == r) right--;
                }
            }
        }

        /* 
        Once our for loop condition ends (and doesn't break because the right pointer is bound by size),
        we then return all of our unique triples. This is done in O(n^2) time with O(1) extra space.
        */
        return result;
    }
};