#include <bits/stdc++.h>
using namespace std;

int p(int x)
{
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 4;
    else{
        return p(x-1)+p(x-2)+p(x-3);
    }
}

vector<int> v;

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int tmp;
        cin >>tmp;
        cout<< p(tmp)<<'\n';
    }

}