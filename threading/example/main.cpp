
#include <iostream>

#include <thread> //threading

using namespace std;

void func() {
    cout << "Hello from the thread" << endl;
}

int main(){
    //create a thread
    thread t( func ); //its go time. its started

    t.join(); //waiting for func to finish
    cout << "main thread finished" << endl;

    return 0;


}