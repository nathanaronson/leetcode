class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, water = 0;
        while(left < right) {
            // Compute the maximum area.
            water = max(water, min(height[left], height[right]) * (right - left));

            // Shift the bar that is smaller.
            if(height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return water;
    }
};