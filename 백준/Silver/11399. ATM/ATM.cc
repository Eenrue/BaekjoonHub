#include <bits/stdc++.h>
using namespace std;
vector<int> nums;

int n[1001]={0,};

int main() {
	int cnt;
	cin>>cnt;
	for(int i=0;i<cnt;i++){
        cin>>n[i];
	}
	int ans=0;
	sort(n,n+cnt);
	for(int i=0;i<cnt;i++){
        for(int j=0;j<=i;j++){
            ans+=n[j];
        }
	}
	cout<<ans;
}
