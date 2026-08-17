class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {

        int total = n * n;

        // jump[x] = destination of snake/ladder from x
        // -1 means there is no snake/ladder
        vector<int> jump(total + 1, -1);

        for (int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        // BFS
        vector<int> dist(total + 1, -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            if (current == total)
                return dist[current];

            // Try dice values 1 to 6
            for (int dice = 1; dice <= 6; dice++) {

                int next = current + dice;

                if (next > total)
                    continue;

                // Take snake or ladder immediately
                if (jump[next] != -1)
                    next = jump[next];

                // Visit each cell only once
                if (dist[next] == -1) {
                    dist[next] = dist[current] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};