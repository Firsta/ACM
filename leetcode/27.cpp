class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        vector<int> tmp;
        for (int i = 0; i < n; i++)
            if (A[i] != elem)
                tmp.push_back(A[i]);
        for (int i = 0; i < tmp.size(); i++)
            A[i] = tmp[i];
        return tmp.size();
    }
};
