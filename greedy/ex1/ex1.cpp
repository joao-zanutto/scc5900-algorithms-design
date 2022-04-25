#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int knights_count, head_counts;

    do{
        priority_queue<int, vector<int>, std::greater<int>> knights, heads;

        cin >> head_counts;
        cin >> knights_count;
        int cost = 0;
        bool lost = false;
        
        // Reads all the heads
        for(int i = 0; i < head_counts; i++){
            int head;
            cin >> head;
            heads.push(head);
        }

        // Reads all the knights
        for(int i = 0; i < knights_count; i++){
            int knight;
            cin >> knight;
            knights.push(knight);
        }

        // Loop through the heads - for each head gets the smallest knight possible
        while(!heads.empty()){
            int head = heads.top();
            heads.pop();
            bool slain = false; // Track if current head has been slain

            // Loop through the knights - looking for the smallest knights available for the head
            while(!knights.empty()){
                int knight = knights.top();
                knights.pop();
                if(knight >= head){
                    slain = true;
                    cost += knight;
                    break;
                }
            }
            
            // If the head has not been slain and there are no knigts available, the game is over
            if(!slain){
                cout << "Loowater is doomed!" << endl;
                lost = true;
                break;
            }
        }

        if(!(head_counts == 0 && knights_count == 0) && !lost) cout << cost << endl;
        
    }while(!(head_counts == 0 && knights_count == 0));
 
    return 0;
}