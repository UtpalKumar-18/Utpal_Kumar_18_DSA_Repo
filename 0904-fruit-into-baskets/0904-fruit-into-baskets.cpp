// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int ans=0;
//         for(int left =0;left<fruits.size();left++){
//             unordered_map<int,int> mp;
//             int cnt =0;
//             for(int right=left;right<fruits.size();right++){
//                 mp[fruits[right]]++;
//                 if(mp.size()>2) break;
//                 cnt++;
//             }
//             ans = max(ans,cnt);
//         }
//         return ans;  
//     }
// };

// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int ans=0;
//         for(int left =0;left<fruits.size();left++){
//             set<int> st;
//             int cnt =0;
//             for(int right=left;right<fruits.size();right++){
//                 st.insert(fruits[right]);
//                 if(st.size()>2) break;
//                 cnt++;
//             }
//             ans = max(ans,cnt);
//         }
//         return ans;  
//     }
// };

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int left =0;
       int ans=0;
       unordered_map<int,int> mp;
       for(int right=0;right<fruits.size();right++){
            mp[fruits[right]]++;
            if(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }
            ans = max(ans,right-left+1);
       }
       return ans;
    }
};