#include <bits/stdc++.h>
using namespace std;

int inp[11];
int main() {
	int n,k;
	int ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>inp[i];
	}
	for(int i=n;i>0;i--){
        if(k<inp[i]) continue;
        int tmp;
        tmp=k/inp[i];
        ans+=tmp;
        k%=inp[i];
	}
	cout<<ans;
}
