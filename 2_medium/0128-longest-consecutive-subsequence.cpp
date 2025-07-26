class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Edge Case: If the list is empty, then return 0.
        if(nums.empty()) return 0;

        // Convert list to hash set in O(n) time for O(1) lookup time.
        unordered_set<int> vals(nums.begin(), nums.end());

        int max_length = 0;
        for(int i : vals) {
            // If it does not start its own unique subsequence, skip.
            if(vals.find(i - 1) != vals.end()) continue;

            int curr = 1;
                
            // Get the length of the subsequence.
            while(vals.find(i + curr) != vals.end()) curr++;

            // Update max value after determining length of subsequence.
            max_length = max(max_length, curr);
        }

        return max_length;
    }
};