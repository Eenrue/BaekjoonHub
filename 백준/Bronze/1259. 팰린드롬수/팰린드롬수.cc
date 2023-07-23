#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string num="1";
	while(1) {
		cin >> num;
		string rev;
		rev = num;
		int flag = 0;
		if (num == "0") break;
		reverse(rev.begin(), rev.end());
		for (int i = 0; i < num.size(); i++) {
			if (num[i] != rev[i]) flag = 1;
		}
		if (flag == 0) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	return 0;
}