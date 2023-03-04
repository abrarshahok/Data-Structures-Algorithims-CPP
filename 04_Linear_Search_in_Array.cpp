#include <iostream>
using namespace std;

int search_element(int [],int,int);

int main(){
    int n,element;
    cout<<"Enter Size of Array     : ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of Array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Element to Find its Index : ";
    cin>>element;
    int index = search_element(arr,n,element);
    cout<<"Element is at Index : "<<index<<endl;
}

int search_element(int arr[],int n, int element){
    for(int i=0; i<n; i++){
        if(arr[i]==element){
            return i;
        }
    }
    return 0;
}