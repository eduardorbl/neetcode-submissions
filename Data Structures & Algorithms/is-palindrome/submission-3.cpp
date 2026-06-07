class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s)
        {
            char lower = static_cast<char>(tolower(c));
            if (lower <= 'z' && lower >= 'a') str += c;
        }
        int lim = str.size() - ((str.size()%2) ? 1 : 0);
        for (int i = 0; i < ; i++)
        {
            if (str[i] != str[str.size()-i-1]) return false;
        }
        return true;
    }
};
