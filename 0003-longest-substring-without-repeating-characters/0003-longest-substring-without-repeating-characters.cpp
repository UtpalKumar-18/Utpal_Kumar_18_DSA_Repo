// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//             int max_len = INT_MIN;
//             if(s.length()==0) return 0;
//             for(int i=0;i<s.length();i++){
//               int  hash_map[256] ={0};
//                 for(int j=i;j<s.length();j++){
//                     if(hash_map[s[j]] == 1) break;
//                     int len = j-i+1;
//                     max_len = max(max_len,len);
//                     hash_map[s[j]]=1;
//                 }
//             }
//             return max_len;
//     }
// };

class Solution {
public:
    // int hash_map[256];
    // for(int i=0;i<256;i++){
    //     hash_map[i] =-1;
    // }

    int lengthOfLongestSubstring(string s) {
            int hash_map[256];
             for(int i=0;i<256;i++){
            hash_map[i] =-1;
        }
            int l=0,r=0;
            int max_len = 0;
            while(r < s.length()){  
                if(hash_map[s[r]]!=-1){
                    if(hash_map[s[r]]>=l){
                        l = hash_map[s[r]]+1;
                    }
                }
                int len = r-l+1;
                max_len = max(max_len,len);                  
                hash_map[s[r]] = r; 
                r++;       

            }
            return max_len;

    }
};