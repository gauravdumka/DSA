class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> cnt(n + 1, 0);
        vector<int> digitSum(n + 1, 0);
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            digitSum[i + 1] = digitSum[i];
            pref[i + 1] = pref[i];

            int d = s[i] - '0';
            if (d != 0) {
                cnt[i + 1]++;
                digitSum[i + 1] += d;
                pref[i + 1] = (pref[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int k = cnt[r + 1] - cnt[l];
            int sm = digitSum[r + 1] - digitSum[l];

            long long val = (pref[r + 1] - (pref[l] * pow10[k]) % MOD + MOD) % MOD;

            ans.push_back((val * sm) % MOD);
        }

        return ans;
    }
};