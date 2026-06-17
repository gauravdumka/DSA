class Solution {
public:
    string sortSentence(string s) {
        map<int,string>mpp;
        int i=0;
        while(i<s.length()){
             int j=i;
            while (j<s.length() && !(s[j]>='0' && s[j]<='9')){
                j++;
            }
            mpp[s[j]-'0']=s.substr(i,j-i);
            if(j+1<s.length()){
                i=j+2;  
            }
            else{
                i=j+1;
            }     
        }
        string ans;
        for(auto x : mpp){
            ans+=x.second;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};