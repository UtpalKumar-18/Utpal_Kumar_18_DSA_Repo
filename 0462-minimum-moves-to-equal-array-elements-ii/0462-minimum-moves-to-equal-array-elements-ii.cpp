class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long mini = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int target = nums[i];
            long long cnt =0;
            for(int i =0;i<n;i++){
                cnt += abs(nums[i]-target);
            }
            mini = min(mini,cnt);
        }

        return mini;
    }
};