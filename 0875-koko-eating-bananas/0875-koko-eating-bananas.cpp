// class Solution {
// public:
//     long long caltime(vector<int>& piles,int hours){
//         long long total_time =0;
//         for(int i=0;i<piles.size();i++){
//             total_time += ceil((double)piles[i]/hours);
//         }
//         return total_time;
//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
//         int maxi = INT_MIN;
//        for(int i=0;i<piles.size();i++){
//             if(piles[i]>maxi) maxi = piles[i];
//        }

//         long long req_time = 0;
//        for(int i=1;i<=maxi;i++){
//             req_time = caltime(piles,i);
//             if(req_time<=h) return i;  
//        }
//        return -1;

//     }
// };


class Solution {
public:
    long long caltime(vector<int>& piles,int hours){
        long long total_time =0;
        for(int i=0;i<piles.size();i++){
            total_time += ceil((double)piles[i]/hours);
        }
        return total_time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi= INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        int low =1, high = maxi;
        int ans =0;
        while(low<=high){
            int mid = (low+high)/2;
            long long total_time = caltime(piles,mid);
             if(total_time<=h){
                ans = mid;
                high = mid-1;
             }
             else{
                low = mid+1; 
             }
        }
        return ans;

    }
};