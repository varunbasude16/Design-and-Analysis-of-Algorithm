#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high]; 
    
    
    int i = low - 1; 

    for (int j = low; j < high ; j++) {
      
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    
    return i + 1;
}


void quickSort(vector<int>& arr, int low, int high) {
    
    if (low < high) {
         
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function to print the vector
void printVector(const std::vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> data = {10, 7, 8, 9, 1, 5};
    int n = data.size();

    cout << "Unsorted array: ";
    printVector(data);

    quickSort(data, 0, n - 1);

    cout << "Sorted array:   ";
    printVector(data);

    return 0;
}
