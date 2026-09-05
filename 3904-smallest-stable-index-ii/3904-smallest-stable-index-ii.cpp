class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix_max(n,0);
        prefix_max[0] = nums[0];
        vector<int> suffix_min(n,0);
        suffix_min[n-1] = nums[n-1];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=prefix_max[i-1]){
                prefix_max[i] = nums[i];
            }
            else{
                prefix_max[i] = prefix_max[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=suffix_min[i+1]){
                suffix_min[i] = nums[i];
            }
            else{
                suffix_min[i] = suffix_min[i+1];
            }
        }
        for(int i=0;i<nums.size();i++){
            int stable = prefix_max[i] - suffix_min[i];
            if(stable<=k) return i;

        }
        return -1;
    }
};