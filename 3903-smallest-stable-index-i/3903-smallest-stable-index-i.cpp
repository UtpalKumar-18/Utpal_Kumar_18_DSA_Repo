class Solution {
public:
    int calmax(vector<int> &nums,int index){
        int maxi = INT_MIN;
        for(int i=0;i<=index;i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }

    int calmin(vector<int> &nums,int index){
        int mini = INT_MAX;
        int n = nums.size();
        for(int i=index;i<=n-1;i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int maxi = calmax(nums,i);
            int mini = calmin(nums,i);
            int stable = maxi - mini;
            if(stable<=k) return i;

        }
        return -1;

    }
};