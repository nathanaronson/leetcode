class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Leverage set's invariants of no duplicates.
        unordered_set<int> seen;

        for(int i : nums) {
            // If we are unable to add the element into the set, we know it is a duplicate.
            if(!seen.insert(i).second) {
                return true;
            }
        }
    
        // All elements were able to be added into the set, thus no duplicates.
        return false;
    }
};