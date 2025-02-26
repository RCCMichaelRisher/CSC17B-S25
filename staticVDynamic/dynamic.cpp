
#include <iostream>

using namespace std;

int main(){
    int size;
    cout << "what size do you want" << endl;
    cin >> size;
    //once we have the size we can allocate the array
    int *array = new int[size];

    for( int i = 0; i < size; i++ ){
        array[i];
    }

    //frees that memory
    delete [] array;
    return 0;


}