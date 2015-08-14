class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int> > G(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            G[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][1]]++;
        }

        queue<int> q;
        for (int i = 0; i < in.size(); i++)
            if (in[i] == 0)
                q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            cnt++;
            for (int i = 0; i < G[temp].size(); i++) {
                in[G[temp][i]]--;
                if (in[G[temp][i]] == 0)
                    q.push(G[temp][i]);
            }
        }
        if (cnt < numCourses)
            return false;
        return true;
    }
};
