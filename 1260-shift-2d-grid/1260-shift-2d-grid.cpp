class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ramesh(n, vector<int>(m, 0)); 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                int linear_index = i * m + j;
                int new_linear_index = (linear_index + k) % (n * m);
                int new_i = new_linear_index / m;
                int new_j = new_linear_index % m;
                ramesh[new_i][new_j] = grid[i][j];
            }
        }
        
        return ramesh;
    }
};