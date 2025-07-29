class Solution {
public:
    int trap(vector<int>& height) {
        // Two-pointer solution.
        int left = 0, right = height.size() - 1;

        // Maximum bar height from either side.
        int lmax = 0, rmax = 0;

        // Total water accumulated.

        int water = 0;
        // Start on either end.
        while(left < right) {
            /*
            The trick of this problem to make it O(1) memory space is that
            we follow the invariants if shifting the bar whose height is lower.
            This allows us to know immediately which maximum bar to compare it to:
            its respective side maximum. It doesn't matter what the other side's maximum
            is, because we only care about the smaller maximum, which is the one we're shifting.
            */
            if(height[left] < height[right]) {
                // Update the water, remember it can't be negative.
                water += max(0, lmax - height[left]);
                // Update the maximum.
                lmax = max(lmax, height[left]);
                // Shift the pointer.
                left++;
                } else {
                // The right-hand logic follows analogously.
                water += max(0, rmax - height[right]);
                rmax = max(rmax, height[right]);
                right--;
            }
        }

        // Return the maximum amount of water once the two pointers have converged.
        return water;
    }
};