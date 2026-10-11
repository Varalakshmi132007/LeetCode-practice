class Solution {
public:
    string encode(vector<string>& strs) {
        string result = "";

        for (string s : strs) {
            result += to_string(s.size()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find the '#' separator
            while (s[j] != '#') {
                j++;
            }

            // Get the length of the string
            int len = stoi(s.substr(i, j - i));

            // Extract the original string
            string word = s.substr(j + 1, len);
            result.push_back(word);

            // Move to the next encoded string
            i = j + 1 + len;
        }

        return result;
    }
};