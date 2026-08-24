class Solution {
public:
    // bool apc( string &s,int idx, int cnt){
    //     if(cnt<0) return false;
    //     if(idx==s.length()) return(cnt==0);
    //     if(s[idx]=='('){
    //         return apc(s,idx+1,cnt+1);
    //     }else if(s[idx]==')'){
    //         return apc(s,idx+1,cnt-1);
    //     }else{          /////// * case
    //         return ((apc(s,idx+1,cnt))|| (apc(s,idx+1,cnt-1)) ||(apc(s,idx+1,cnt+1)));
    //     }
    // }
    bool checkValidString(string s) {
    //  return apc(s,0,0);               //// above recurrdive sol gives a TLE
        stack<int>openst; stack<int>asterisk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                openst.push(i);
            }else if(s[i]==')'){
                if(!openst.empty()){
                    openst.pop();
                }else if(!asterisk.empty()){
                    asterisk.pop();
                }else{
                    return false;
                }
            }else{
                asterisk.push(i);
            }
        }
        while((!openst.empty())&&(!asterisk.empty())){
            if(openst.top()>asterisk.top()) return false;
            openst.pop();
            asterisk.pop();
        }
        return (openst.empty());
    }
};