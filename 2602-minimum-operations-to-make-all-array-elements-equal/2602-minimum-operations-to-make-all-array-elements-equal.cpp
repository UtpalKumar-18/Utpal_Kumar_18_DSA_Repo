// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         int n = nums.size();
//         int m = queries.size();
//         vector<long long> ans;

//         for(int i=0;i<m;i++){
//             long long cnt  =0;
//             for(int j =0;j<n;j++){
//                 int num = nums[j];
//                 if(num > queries[i]){
//                     while(num > queries[i]){
//                         num--;
//                         cnt++;
//                     }
                    
//                 }
//                 else{
//                     while(num < queries[i]){
//                         num++;
//                         cnt++;
//                     }
//                 }
                
//             }
//             ans.push_back(cnt);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         int n = nums.size();
//         int m = queries.size();
//         vector<long long> ans;

//         for(int i=0;i<m;i++){
//             long long cnt  =0;
//             for(int j =0;j<n;j++){ 
//                cnt += abs(nums[j]-queries[i]);      
//         }
//         ans.push_back(cnt);
//         }
//         return ans;
        
//     }
// };

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        long long num_of_operations = 0;

        vector<long long> ans;

        sort(nums.begin(),nums.end());

        vector<long long> prefix(n+1,0);
        
        for(int i =0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        for(int q : queries){
        int ind = (lower_bound(nums.begin(),nums.end(),q) - nums.begin());

        long long left = 1LL*q*ind - prefix[ind];

        long long right = (prefix[n] - prefix[ind]) - 1LL*q*(n-ind);

        num_of_operations = (left + right);

        ans.push_back(num_of_operations);


        }

        return ans;

        
        
    }
};