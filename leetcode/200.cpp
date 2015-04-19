class Solution {
public:
    bool **p;
    void dfs(int x, int y, vector<vector<char> > &grid, vector<vector<bool> > &vis)
    {
        vis[x][y] = true;
        int n = grid.size(), m = grid[0].size();
        if (x + 1 < n && grid[x + 1][y] == '1' && !vis[x + 1][y])
            dfs(x + 1, y, grid, vis);
        if (x - 1 >= 0 && grid[x - 1][y] == '1' && !vis[x - 1][y])
            dfs(x - 1, y, grid, vis);
        if (y + 1 < m && grid[x][y + 1] == '1' && !vis[x][y + 1])
            dfs(x, y + 1, grid, vis);
        if (y - 1 >= 0 && grid[x][y - 1] == '1' && !vis[x][y - 1])
            dfs(x, y - 1, grid, vis);
    }
    
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() == 0)
            return 0;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false)); 
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                vis[i][j] = false;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis);
                    ans++;
                }
        return ans;
    }
};
