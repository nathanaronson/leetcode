class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L = 0, M = matrix.size() - 1, N = matrix[0].size() - 1;

        // Trivial nested binary search. Outer loop finds proper row.
        while(L <= M) {
            int R = (L + M) / 2;
            if(target < matrix[R][0]) M = R - 1;
            else if(target > matrix[R][N]) L = R + 1;
            else {
                // Inner loop finds proper column in row.
                L = 0;
                while(L <= N) {
                    int C = (L + N) / 2;
                    if(target < matrix[R][C]) N = C - 1;
                    else if(target > matrix[R][C]) L = C + 1;
                    else return true;
                }

                // If range in row but not in row, return false.
                return false;
            }
        }

        // If range not in bounds of matrix, return false.
        return false;

    /*
     * As a side note, I realized this solution could be treated as a singular 
     * binary search by flattening the matrix. The row is the middle value divided
     * by the width, while the column is the middle value modulo the width.
     * While this solution is more elegant, such a mathematical observation
     * is subtle to discern at first glance, ergo the solution above is more trivial.
     * Note that both provide an optimal solution of O(log(m) + log(n)) or O(log(mn)).
     */

    }
};
