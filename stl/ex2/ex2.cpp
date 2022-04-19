#include <iostream>
#include <queue>
using namespace std;

bool queue_has_higher_priority_job(queue<int> q, int first_priority) {
    while(!q.empty()) {
        int job_priority = q.front();
        q.pop();
        if(job_priority > first_priority) {
            return true;
        }
    }
    return false;
}

int main(void)
{
    // t     = number of test cases
    // n     = size of input array
    // m     = user job position in the queue
    int t, n, m;
    queue<int> q;

    cin >> t;
    for(int i = 0; i < t; i++){
        int time = 0;

        cin >> n;
        cin >> m;

        // Reads the job queue
        for(int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            q.push(temp);
        }

        // Checks if the user job has higher priority than the rest of the jobs
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            m--;

            // If there is a job with higher priority, the job is added to the queue
            if(queue_has_higher_priority_job(q, temp)){
                q.push(temp);
                if(m == -1) m += q.size();
            }
            else{
                time += 1;
                if(m == -1) printf("%d\n", time);
            }
            
        }
        
    }

    return 0;
}