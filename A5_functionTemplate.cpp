/*Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.*/

#include<iostream> 
using namespace std; 

#define MAX 10 
int length; 

template<typename T> 
    void selectionSort(T arr[], int size) { 
    int i, j, minIndex; 
    T temp;

    for(i = 0; i < size - 1; i++) { 
        minIndex = i; 
            for(j = i + 1; j < size; j++) { 
                if(arr[j] < arr[minIndex]) 
                minIndex = j; 
            } 
        temp = arr[i]; 
        arr[i] = arr[minIndex]; 
        arr[minIndex] = temp; 
    } 
} 

int main() { 
    int intArr[MAX]; 
    float floatArr[MAX]; 
    int numInt, numFloat; 

    cout << "Select sort Integer Element" << endl; 

    cout << "Enter how many elements you want: "; 
    cin >> numInt; 
    cout << "Enter the Integer elements:" << endl; 
    for(int i = 0; i < numInt; i++) { 
        cin >> intArr[i]; 
    } 

    cout << "Float Element" << endl; 
    cout << "Enter how many elements you want: "; 
    cin >> numFloat; 
    cout << "Enter the float elements:" << endl; 
    for(int i = 0; i < numFloat; i++) { 
        cin >> floatArr[i]; 
    } 

    selectionSort(intArr, numInt); 
    selectionSort(floatArr, numFloat); 

    cout << "SORTED ELEMENTS\n"; 

    for(int i = 0; i < numInt; i++) { 
        cout << intArr[i] << "\t" << floatArr[i] << endl; 
    } 

return 0; 
}
