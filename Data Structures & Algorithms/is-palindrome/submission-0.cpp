class Solution {
public:
    bool isPalindrome(string s) {
        s.toLowerCase();
        erase_if(s, [](unsigned char c){return !isalnum(c)});
        cout << s;
    }
};
