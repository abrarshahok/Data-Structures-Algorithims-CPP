/*
    Write a C++ program to deletes ITEM from lOC given by user of the array. Print all
    elements of the array.
*/
#include <iostream>
using namespace std;
void delete_element(int [],int,int);
void Display_Array(int [],int);

int main(){
    int n,index;
    cout<<"Enter Size of Array     : ";
    cin>>n;
    int arr[n];
    cout<<"Enter Elements of Array : ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Enter Index : ";
    cin>>index;
    delete_element(arr,n,index);
    Display_Array(arr,n);
}

void delete_element(int arr[],int size,int index){
    cout << "Deleted Element -> "<<arr[index]<<endl;
    for(int i=index; i<size; i++){
        arr[i] = arr[i+1];
    }
}

void Display_Array(int arr[],int size){
    size--;
    cout<<"Elements After Deleting : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}