class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;        //fill the buckets
            count[t[i] - 'a']--;        //empty the buckets
        }

        for (int i = 0; i < 26; i++) {    //check if all the buckets are empty
            if (count[i] != 0)
                return false;
        }

        return true;
    }
};