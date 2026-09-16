// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         int max_freq =0,max_len = 0;

//         for(int i=0;i<n;i++){
//            int hash[26] = {0};
//             for(int j=i;j<n;j++){
//                 hash[s[j] - 'A']++;
//                 max_freq = max(max_freq,hash[s[j] - 'A']);
//                 int changes = (j-i+1) - max_freq;
//                 if(changes <= k){
//                     max_len = max(max_len,j-i+1);
//                 }
//                 else break;

//             }   
//         }
//         return max_len;
//     }
// };

// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         int l =0,r = 0;
//         int hash[26] = {0};
//         int max_len = 0,max_freq = 0;

//         while(r < n){
//             hash[s[r] - 'A']++;
//             max_freq = max(max_freq,hash[s[r]-'A']);
            
//             while((r-l+1) - max_freq > k){
//                 hash[s[l]-'A']--;
//                 max_freq =0;
//                 for(int i =0;i<26;i++){
//                     max_freq = max(max_freq,hash[i]);
//                 }
//                 l++;
//             }
//             max_len = max(max_len,r-l+1);
//             r++;
//         }
//         return max_len;
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l =0,r = 0;
        int hash[26] = {0};
        int max_len = 0,max_freq = 0;

        while(r < n){
            hash[s[r] - 'A']++;
            max_freq = max(max_freq,hash[s[r]-'A']);
            
            if((r-l+1) - max_freq > k){
                hash[s[l]-'A']--;
                l++;
            }
            max_len = max(max_len,r-l+1);
            r++;
        }
        return max_len;
    }
};