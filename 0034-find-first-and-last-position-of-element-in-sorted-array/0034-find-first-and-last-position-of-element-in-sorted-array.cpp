// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//             int first = -1,last =-1;
//             for(int i=0;i<nums.size();i++){
//                     if(nums[i] == target){
//                         if(first == -1) first = i;
//                         last =i;
//                     }
//             }
//         vector<int> v;
//         v.push_back(first);
//         v.push_back(last);
//         return v;
//     }
// };

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//            int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
//            int ub = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
//            vector<int> v;
//            if(lb == nums.size() || nums[lb] !=target){
//             lb =-1;
//             ub =-1;
//             // v.push_back(-1);
//             // v.push_back(-1);
//             // return v;
//             return {-1,-1};

//            }
//             // v.push_back(lb);
//             // v.push_back(ub-1);
//             // return v;
//             return {lb,ub-1};
                
//     }
// };

class Solution {
public:
    int findfirst(vector<int> &nums,int n,int target){
        int first =  -1;
        int low=0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid-1;

            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;

        }
        return first;
    }

      int findlast(vector<int> &nums,int n,int target){
        int last =  -1;
        int low=0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                last = mid;
               low =mid+1;

            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;

        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = findfirst(nums,n,target);
        int last = findlast(nums,n,target);
        return {first,last};
                
    }
};