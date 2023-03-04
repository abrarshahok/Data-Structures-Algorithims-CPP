#include <iostream>
using namespace std;

int search_element (int arr[],int index , int size){
    int low,mid,high;
    low = 0;
    high = size - 1;

    while (low <= high){
        mid = (low + high)/2;
        if(arr[mid] == index){
            return arr[index];
        }

        if(arr[mid] < index){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return 0;
}

int main(){
    int key,n = 5;
    int arr[n] = {1,2,3,4,5};
    cout << "Enter Index : ";
    cin >> key;
    int element = search_element(arr,key,n);
    cout<<element<<" is Found at index : "<<key<<endl;
}