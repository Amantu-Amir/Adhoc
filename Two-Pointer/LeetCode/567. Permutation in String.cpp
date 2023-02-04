//slide size s1.size()

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(30, 0), cnt(30, 0);
        for (auto i : s1) {
            v[i - 'a' + 1]++;
        }
        int siz = s1.size(), n = s2.size(), l = -1, flag = 0;
        for (int i = 0; i < n; i++) {
            if (i >= (siz - 1)) {
                cnt[s2[i] - 'a' + 1]++;
                if (l != -1) {
                    cnt[s2[l] - 'a' + 1]--;
                }
                bool ok = 1;
                for (int j = 1; j <= 26; j++) {
                    if (cnt[j] != v[j]) {
                        ok = 0; break;
                    }
                }
                if (ok) {
                    flag = 1; break;
                }
                l++;
            }
            else {
                cnt[s2[i] - 'a' + 1]++;
            }
        }
        return flag;
    }
};
