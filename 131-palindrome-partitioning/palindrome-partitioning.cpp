class Solution {
public:

    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>& ans,
               vector<string>& part, int index) {

        // Base case
        if(index == s.size()) {
            ans.push_back(part);
            return;
        }

        // Try all possible partitions
        for(int i = index; i < s.size(); i++) {

            // Check if current substring is palindrome
            if(isPalindrome(s, index, i)) {

                // Add substring
                part.push_back(s.substr(index, i - index + 1));

                // Recursion
                solve(s, ans, part, i + 1);

                // Backtracking
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> part;

        solve(s, ans, part, 0);

        return ans;
    }
};