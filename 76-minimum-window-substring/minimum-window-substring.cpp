class Solution {
public:
    string minWindow(string s, string t) {

        if (t.length() > s.length())
            return "";

        vector<int> freq(128, 0);

        // Store frequency of characters in t
        for (char ch : t) {
            freq[ch]++;
        }

        int left = 0;
        int right = 0;

        int required = t.length();
        int minLength = INT_MAX;
        int start = 0;

        while (right < s.length()) {

            // Add current character
            if (freq[s[right]] > 0) {
                required--;
            }

            freq[s[right]]--;
            right++;

            // Window is valid
            while (required == 0) {

                // Update minimum window
                if (right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }

                // Remove left character
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX)
            return "";

        return s.substr(start, minLength);
    }
};