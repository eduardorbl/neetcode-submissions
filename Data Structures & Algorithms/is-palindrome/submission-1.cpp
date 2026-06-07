class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s)
        {
            char lower = static_cast<char>(toLower(c));
            if (lower <= 'z' && lower >= 'a') str += c;
        }

        


    }
};
