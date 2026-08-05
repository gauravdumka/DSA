class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // sort(p.begin(),p.end()); vector<int>result;
        // int n=s.length();
        // int m=p.length();
        // for(int i=0; i<=n-m;i++){
        //     string substring=s.substr(i,m);
        //     sort(substring.begin(),substring.end());
        //     if(substring==p){
        //         result.push_back(i);
        //     }

        // }
        // return result;

          //// above approach was TLE now the optimal one

        
        int n = s.length();
        int m = p.length();

        if (m > n) return {};

        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        // Frequency of p
        for (int i = 0; i < m; i++) {
            hash1[p[i] - 'a']++;
        }

        // First window
        for (int i = 0; i < m; i++) {
            hash2[s[i] - 'a']++;
        }

        vector<int> result;

        int i = 0;

        while (i <= n - m) {

            int cnt = 0;

            // Compare hash arrays
            for (int k = 0; k < 26; k++) {
                if (hash1[k] == hash2[k]) {
                    cnt++;
                }
            }

            if (cnt == 26) {
                result.push_back(i);
            }

            // Move window
            if (i + m < n) {
                hash2[s[i] - 'a']--;
                hash2[s[i + m] - 'a']++;
            }

            i++;
        }

        return result;
    }
};