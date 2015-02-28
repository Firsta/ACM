#include    <vector>
#include    <sstream>
#include    <string>
#include    <iostream>
#include    <algorithm>

using namespace std;

bool cmp(const string &a, const string &b) {
    if (a.length() == b.length())
        return a < b;
    int alen = a.length(), blen = b.length();
    int minl = min(alen, blen);
    for (int i = 0; i < alen * blen; i++) {
        if (a[i%alen] == b[i%blen])
            continue;
        else
            return a[i%alen] < b[i%blen];
    }
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string tmps, ret;
        int n = num.size();
        vector<string> sv;
        for (int i = 0; i < n; i++) {
            string tmps;
            stringstream ss;
            ss << num[i];
            tmps = ss.str();
            sv.push_back(tmps);
        }
        int maxl = 0;
        for (int i = 0; i < n; i++)
            maxl = max(maxl, (int)sv[i].length());
        int maxn = 0;
        for (int i = 0; i < n; i++)
            maxn = max(maxn, num[i]);
        if (maxn == 0)
            return sv[0];
        sort(sv.begin(), sv.end(), cmp);
        for (int i = n - 1; i >= 0; i--)
            ret += sv[i];
        return ret;
    }
};

int main()
{
    Solution test;
    int n, tmp;
    vector<int> a;
    cin >> n;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << test.largestNumber(a) << endl;
}
