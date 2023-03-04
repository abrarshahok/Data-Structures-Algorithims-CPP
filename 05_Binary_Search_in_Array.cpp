#include <iostream>
using namespace std;

int binary_search(int arr[], int element,int size){
    int low,mid,high;
    low  = 0;
    high = size - 1;
    while (low <= high){
        mid = (low+high)/2;
        if (arr[mid] == element){
            return mid;
        }
        if (arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return -1;
}

int main(){
    system("clear");
    int size,element;
    cout<<"Enter Size of Array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter Elements (Sorted) : ";
    for(int i=0; i<size; i++)
        cin>>arr[i];
    
    cout<<"Enter Element to Find its Index : ";
    cin>>element;
    int index = binary_search(arr,element,size);
    if(index < 0 ){
        cout<<"Not Found!"<<endl;
        return 0;
    }
    cout<<"Found at Index : "<<index<<endl;
}