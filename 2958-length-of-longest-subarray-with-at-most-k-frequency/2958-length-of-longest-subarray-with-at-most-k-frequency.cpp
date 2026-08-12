// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//             // unordered_map<int,int> mp;
//             // for(int i=0;i<nums.size();i++){
//             //         mp[nums[i]]++;
//             // }
//             int maxi = INT_MIN;
//             for(int i=0;i<nums.size();i++){
//                 unordered_map<int,int> mp;
//                 int cnt =0;
//                 for(int j = i;j<nums.size();j++){
//                     if(mp[nums[j]]>=k) break;
//                     mp[nums[j]]++;
//                     cnt++;
//                     maxi= max(maxi,cnt);
//                 }
//             }
//             return maxi;
//     }   
// };

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

            unordered_map<int,int> fre;
            
            int l = 0;
            int cnt =0;
            for(int r =0;r<nums.size();r++){
                    fre[nums[r]]++;
                    while(fre[nums[r]] > k){
                        fre[nums[l]]--;
                        l++;
                        
                    }
                    cnt = max(cnt,r-l+1);


            }
            return cnt;
    }   
};