class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0, sum = 0, n = nums.size(), res = INT_MAX;
        for (int R = 0; R < n; R++) {
            sum += nums[R];
            while (sum >= target) {
                res = min(res, R - L + 1);
                sum -= nums[L++];
            }
        }
        if (res == INT_MAX) res = 0;
        return res;
    }
};
