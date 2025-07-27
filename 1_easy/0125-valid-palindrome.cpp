class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        // Checker either side for symmetry.
        while(left < right) {

            // Skip non-alphanumeric values on the left and right-hand side.
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;

            // If the alphanumeric values, non-case sensitive, aren't the same, not a palindrome.
            if(tolower(s[left]) != tolower(s[right])) return false;

            // Increment both.
            left++;
            right--;
        }

        // If no inequalities are found on both sides, it is a palindrome.
        return true;
    }
};