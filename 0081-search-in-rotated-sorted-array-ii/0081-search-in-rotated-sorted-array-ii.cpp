// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();i++){
//             if(nums[i] == target) return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low =0,high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target) return true;

            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low = low+1;
                high = high-1;
                continue;
            }

            if(nums[mid] >=nums[low]){
                if(target>=nums[low] && target<=nums[mid])
                    high = mid -1;
                else
                    low = mid+1;

            }
            else{
                if(target>=nums[mid] && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return false;
    }
};