#include <iostream>
#include <chrono> // Required for measuring time

using namespace std;


long long comparisons = 0;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int k = 1, j, temp;
    while (k < n) {
        temp = arr[k];
        j = k - 1;
        while (j >= 0) {
            comparisons++;
            if (temp <= arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
        k++;
    }
}

//
int arr[10000];

void test(int n) {

    cout << "n = " << n << "\n";
    

    for (int i = 0; i < n; i++) arr[i] = i + 1; // Already sorted
    comparisons = 0;
    
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr, n);
    auto end = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Bubble Sort (Best Case) | Comps: " << comparisons 
         << " | Time: " << duration << " us\n";

    for (int i = 0; i < n; i++) arr[i] = n - i; // Reverse sorted
    comparisons = 0;
    
    start = chrono::high_resolution_clock::now();
    bubbleSort(arr, n);
    end = chrono::high_resolution_clock::now();
    
    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Bubble Sort (Worst Case) | Comps: " << comparisons 
         << " | Time: " << duration << " us\n\n";

    for (int i = 0; i < n; i++) arr[i] = i + 1; // Already sorted
    comparisons = 0;
    
    start = chrono::high_resolution_clock::now();
    insertionSort(arr, n);
    auto endInsert = chrono::high_resolution_clock::now();
    
    duration = chrono::duration_cast<chrono::microseconds>(endInsert - start).count();
    cout << "Insertion Sort (Best Case) | Comps: " << comparisons 
         << " | Time: " << duration << " us\n";

  
    for (int i = 0; i < n; i++) arr[i] = n - i; // Reverse sorted
    comparisons = 0;
    
    start = chrono::high_resolution_clock::now();
    insertionSort(arr, n);
    endInsert = chrono::high_resolution_clock::now();
    
    duration = chrono::duration_cast<chrono::microseconds>(endInsert - start).count();
    cout << "Insertion Sort (Worst Case) | Comps: " << comparisons 
         << " | Time: " << duration << " us\n\n";
}

int main() {
    test(100);
    test(1000);
    test(10000);
    return 0;
}
