#include	<iostream>
#include    <sstream>
#include	<string>

using namespace std;

class Solution {
public:
    void reverse(int l, int r, string &s) {
        char tmp;
        while(l < r) {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;r--;
        }
    }
    void reverseWords(string &s) {
        int j = 0, i = 0;
        while (s[j] == ' ' && j < s.size())
            j++;
        for (i = j; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(j, i - 1, s);
                while (s[i] == ' ' && i < s.size())
                    i++;
                j = i;
            }
        }
        if (s[i - 1] != ' ')
            reverse(j, i - 1, s);
        reverse(0, s.size() - 1, s);
        while (s[0] == ' ' && s.size() != 0) {
            s = s.substr(1, s.size() - 1);
        }
        while (s[s.size() - 1] == ' ' && s.size() != 0) {
            s = s.substr(0, s.size() - 1);
        }
        string ans;
        stringstream ss;
        ss << s;
        cout << ss.str() << endl;
        string tmp;
        while(ss >> tmp) {
            ans = ans + tmp  + " ";
            cout << "tmp" << tmp << endl;
        }
        ans = ans.substr(0, ans.size() - 1);
        s = ans;
    }
};

int main()
{
	string s;
	getline(cin,s);
	Solution test;
	test.reverseWords(s);
	cout<<s<<endl;
}
