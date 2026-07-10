class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
    vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        vector<int> sortedNums(n);
        for (int i = 0; i < n; i++) {
            sortedNums[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        // Component ids
        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (sortedNums[i] - sortedNums[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        // jump[0]
        vector<int> reach(n);
        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r + 1 < n && sortedNums[r + 1] - sortedNums[l] <= maxDiff)
                r++;
            reach[l] = r;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = reach[i];

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u > v) swap(u, v);

            int cur = u;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += 1 << k;
                }
            }

            ans.push_back(steps + (u == v ? 0 : 1));
        }

        return ans;
    }
};