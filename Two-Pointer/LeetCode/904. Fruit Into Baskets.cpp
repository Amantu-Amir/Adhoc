class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), l = 0, r = 0, curr = 0, res = 0;
        map<int, int> cnt;
        while (l <= r and r < n) {
            cnt[fruits[r]]++;
            if (cnt[fruits[r]] == 1) curr++;
            while (curr > 2) {
                cnt[fruits[l]]--;
                if (cnt[fruits[l]] == 0) curr--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};

