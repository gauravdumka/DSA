class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int counter=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='(' && counter != 0){
                ans+=s[i];
                counter++;
            }else if(s[i]==')'&& counter!=0){
                counter--;
                if(counter!=0){
                    ans+=s[i];
                }
            }else{
                counter++;
            }
            i++;

        } 
        return ans;
    }
};