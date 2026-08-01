class Solution {
public:
    vector<int> calculateLPS(string pat) {
        int M = pat.length();
        vector<int> LPS(M, 0);

        int len = 0;
        int i = 1;

        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        return LPS;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;

        int N = haystack.length();
        int M = needle.length();

        vector<int> LPS = calculateLPS(needle);

        int i = 0;
        int j = 0;

        while (i < N) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == M) {
                return i - M;
            } else if (i < N && haystack[i] != needle[j]) {
                if (j != 0)
                    j = LPS[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};