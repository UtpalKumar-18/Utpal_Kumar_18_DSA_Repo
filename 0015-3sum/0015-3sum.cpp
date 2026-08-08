 // class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>>st;
//         for(int i=0;i<nums.size();i++)
//         {   set<int> hashset;
//             for(int j=i+1;j<nums.size();j++)
//             {
//                int k = -(nums[i] + nums[j]);
//                if(hashset.find(k) != hashset.end())
//                {
//                 vector<int> v = {nums[i],nums[j],k};
//                 sort(v.begin(),v.end());
//                 st.insert(v);
//                }
//                hashset.insert(nums[j]);

           
//             }
//         }
//          vector<vector<int>> result(st.begin(),st.end());
//          return result;
//         }    
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
            for(int i =0;i<nums.size();i++){
                if(i>0 && nums[i] == nums[i-1]) continue;
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int sum= nums[j] + nums[k] + nums[i];
                    if(sum < 0){
                        j++;
                    }
                    else if(sum>0){
                        k--;
                    }
                    else{
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1]) j++;
                        while(j<k && nums[k]==nums[k+1]) k--;
                    }
                }

            }
            return ans;

        }    
};