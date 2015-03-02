class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 1; j <= i; j++) {
               tmp.push_back((int)((long long)tmp[j - 1] * (long long)(i - j + 1) / (long long)j));
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
