#include <iostream>
using namespace std;

int staircase(int coins, int n) {
    if(coins - n < 0) return 0;
    else if(coins - n == 0) return 1;
    return 1 + staircase(coins - n, n + 1);
}

int main(void){

    while(!cin.eof()) {
        int coins;
        cin >> coins;
        if(cin.eof()) break;

        int n = staircase(coins, 1);

        cout << n << endl;
    }

    return 0;
}