class Solution {
public:
    int LB(vector<int>& nums, int target) {
        // lower bound
        int low = 0, high = nums.size() - 1;
        int lb = nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                lb = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return lb;
    }

    int UB(vector<int>& nums, int target) {
        // upper bound
        int low = 0, high = nums.size() - 1;
        int ub = nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target) {
                ub = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ub;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = LB(nums, target);
        int right = UB(nums, target) - 1;

        if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target) {
            return {left, right};
        }
        return {-1, -1};
    }
};
