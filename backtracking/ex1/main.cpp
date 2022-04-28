#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

void print(string word, string rule, int value){
    int digit = 0;
    for(int i = 0; i < int(rule.length()); i++){
        if(rule[i] == '0') cout << to_string(value)[digit++];
        else if(rule[i] == '#') cout << word;
    }
    cout << endl;
}

int main(void)
{
        
    while(!cin.eof()) {
        int n;
        cin >> n;
        if(cin.eof()) break;
        
        queue<string> words;
        for(int i = 0; i < n; i++){
            string word;
            cin >> word;
            words.push(word);
        }

        int m;
        cin >> m;

        queue<string> rules;
        for(int i = 0; i < m; i++){
            string rule;
            cin >> rule;
            rules.push(rule);
        }
        
        while(!rules.empty()){
            string rule = rules.front();
            rules.pop();

            if(!rule.empty()){ 
                cout << "--" << endl;
            }

            queue<string> temp_words = words;
            while(!temp_words.empty()){
                string word = temp_words.front();
                temp_words.pop();

                int digits = 0;
                for(int i = 0; i < int(rule.length()); i++){
                    if(rule[i] == '0') digits++;
                }
                int max = pow(10, digits);
                for(int i = 0; i < max; i++){
                    print(word, rule, i);
                }
            }
        }
    } 

    return 0;
}