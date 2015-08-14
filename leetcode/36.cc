#include    <string.h>
#include    <functional>
#include    <iostream>
#include    <vector>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> >& board) {
            int line[9][10], row[9][10], square[9][10];
            memset(line, 0, sizeof(line));
            memset(row, 0, sizeof(row));
            memset(square, 0, sizeof(square));
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        int now = board[i][j] - '0';
                        if (line[i][now] != 0)
                            return false;
                        if (row[j][now] != 0)
                            return false;
                        if (square[j / 3 + i / 3 * 3][now] != 0)
                            return false;
                        line[i][now] = row[j][now] = square[j / 3 + i / 3 * 3][now] = 1;

                    }

                }
            return true;

        }

};

int main() {
    vector<vector<char> > board(9);
    for (int i = 0; i < 9; i++) {
         string tmp;
         cin >> tmp;
         for (unsigned long j = 0; j < tmp.length(); j++)
             board[i].push_back(tmp[j]);
    }
    std::function<bool(Solution &, vector<vector<char> > &board)> f = &Solution::isValidSudoku;
    Solution test;
    cout << f(test, board);
    return 0;
}
