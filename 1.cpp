#include <bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<char>> &board, int r, int c, char val)
{

    for (int k = 0; k < board.size(); k++)
    {
        if (board[k][c] == val || board[r][k] == val)
            return false;
    }

    int s = 3;
    int rs = r - r % s;
    int cs = c - c % s;
    for (r = 0; r < s; r++)
    {
        for (c = 0; c < s; c++)
        {
            if (board[r + rs][c + cs] == val)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    int n = board.size();
    int i, j;
    char val;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
                break;
        }
    }
    if (i == n && j == n)
        return true;

    for (val = '1'; val <= '9'; val++)
    {
        if (issafe(board, i, j, val))
        {

            board[i][j] = val;
            if (solve(board))
                return true;
            board[i][j] = '.';
        }
    }
    return false;
}

int main()
{

    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solve(board);
    return 0;
}
