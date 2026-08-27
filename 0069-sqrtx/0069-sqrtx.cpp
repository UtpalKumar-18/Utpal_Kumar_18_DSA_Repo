// class Solution {
// public:
//     int mySqrt(int x) {
//         return sqrt(x);

//     }
// };

class Solution {
// public:
//     int mySqrt(int x) {
//         long long ans=0;
//         for(long long i=1;i<=x;i++){
//             if(i*i<=x) ans = i;
//             else break;
//         }
//         return ans;
        
        
//     }
// };

// public:
//     int mySqrt(int x) {
//         long long ans=0;
//         for(long long i=1;i<=x;i++){
//             if(i*i == x) ans =i;
//             else if(i*i > x){
//                 ans = i-1;
//                 break;
//             }
//         }
//         return ans; 
        
//     }
// };

public:
    int mySqrt(int x) {
        int low =1,high =x;
        int ans =1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long val = mid*mid;
            if(val<=x){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;


        }
        return high;
    }
};