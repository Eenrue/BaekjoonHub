#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int ls[1000002] = { 0, };
int line = 0;

void dp(int x) {
    if (x <= 1) return;
    else {
        if (x % 2 == 0) {
            if (ls[x / 2] == 0 || ls[x] + 1 < ls[x / 2]) {
                ls[x / 2] = ls[x] + 1;
                dp(x / 2);
            }
        }
        if (x % 3 == 0) {
            if (ls[x / 3] == 0 || ls[x] + 1 < ls[x / 3]) {
                ls[x / 3] = ls[x] + 1;
                dp(x / 3);
            }
        }
        if (ls[x-1] == 0 || ls[x] + 1 < ls[x-1]) {
            ls[x-1] = ls[x] + 1;
            dp(x-1);
        }
    }
}

int main()
{
    cin >> line;
    
    dp(line);
    cout << ls[1];

    return 0;
}