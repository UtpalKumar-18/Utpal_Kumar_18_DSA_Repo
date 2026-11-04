// class Solution {
// public:
//     bool check_equals(vector<int> &nums){
//         int n = nums.size();
//         for(int i=0;i<n-1;i++){
//             if(nums[i] != nums[i+1]) return true;
//         }
//         return false;
//     }
//     int cal_max(vector<int> &nums){
//         int maxi = INT_MIN;
//         int max_ind = -1;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i] > maxi){
//                 maxi = nums[i];
//                 max_ind = i;
//             }
//         }
//         return max_ind;
//     }
//     int minMoves(vector<int>& nums) {
//     int cnt = 0;
//     while(check_equals(nums)){
//         int max_ind = cal_max(nums);
//         for(int i=0;i<nums.size();i++){
//             if(i != max_ind){
//                 nums[i]++;
//             }
//         }
//         cnt++;

//     }

//     return cnt;


//     }
// };

class Solution {
public:
    int minMoves(vector<int>& nums) {
    int cnt = 0;
    int mini = INT_MAX;

    for(int i=0;i<nums.size();i++){
        mini = min(mini,nums[i]);
    }

    for(int i=0;i<nums.size();i++){
        cnt += nums[i]- mini;
    }

    return cnt;


    }
};