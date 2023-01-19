class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            sum = (sum + (nums[i] % k + k)) % k;
            res += cnt[sum];
            cnt[sum]++;
        }
        return res;
    }
};
