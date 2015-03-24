class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "*") {
                int tmp = s.top();
                s.pop();
                tmp *= s.top();
                s.pop();
                s.push(tmp);
            } else if (tokens[i] == "+") {
                int tmp = s.top();
                s.pop();
                tmp += s.top();
                s.pop();
                s.push(tmp);
            } else if (tokens[i] == "-") {
                int tmp = s.top();
                s.pop();
                tmp = s.top() - tmp;
                s.pop();
                s.push(tmp);
            } else if (tokens[i] == "/") {
                int tmp = s.top();
                s.pop();
                tmp = s.top() / tmp;
                s.pop();
                s.push(tmp);
            } else {
                int tmp = 0;
                int j = 0;
                if (tokens[i][j] == '-')
                    j++;
                for (; j < tokens[i].size(); j++)
                   tmp = tmp * 10 + (int)(tokens[i][j] - '0');
                if (tokens[i][0] == '-')
                    tmp = -tmp;
                s.push(tmp);
            }
        }
        if (s.empty())
            return 0;
        else
            return s.top();
    }
};
