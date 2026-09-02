// class Solution {
// public:
//     bool canWePlace(vector<int>& position,int dist,int m){
//         int cntBalls =1,last_basket= position[0];
//         for(int i=1;i<position.size();i++){
//             if(position[i]-last_basket >= dist){
//                 cntBalls++;
//                 last_basket = position[i];
//             }
//             if(cntBalls >= m) return true;
//         }
//         return false;
//     }
//     int maxDistance(vector<int>& position, int m) {
//         sort(position.begin(),position.end());
//         int n = position.size();
//         int max_dis = position[n-1] - position[0];
//         for(int i=1;i<max_dis;i++){
//              if(canWePlace(position,i,m)){
//                     continue;
//              }
//              else{
//                     return i-1;
//              }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    bool canWePlace(vector<int>& position,int dist,int m){
        int cntBalls =1,last_basket= position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last_basket >= dist){
                cntBalls++;
                last_basket = position[i];
            }
            if(cntBalls >= m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int max_dis = position[n-1] - position[0];
        int low=1,high = max_dis;
        // int ans =-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(canWePlace(position,mid,m)){
                // ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;

            }
        }
        return high;
    }
};