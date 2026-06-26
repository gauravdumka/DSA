class Solution {
public:
//writing function to count days required
        int countdays(int capacity,vector<int>weights){
            int daystaken=1; int load=0;
            for(int i=0;i<weights.size();i++){
                if((load+weights[i])>capacity){
                    daystaken+=1;
                    load=weights[i];
                }else{
                    load+=weights[i];
                }
            }
            return daystaken;
        }
    int shipWithinDays(vector<int>& weights, int days) {
        //find elements for giving range
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }
        int low=maxi; int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int daystaken=countdays(mid,weights);
            if(daystaken<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return low;
    }
};