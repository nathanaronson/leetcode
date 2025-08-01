class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            // Store the positions and speeds as a pair.
            vector<pair<int, int>> pair;
            for(int i = 0; i < position.size(); ++i) {
                pair.push_back({position[i], speed[i]});
            }
    
            // Sort the pairs in decreasing order of position.
            sort(pair.rbegin(), pair.rend());
    
            vector<double> stack;
            for(auto& p : pair) {
                // For each pair, calculate how long it takes to reach the end.
                stack.push_back((double)(target - p.first) / p.second);

                /*
                If it takes less time than the previous value, remove it from the stack.
                This allows us to treat each unique value in the stack as a group.
                */
                if(stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]) {
                    stack.pop_back();
                }
            }
    
            // Therefore, we simply return the number of elements in the stack to get the number of groups.
            return stack.size();
        }
    };