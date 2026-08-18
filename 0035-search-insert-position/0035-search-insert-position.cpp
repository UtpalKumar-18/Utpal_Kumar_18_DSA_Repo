class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0,end = nums.size()-1,mid=0,index=0;
        while (start<=end)
        {
            mid = end + (start - end)/2;
            if (nums[mid]==target)
            return mid;

            else if(nums[mid]<target)
            {
                index=mid+1;
                start = mid+1;
            }
            else
            {
                index = mid;
                end = mid-1;
            }
        }
        return index;
    }
};