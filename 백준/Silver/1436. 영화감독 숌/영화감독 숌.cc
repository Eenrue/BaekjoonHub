#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	cin >> num;
	int count = 0;
	int res = 0;
	int tmp;
	while (num != count) {
		res++;
		tmp = res;
		while (tmp >= 666) {
			if (tmp % 1000 == 666) {
				count++;
				break;
			}
			tmp /= 10;
		}
	}

	cout << res;
	return 0;
}