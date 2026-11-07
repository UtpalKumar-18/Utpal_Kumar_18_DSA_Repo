// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         long long mini = INT_MAX;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int target = nums[i];
//             long long cnt =0;
//             for(int i =0;i<n;i++){
//                 cnt += abs(nums[i]-target);
//             }
//             mini = min(mini,cnt);
//         }

//         return mini;
//     }
// };


// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         int n = nums.size();
//         int moves =0;
//         sort(nums.begin(),nums.end());
//         int middle = nums[n/2];
//         for(int i =0;i<n;i++){
//             moves += abs(nums[i]-middle);
//         }

//         return moves;
//     }
// };


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int moves =0;
        sort(nums.begin(),nums.end());
        int middle = nums[n/2];
        for(int i =0;i<n/2;i++){
            moves += abs(nums[i]-middle);
            moves += abs(nums[n-1-i]-middle);
        }

        return moves;
    }
};