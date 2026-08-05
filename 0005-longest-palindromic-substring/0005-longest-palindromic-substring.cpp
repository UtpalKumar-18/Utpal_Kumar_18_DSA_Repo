// class Solution {
// public:
//     int maxi = INT_MIN;
//     bool checkPalindrome(string &s,int i,int j){
//         while(i<j){
//             if(s[i]!=s[j])
//                  return false;
//             i++;
//             j--;
//          }
//          return true;
//     }
//     string longestPalindrome(string s) {
//             string s1 ="";
//             for(int i=0;i<s.size();i++){
//                 for(int j=i;j<s.size();j++){
//                    bool res = checkPalindrome(s,i,j);
//                     if(res == true){
//                         if((j-i)+1>maxi){
//                             maxi = (j-i)+1;
//                             s1 = s.substr(i,(j-i)+1);
//                         }
//                     }
//                 }
//             }
//             return s1;
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        int start =0,end =0;
          for(int i=0;i<s.size();i++){
              int even_len_palind = expand(s,i,i);
              int odd_len_palind = expand(s,i,i+1);
              int len = max(even_len_palind,odd_len_palind);
              if(len>(end - start)+1){
                start = i - (len-1)/2;
                end = i + (len)/2;
              }
          }
           return s.substr(start,(end-start)+1);
    }

    int expand(string &s,int left,int right){
            while(left>=0 && right<s.size() && s[left] == s[right]){
                left--;
                right++;
            }
            return right-left-1;
    }
};