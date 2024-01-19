#include <stdio.h>
#include <numeric>
using namespace std;

using ll = long long;
ll MOD = 1'000'000'007;

ll f(ll x, ll y){
	if(y==1) return x;
	if(y%2==1) return x*f(x,y-1)%MOD;
	ll p = f(x,y/2);
	return p*p%MOD;
}

int main(){
	ll m,a,b;
	ll ans = 0;
	
	scanf("%lld",&m);
	
	while(m--){
		scanf("%lld %lld",&b,&a);
		ll g = gcd(a,b);
		b /= g;
		a /= g;
		ans += a*f(b,MOD-2)%MOD;
		ans%=MOD;
	}
	
	printf("%lld",ans);
	
	return 0;
}