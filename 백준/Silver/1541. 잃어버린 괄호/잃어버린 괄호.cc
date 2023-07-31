#include <bits/stdc++.h>
using namespace std;
vector<int> nums;

int main() {
	string inp;
	cin>>inp;
	int flag=0;
	int cnt=0;
	int num=0;
	int fir=-1;

	for(int i=0;i<inp.size();i++){
        char let=inp[i];
        if('0'<=let&&let<='9'){
            if(let=='0'&&flag==0)continue;
            flag=1;
            num*=10;
            num+=int(let)-48;
        }
        else if(let=='+'||let=='-'){
            nums.push_back(num);
            num=0;
            flag=0;
            cnt++;
            if(let=='-'&&fir==-1){
                fir=cnt;
            }
        }
	}
	nums.push_back(num);
	int ans=0;
	if(fir==-1)fir=nums.size();
    for(int i=0;i<nums.size();i++){
        if(i>=fir){
            ans-=nums[i];
        }
        else{
            ans+=nums[i];
        }
    }
    cout<<ans;
}
