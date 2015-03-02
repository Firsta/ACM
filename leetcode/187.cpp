int cha(char c)
{
    switch (c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
    }
}


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<int, int> m;
        int n = s.size();
        for (int i = 0; i < n-9; i++) {
            int sum = 0;
            for (int j = i; j < i + 10; j++)
                sum = sum*4 + cha(s[j]);
            if (m[sum] == 0)
                m[sum]++;
            else if (m[sum] == 1){
                m[sum]++;
                ans.push_back(s.substr(i, 10));
            } else
                continue;
        }
        return ans;
    }
};
