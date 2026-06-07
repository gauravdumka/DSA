class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k = k%n;
        if( k==0) return;
        int temp[k];
        // storing k elements in temp variable
        for(int i=n-k; i<=n-1; i++){
            temp[i-(n-k)]=nums[i];
        }
        //shifting remaining elements of array backwards by k places
        for(int j=(n-1-k); j>=0; j--){
            nums[j+k]=nums[j];
        }
        //putting temp back to array
        for(int a=0;a<=k-1;a++){
            nums[a]=temp[a];
        }

    }
};