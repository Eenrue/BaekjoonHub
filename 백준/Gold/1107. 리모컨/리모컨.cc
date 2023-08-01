#include <bits/stdc++.h>
using namespace std;
int ch[1000002]={0,};
int obj;
vector<int> valid={0,1,2,3,4,5,6,7,8,9};

void check(int k){
    int tmp=k;
    tmp*=10;
    if(tmp>1000000)return;
    for(int i=0;i<valid.size();i++){
        if(ch[tmp+valid[i]]!=0)return;
        ch[tmp+valid[i]]=1;
        check(tmp+valid[i]);
    }
}



int main() {
	cin>>obj;
	int rep;
	cin>>rep;

    for(int i=0;i<rep;i++){
        int tmp;
        cin>>tmp;
        valid.erase(find(valid.begin(),valid.end(),tmp));
    }

    check(0);

    int res=abs(obj-100);
	for(int i=0;i<1000000;i++){
        if(ch[i]==0)continue;
        int tmp;
        string tmps=to_string(i);
        tmp=tmps.size();
        if(tmp+(abs(i-obj))<res) res= tmp+(abs(i-obj));
	}
    cout<<res;
}
