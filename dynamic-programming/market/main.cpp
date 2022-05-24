#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        int P[N], W[N];
        for(int j = 0; j < N; j++)
            cin >> P[j] >> W[j];

        int dp[32];
        memset (dp, 0, sizeof (dp));
 
        for ( int j = 0; j < N; j++ ) {
            for ( int i = 32; i >= 0; i-- ) {
                if ( W[j] <= i && dp[i] < dp[i - W[j]] + P[j] )
                    dp[i] = dp[i - W[j]] + P[j];
            }
        }

        int G;
        cin >> G;
        int maxPrice = 0;
        while(G--){
            int MW;
            cin >> MW;
            maxPrice += dp[MW];
        }

        cout << maxPrice << endl;
    }

    return 0;
}