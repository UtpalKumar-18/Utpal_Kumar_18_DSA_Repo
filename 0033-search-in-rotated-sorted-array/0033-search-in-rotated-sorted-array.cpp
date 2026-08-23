// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int start = 0, end = nums.size()-1, index = -1,mid=0;
//         while(start<=end)
//         {
//             mid = end + (start - end)/2;
//             if (nums[mid]==target)
//             return mid;

//             else if(nums[start]<nums[mid])
//             {
//                 if(nums[start]<=target && target<nums[mid])
//                 end = mid - 1;
//                 else
//                 start = mid + 1;
//             }
         
//             else
//             {
//                 if(nums[mid]<target && target<=nums[end])
//                 {
//                     start = mid+1;
//                 }
//                 else
//                 end = mid-1;
//             }
            
//         }
//         return index;
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0,high = nums.size()-1;
        while(low<=high){
             int mid = (low+high)/2;

             if(nums[mid] == target) return mid;

             if(nums[mid]>=nums[low]){
                if(target>=nums[low] && target<nums[mid])
                    high = mid-1;
                else
                    low = mid+1;

            }
            else{
                if(target>nums[mid] && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }

        }
        return -1;

    }
};