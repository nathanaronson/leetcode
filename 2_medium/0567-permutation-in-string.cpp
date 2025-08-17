class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            int l1 = s1.length(), l2 = s2.length();

            // If the permutation is longer than the string, it can't be a permutation
            if(l1 > l2) return false;
            vector<int> v1(26), v2(26);

            // Count the frequency of each lowercase character in s1 and s2
            for(int i = 0; i < l1; ++i) {
                v1[s1[i] - 'a']++;
                v2[s2[i] - 'a']++;
            }
    
            // Count the number of matching frequencies of characters
            int matches = 0;
            for(int i = 0; i < 26; ++i) {
                if(v1[i] == v2[i]) matches++;
            }
    
            // Maintain a sliding window of size l1 across l2 and check if the frequencies of characters match
            for(int i = l1; i < l2; ++i) {
                // If all the lowercase character frequencies match, then s1 is a permutation of s2
                if(matches == 26) return true;
                int j = s2[i] - 'a';

                // Adding the right character to the window and updating frequencies
                v2[j]++;
                if(v1[j] == v2[j]) matches++;
                if(v1[j] + 1 == v2[j]) matches--;
                
                // Removing the left character from the window and updating frequencies
                j = s2[i - l1] - 'a';
                v2[j]--;
                if(v1[j] == v2[j]) matches++;
                if(v1[j] - 1 == v2[j]) matches--;
            }
    
            // If all the lowercase character frequencies match, then s1 is a permutation of s2
            return matches == 26;
        }
    };
    