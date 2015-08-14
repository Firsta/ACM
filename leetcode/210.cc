class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans, emp;
        int n = numCourses;
        int *in = new int[n];
        for (int i = 0; i < n; i++)
            in[i] = 0;
        for (int i = 0; i < prerequisites.size(); i++)
            in[prerequisites[i].first]++;
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
                ans.push_back(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (int i = 0; i < prerequisites.size(); i++) {
                if (prerequisites[i].second == top) {
                    if (--in[prerequisites[i].first] == 0) {
                        q.push(prerequisites[i].first);
                        ans.push_back(prerequisites[i].first);
                        cnt++;
                    }
                }
            }
        }
        if (cnt == n)
            return ans;
        else
            return emp;
    }
};
