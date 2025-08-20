class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// This DP solution involves breaking the vector into fixed-size blocks of size k.
		int n = nums.size();

		// Stores max element of box from left and right starting directions.
		vector<int> left(n), right(n);

		left[0] = nums[0];
		right[n - 1] = nums[n - 1];

		for(int i = 1; i < n; ++i) {
			// For each index, compute the max element within its given box.
			
			// Start a new box.
			if(i % k == 0) left[i] = nums[i];

			// Continue prefix max.
			else left[i] = max(left[i - 1], nums[i]);

			// Start a new box.
			if((n - 1 - i) % k == 0) right[n - i - 1] = nums[n - i - 1];
			
			// Continue suffix max.
			else right[n - i - 1] = max(right[n - i], nums[n - i - 1]);
		}

		vector<int> result(n - k + 1);
		for(int i = 0; i < n - k + 1; ++i)
			/*
			 * The trick here is that left[i - k + 1] gives the max from the start of the block,
			 * while right[i] gives the max from i to the end of its block. So together, they cover
			 * the whole window, regardless of whether it's inside one box or within the intersection
			 * of the two. This allows us to achieve a linear time solution through querying.
			 *
			 */
			result[i] = max(left[i + k - 1], right[i]);

		return result;
	}
};
