class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<int> t;
        vector<vector<int>> ans;
        if (num.size() == 0)
            return ans;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int j = i + 1, k = num.size() - 1;
            int tmp = 0 - num[i];
            
            if (i != 0 && num[i] == num[i - 1])
                continue;
            while (j < k) {
                if (num[j] + num[k] < tmp)
                    j++;
                else if(num[j] + num[k] > tmp)
                    k--;
                else {
                    vector<int> ta;
                    ta.push_back(min(num[i], min(num[j], num[k])));
                    ta.push_back(num[i]+num[j]+num[k] - min(num[i], min(num[j], num[k])) - max(num[i], max(num[j], num[k])));
                    ta.push_back(max(num[i], max(num[j], num[k])));
                    ans.push_back(ta);
                    k--;
                    while (j < k && k >= 0 && num[k] == num[k + 1])
                        k--;
                    j++;
                    while (j < k && j < num.size() && num[j] == num[j - 1])
                        j++;
                }
            }
        }
    }
};
