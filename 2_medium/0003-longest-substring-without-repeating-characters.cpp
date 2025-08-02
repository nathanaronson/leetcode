class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // Keep track of the current values in the string as a hashset.
            unordered_set<char> seen;

            // Keep track of the left value of the hashset.
            int left = 0, result = 0;
            for(int right = 0; right < s.size(); ++right) {
                /* 
                Prune out values up to and including the duplicate character.
                The trick here is that by storing the left-most index, we know
                what values are in the hashset and what aren't. This allows us
                to manipulate the set in O(1) time. Trivial sliding window.
                */
                while(seen.find(s[right]) != seen.end()) {
                    seen.erase(s[left]);
                    left++;
                }
    
                // Reinsert the value after deleting it.
                seen.insert(s[right]);

                // Update the maximum value.
                result = max(result, right - left + 1);
            }
    

            // Return the maximum value.
            return result;
        }
    };