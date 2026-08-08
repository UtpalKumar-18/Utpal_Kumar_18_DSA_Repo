// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         multiset<int>ms;
//         for(int i=0;i<nums.size();i++)
//         {
//             ms.insert(nums[i]);
//         }
//         int index=0;
//         for(auto it : ms)
//         {
//             nums[index]=it;
//             index++;
//         }
//     }      
// };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int  n = nums.size();
        int low =0, mid =0, high = n-1;
        while(mid<=high){
            if(nums[mid] == 0){
                nums[mid] = nums[low];
                nums[low] =0;
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                nums[mid] = nums[high];
                nums[high] = 2;
                high--;
            }
        }

    }      
};