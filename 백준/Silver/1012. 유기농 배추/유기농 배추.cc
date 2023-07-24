#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int bae[52][52] = {0,};

int color(int i, int j) {
	if (bae[i][j] != 1) return 0;
	bae[i][j] = 2;
	return color(i, j + 1) + color(i + 1, j) + color(i, j - 1) + color(i - 1, j);
}

int check(int n, int m) {
	int cnt = 0; // 지렁이
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (bae[i][j] == 1) {
				color(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}


int main()
{
	int rep;
	int M, N;
	int b;
	int  inp;
	cin >> rep;
	for (int i = 1; i <= rep; i++) {
		bae[52][52] = { 0, };
		cin >> M>>N>>b;
		for (int j = 0; j < b; j++) {
			int t1, t2;
			cin >> t1 >> t2;
			bae[t2+1][t1+1] = 1;
		}
		cout << check(N, M) <<'\n';
	}

	return 0;
}