#include <iostream>
using namespace std;

int main()
{

    // Declaration and initilization of Array
    // int arr[5] = {1, 2, 3, 4, 5};

    // Accessing Array Elements
    // Method 1 for Accessing
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // Method 2 for Accessing
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << i[arr] << " ";
    // }
    // cout << endl;

    // Method 3 for Accessing
    // int *ptr = arr;
    // for (int i = 0; i < 5; i++)
    // {
    //     // cout << ptr[i] << " "; //or
    //     cout << *(ptr++) << " ";
    // }
    // cout << endl;

    /*    Static and Dynamic Array
        1) In Static array size is defined at Compile Time (Memory will be Allocated during runtime)
           In C language size has to be defined at compile time but in C++ we can define size at runtime,
           and both will allocate memory in Stack

        2) In Dynamic array size can be defined at Runtime and it will allocate memory in Heap.
           We can achieve this using pointers First pointer will allocate sapace in stack when it is declared like:
           int *p;  (*p will allocate space in stack) then,
           in C Language = p = (int * ) malloc (5 * sizeof(int));
           in C++ = p = new int[5]; (it will allocate space in heap for 5 integers)
           and p will be pointing to address of all 5 integers

           After Performing Operation we have to free Allocated space to prevent Memory Leak
           in C = free(p);
           in C++ = delete []p; because p is used for array

           Size of Array
           1) Size of Array cannot be changed once it is created
           2) But if you want to change it is possible in other way but it is possible only in heap,
              same array can not be resized but we have alternative for that from which we can increase or decrease
              size of aaray.
    */

    // Create array in heap
    // int *p = new int[5];
    // int arr[5] = {1, 2, 3, 4, 5};
    // p = arr;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << *(p++) << " ";
    // }

    // Increase or Decrease Size of Array
    int *p = new int[5];
    int *q = new int[10];

    // Assign some values in p
    for (int i = 0; i < 5; i++)
        p[i] = i + 1;

    // Copy Elements of p in Large Sized array q
    for (int i = 0; i < 5; i++)
        q[i] = p[i];

    // Now elements are Copied from p to q
    // Now delete p we don't need elemnets of p anymore as they are already in q
    delete[] p;

    // Now Giving Ownership of q to p and Making q = NULL
    p = q;
    q = NULL;

    for (int i = 0; i < 10; i++)
        cout << p[i] << " ";

    cout << endl;
}