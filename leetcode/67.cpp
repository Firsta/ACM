class Solution {
public:
    string addBinary(string a, string b) {
        int tmp = 0;
        string ans;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0, j >= 0; i--, j--) {
            if (a[i] == '0' &&  b[j] == '0') {
                ans = char(tmp + '0') + ans;
                tmp = 0;
            } else if ((a[i] == '1' && b[j] == '0') || (a[i] == '0') && (b[j] == '1')) {
                if (tmp == 1)
                    ans = '0' + ans;
                else
                    ans = '1' + ans;
            } else {
                if (tmp == 1)
                    ans = '1' + ans;
                else {
                    ans = '0' + ans;
                    tmp = 1;
                }
            }
            
            if (i == 0 && j == 0) {
                if (tmp)
                    ans = '1' + ans;
            } else if (i == 0) {
                while ((--j) != -1) {
                    if (tmp == 1) {
                        if (b[j] == '1')
                            ans = '0' + ans;
                        else {
                            ans = '1' + ans;
                            tmp = 0;
                        }
                    } else
                        ans = b[j] + ans;
                }
                if (tmp)
                    ans = '1' + ans;
            } else if (j == 0) {
                while ((--i) != -1) {
                    if (tmp == 1) {
                        if (a[i] == '1')
                            ans = '0' + ans;
                        else {
                            ans = '1' + ans;
                            tmp = 0;
                        }
                    } else
                        ans = a[i] + ans;
                }
                if (tmp)
                    ans = '1' + ans;
            }
        }
        return ans;
    }
};
