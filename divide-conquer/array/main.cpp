#include <iostream>
using namespace std;

int main(void){

    int t;
    cin >> t;
    for(int test = 0; test < t; test++){
        int n, q, pretty;
        cin >> n >> q;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        for(int i = 0; i < q; i++){
            cin >> pretty;
            validate_prettiness(arr, n, pretty);
        }

    }

    return 0;
}