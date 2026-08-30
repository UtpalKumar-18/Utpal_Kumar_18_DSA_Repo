class Solution {
public:
    bool check(vector<int> &bloomDay,int mid,int m,int k){
        int cnt =0;
        int num_of_bouquets =0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                num_of_bouquets += cnt/k;
                cnt =0;
            }
        }
        num_of_bouquets += cnt/k;
        return num_of_bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        long long val = m*1LL*k*1LL;
        if(n<val) return -1;

        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            maxi = max(maxi,bloomDay[i]);
            mini = min(mini,bloomDay[i]);
        }
        int low =mini,high = maxi;
        int ans=high;
        while(low<=high){
            int mid  = (low+high)/2;
            bool flag = check(bloomDay,mid,m,k);
            if(flag){
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