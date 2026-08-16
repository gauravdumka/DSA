class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0; int j=0; vector<vector<int>>res; int n= firstList.size(); int m=secondList.size();
        while(i<n && j<m){
            int st1=firstList[i][0] ; int end1= firstList[i][1];
            int st2= secondList[j][0] ; int end2= secondList[j][1];
            if(st1<= st2 && st2 <= end1){
                int s= max(st1,st2);
                int e= min(end1, end2);
                res.push_back({s,e});
            }
            else if(st2<= st1 && st1 <= end2){
                int s= max(st1,st2);
                int e= min(end1, end2);
                res.push_back({s,e});
            }
            if(end1<=end2){
                i++;
            }
            if(end2<=end1){
                
                j++;
            }
        }
        return res;
    }
   
};