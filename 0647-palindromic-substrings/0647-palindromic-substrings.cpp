// class Solution {
// public:
//     int cnt =0;
//     bool isPalindrome(string &s,int i,int j){
//         while(i<j){
//             if(s[i] != s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
            
        
//     }
//     int countSubstrings(string s) {
//         for(int i=0;i<s.size();i++){
//             for(int j=i;j<s.size();j++){
//                 if(isPalindrome(s,i,j)) cnt++;
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
     int expand(string &s,int left,int right){
            int cnt =0;
            while(left>=0 && right<s.size() && s[left] == s[right]){
            cnt++;
                left--;
                right++;
            }
            return cnt;
    }

    int countSubstrings(string s) {
        int ans =0;
          for(int i=0;i<s.size();i++){
               ans += expand(s,i,i);
               ans  += expand(s,i,i+1);
            
              }
              return ans;
          }
           
};