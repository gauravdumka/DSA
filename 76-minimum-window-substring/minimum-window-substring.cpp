class Solution {
public:
    string minWindow(string s, string t) {
        int low = 0;
        int high = 0;

        vector<int> hash(256, 0);
        vector<int> hash1(256, 0);

        int n = s.length();
        int idx = -1;
        int len = INT_MAX;

        for(int i = 0; i < t.length(); i++) {
            hash1[t[i]]++;
        }

        int count = 0;

        while(high < n) {

            hash[s[high]]++;

            if(hash1[s[high]] > 0 &&
               hash[s[high]] <= hash1[s[high]]) {
                count++;
            }

            while(count == t.length()) {

                if(high - low + 1 < len) {
                    len = high - low + 1;
                    idx = low;
                }

                if(hash1[s[low]] > 0 &&
                   hash[s[low]] <= hash1[s[low]]) {
                    count--;
                }

                hash[s[low]]--;
                low++;
            }

            high++;
        }

        if(idx == -1)
            return "";

        return s.substr(idx, len);
    }
};