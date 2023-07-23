#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ran[10000];
int main()
{
	int k;
	int n2 = 0;
	int n5 = 0;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int tmp = i;
		while (tmp % 2 == 0) {
			n2++;
			tmp /= 2;
		}
		while (tmp % 5 == 0) {
			n5++;
			tmp /= 5;
		}
	}
	cout << min(n2, n5);
	return 0;
}