class Solution {
public:
	string minWindow(string s, string t) {
		// Base case, empty string so empty substring.
		if(t.empty()) return "";

		// Store frequency map of t's characters and current window's
		unordered_map<char, int> t_freq, window;
		for(char c : t)
			t_freq[c]++;

		// Similar to permutation problem, determine our target number of matches.
		int have = 0, need = t_freq.size();

		// Store the start and end indices of the minimum string.
		pair<int, int> res = {-1, -1};

		// Initial length set to max in case substring never found.
		int len = INT_MAX;

		// Left pointer
		int l = 0;

		// Right pointer
		for(int r = 0; r < s.length(); ++r) {
			char c = s[r];

			// Add current right pointer to window
			window[c]++;

			// If adding this character creates another match, increment it.
			if(t_freq.count(c) && window[c] == t_freq[c])
				have++;

			// Prune the substring from the left until the number of matches fall below the target.
			while(have == need) {

				// Update result.
				if(r - l + 1 < len) {
					len = r - l + 1;
					res = {l, r};
				}

				c = s[l];

				// Remove left-most character from window.
				window[c]--;

				// If removing this removes the match, update.
				if(t_freq.count(c) && window[c] < t_freq[c])
					have--;

				// Incremenet left to the right (pruning).
				l++;
			}
		}

		// If we never found a substring, return empty otherwise our left and right pointer.
		return len == INT_MAX ? "" : s.substr(res.first, len);

		/*
		 *  Overall, this problem wasn't that hard considering it is just a step up from Permutation in String.
		 *  The only catch is that our number of matches isn't lowercase letters (26), so we need to determine
		 *  that ourselves. The remainder of the problem is a trivial sliding window solution. Very fun!
		 * / 
	}
};
