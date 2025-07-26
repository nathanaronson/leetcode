class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {

            // Ues hashsets to guarantee that values are unique (can only appear once)
            unordered_set<int> row, column, box;

            row.reserve(9);
            column.reserve(9);
            box.reserve(9);
            for(int j = 0; j < 9; ++j) {

                /* 
                   Get the relative sub-grid x and y position for the box hashset.
                   Allows us to traverse an entire 3x3 grid in one linear sweep.
                   i pins the starting location, while j is what walks and creates the
                   3x3 comparison shape.
                */ 
                int x = 3 * (i / 3) + j / 3;
                int y = 3 * (i % 3) + j % 3;

                /* 
                   Check if cannot insert the element and it is a number.
                   Find it interesting how we can swap the indices to walk
                   left-to-right and up-to-down contemporaneously.
                */
                if(
                    !row.insert(board[i][j]).second &&
                    board[i][j] != '.' ||
                    !column.insert(board[j][i]).second &&
                    board[j][i] != '.' ||
                    !box.insert(board[x][y]).second &&
                    board[x][y] != '.'
                ) {
                    return false;
                }
            }
        }

        // If we were able to successfully add in all elements, then it is valid.
        return true;
    }
};