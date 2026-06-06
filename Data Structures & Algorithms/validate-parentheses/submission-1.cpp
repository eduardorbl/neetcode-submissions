class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else
            {
                if (stk.empty()) return false;
                char t = stk.top(); stk.pop();
                if (t == '(' && c != ')') return false;
                if (t == '[' && c != ']') return false;
                if (t == '{' && c != '}') return false;
            }
        }
        return stk.empty();
    }
};
