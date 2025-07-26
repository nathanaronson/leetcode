class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);

        // Compute the product of all integers to the left of a given index and multiply result by it.
        int prefix = 1;
        for(int i = 0; i < size; ++i) {
            result[i] *= prefix;
            prefix *= nums[i];
        }

        // Compute the product of all integers to the left of a given index and multiply result by it. 
        int suffix = 1;
        for(int i = size - 1; i >= 0; --i) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        /*
        By multiplying the left and the right, we effectively sandwich multiplication around a given index.
        This is done in two sweeps of linear time O(n) with O(1) extra space as the prefix and suffix are scalar.
        */
        return result;
    }
};