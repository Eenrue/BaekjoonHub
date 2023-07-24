#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int stack[10000] = { 0 };
int k = -1;

int main()
{
	int N;
	int inp;
	int ind;
	int tmp=-1;
	int eflag = 0;
	cin >> N;
	vector<int> vec;
	vector<char> res;
	for (int i = 1; i <= N; i++) {
		vec.push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		cin >> inp;
		if (eflag == 0) {
			ind = (find(vec.begin(), vec.end(), inp) - vec.begin());
			if (ind >= tmp) {
				while (ind != tmp) {
					res.push_back('+');
					tmp++;
				}
				res.push_back('-');
				vec.erase(find(vec.begin(), vec.end(), inp));
				tmp--;
			}
			else {
				eflag = 1;
			}
		}
	}
	if (eflag == 1) cout << "NO";
	else {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << "\n";
		}
	}



	return 0;
}