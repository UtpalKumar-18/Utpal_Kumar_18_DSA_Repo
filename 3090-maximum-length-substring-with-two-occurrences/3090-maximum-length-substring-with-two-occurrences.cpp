class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left =0;
        int length =0;
        unordered_map<int,int> fre;
        for(int right =0;right<s.length();right++){
                fre[s[right]]++;
                while(fre[s[right]]>2){
                    fre[s[left]]--;
                    left++;
                }
                length =  max(length,right-left+1);
        }
        return length;
    }
};