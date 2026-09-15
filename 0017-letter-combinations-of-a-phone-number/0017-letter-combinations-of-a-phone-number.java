import java.util.*;

class Solution {
    public List<String> letterCombinations(String digits) {

        List<String> result = new ArrayList<>();

        String[] phone = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        backtrack(digits, 0, "", result, phone);

        return result;
    }

    public void backtrack(String digits, int index, String current,
                           List<String> result, String[] phone) {

        // If we have used all digits
        if (index == digits.length()) {
            result.add(current);
            return;
        }

        // Get letters for current digit
        String letters = phone[digits.charAt(index) - '0'];

        // Try each letter
        for (int i = 0; i < letters.length(); i++) {

            char letter = letters.charAt(i);

            // Add letter and move to next digit
            backtrack(digits, index + 1, current + letter,
                      result, phone);
        }
    }
}