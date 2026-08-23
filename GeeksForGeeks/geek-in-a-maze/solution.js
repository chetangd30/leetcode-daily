class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d,
                      vector<vector<char>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#')
            return 0;

        const int INF = 1e9;

        // dist[i][j] = minimum number of upward moves
        // required to reach (i, j).
        vector<vector<int>> dist(n, vector<int>(m, INF));

        deque<pair<int, int>> dq;

        dist[r][c] = 0;
        dq.push_front({r, c});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (mat[nx][ny] == '#')
                    continue;

                // Moving up costs 1.
                // Down/left/right cost 0.
                int cost = (nx < x) ? 1 : 0;

                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 1)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '#' || dist[i][j] == INF)
                    continue;

                int upMoves = dist[i][j];

                // From:
                // upMoves - downMoves = r - i
                //
                // therefore:
                // downMoves = upMoves + i - r
                int downMoves = upMoves + i - r;

                if (upMoves <= u && downMoves <= d)
                    ans++;
            }
        }

        return ans;
    }
};