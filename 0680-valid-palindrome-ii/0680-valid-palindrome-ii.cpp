// class Solution {
// public:
//     bool checkPalindrome(string &s,int i,int j){
//          while(i<j){
//             if(s[i]!=s[j]) return false;
//             i++;
//             j--;
//          }
//          return true;
//     }
//     bool validPalindrome(string s) {
            
//             bool result = checkPalindrome(s,0,s.size()-1); 
//             if(result == true) return result;
//             int n = s.size();
//             for(int i=0;i<=n-1;i++){
//             string s1 = s;
//              s1.erase(s1.begin()+i);
//             result =   checkPalindrome(s1,0,s1.size()-1);
//             if(result == true) return result;
//             }
//              return false;
//     }


// };

class Solution {
public:
    bool checkPalindrome(string &s,int i,int j){
         while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
         }
         return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else{
                return checkPalindrome(s,i+1,j)|| checkPalindrome(s,i,j-1);
            }

       
    }
    return true;
    }

};