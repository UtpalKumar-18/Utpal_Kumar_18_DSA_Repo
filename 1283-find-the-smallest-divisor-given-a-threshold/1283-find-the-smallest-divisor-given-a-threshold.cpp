// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//          int maxi = INT_MIN;
//          for(int i=0;i<nums.size();i++){
//             maxi = max(maxi,nums[i]);
//          }

//          for(int d=1;d<=maxi;d++){
//             int sum =0;
//             for(int i=0;i<nums.size();i++){
//                 sum += ceil((double)nums[i]/d);
//             }
//             if(sum <= threshold) return d;
//          }

//          return -1;
//     }
// };

class Solution {
public:
    bool check(vector<int>& nums,int d,int threshold){
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i]/d);
        }
        if(sum<=threshold) return true;

        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
          int maxi = INT_MIN;
         for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
         }

         int low =1,high = maxi;
         while(low<=high){
            int mid = (low+high)/2;

            bool flag = check(nums,mid,threshold);
            if(flag){
                high = mid -1;

            }
            else{
                low = mid+1;
            }

         }
         return low;

    }
};