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

        
        vector<int> hash1(26, 0);

        int n = s.length();
        int m = p.length();

        if (m > n) return {};

        // Frequency of p
        for (int i = 0; i < m; i++) {
            hash1[p[i] - 'a']++;
        }

        // First window
        vector<int> hash2(26, 0);

        int i = 0;
        int j;

        for (j = 0; j < m; j++) {
            hash2[s[j] - 'a']++;
        }

        vector<int> result;

        // Check and slide
        while (j < n) {

            int cnt = 0;

            for (int k = 0; k < 26; k++) {
                if (hash1[k] == hash2[k]) {
                    cnt++;
                }
            }

            if (cnt == 26) {
                result.push_back(i);
            }

            // Slide window
            hash2[s[i] - 'a']--;
            i++;

            hash2[s[j] - 'a']++;
            j++;
        }

        // Check the LAST window
        int cnt = 0;

        for (int k = 0; k < 26; k++) {
            if (hash1[k] == hash2[k]) {
                cnt++;
            }
        }

        if (cnt == 26) {
            result.push_back(i);
        }

        return result;
    }
};