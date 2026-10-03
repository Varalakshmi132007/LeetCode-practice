class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;

        for (string email : emails) {
            int at = email.find('@');

            string local = email.substr(0, at);
            string domain = email.substr(at + 1);

            string newLocal = "";

            for (char c : local) {
                if (c == '+')
                    break;

                if (c != '.')
                    newLocal += c;
            }

            s.insert(newLocal + "@" + domain);
        }

        return s.size();
    }
};