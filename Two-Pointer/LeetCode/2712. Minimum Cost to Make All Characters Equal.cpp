class Solution {
public:
    long long solve(string& s, char a) {
        int n = s.size();
        int L = (n - 1) / 2;
        int R = L + 1, cnt = 0;
        long long res = 0;
        char ch = a;
        while (L >= 0) {
            cnt %= 2;
            ch = s[L];
            if (cnt == 1) {
                if (s[L] == '0') ch = '1';
                else ch = '0';
            }
            if (ch == a) {
                cnt++;
                res += (L + 1);
            }
            L--;
        }
        cnt = 0;
        while (R < n) {
            cnt %= 2;
            ch = s[R];
            if (cnt == 1) {
                if (s[R] == '0') ch = '1';
                else ch = '0';
            }
            if (ch == a) {
                cnt++;
                res += (n - R);
            }
            R++;
        }
        return res;
    }
    long long minimumCost(string s) {
        long long res = min(solve(s, '0'), solve(s, '1'));
        return res;
    }
};

