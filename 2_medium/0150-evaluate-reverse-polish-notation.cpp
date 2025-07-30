class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Store the numbers in a stack. When performing an operation, append the result to the stack.
        stack<int> vals;

        for(const string& s : tokens) {
            // Case on operators.
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = vals.top(); vals.pop();
                int a = vals.top(); vals.pop();
                // When performing an operation, top two values are operands and append result to top.
                switch(s[0]) {
                    case '+': vals.push(a + b); break;
                    case '-': vals.push(a - b); break;
                    case '*': vals.push(a * b); break;
                    case '/': vals.push(a / b); break;
                }
            } else {
                // Convert numeric string to int.
                vals.push(stoi(s));
            }
        }

        // Return the result.
        return vals.top();
    }
};