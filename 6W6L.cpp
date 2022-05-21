#include <iostream>
#include <ctime>
#include <thread>

using namespace std;

/* function to calculate no. of times a loop has run in n seconds*/
void fun(long long int n,long long int* b){
    
    time_t initial_time = time(0);  // initial time before before the loop starts to run
    time_t current_time;            // current time which will be updated after every iteration
    time_t time_taken;              // amount of time the loop has run
    
    
    for(long long int i = 0; ; i++){
        current_time = time(0);
        time_taken = current_time - initial_time;
        if(time_taken > n){
            *b = i;
            return ;
        }
    }
}


int main(){
    
    
    long long int count,flag,ans = 0;
    
    /* count is the number of threads you want to use
     i have used long long int so that the value of ans does not overflow the integer limits.
     also for longer time duration,the value of a single thread can exceed integer limits */
    
    cin >> count;
    flag = count;
    
    long long int b[count];  // this array will store the no. of times the loop has run for every thread
    std::thread t[count];
    
    while(count--){
        
        t[count] = std ::thread(fun,1, b+count);
        
    }
    
    /* as the value of count has become 0 so we have to update its value for the second loop to run */
    count = flag;
    
    
    /* waiting for the threads to finsh and then, update the answer */
    while(count--){
        t[count].join();
        ans += b[count];
    }
    
    
    cout << ans << "\n";
    
    return 0;
}
