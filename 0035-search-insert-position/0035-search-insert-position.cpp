// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int start=0,end = nums.size()-1,mid=0,index=0;
//         while (start<=end)
//         {
//             mid = end + (start - end)/2;
//             if (nums[mid]==target)
//             return mid;

//             else if(nums[mid]<target)
//             {
//                 index=mid+1;
//                 start = mid+1;
//             }
//             else
//             {
//                 index = mid;
//                 end = mid-1;
//             }
//         }
//         return index;
//     }
// };


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high = nums.size()-1;
        int ind = nums.size();
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] >= target){
             ind = mid;
             high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return ind;
    }
};