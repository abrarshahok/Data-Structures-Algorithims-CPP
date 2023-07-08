#include <iostream>
#include <algorithm>
using namespace std;

class ArrayADT
{

public:
    int size;
    int length;
    int *arr;

    void create_array(int);
    void add_elements(int);
    void append(int);
    void insert_at_index(int, int);
    void insert_element_in_sorted_array(int);
    void delete_element(int);
    int isSorted();
    int linear_search(int);
    void linear_search_with_Transposition(int);
    void linear_search_Move_Forward(int);
    int binary_search_deccending(int);
    int binary_search_accending(int);
    int binary_search_rec_accending(int, int, int);
    int binary_search_rec_deccending(int, int, int);
    void search(int);
    void get_element(int);
    void set_element(int, int);
    int get_max();
    int get_min();
    int get_sum();
    int get_sum_rec(int);
    double get_avg();
    double get_avg_rec(int);
    void reverse();
    void reverse_using_2nd_Array();
    void left_shift();
    void right_shift();
    void left_rotate();
    void right_rotate();
    void negative_on_left_side();
    ArrayADT merge(ArrayADT *, ArrayADT *);
    ArrayADT set_union(ArrayADT *, ArrayADT *);
    ArrayADT set_intersection(ArrayADT *, ArrayADT *);
    ArrayADT set_difference(ArrayADT *, ArrayADT *);
    void display_elements();
};

void ArrayADT::create_array(int s)
{
    size = s;
    length = 0;
    arr = new int[size];
}

void ArrayADT::add_elements(int n)
{
    if (n > size)
    {
        cout << "Elements should be less than size of Array!" << endl;
        return;
    }

    if (length == size)
    {
        cout << "Array is Full!" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i + 1 << " : ";
        cin >> arr[i];
    }
    length = n;
}

void ArrayADT::append(int ele)
{
    if (length == size)
    {
        cout << "Array is Full!" << endl;
        return;
    }
    if (length < size)
    {
        arr[length] = ele;
        length++;
    }
}

void ArrayADT::insert_at_index(int ele, int index)
{
    if (index < 0)
    {
        cout << "Index Should be >= 0 " << endl;
        return;
    }
    if (index > size)
    {
        cout << "Out of the Size!" << endl;
        return;
    }
    for (int i = length; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = ele;
    length++;
}

void ArrayADT::insert_element_in_sorted_array(int element)
{
    if (isSorted() == 1)
    {
        for (int i = length - 1; i >= 0; i--)
        {
            if (arr[i] > element)
            {
                arr[i + 1] = arr[i];
            }
            else if (arr[i] <= element)
            {
                arr[i + 1] = element;
                break;
            }
        }
        length++;
    }

    else if (isSorted() == 2)
    {
        for (int i = length - 1; i >= 0; i--)
        {
            if (arr[i] < element)
            {
                arr[i + 1] = arr[i];
            }
            else if (arr[i] >= element)
            {
                arr[i + 1] = element;
                break;
            }
        }
        length++;
    }
}

void ArrayADT::delete_element(int index)
{
    if (index < 0 || index >= length)
    {
        cout << "Invalid Index!" << endl;
        if (index > size)
        {
            cout << "Out of the Size!" << endl;
        }
        return;
    }
    for (int i = index; i < length - 1; i++)
    {
        arr[index] = arr[i + 1];
    }
    length--;
}

int ArrayADT::linear_search(int key)
{

    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {

            return i;
        }
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ArrayADT::linear_search_with_Transposition(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            swap(arr[i], arr[i - 1]);
            cout << key << " found at index " << i - 1 << endl;
            return;
        }
    }
    cout << key << " not found!" << endl;
}

void ArrayADT::linear_search_Move_Forward(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            swap(arr[i], arr[0]);
            cout << key << " found at index " << 0 << endl;
            return;
        }
    }
    cout << key << " not found!" << endl;
}

int ArrayADT::binary_search_accending(int key)
{
    int low = 0;
    int high = length;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }

        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int ArrayADT::binary_search_deccending(int key)
{
    int low = 0;
    int high = length;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }

        else if (key > arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int ArrayADT::binary_search_rec_accending(int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return binary_search_rec_accending(l, mid - 1, key);
        else
            return binary_search_rec_accending(mid + 1, h, key);
    }
    return -1;
}

int ArrayADT::binary_search_rec_deccending(int l, int h, int key)
{
    int mid;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            return binary_search_rec_deccending(l, mid - 1, key);
        else
            return binary_search_rec_deccending(mid + 1, h, key);
    }
    return -1;
}

int ArrayADT::isSorted()
{
    int check = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            check++;
        }
    }
    if (check == 0)
        return 1;
    else if (check == length - 1)
        return 2;
    return 0;
}

void ArrayADT::search(int key)
{
    if (isSorted() == 1)
    {
        cout << "Array is Sorted in Accending Order\nDoing Binary Search" << endl;
        binary_search_accending(key);
    }

    else if (isSorted() == 2)
    {
        cout << "Array is Sorted in Descending Order\nDoing Binary Search" << endl;
        binary_search_deccending(key);
    }
    else
    {
        cout << "Array is Unsorted\nDoing Linear Search" << endl;
        linear_search(key);
    }
}

void ArrayADT::get_element(int index)
{
    if (index >= 0 || index < length)
    {
        cout << "Element at index " << index << " is " << arr[index] << endl;
        return;
    }
    cout << "Invalid Index" << endl;
}

void ArrayADT::set_element(int index, int element)
{
    if (index >= 0 || index < length)
    {
        arr[index] = element;
        return;
    }
    cout << "Invalid Index" << endl;
}

int ArrayADT::get_max()
{
    int max = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int ArrayADT::get_min()
{
    int min = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int ArrayADT::get_sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int ArrayADT::get_sum_rec(int n)
{
    if (n < 0)
        return 0;
    return arr[n] + get_sum_rec(n - 1);
}

double ArrayADT::get_avg()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += arr[i];
    }
    return (total / (double)length);
}

double ArrayADT::get_avg_rec(int n)
{
    static int total = 0;
    if (n < 0)
        return (total / (double)length);
    total += arr[n];
    return get_avg_rec(n - 1);
}

void ArrayADT::reverse()
{
    // Method 1
    for (int i = 0; i < length / 2; i++)
    {
        swap(arr[i], arr[length - i - 1]);
    }

    // Method 2
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}

void ArrayADT::reverse_using_2nd_Array()
{
    int *temp = new int[length];

    // Reverse Copying Method 1
    // for (int i = length - 1; i >= 0; i--)
    //     temp[length - i - 1] = arr[i];

    // Reverse Copying Method 2
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
        temp[j] = arr[i];

    for (int i = 0; i < length; i++)
        arr[i] = temp[i];
}

void ArrayADT::left_shift()
{
    for (int i = 0; i < length; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[length - 1] = 0;
}

void ArrayADT::left_rotate()
{
    for (int i = 0; i < length; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[length - 1] = arr[-1];
}

void ArrayADT::right_shift()
{
    for (int i = length - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = 0;
}

void ArrayADT::right_rotate()
{
    for (int i = length - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = arr[length];
}

void ArrayADT::negative_on_left_side()
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        while (arr[i] < 0)
            i++;
        while (arr[j] >= 0)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
}

ArrayADT ArrayADT::merge(ArrayADT *arr1, ArrayADT *arr2)
{
    ArrayADT newArray;
    newArray.length = arr1->length + arr2->length;
    newArray.arr = new int[newArray.length];

    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->arr[i] < arr2->arr[j])
            newArray.arr[k++] = arr1->arr[i++];
        else
            newArray.arr[k++] = arr2->arr[j++];
    }

    while (i < arr1->length)
        newArray.arr[k++] = arr1->arr[i++];
    while (j < arr2->length)
        newArray.arr[k++] = arr2->arr[j++];

    return newArray;
}

ArrayADT ArrayADT::set_union(ArrayADT *set1, ArrayADT *set2)
{
    ArrayADT newArray;
    newArray.length = set1->length + set2->length;
    newArray.arr = new int[newArray.length];

    int i = 0, j = 0, k = 0;
    while (i < set1->length && j < set2->length)
    {
        if (set1->arr[i] < set2->arr[j])
            newArray.arr[k++] = set1->arr[i++];
        else if (set1->arr[i] > set2->arr[j])
            newArray.arr[k++] = set2->arr[j++];
        else
        {
            newArray.arr[k++] = set1->arr[i++];
            j++;
        }
    }

    while (i < set1->length)
        newArray.arr[k++] = set1->arr[i++];
    while (j < set2->length)
        newArray.arr[k++] = set2->arr[j++];

    newArray.length = k;
    return newArray;
}

ArrayADT ArrayADT::set_intersection(ArrayADT *set1, ArrayADT *set2)
{
    ArrayADT newArray;
    newArray.length = set1->length + set2->length;
    newArray.arr = new int[newArray.length];

    int i = 0, j = 0, k = 0;
    while (i < set1->length && j < set2->length)
    {
        if (set1->arr[i] == set2->arr[j])
        {
            newArray.arr[k++] = set1->arr[i++];
        }
        j++;
    }

    newArray.length = k;
    return newArray;
}

ArrayADT ArrayADT::set_difference(ArrayADT *set1, ArrayADT *set2)
{
    ArrayADT newArray;
    newArray.length = set1->length;
    newArray.arr = new int[newArray.length];

    sort(set1->arr, set1->arr + set1->length);
    sort(set2->arr, set2->arr + set2->length);

    int i = 0, j = 0, k = 0;

    while (i < set1->length && j < set2->length)
    {
        if (set1->arr[i] < set2->arr[j])
            newArray.arr[k++] = set1->arr[i++];
        else if (set1->arr[i] > set2->arr[j])
            j++;

        else
        {
            i++;
            j++;
        }
    }

    while (i < set1->length)
    {
        newArray.arr[k++] = set1->arr[i++];
    }

    newArray.length = k;
    return newArray;
}

void ArrayADT::display_elements()
{
    if (length == 0)
    {
        cout << "Array is Empty!" << endl;
        return;
    }
    cout << "Elements: ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size = 5, n = 5;
    // arr->create_array(size);
    // arr->add_elements(n);

    // arr->insert_at_index(8, 6);
    // arr->append(5);
    // arr->delete_element(6);
    // arr->display_elements();
    // arr->linear_search_with_Transposition(4);
    // arr->linear_search_Move_Forward(4);
    // arr->linear_search(4);
    // arr->binary_search_deccending(4);
    // arr->search(4);
    // cout << arr->binary_search_rec_deccending(0, n, 4) << endl;
    // arr->get_element(4);
    // cout << "Maximum: " << arr->get_max() << endl;
    // cout << "Minimum: " << arr->get_min() << endl;
    // cout << "Sum: " << arr->get_sum() << endl;
    // cout << "Sum: " << arr->get_sum_rec(n) << endl;
    // cout << "Avg: " << arr->get_avg() << endl;
    // cout << "Avg: " << arr->get_avg_rec(n) << endl;
    // arr->display_elements();
    // arr->reverse();
    // arr->reverse_using_2nd_Array();
    // arr->left_shift();
    // arr->right_shift();
    // arr->left_rotate();
    // arr->right_rotate();
    // arr->insert_element_in_sorted_array(3);
    // arr->insert_element_in_sorted_array(7);
    // arr->negative_on_left_side();
    // ArrayADT *arr1 = new ArrayADT();
    // ArrayADT *arr2 = new ArrayADT();
    // ArrayADT arr3;
    // arr1->create_array(size);
    // arr2->create_array(size);
    // arr1->add_elements(n);
    // arr2->add_elements(n);
    // arr3 = arr3.merge(arr1, arr2);
    // arr3.display_elements();
    ArrayADT *set1 = new ArrayADT();
    ArrayADT *set2 = new ArrayADT();
    ArrayADT set3;
    set1->create_array(size);
    set2->create_array(size);
    set1->add_elements(n);
    set2->add_elements(n);

    set3 = set3.set_difference(set1, set2);
    set3.display_elements();
}