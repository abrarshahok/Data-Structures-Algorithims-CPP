#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct myArray{
    int total_size;
    int used_size;
    int* ptr;
}myArray;

void create_array(myArray *p, int t_size, int u_size){
    p->total_size=t_size;
    p->used_size=u_size;
    p->ptr = new int;
}

void set_array_element(myArray *s){
    for(int i=0; i<s->used_size; i++){
        cout<<"Enter Element No "<<i<<" : ";
        cin>>s->ptr[i];
    }
}

void show_array(myArray *s){
    cout<<"Elements are : ";
    for(int i=0; i<s->used_size; i++){
        cout<<s->ptr[i]<<" ";
    }
    cout<<endl;
}

void delete_element(myArray *s, int index){
    for(int i=index; i<s->used_size; i++){
        s->ptr[i] = s->ptr[i+1];
    }
    s->used_size--;
}

void insert_element(myArray *s, int index, int element){
    s->used_size++;
    for(int i=s->used_size-1; i>=index; i--){
        s->ptr[i+1] = s->ptr[i];
    }
    s->ptr[index] = element;
}

void find_element(myArray *s, int element){
    int low,mid,high;
    low  = 0;
    high = s->used_size-1;
    while (low<=high){
        mid = (low+high)/2;
        if (s->ptr[mid] == element){
            cout<<"Found at Index : "<<mid<<endl;
            return;
        }
        if (s->ptr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<"Not Found"<<endl;
}

int main(){
    system("clear");
    myArray marks;
    int t_size=10,u_size=5;
    create_array(&marks,t_size,u_size);
    set_array_element(&marks);
    show_array(&marks);
    delete_element(&marks,1);
    show_array(&marks);
    insert_element(&marks,1,5);
    show_array(&marks);
    find_element(&marks,4);
}