class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right) {

            // If we've reached the sum, return the indices + 1 (1-indexed).
            if(numbers[left] + numbers[right] == target) return {left + 1, right + 1};

            // If we're undershooting, increase the sum by following the strictly ascending variants.
            if(numbers[left] + numbers[right] < target) left++;

            // If we're overshooting, decrease the sum by following the strictly ascending variants.
            if(numbers[left] + numbers[right] > target) right--; 
        }
   
        // Vestigial.
        return {};
    }
};