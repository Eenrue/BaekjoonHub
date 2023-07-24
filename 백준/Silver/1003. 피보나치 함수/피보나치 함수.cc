#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mem0[41] = {-1, };
int mem1[41] = { -1, };

int check0(int n) {
	if (mem0[n] > 0) return mem0[n];
	else if (n == 1)return 0;
	else if (n == 0)return 1;
	else {
		return mem0[n]=check0(n-1)+check0(n-2);
	}
}
int check1(int n) {
	if (mem1[n] > 0) return mem1[n];
	else if (n == 1)return 1;
	else if (n == 0)return 0;
	else {

		return mem1[n] = check1(n - 1) + check1(n - 2);
	}
}

int main()
{
	int N;
	int  inp;
	int cnt = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> inp;
		cout << check0(inp) << ' '<<check1(inp)<<'\n';
	}

	return 0;
}