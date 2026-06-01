class Solution {
public:
    string encode(vector<string>& strs) {
        string s;

        for (int i = 0; i < strs.size(); i++) {
            s += to_string(strs[i].size());
            s += "#";
            s += strs[i];
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            j++; // pula o '#'

            string original = s.substr(j, len);
            v.push_back(original);

            i = j + len;
        }

        return v;
    }
};