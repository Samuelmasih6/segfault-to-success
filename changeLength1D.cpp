#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;

class illegalParameterValue : public logic_error {
public:
    illegalParameterValue(const string& message)
        : logic_error(message) {}
};


template <typename T>
void changeLength1D(T*& a, int oldlength, int newlength)
{
    if(newlength < 0)
    throw illegalParameterValue("new length must be >=0");

    T* temp = new T[newlength]; //Allocates a new dynamic array of type T with size newlength.
    int number = min(oldlength,newlength); // min return minimum value
    copy(a,a + number, temp); //copy is used to copy elements from the old array a into the new array temp.
    //Equivalent to a for loop:
    // for(int i=0; i<number; i++) 
    // temp[i] = a[i];
    delete [] a;
    a = temp;
}
int main() {
    int* arr = new int[3]{10, 20, 30};
    int oldLen = 3;
    int newLen = 5;

    changeLength1D(arr, oldLen, newLen);

    // Now arr has size 5: [10, 20, 30, 0, 0]
    for(int i=0; i<newLen; i++)
        std::cout << arr[i] << " ";
}
