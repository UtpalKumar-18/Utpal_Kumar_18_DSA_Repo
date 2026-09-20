// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt =0;
//         for(int i=0;i<s.size();i++){
//             set<char> st;
//             for(int j=i;j<n;j++){
//                 st.insert(s[j]);
//                 if(st.size() >=3) cnt++;
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt =0;
//         for(int i=0;i<s.size();i++){
//             set<char> st;
//             for(int j=i;j<n;j++){
//                 st.insert(s[j]);
//                 if(st.size() == 3){
//                     cnt = cnt + (n-j);
//                     break;
//                 } 
//             }
//         }
//         return cnt;
//     }
// };


// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt = 0;
//         for(int i=0;i<s.size();i++){
//             int hash[3] = {0};
//             for(int j=i;j<n;j++){
//                 hash[s[j]-'a'] = 1;
//                 if((hash[0] + hash[1] + hash[2]) == 3){
//                     cnt = cnt + (n-j);
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt =0;
//         int lastseen[3] = {-1,-1,-1};
//         for(int i=0;i<n;i++){
//             lastseen[s[i]-'a'] = i;
//             if(lastseen[0]!= -1 && lastseen[1] != -1 && lastseen[2] != -1){
//                 cnt = cnt + (1 + min(lastseen[0],min(lastseen[1],lastseen[2])));
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt =0;
        int lastseen[3] = {-1,-1,-1};
        for(int i=n-1;i>=0;i--){
            lastseen[s[i]-'a'] = i;
            if(lastseen[0]!= -1 && lastseen[1] != -1 && lastseen[2] != -1){
                cnt = cnt + (n- max(lastseen[0],max(lastseen[1],lastseen[2])));
            }
        }
        return cnt;
    }
};