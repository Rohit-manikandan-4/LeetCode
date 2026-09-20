class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();

        vector<int> valid(m, 0);

        // Create a bitmask for each row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (seats[i][j] == '.')
                    valid[i] |= (1 << j);
            }
        }

        vector<vector<int>> dp(m, vector<int>(1 << n, -1));

        int answer = 0;

        // Try every possible arrangement for the first row
        for (int mask = 0; mask < (1 << n); mask++) {

            // Students cannot sit in broken seats
            if ((mask & valid[0]) != mask)
                continue;

            // No two students can sit next to each other
            if (mask & (mask << 1))
                continue;

            dp[0][mask] = __builtin_popcount(mask);
            answer = max(answer, dp[0][mask]);
        }

        // Process remaining rows
        for (int row = 1; row < m; row++) {
            for (int mask = 0; mask < (1 << n); mask++) {

                if ((mask & valid[row]) != mask)
                    continue;

                // No students sitting side-by-side
                if (mask & (mask << 1))
                    continue;

                for (int prev = 0; prev < (1 << n); prev++) {

                    if (dp[row - 1][prev] == -1)
                        continue;

                    // Check diagonal cheating:
                    // current student's upper-left / upper-right
                    // seats must not contain students.
                    if (mask & (prev << 1))
                        continue;

                    if (mask & (prev >> 1))
                        continue;

                    dp[row][mask] = max(
                        dp[row][mask],
                        dp[row - 1][prev] + __builtin_popcount(mask)
                    );

                    answer = max(answer, dp[row][mask]);
                }
            }
        }

        return answer;
    }
};