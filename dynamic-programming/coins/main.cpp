#include <iostream>
#include <cstring>

using namespace std;

int a[]={1,5,10,25,50};
long long memo[30001][5];

long long num(int x, int y){
    if(y > 4 || x < 0)
        return 0;
    if(x == 0)
        return 1;
    if(memo[x][y] != -1)
        return memo[x][y];
    
    memo[x][y]= num(x,y+1) + num(x-a[y],y);
    
    return memo[x][y];
}

int main(){
    memset(memo,-1,sizeof(memo));

    int n;
    while(cin >> n){
        long long result = num(n,0);
        if(result != 1)
            cout << "There are " << result << " ways to produce " << n << " cents change."<< endl;
        else
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
    }

    return 0;
}
