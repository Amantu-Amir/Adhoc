class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> cnt(100005, 0);
        for (int i = 0; i < m; i++) cnt[potions[i]]++;
        for (int i = 100000; i >= 0; i--) cnt[i] += cnt[i + 1];
        for (int i = 0; i < n; i++) {
            long long need = (success - 1) / spells[i] + 1;
            if (need <= 100000) spells[i] = cnt[need];
            else spells[i] = 0;
        }
        return spells;
    }
};
