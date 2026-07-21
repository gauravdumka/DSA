class Solution {
public:
    vector<int>nse_find(vector<int>&arr){
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
    vector<int>nge_find(vector<int>&arr){
        int n=arr.size();
        stack<int>st; vector<int>nse(n);
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
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
    vector<int>psee_find(vector<int>&arr){
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
    vector<int>pgee_find(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>psee(n);
        for(int i =0; i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
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
    long long subArrayRanges(vector<int>& nums) {
        long long smaller=0; int mod=(1e9)+7;
        vector<int>nse=nse_find(nums);
        vector<int>psee=psee_find(nums);
        for(int i=0;i<nums.size();i++){
            int left=i-psee[i];
            int right= nse[i]-i;
            smaller = (smaller + (1LL * left * right * nums[i]));

        }

        long long greater=0;
        vector<int>nge=nge_find(nums);
        vector<int>pgee=pgee_find(nums);
        for(int i=0;i<nums.size();i++){
            int left=i-pgee[i];
            int right= nge[i]-i;
            greater = (greater + (1LL * left * right * nums[i]));

        }
        return(greater-smaller);
    }
};