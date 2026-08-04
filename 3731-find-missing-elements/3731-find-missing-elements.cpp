// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;

//         }
//         vector<int> ans;
//         sort(nums.begin(),nums.end());
//         int first = nums[0];
//         int last = nums[nums.size()-1];
//         for(int i=first;i<last;i++){
//             if(mp.find(i) == mp.end()) ans.push_back(i);
//         }

//     return ans;
//     }
// };

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;

        }
        int maxi=INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi) maxi = nums[i];   
            if(nums[i]<mini) mini = nums[i]; 
        }
        vector<int> ans;
        for(int i=mini;i<maxi;i++){
            if(mp.find(i) == mp.end()) ans.push_back(i);
        }

    return ans;
    }
};