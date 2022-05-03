#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

string digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
int n, m;


void print_password(string password[], int cont){
    for(int i = 0; i < cont; i++){
        cout << password[i];
    }
}

void update_password(int cont, string rule, string words[], string password[]){
    if(cont == int(rule.length())){
        print_password(password, cont);
        return;
    } else {
        if(rule[cont] == '#'){
            for(int i = 0; i < n; i++){
                password[cont] = words[i];
                update_password(cont + 1, rule, words, password);
                if(i < n - 1) cout << endl;
            }
        } else {
            for(int i = 0; i < 10; i++){
                password[cont] = digits[i];
                update_password(cont + 1, rule, words, password);
                if(i < 9) cout << endl;
            }
        }
    }
}

int main(void)
{
    string password[300], words[100], rule;

    while(!cin.eof()){
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> words[i];
        }

        cin >> m;
        
        for(int i = 0; i < m; i++) {
            string rule;
            cin >> rule;

            if(!rule.empty()) cout << "--" << endl;

            update_password(0, rule, words, password);
            if(i < m -1) cout << endl;
        }
        if(!cin.eof()) cout << endl;
    }

    return 0;
}