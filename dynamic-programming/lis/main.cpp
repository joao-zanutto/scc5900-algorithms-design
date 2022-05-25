#include <iostream>
#include <cstring>

#define TAM 2500

using namespace std;

int arr[TAM], dp[TAM];

int lis(int i, int &maxlis){
    if(i == 0)
        return 1;
    if(dp[i] != -1)
        return dp[i];

    int maior = 1;
    for(int j = i-1; j >=0 ; j--){
        int temp = lis(j, maxlis);
        if(arr[i] > arr[j])
               maior = max(temp+1, maior);
    }

    dp[i] = maior;

    if(maior > maxlis)
        maxlis = maior;

    return dp[i];
}

int main(void){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    memset(dp, -1, sizeof(dp));
    int maxlis = 1;
    lis(n-1, maxlis);

    cout << maxlis << endl;

    return 0;
}