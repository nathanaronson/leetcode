class Solution {
public:
    bool isValid(string s) {
        // Create mapping of right to left brackets.
        unordered_map<char, char> brackets = {
            {'}', '{'},
            {')', '('},
            {']', '['},
        };

        // Store left brackets in a stack.
        stack<char> vals;
        for(char c : s) {
            if(brackets.find(c) != brackets.end()) {
                // If it's a right bracket, the top of the stack must be the matching left bracket.
                if(!vals.empty() && vals.top() == brackets[c]) {
                    vals.pop();
                } else {
                    // Otherwise it is invalid.
                    return false;
                }
            } else {
                // If it's a left bracket, then add it to the stack.
                vals.push(c);
            }
        }

        // Return whether there are no remaining left brackets in the stack.
        return vals.empty();
    }
};