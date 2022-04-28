#include<iostream>
#include<cstring>
#include <iomanip>
using namespace std;

int chess[8][8], loc[8], maxVal;
bool vis[8];

bool judge(int cur, int col){
    for(int i = 0; i < cur; i++){
        if(loc[i] == col || cur - i == loc[i] - col || cur - i == col - loc[i])
            return false;
    }
    return true;
}

void search(int cur, int sum){
    for(int i = 0; i < 8; i++)
        if(!vis[i] && judge(cur,i)){
            vis[i] = true;
            loc[cur] = i;
            search(cur + 1, sum + chess[cur][i]);
            vis[i] = false;
        }
    if(cur == 8 && sum > maxVal) maxVal = sum;
}

int main(){
    int k;
    cin >> k;
    
    for(int cases = 0; cases < k; cases++){
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                cin >> chess[i][j];

        maxVal = -1;
        memset(vis, 0, sizeof(vis));
        search(0, 0);

        cout << setw(5) << maxVal << endl;
    }

    return 0;
}