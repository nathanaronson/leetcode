class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> vals;
    
            for(int i = 0; i < nums.size(); ++i) {
                if(vals.find(target - nums[i]) != vals.end()) {
                    return {vals[target - nums[i]], i};
                }
                vals[nums[i]] = i;
            }
    
            return {};
        }
};