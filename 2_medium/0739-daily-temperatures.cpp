class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size);
        // Store the given temperature and index in a stack: {temp, index}.
        stack<pair<int, int>> stack;

        for(int i = 0; i < size; ++i) {
            int t = temperatures[i];

            // Continue to go through the stack until we reach a value greater than the current temperature.
            while(!stack.empty() && t > stack.top().first) {
                /*
                    As we pop an element from the stack, we can determine how long it took to 
                    find a greater day, because we know that this greater day is the day
                    which we just compared the element we are popping off to. This means
                    that we have the index of the first greater day: i, as well as the index
                    of the element which was just popped off: the second element of the tuple.
                    From there, it is a trivial calculation of finding the difference in indices.
                    The trick here is to maintain a monotonically decreasing stack to ensure that
                    when we pop an element off the stack, we know that the current iteration is the
                    first day whose temperature is greater.
                */ 
                int index = stack.top().second;
                stack.pop();
                result[index] = i - index;
            }

            // Add in the temperature into the stack after removing other elements.
            stack.push({t, i});
        }

        // Return the resulting vector.
        return result;
    }
};