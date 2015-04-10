#include    <vector>
#include    <iostream>
#include    <algorithm>

using namespace std;

int partition(vector<int> &v, int p, int r)
{
    int i = p - 1;
    int key = v[r];
    for (int j = p; j < r; j++)
        if (v[j] <= key) {
            i++;
            swap(v[i], v[j]);
        }
    swap(v[i + 1], v[r]);
    return i + 1;
}

void quicksort(vector<int> &v, int p, int r)
{
    if (p >= r)
        return;
    int m = partition(v, p, r);
    quicksort(v, p, m - 1);
    quicksort(v, m + 1, r);
}

void bubblesort(vector<int> &v, int n)
{
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        if (!flag)
            break;
    }
}

void insertsort(vector<int> &v, int n)
{
    for (int i = 1; i < n; i++) {
        int tmp = v[i];
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (v[j] > tmp)
                v[j + 1] = v[j];
            else {
                v[j + 1] = tmp;
                break;
            }
        }
        if (j == -1)
            v[0] = tmp;
    }
}

void xzsort(vector<int> &v, int n)
{
    int i = 0;
    for (int j = 0; j < n - 1; j++) {
        int minn = v[j];
        int ind = j;
        for (int k = j + 1; k < n; k++) {
            if (v[k] < minn) {
                minn = v[k];
                ind = k;
            }
        }
        swap(v[i], v[ind]);
        i++;
    }
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    xzsort(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}
