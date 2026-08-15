class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool exponentSeen = false;
        bool exponentDigitSeen = true;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Digit
            if (isdigit(c)) {
                digitSeen = true;

                // If we are after e/E, exponent must contain a digit
                if (exponentSeen)
                    exponentDigitSeen = true;
            }

            // Decimal point
            else if (c == '.') {
                // Dot cannot appear after exponent or twice
                if (dotSeen || exponentSeen)
                    return false;

                dotSeen = true;
            }

            // Exponent
            else if (c == 'e' || c == 'E') {
                // Exponent cannot appear twice
                // and there must be a number before it
                if (exponentSeen || !digitSeen)
                    return false;

                exponentSeen = true;
                exponentDigitSeen = false;
            }

            // Sign
            else if (c == '+' || c == '-') {
                // Sign is valid only at the beginning
                // or immediately after e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }

            // Anything else is invalid
            else {
                return false;
            }
        }

        return digitSeen && exponentDigitSeen;
    }
};