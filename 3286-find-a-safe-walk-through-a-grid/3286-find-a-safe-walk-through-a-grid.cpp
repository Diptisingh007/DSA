class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        int startHealth = health - grid[0][0];
        if (startHealth <= 0)
            return false;

        vector<vector<int>> best(n, vector<int>(m, -1));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, startHealth});
        best[0][0] = startHealth;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [row, col, curHealth] = q.front();
            q.pop();

            if (row == n - 1 && col == m - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int newr = row + dr[k];
                int newc = col + dc[k];

                if (newr < 0 || newr >= n || newc < 0 || newc >= m)
                    continue;

                int newHealth = curHealth - grid[newr][newc];

                if (newHealth <= 0)
                    continue;

                if (newHealth > best[newr][newc]) {
                    best[newr][newc] = newHealth;
                    q.push({newr, newc, newHealth});
                }
            }
        }

        return false;
    }
};