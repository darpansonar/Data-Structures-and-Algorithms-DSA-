#include <iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int left=low+1;
    int right=high;
    while (left <= right) {
        while (left <= high && arr[left] <= pivot) {
            left++;
        }
        while (right >= low && arr[right] > pivot) {
            right--;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[low], arr[right]);
    return right;  
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int piv = partition(arr, low, high);  
        quickSort(arr, low, piv - 1);   
        quickSort(arr, piv + 1, high);  
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];  
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Given array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    quickSort(arr, 0, n-1 );
    
    cout << "\nSorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}