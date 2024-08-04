// problem link
// https://leetcode.com/problems/design-neighbor-sum-service/description/

class neighborSum {
public:
    vector<vector<int>> arr;
    int n;

    neighborSum(vector<vector<int>>& grid) {
        arr = grid;
        n = grid.size();
    }

    int adjacentSum(int value) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == value) {
                    if(i - 1 >= 0) sum += arr[i - 1][j]; // top
                    if(i + 1 < n) sum += arr[i + 1][j];  // bottom
                    if(j - 1 >= 0) sum += arr[i][j - 1]; // left
                    if(j + 1 < n) sum += arr[i][j + 1];  // right
                    return sum;
                }
            }
        }
        return sum;
    }

    int diagonalSum(int value) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == value) {
                    if(i - 1 >= 0 && j - 1 >= 0) sum += arr[i - 1][j - 1]; // top-left
                    if(i - 1 >= 0 && j + 1 < n) sum += arr[i - 1][j + 1];  // top-right
                    if(i + 1 < n && j - 1 >= 0) sum += arr[i + 1][j - 1];  // bottom-left
                    if(i + 1 < n && j + 1 < n) sum += arr[i + 1][j + 1];  // bottom-right
                    return sum;
                }
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
