class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;

        if(words.empty())
            return {};

        int wordLen = words[0].size();
        int wordCount = words.size();
        int total = wordLen * wordCount;

        if(s.size() < total)
            return {};

        unordered_map<string, int> need;

        for(string word : words) {
            need[word]++;
        }

        for(int i = 0; i <= s.size() - total; i++) {

            unordered_map<string, int> current;

            for(int j = i; j < i + total; j += wordLen) {

                string part = s.substr(j, wordLen);

                current[part]++;
            }

            if(current == need) {
                result.push_back(i);
            }
        }

        return result;
    }
};