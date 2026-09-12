// class Solution {
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         int peak_ele = INT_MIN;
//         int ind1=-1,ind2=-1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(mat[i][j] > peak_ele){
//                     peak_ele = mat[i][j];
//                     ind1 = i;
//                     ind2 = j;
//                 }
//             }
//         }
//         return {ind1,ind2};
//     }
// };

class Solution {
public:
    int calmax(vector<vector<int>> &mat,int n,int m,int col){
        int maxVal =-1;
        int ind = -1;
        for(int i=0;i< n;i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low =0,high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int max_row_index = calmax(mat,n,m,mid);
            int  left = mid-1 >=0 ? mat[max_row_index][mid-1] : -1;
            int  right = mid+1 <m ? mat[max_row_index][mid+1] : -1;

            if(mat[max_row_index][mid] > left && mat[max_row_index][mid] > right) return {max_row_index,mid};
            else if(mat[max_row_index][mid] < left) high = mid-1;
            else low = mid+1;

        }
        return {-1,-1};
    }

};