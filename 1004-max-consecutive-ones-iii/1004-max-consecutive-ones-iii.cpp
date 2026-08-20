class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int max_cnt = 0;
        int left = 0, right = 0;
        while(right < nums.size()){
            if(nums[right]==0){
                zeros++;
            }
            while(zeros > k){
                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }
            max_cnt = max(max_cnt, right - left + 1);
            right++;
        }
        return max_cnt;
    }
};