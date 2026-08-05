class Solution {
public:
    int maxi = INT_MIN;
    bool checkPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])
                 return false;
            i++;
            j--;
         }
         return true;
    }
    string longestPalindrome(string s) {
            string s1 ="";
            for(int i=0;i<s.size();i++){
                for(int j=i;j<s.size();j++){
                   bool res = checkPalindrome(s,i,j);
                    if(res == true){
                        if((j-i)+1>maxi){
                            maxi = (j-i)+1;
                            s1 = s.substr(i,(j-i)+1);
                        }
                    }
                }
            }
            return s1;
    }
};