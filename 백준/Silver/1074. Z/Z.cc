#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int check(int r, int c) {
	int cnt = 0;
	int tmp = max(r, c);
	if (tmp <= 1) {
		if (r == 0 && c == 0) return 1;
		if (r == 0 && c == 1) return 2;
		if (r == 1 && c == 0) return 3;
		if (r == 1 && c == 1) return 4;
	}

	while (tmp > pow(2, cnt)-1) {
		cnt++;
	} //

	int line = pow(2, cnt - 1);
	if (c > line-1 && r <= line-1) {
		return pow(4, cnt - 1) + check(r, c - line);
	}
	if (c <= line-1 && r > line-1) {
		return 2*pow(4, cnt - 1) + check(r - line, c );
	}
	if (c > line-1 && r > line-1) {
		return 3 * pow(4, cnt - 1) + check(r - line, c - line);
	}
	else return 0;
}

int main()
{
	int N;
	int r, c;
	cin >> N >> r >> c;
	cout << check(r, c)-1;


	return 0;
}