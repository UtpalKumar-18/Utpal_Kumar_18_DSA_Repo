class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int peak_ele = INT_MIN;
        int ind1=-1,ind2=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] > peak_ele){
                    peak_ele = mat[i][j];
                    ind1 = i;
                    ind2 = j;
                }
            }
        }
        return {ind1,ind2};

    }
};