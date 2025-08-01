class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            // Store the maximum area and update it as we traverse the heights.
            int area = 0, size = heights.size();

            // Store the height and how far left that height can extend.
            stack<pair<int, int>> pairs;
    
            // Go through the heights.
            for(int i = 0; i < size; ++i) {
                int position = i;
    
                /* 
                The trick here is to keep the stack in strictly increasing order. This allows us
                to guarantee that the right-most bound is the current index i, while the left-most
                bound is what we are going to store as the second value in the tuple.
                */
                while(!pairs.empty() && heights[i] < pairs.top().first) {
                    auto& pair = pairs.top();

                    // The area is the difference of the two bounds times the height.
                    area = max(area, (i - pair.second) * pair.first);
                    pairs.pop();

                    /* 
                    Calculate how far left the current height can extend (the left bound).
                    The left bound is the index of the left-most height whose height is
                    greater than or equal to the current height. We can determine this
                    through the ascending order property, because we know that if we can
                    extend a taller height to a specific position, we can definitely
                    extend a shorter height to that same position. Therefore, it is trivial.
                    */
                    position = pair.second;
                }
    
                // Add the current value to the stack for future comparison.
                pairs.push({heights[i], position});
            }
    
            // Go through the remainder of the stack for any values who haven't proceeded a smaller value.
            while(!pairs.empty()) {
                auto& pair = pairs.top();

                // In this case, we know that the right bound is the end of the histogram, so its trivial.
                area = max(area, (size - pair.second) * pair.first);
                pairs.pop();
            }
    
            // Return the maximum area.
            return area;
        }
    };