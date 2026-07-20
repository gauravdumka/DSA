class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            int current=asteroids[i];
            bool alive=true;
            while(!st.empty() && (current<0 && st.top()>0)){
                if(abs(current)==abs(st.top())){
                    st.pop();
                    alive=false;
                    break;
                }
                if(abs(st.top())>abs(current)){
                    alive=false;
                    break;
                }else{
                    st.pop();
                }
            }
            if(alive){
                st.push(current);
            }
        }
        vector<int> ans(st.size());

        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};