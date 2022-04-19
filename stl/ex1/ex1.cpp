#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    // n     = test case size
    // cost  = the total cost in the current iteration
    int n, cost = 0;
    priority_queue<int, vector<int>, std::greater<int>> numbers;

    do{
        cin >> n;
        // read n numbers and push them into the queue
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            numbers.push(x);
        }

        cost = 0;
        while(numbers.size() > 1){
            int n1 = numbers.top();
            numbers.pop();
            int n2 = numbers.top();
            numbers.pop();
            cost += n1 + n2;
            numbers.push(n1 + n2);
        }
         numbers.pop();
        // print the cost if the input is not 0
        if(n != 0) cout << cost << '\n';
    }while(n != 0);
 
    return 0;
}