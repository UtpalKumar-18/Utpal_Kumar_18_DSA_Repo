class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int max_cnt = INT_MIN;
        int ind = -1;
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j =0;j<m;j++){
                cnt += mat[i][j];
            }
            if(cnt>max_cnt){
                max_cnt = cnt;
                ind = i;
            }
        }
        
        return {ind,max_cnt};
    }
};