#include <iostream>
using namespace std;

void insert_element(int [],int,int,int);
void Display_Array(int [],int);

int main(){
    int size,element,index;
    cout<<"Enter Size of Array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter Elements of Array : ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"Old Array : ";
    Display_Array(arr,size);
    cout<<"Enter New Element  : ";
    cin>>element;
    cout<<"Enter Index Number : ";
    cin>>index;
    insert_element(arr,size,element,index);
    cout<<"New Array : ";
    Display_Array(arr,size);
}

void insert_element(int arr[],int size, int element, int index){
    if(index >= size){
        cout<<"Array out of the Bound!"<<endl;
        return;
    }
    for(int i=0; i<size; i++){
        arr[index] = element;
    }
}

void Display_Array(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}