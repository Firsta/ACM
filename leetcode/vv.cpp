#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(version1.size() != 0 && version1[0] == '0')
            version1 = version1.substr(1, version1.size() - 1);
        while(version2.size() != 0 && version2[0] == '0')
            version2 = version2.substr(1, version2.size() - 1);
        int n1 = version1.size(), n2 = version2.size();
        if (n1 > n2) {
            version2 += string(n1 - n2, '0');
            n2 = n1;
        } else if (n2 > n1) {
            version1 += string(n2 - n1, '0');
            n1 = n2;
        }
        int i = 0, j = 0;
        for (; i < n1; i++)
            if (version1[i] == '.')
                break;
        for (; j < n2; j++)
            if (version2[j] == '.')
                break;
        if (i > j)
            return 1;
        else if (i < j) 
            return -1;
        cout << version1 <<' '<< version2 << endl;
        for (int k = 0; k < i; k++) {
            if (version1[k] > version2[k])
                return 1;
            else if (version1[k] < version2[k])
                return -1;
        }
        for (int k = i + 1; k < n1; k++) {
            if (version1[k] > version2[k])
                return 1;
            else if (version1[k] < version2[k])
                return -1;
        }
        return 0;
    }
};
int main()
{
	Solution test;
	string s1,s2;
	cin>>s1>>s2;
	cout << test.compareVersion(s1,s2);
}
