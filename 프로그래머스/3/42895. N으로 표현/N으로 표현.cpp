#include <string>
#include <vector>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<int> dp[10]={};
    dp[1].push_back(N);
    if(N==number) return 1;
    for(int i=2;i<=8;i++){
        bool vis[32001]={};
        int num1=0;
        for(int j=0;j<i;j++){
            num1*=10;
            num1+=N;
        }
        dp[i].push_back(num1);
        for(int k=1;k<i;k++){
            int fir=k;
            int sec=i-k;
            
            for(int j=0;j<dp[fir].size();j++){
                for(int l=0;l<dp[sec].size();l++){
                    int tmp=0;
                    tmp=dp[fir][j]+dp[sec][l];
                    if(tmp>0&&tmp<=32000){
                        dp[i].push_back(tmp);
                    }
                    tmp=dp[fir][j]-dp[sec][l];
                    if(tmp>0&&tmp<=32000){
                        dp[i].push_back(tmp);
                    }
                    tmp=-dp[fir][j]+dp[sec][l];
                    if(tmp>0&&tmp<=32000){
                        dp[i].push_back(tmp);
                    }
                    tmp=dp[fir][j]*dp[sec][l];
                    if(tmp>0&&tmp<=32000){
                        dp[i].push_back(tmp);
                    }
                    tmp=dp[fir][j]/dp[sec][l];
                    if(tmp>0&&tmp<=32000){
                        dp[i].push_back(tmp);
                    }
                    tmp=dp[sec][l]/dp[fir][j];
                    if(tmp>0&&tmp<=32000){
                        dp[i].push_back(tmp);
                    }
                }
            }
        }
        for(int j=0;j<dp[i].size();j++){
            if(dp[i][j]==number)return i;
        }
    }
    return -1;
    return answer;
}