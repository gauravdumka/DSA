class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0]; int onedelete=0; int result=arr[0];
        for(int i=1;i<arr.size();i++){
            int prev_no_del=nodelete;
            int prev_del=onedelete;
            nodelete=max(arr[i],prev_no_del+arr[i]);
            onedelete=max(prev_del+arr[i],prev_no_del);
            result=max(result,max(onedelete,nodelete));
        }
        return result;
    }
};