// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int low=0,high = nums.size() -1;
//         while(low<high){
//             int mid = low + (high-low)/2;
//             if(nums[mid]<nums[mid+1]) low = mid+1;
//             else high = mid;

//         }
//         return high;
//     }
// };

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]) return i;
        }
        return -1;
    }
};
