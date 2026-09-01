// class Solution {
// public:
//     int caldays(vector<int> &weight,int cap){
//         int load =0,days =1;
//         for(int i=0;i<weight.size();i++){
//             if(load + weight[i] > cap){
//                 days = days+1;
//                 load = weight[i];
//             }
//             else{
//                 load+=weight[i];
//             }
                 
//         return days;
//     }
//     int shipWithinDays(vector<int>& weights, int days) {
//         int maxi = INT_MIN;
//         int sum =0;
//         for(int i=0;i<weights.size();i++){
//             maxi = max(maxi,weights[i]);
//             sum += weights[i];
//         }

//         for(int cap = maxi;cap<=sum;cap++){
//             int req_days = caldays(weights,cap);
//             if(req_days <= days) return cap;
//         }

//         return -1;

//     }
// };


class Solution {
public:
    int caldays(vector<int> &weight,int cap){
        int load =0,days =1;
        for(int i=0;i<weight.size();i++){
            if(load + weight[i] > cap){
                days = days+1;
                load = weight[i];
            }
            else{
                load+=weight[i];
            }

        }
                 
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum =0;
        for(int i=0;i<weights.size();i++){
            maxi = max(maxi,weights[i]);
            sum += weights[i];
        }
        
        int low = maxi,high = sum;
        int ans = sum;
        while(low<=high){
            int mid = (low+high)/2;

            int req_days = caldays(weights,mid);
            if(req_days <=days){
                ans= mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;

    }
};