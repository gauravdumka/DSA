class Solution {
public:
    vector<int>nse_find(vector<int>arr){
        int n=arr.size();
        stack<int>st; vector<int>nse(n);
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int>psee_find(vector<int>arr){
        int n=arr.size();
        stack<int>st;
        vector<int>psee(n);
        for(int i =0; i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                psee[i]=-1;
            }else{
                psee[i]=st.top();
            }
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int total=0; int mod=(1e9)+7;
        vector<int>nse=nse_find(arr);
        vector<int>psee=psee_find(arr);
        for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right= nse[i]-i;
            total = (total + (1LL * left * right * arr[i]) % mod) % mod;

        }
        return total;
    }
};