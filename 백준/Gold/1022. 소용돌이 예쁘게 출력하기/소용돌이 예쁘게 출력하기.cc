#include <iostream>
#include <string>
#include <iomanip>
#define MAX 10001

using namespace std;

int board[51][5] = { 0, };
// 오, 위, 왼, 아
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


int main() 
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    
	int r1, c1, r2, c2;

	cin >> r1 >> c1 >> r2 >> c2;

	int size = 1, cnt = 1;
    int cur = 0, dir = 0;
	int x = 0, y = 0;

	if (r1 <= x && x <= r2 && c1 <= y && y <= c2)
		board[x - r1][y - c1] = cnt;
	
	++cnt;

	while (board[0][0] == 0 || board[r2 - r1][0] == 0 ||
    board[r2 - r1][c2 - c1] == 0 || board[0][c2 - c1] == 0) 
	{
		x += dx[dir], y += dy[dir];

		if (r1 <= x && x <= r2 && c1 <= y && y <= c2) 
			board[x - r1][y - c1] = cnt;

		++cnt;
		++cur;

		if (cur == size) 
		{
			cur = 0;
			++dir;
			dir %= 4;

			if (dir == 0 || dir == 2)
				++size;
		}
	}

	int space = to_string(cnt).size();

	for (int i = 0; i <= r2 - r1; i++) 
	{
		for (int j = 0; j <= c2 - c1; j++)
		{
        	    int size = space - to_string(board[i][j]).size();
		    for(int k = 0; k < size; ++k)
			    cout << ' ';

		
			cout << board[i][j] << ' ';
		}

		
		cout << '\n';
	}

	return 0;
}