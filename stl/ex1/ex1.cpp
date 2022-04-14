#include <iostream>
#include <queue>
using namespace std;
 
int main(void)
{
    // n     = test case size
    // sum   = sum of elements up to the current iteration
    // cost  = the total cost in the current iteration
    int n, sum = 0, cost = 0;
    priority_queue<int, vector<int>, std::greater<int>> numbers;

    do{
        sum = 0, cost = 0;
        cin >> n;
        // read n numbers and push them into the queue
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            numbers.push(x);
        }
        cost -= numbers.top(); // remove the top number from the cost since it will count 2 times
        // sum up the numbers in the queue and obtain the total cost
        for(int i = 0; i < n; i++){
            cost += numbers.top() + sum;
            sum += numbers.top();
            numbers.pop();
        }
        // print the cost if the input is not 0
        if(n != 0) cout << cost << '\n';
    }while(n != 0);
 
    return 0;
}