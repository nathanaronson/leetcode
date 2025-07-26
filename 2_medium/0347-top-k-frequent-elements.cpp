class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
    
        // Create a hash map storing numbers to their frequency.
        for(int i : nums) {
            count[i]++;
        }
    
        int size = nums.size();
    
        /* Create a bucket where the index is the frequency and the
           value is a vector of numbers whose frequency is that. */
        vector<vector<int>> freq(size + 1);
        for(const auto& [key, value] : count) {
            freq[value].push_back(key);
        }
    
        // Memory allocate the size of the resultant vector.
        vector<int> result;
        result.reserve(k);

        /* Traverse the bucket from highest frequency to lowest.
           Short-circuit once the result has reached k elements. */
        for(int i = size; i >= 0 && result.size() < k; --i) {

            // Add the elements of the vector in each index.
            for(int n : freq[i]) {
                result.push_back(n);

                /* 
                I believe the test cases are arranged such that if we add an element
                of a specific frequency, we add all elements of that frequency. 
                This guarantees order not mattering, and thus we only check for termination
                as we traverse the bucket, not the contents of a specific index.
                */
            }
        }
    
        // Loop terminates because result has reached size k.
        return result;
    }
};