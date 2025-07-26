class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        Store list of string based on their frequency as the keys.
        Use std::array<int, 26> rather than C-style array don't have comparison implemented.
        Use tree map instead of hash map because std::array<int, 26> does not have hasing function.
        This in turn results in O(log n) rather than O(1) lookup time – not ideal.
        */ 
        map<array<int, 26>, vector<string>> vals;

        // Create the frequency map, appending strings to their respective lists.
        for(const string& s : strs) {
            array<int, 26> freq = {0};
            for(char c : s) {
                freq[c - 'a']++;
            }

            // Cool things about operation[] is that it automatically inserts a new element.
            vals[freq].push_back(s);
        }
    
        // Create result vector and reserve size to pre-allocate memory.
        vector<vector<string>> result;
        result.reserve(vals.size());

        // Append vectors into result.
        for(const auto& [key, value] : vals) {
            result.push_back(value);
        }
    
        return result;
    }
};