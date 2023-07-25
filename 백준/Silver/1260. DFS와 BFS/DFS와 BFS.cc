#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int line[1001][1001] = {0,};
vector<int> dvec;
vector<int> bvec;
vector<int> bans;

void dfs(int x) {
	if (find(dvec.begin(), dvec.end(), x) != dvec.end()) return;
	dvec.push_back(x);
	for (int i = 0; i < 1001; i++) {
		if (line[x][i] && find(dvec.begin(), dvec.end(), i) == dvec.end()) {
			dfs(i);
		}
	}
	return;
}

void bfs() {
	while (bvec.size() != 0) {
		int next;
		next = bvec[0];
		if (find(bans.begin(), bans.end(), next) == bans.end()) bans.push_back(next);

		bvec.erase(bvec.begin());
		for (int i = 0; i < 1001; i++) {
			if (line[next][i] && find(bans.begin(), bans.end(), i) == bans.end()) {
				bvec.push_back(i);
			}
		}
		bfs();
	}
}


int main() {
	int n,m,v;
	cin >> n>>m>>v;
	
	for (int i = 0; i < m; i++) {
		int inp1, inp2;
		cin >> inp1 >> inp2;
		line[inp1][inp2] = 1;
		line[inp2][inp1] = 1;
	}

	dfs(v);
	bvec.push_back(v);
	bfs();
	for (int i = 0; i < dvec.size(); i++) {
		cout << dvec[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < bans.size(); i++) {
		cout << bans[i] << ' ';
	}
	
	return 0;
}