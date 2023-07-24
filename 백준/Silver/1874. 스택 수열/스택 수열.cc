#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	stack<int> s;
	vector<char> res;
	int  inp;
	int cnt = 1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> inp;
		while (inp >= cnt) {
			s.push(cnt);
			res.push_back('+');
			cnt++;
		}
		if (inp == s.top()) {
			s.pop();
			res.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "\n";
	}


	return 0;
}