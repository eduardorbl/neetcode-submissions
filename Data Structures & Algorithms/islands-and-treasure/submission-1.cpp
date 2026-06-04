class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long inf = 2147483647; 
        vector<vector<int>> dirs = {
            {-1,0}, {1,0}, {0,-1}, {0,1}       
        };
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]==0) q.push({i, j});
            }
        }
        int dist = 1;
        while (!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto [i, j] = q.top();
                q.pop();

                for (auto [dx, dy] : dirs)
                {
                    int ni = dx + i, nj = dy + j;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (grid[ni][nj] == inf) grid[ni][nj] = dist;
                    q.push({ni,nj});
                }
            }
            dist++;
        }
    }
};
