class Solution {
public:
    string encode(vector<string>& strs) {
	// O(n) linear time
        string result;

	// Schema: Length1#String1Length2#String2...
        for(string s : strs) {
            result += to_string(s.size()) + '#' + s;
        }

        return result;
    }

    vector<string> decode(string s) {
	// O(n) linear time
        vector<string> result;
        int i = 0;

	// Traverse the single string.
        while(i < s.size()) {
            int j = i;
	    
	    // Determine the length of the current string.
            while(s[j] != '#') j++;
            int length = stoi(s.substr(i, j - i));
            
	    // Move the pointer to the start of the string contents.
	    i = j + 1;

	    // Push back the substring given the pointer and the length.
            result.push_back(s.substr(i, length));

	    // Update the pointer past the string contents.
            i += length; 
        }

	/*
	 * The reason this works is due to the fact that we can guarantee
	 * the first few characters of the encoded string describes the length
	 * of the first string, meaning we can follow that pattern to effectively
	 * represent each character and not misrepresent length for contents or
	 * content for length.
	 */
        return result;
    }
};

