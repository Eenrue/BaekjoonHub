#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	vector<int> comp;
	for (int i = 0; i < 8; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
	comp = vec;

	sort(comp.begin(), comp.end());
	if (comp == vec)
		cout << "ascending";
	else {
		sort(comp.begin(), comp.end(), greater<int>());
		if (comp == vec)
			cout << "descending";
		else cout << "mixed";

	}
	return 0;
}