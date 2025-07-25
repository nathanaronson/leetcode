class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store values and their indices with O(1) lookup time.
        unordered_map<int, int> vals;
    
        for(int i = 0; i < nums.size(); ++i) {
            // If the target difference exists, return its value and the current index.
            if(vals.find(target - nums[i]) != vals.end()) {
                return {vals[target - nums[i]], i};
            }
            // Otherwise, add the current value and its index to the map.
            vals[nums[i]] = i;
        }
    
        // Vestigial.
        return {};
    }
};