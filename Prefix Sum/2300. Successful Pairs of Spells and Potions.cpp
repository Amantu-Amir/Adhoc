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




//C#

public class Solution {
    int Search(int[] a, int need) {
        int L = 0, R = a.Length - 1, idx = a.Length;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (a[mid] >= need) {
                idx = mid;
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        return idx;
    }

    public int[] SuccessfulPairs(int[] spells, int[] potions, long success) {
        Array.Sort(potions);
        int n = spells.Length, m = potions.Length;
        int[] successfulPair = new int[n];
        for (int i = 0; i < n; i++) {
            long need = (success - 1) / spells[i] + 1;
            if (need <= 100000) {
                int idx = Search(potions, (int)need);
                successfulPair[i] = m - idx;
            }
            else successfulPair[i] = 0;
        }
        return successfulPair;
    }
}


