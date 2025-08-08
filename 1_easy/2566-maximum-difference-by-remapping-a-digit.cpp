class Solution {
    public:
        int minMaxDifference(int num) {
            string s = to_string(num);
            char to9 = '9';
    
            // Determine the most significant digit that isn't 9.
            for(char c : s) {
                if(c != '9') {
                    to9 = c;
                    break;
                }
            }
    
            // Change all instances of that digit to 9.
            string max = s;
            for(char &c : max) {
                if(c == to9) {
                    c = '9';
                }
            }
    
            int maxVal = stoi(max);
    
            // Follow except with 0.
            char to0 = '0';
            for(char c : s) {
                if(c != '0') {
                    to0 = c;
                    break;
                }
            }
    
            string min = s;
            for(char& c : min) {
                if(c == to0) {
                    c = '0';
                }
            }
    
            int minVal = stoi(min);
    
            // Return the difference.
            return maxVal - minVal;
        }
    };