class Solution {
private:
    void backTrack(int open, int closed, int n, string& current, vector<string>& result) {
        // The trick behind generating all cases is through a recursive tree.

        // Base Case: We have used the total amount of parentheses possible, append string and end recursion.
        if(open == n && closed == n) {
            result.push_back(current);
            return;
        }

        // Case 1: Still have opportunity to add more parentheses. Branch here.
        if(open < n) {
            // Add in parenthesis.
            current.push_back('(');
            
            // Make recursive call.
            backTrack(open + 1, closed, n, current, result);
            
            // Backtrack.
            current.pop_back();
        }

        // Case 2: Still need to close parentheses. Branch here.
        if(closed < open) {
            // Add in parenthesis.
            current.push_back(')');
            
            // Make recursive call.
            backTrack(open, closed + 1, n, current, result);
            
            // Backtrack.
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // Initialize result and current string to be passed between recursive calls.
        vector<string> result;
        string current;
        
        // Begin recursive call.
        backTrack(0, 0, n, current, result);

        // Return result.
        return result;
    }
};