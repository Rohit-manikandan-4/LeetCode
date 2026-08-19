class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats for each row using bitmask
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        // Every completely empty row can accommodate 2 groups
        int ans = (n - mp.size()) * 2;

        for (auto &[row, mask] : mp) {
            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int seat = 2; seat <= 5; seat++) {
                if (mask & (1 << seat)) {
                    left = false;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (mask & (1 << seat)) {
                    middle = false;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (mask & (1 << seat)) {
                    right = false;
                }
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};