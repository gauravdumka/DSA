class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(),intervals.end()); vector<vector<int>>res;
        int m=intervals[0].size(); int n=intervals.size();
        int st1=intervals[0][0];  
        int end1=intervals[0][m-1]; 
        for(int i=1; i<n; i++){
            int st2=intervals[i][0];
            int end2= intervals[i][m-1];
            if(end1>=st2){
                st1=st1;
                end1 =max(end1,end2);
                continue;
            }
            
            res.push_back({st1, end1});
            st1=st2;
            end1=end2;
            
            
        }
        res.push_back({st1, end1});

        return res;
    }
};