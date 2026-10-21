class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());

        // Already sorted
        if (s == t) return 0;

        // Cannot rearrange a string of length 2
        if (n == 2) return -1;

        // One operation: at least one endpoint is already correct
        if (s[0] == t[0] || s[n - 1] == t[n - 1]) {
            return 1;
        }

        // Check whether the maximum at the beginning and
        // minimum at the end are both unique
        char mx = t[n - 1];
        char mn = t[0];

        int maxCount = count(s.begin(), s.end(), mx);
        int minCount = count(s.begin(), s.end(), mn);

        if (s[0] == mx && s[n - 1] == mn &&
            maxCount == 1 && minCount == 1) {
            return 3;
        }

        return 2;
    }
};