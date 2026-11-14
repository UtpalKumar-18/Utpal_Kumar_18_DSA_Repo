// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         double sum =0;
//         double maxi = DBL_MIN;
//         for(int i =0;i<=nums.size()-k;i++){
//             sum =0;
//             for(int j=i;j<k+i;j++){
//                 sum += nums[j];
               
//             }
//             sum = sum/k;
//              maxi = max(maxi,sum);
//         }
//         return maxi;
//     }
// };

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         double sum=0;
//         int n= nums.size();
//         for(int i=0;i<k;i++){
//             sum += nums[i];
//         }

//         double maxi = sum;

//         for(int j=k;j<n;j++){
//             sum+=nums[j];
//             sum-=nums[j-k];
//             maxi = max(maxi,sum);
//         }
//         return maxi/k;


//     }
// };


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int n= nums.size();
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        int maxsum = sum;
        int start = 0;
        int end = k;
        while(end<nums.size()){
            sum -= nums[start];
            start++;

            sum += nums[end];
            end++;

            maxsum = max(sum,maxsum);

        }

        return (double)maxsum/k;

    }
};


