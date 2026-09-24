class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int smallest = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int sum =0;
            while(num){
                int last_digit = num%10;
                 sum += last_digit;
                num = num/10;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};