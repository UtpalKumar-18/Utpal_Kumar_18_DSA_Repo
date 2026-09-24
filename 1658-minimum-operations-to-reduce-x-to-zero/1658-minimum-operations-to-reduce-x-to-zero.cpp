class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l =0,r=0;
        int n = nums.size();
        long long sum =0;
        for(int i=0;i<n;i++){
            sum += nums[i];

        }
        int target = sum - x;

        if(target <0) return -1;
        
        sum =0;
        int min_len = INT_MAX;
        while(r<n){
            sum += nums[r];

            while(sum > target){
                sum -=nums[l];
                l++;
            }                             
            if(sum == target){
               min_len = min(min_len,(n-(r-l+1))); 
            }
            r++;
        }

        return min_len==INT_MAX?-1: min_len;

    }
};