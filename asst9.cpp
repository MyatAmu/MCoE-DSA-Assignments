#include <iostream>
using namespace std;

void heapify(int arr[],int n, int i){
    int large = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[large])
        large = left;
    if (right < n && arr[right] > arr [large])
        large = right;
    if (large != i){
        swap (arr[i], arr[large]);
        heapify(arr, n, large);
    }
}

void heapsort (int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i --){
        heapify (arr, n, i);
    }
    for (int i = n - 1; i > 0; i --){
        swap (arr[0], arr[i]);
        heapify (arr, n, 0);
    }
}
int main (){
    cout << "Enter the Size of the Array : ";
    int size;
    cin >> size;

    int arr[size];
    cout << "Enter the Elements in the Array : ";
    for (int i = 0; i < size; i ++)
        cin >> arr[i];

    heapsort (arr, size);

    cout << "Sorted Array is : ";
    for (int i = 0; i < size; i ++)
        cout << arr[i] << " ";
    return 0;
}