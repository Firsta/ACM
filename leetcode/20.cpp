char match(char c)
{
    switch (c) {
        case '(':
            return ')';
        case '{':
            return '}';
        case '[':
            return ']';
    }    
    return 'x';
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (int i = 0; i < s.size(); i++) {
            if (sta.size() > 0 && s[i] == match(sta.top()))
                sta.pop();
            else
                sta.push(s[i]);
        }
        if (sta.size() == 0)
            return true;
        else
            return false;
    }
};
