class Solution {
public:
    int cnt =0;
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
            
        
    }
    int countSubstrings(string s) {
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(s,i,j)) cnt++;
            }
        }
        return cnt;
    }
};