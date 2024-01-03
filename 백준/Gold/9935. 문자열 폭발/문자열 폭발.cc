#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int main()
{
    string a;
    string b;

    cin>>a>>b;
    string t="";

    for(int i=0;i<a.size();i++){
        t+=a[i];
        if(t.size()>=b.size()){
            bool f=true;
            for(int j=0;j<b.size();j++){
                if(t[t.size()-b.size()+j]!=b[j]){
                    f=false;
                    break;
                }
            }
            if(f){
                t.erase(t.end()-b.size(),t.end());
            }
        }
    }
    if(t.empty()) cout<<"FRULA";
    else cout<<t;

    return 0;
}
