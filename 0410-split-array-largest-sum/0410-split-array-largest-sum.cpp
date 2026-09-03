class Solution {
public:
    bool allocation(vector<int> &nums,int max_sum,int k){
        int num_of_sub = 1; int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]> max_sum) return false;

            if(sum + nums[i] > max_sum){
                num_of_sub++;
                sum = nums[i];
            }
            else{
                sum+=nums[i];
            }

        }
        if(num_of_sub > k) return false;
        else return true;

    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum =0,maxi = INT_MIN; 
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxi = max(maxi,nums[i]);
        }
        int low = maxi,high = sum;
        int ans =-1;  

        while(low<=high){
            int mid = (low+high)/2;
            if(allocation(nums,mid,k)){
                ans = mid;
                high = mid-1;

            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};