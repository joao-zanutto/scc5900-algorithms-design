#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

long long min(stack<long long> number_stack, stack<char> operation_stack){
    long long sum = 0;

    stack<long long> new_number_stack;

    while(number_stack.size() > 1) {
        long long num = number_stack.top();
        number_stack.pop();
        char op = operation_stack.top();
        operation_stack.pop();

        if(op == '+') {
            new_number_stack.push(num);
        } else {
            num *= number_stack.top();
            number_stack.pop();
            number_stack.push(num);
        }
    }
    new_number_stack.push(number_stack.top());

    while(!new_number_stack.empty()) {
        sum += new_number_stack.top();
        new_number_stack.pop();
    }

    return sum;
}

long long max(stack<long long> number_stack, stack<char> operation_stack){
    long long mult = 1;

    stack<long long> new_number_stack;

    while(number_stack.size() > 1) {
        long long num = number_stack.top();
        number_stack.pop();
        char op = operation_stack.top();
        operation_stack.pop();

        if(op == '*') {
            new_number_stack.push(num);
        } else {
            num += number_stack.top();
            number_stack.pop();
            number_stack.push(num);
        }
    }
    new_number_stack.push(number_stack.top());

    while(!new_number_stack.empty()) {
        mult *= new_number_stack.top();
        new_number_stack.pop();
    }

    return mult;
}

int main(void)
{
    // Reads number of test cases
    int N;
    cin >> N;

    // Loop through all test cases
    for(int i = 0; i < N; i ++){
        stack<long long> number_stack;
        stack<char> operation_stack;

        string temp;
        cin >> temp;
        stringstream ss(temp);

        long long num;
        char op;
        ss >> num;
        number_stack.push(num);
        
        // Reads the string input for the mathematical operation
        while(ss.rdbuf()->in_avail()){
            ss >> op;
            ss >> num;
            number_stack.push(num);
            operation_stack.push(op);
        }

        long long minValue = min(number_stack, operation_stack);
        long long maxValue = max(number_stack, operation_stack);

        cout << "The maximum and minimum are " << maxValue << " and " << minValue << "." << endl;


    }

    return 0;
}