#include    <vector>
#include    <iostream>
#include    <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res, left, right;
        bool flag = false;
        for(int i = 0; i < input.size(); i++) {
            if(!isdigit(input[i]))
                flag = true;
            switch(input[i]) {
                case '+':
                    left = diffWaysToCompute(input.substr(0, i));
                    right = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
                    for (const auto &j : left)
                        for (const auto &k : right)
                            res.push_back(j + k);
                    break;
                case '-':
                    left = diffWaysToCompute(input.substr(0, i));
                    right = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
                    for (const auto &j : left)
                        for (const auto &k : right)
                            res.push_back(j - k);
                    break;
                case '*':
                    left = diffWaysToCompute(input.substr(0, i));
                    right = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
                    for (const auto &j : left)
                        for (const auto &k : right)
                            res.push_back(j * k);
                    break;
            }
        }
        if (!flag) {
            int num = 0;
            for(int i = 0; i < input.size(); i++)
                num = num * 10 + int(input[i] - '0');
            res.push_back(num);
        }
        for (const auto &t : res)
            cout << t << '!' << endl;
        return res;
    }
};

int main() {
    Solution test;
    string s;
    cin >> s;
    for (auto const &t : test.diffWaysToCompute(s))
        cout << t << ' ' << endl;
    return 0;
}
