// class Solution {
// public:
//     int maxArea(vector<int>& height) {
        
//                int maxstorage = 0;
//                for(int i=0;i<height.size();i++){

               
//                for(int j=i+1;j<height.size();j++){
//                    int minheight = min(height[i],height[j]);
//                    int storage = (j-i)*(minheight);
//                    maxstorage = max(maxstorage, storage);
        
//                }

//                }
//                return maxstorage;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        
             int start = 0,end=height.size()-1;
             int maxstorage = 0;
             while(start<end){
                int minheight = min(height[start],height[end]);
                int storage = minheight*(end-start);
                maxstorage = max(maxstorage, storage);
                if(height[start]<height[end]) start++;
                else end--;

             }
             return maxstorage;
    }
};
