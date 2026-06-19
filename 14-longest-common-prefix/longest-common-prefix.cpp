class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string ans="";
        sort(strs.begin(),strs.end());
        int j=strs.size()-1;
        int i=0;
        while( i< strs[0].size()  && i<strs[j].size() && strs[0][i]==strs[j][i] ){
            ans.push_back(strs[0][i]);
            i++;
        }
        return ans;
    }
};