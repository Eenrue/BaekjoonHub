#include<iostream>
#include<algorithm>
using namespace std;

int chess[50][50];

int score(int a, int b) {
	int res1 = 0;
	int res2 = 0;

	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if ((i + j) % 2 == chess[i][j])
				res1++;
			if ((i + j + 1) % 2 == chess[i][j])
				res2++;
		}
	}

	return min(res1, res2);
}

int main()
{
	int n, m; // 8 <= n <= 50 
	char tmp;
	int mini = 10000;

	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			if (tmp == 'B') chess[i][j] = 0;
			else chess[i][j] = 1;
		}
	}

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			mini = min(score(i, j), mini);
		}
	}

	cout << mini;

	return 0;
}