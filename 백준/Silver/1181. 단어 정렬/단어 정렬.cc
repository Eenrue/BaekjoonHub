#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main()
{
	vector<string> vec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (find(vec.begin(), vec.end(), str) ==vec.end())
			vec.push_back(str);
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}

	return 0;
}