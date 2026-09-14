// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int left =0;
//         int n = nums.size();
//         int zerocnt =0;
//         for(int right=0;right<n;right++){
//             if(nums[right] == 0){
//                 zerocnt++;
//             }
//             if(zerocnt > k){
//                 if(nums[left] == 0) zerocnt--;
//                 left++;
//             }
        
//         }
//          return n - left;
        
//     }
        
// };

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int max_ans = INT_MIN;
//         int cnt =0; 
//        for(int i=0;i<nums.size();i++){
//            int c1 = k;
//             cnt =0;
//         for(int j=i;j<nums.size();j++){
//             if(nums[j] == 1){
//                 cnt++;
//             }
//             else if(nums[j] == 0 && c1>0){
//                 cnt++;
//                 c1--;
//             }
//             else if(nums[j]==0 && c1<=0) break;
//         }
//         max_ans = max(max_ans,cnt);
//        }
//        return max_ans;
//     }
// };

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int left =0;
//         int n = nums.size();
//         int max_len = 0;
//         int zero_cnt =0;

//         for(int right =0;right<n;right++){
//             if(nums[right] == 0){
//                 zero_cnt++;
//             }
//             while(zero_cnt > k){
//                 if(nums[left] == 0) zero_cnt--;
//                 left++;
//             }
//             max_len  = max(max_len,right-left+1);
//         }
//         return max_len;
        
//     }
        
// };


// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int left =0;
//         int n = nums.size();
//         int max_len = 0;
//         for(int i=0;i<n;i++){
//             int zero_cnt =0;
//             for(int j=i;j<n;j++){
//                 if(nums[j] == 0){
//                     zero_cnt++;
//                 }

//                 if(zero_cnt > k) break;
//                 int len = (j-i) +1;
//                 max_len = max(max_len,len); 
//             }
//         }
//     return max_len;
        
        
//     }
        
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0,right =0;
        int n = nums.size();
        int max_len = 0;
        int zero_cnt =0;
        while(right < n)
        {
            if(nums[right] == 0) zero_cnt++;

            if(zero_cnt > k){
               if(nums[left] == 0) zero_cnt--;
               left++;
            }

            if(zero_cnt <=k){
                int len = right -left +1;
                max_len = max(max_len,len);
            }

            right++;
            
        }

        return max_len;
           
    }
        
};