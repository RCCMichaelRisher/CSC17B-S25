
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread> //threading

using namespace std;

mutex coutMutex; //global lock on cout

void func( int s ) {
    for( int i = s; i > 0; i-- ){
        lock_guard<mutex> lock( coutMutex ); //lock cout
        cout << "thread " << i << endl;
    }
}



int main(){
    int s = 5; 
    
    //create a thread
    thread t( func, s ); //its go time. its started

    for( int i = 0; i < s; i++ ){
        lock_guard<mutex> lock( coutMutex ); //lock cout
        cout << "main " << i << endl;
    }
    
    t.join(); //waiting for func to finish
//    t.detach(); //set it free to finish on its own
    cout << "main thread finished" << endl;

    return 0;


}