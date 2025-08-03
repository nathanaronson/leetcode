class Solution {
    public:
        int characterReplacement(string s, int k) {
            // Use a sliding window and store the frequency of each character.
            unordered_map<char, int> freq;

            // Store the maximum frequency of a given character in the frequency map.
            int l = 0, maxf = 0, res = 0;
            for(int r = 0; r < s.size(); ++r) {
                // Add the value to the window and update the frequency.
                freq[s[r]]++;
    
                // Update the frequency.
                maxf = max(maxf, freq[s[r]]);
                
                /* 
                The difference of the number of characters minus the maximum frequency should be greater than
                the total number of swaps, otherwise it is not going to be all unique.
                */
                while((r - l + 1) - maxf > k) {
                    freq[s[l]]--;
                    l++;
                }
    
                // Update the maximum length.
                res = max(res, r - l + 1);
            }
    
            // Return the maximum length.
            return res;
        }
    };