class Solution {
public:
    bool isAnagram(string s, string t) {
        // If they are different sizes, they cannot be anagrams.
        if(s.size() != t.size()) return false;

        // Rather than use a frequency map, we can store lowercase letters based on index.
        // This enables faster caching.
        int freq[26] = {0};

        // Take the difference in frequency of each character.
        for(int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        // If that difference is non-zero, they are not anagrams.
        for(int i : freq) {
            if(i != 0) return false;
        }

        // If all characters have the same frequency, they are anagrams.
        return true;
    }
};