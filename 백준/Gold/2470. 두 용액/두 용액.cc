#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
int res=0;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		ll tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	int s=0;
	int e=v.size()-1;
	int tmp[2]={s,e};
	res=v[s]+v[e];
	while(s<e){
		ll sum=v[s]+v[e];
		if(abs(sum)<abs(res)){
			tmp[0]=s;
			tmp[1]=e;
			res=sum;
		}
		if(sum>=0){
			e--;
		}
		if(sum<0){
			s++;
		}
	}
	cout<<v[tmp[0]]<<' '<<v[tmp[1]];
}