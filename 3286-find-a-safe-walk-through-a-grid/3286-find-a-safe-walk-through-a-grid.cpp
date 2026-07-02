class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, -1));

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        q.push({{0, 0}, startHealth});
        vis[0][0] = startHealth;

        int dr[4] = {0, 0, -1, 1};
        int dc[4] = {-1, 1, 0, 0};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int currHealth = it.second;

            if (row == n - 1 && col == m - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int newr = row + dr[k];
                int newc = col + dc[k];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {

                    int newHealth = currHealth;

                    if (grid[newr][newc] == 1)
                        newHealth--;

                    if (newHealth > 0 && newHealth > vis[newr][newc]) {
                        vis[newr][newc] = newHealth;
                        q.push({{newr, newc}, newHealth});
                    }
                }
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return solve(0, 0, grid, health);
    }
};