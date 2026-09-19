// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//        int n = nums.size();
//        int cnt =0;
        
//        for(int i=0;i<n;i++){
//             int cnt_odds =0;
//             for(int j=i;j<n;j++){
//                 if((nums[j] %2) !=0){
//                     cnt_odds++;
//                 }
//                 if(cnt_odds == k){
//                     cnt++;
//                 }
//             }
//        } 
//        return cnt;
//     }
// };

// class Solution {
// public:
//     int countNumberofNiceSubarrays(vector<int> &nums, int k){
//         if(k<0) return 0;
//          int n = nums.size();
        
//        int l=0,r=0;
//        int cnt_odds = 0;
//        int cnt_sub =0;

//        while(r<n){
//             if(nums[r]%2 != 0){
//                 cnt_odds++;
//             }
//             while(cnt_odds > k){
//                 if(nums[l]%2 != 0) cnt_odds--;
//                 l++;
//             }
//             if(cnt_odds <= k) cnt_sub += r-l+1;
//             r++;
//        }
//        return cnt_sub;
//     }

//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int cnt_sub1 = countNumberofNiceSubarrays(nums,k);
//         int cnt_sub2 = countNumberofNiceSubarrays(nums,k-1);
//         return cnt_sub1 - cnt_sub2;
//     }
// };


class Solution {
public:
    int countNumberofNiceSubarrays(vector<int> &nums, int k){
        if(k<0) return 0;
         int n = nums.size();
        
       int l=0,r=0;
       int sum = 0;
       int cnt_sub =0;

       while(r<n){

            sum += nums[r]%2;
            while(sum > k){
                sum -= nums[l]%2;
                l++;
            }
            if(sum <= k) cnt_sub += r-l+1;
            r++;
       }
       return cnt_sub;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt_sub1 = countNumberofNiceSubarrays(nums,k);
        int cnt_sub2 = countNumberofNiceSubarrays(nums,k-1);
        return cnt_sub1 - cnt_sub2;
    }
};