#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Sorter {
public:
    virtual void sort(int arr[], int n) = 0;
};

// Bubble Sort
class BubbleSort : public Sorter{
public:
    void sort(int arr[], int n) override{
        int i, j;
        for (i = 0; i < n-1; i++)
        {
            for (j = 0; j < n-i-1; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};

//Insertion Sort
class InsertionSort : public Sorter{
public:
    void sort(int arr[], int n) override{
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
};

//Quick Sort
class QuickSort : public Sorter {
public:
    void sort(int arr[], int n) override {
        quickSort(arr, 0, n-1);
    }

private:
    void quickSort(int arr[], int left, int right) {
        if (left < right) {
            int pivot = partition(arr, left, right);
            quickSort(arr, left, pivot-1);
            quickSort(arr, pivot+1, right);
        }
    }

    int partition(int arr[], int left, int right) {
        int pivot = arr[right];
        int i = left-1;
        for (int j = left; j < right; ++j) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[right]);
        return i+1;
    }
};

//Selection Sort
class SelectionSort : public Sorter {
public:
    void sort(int arr[], int n) override {
        for (int i = 0; i < n-1; ++i) {
            int min_val = i;
            for (int j = i+1; j < n; ++j) {
                if (arr[j] < arr[min_val]) {
                    min_val = j;
                }
            }
            swap(arr[i], arr[min_val]);
        }
    }
};

// Merge Sort
class MergeSort : public Sorter {
public:
    void sort(int arr[], int n) override {
        int tempArr[n];
        mergeSort(arr, tempArr, 0, n-1);
    }

private:
    void mergeSort(int arr[], int tempArr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            //recursion
            mergeSort(arr, tempArr, left, mid);
            mergeSort(arr, tempArr, mid+1, right);
            
            merge(arr, tempArr, left, mid, right);
        }
    }

    void merge(int arr[], int tempArr[], int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = left;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                tempArr[k] = arr[i];
                i++;
            } else {
                tempArr[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            tempArr[k] = arr[i];
            i++;
            k++;
        }
        while (j <= right) {
            tempArr[k] = arr[j];
            j++;
            k++;
        }
        for (int p = left; p <= right; p++) {
            arr[p] = tempArr[p];
        }
    }
};

//Printing Sorted Array
void printArray(int arr[], const string sortName, int n) {
    cout << sortName << ": [";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n-1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    // create an array to sort
    int arr[] = {9, 3, 2, 1, 8, 7, 6, 5};
    int N = sizeof(arr)/sizeof(arr[0]);

    // create instances of the sorters
    BubbleSort bubbleSort ;
    InsertionSort insertionSort;
    QuickSort quickSort;
    SelectionSort selectionSort;
    MergeSort mergeSort;

    // sort the array using each sorter
    bubbleSort.sort(arr,N);
    printArray(arr, "Bubble Sort", N);
    
    insertionSort.sort(arr, N);
    printArray(arr, "Insertion Sort", N);
    
    quickSort.sort(arr, N);
    printArray(arr, "Quick Sort", N);
    
    selectionSort.sort(arr,N);
    printArray(arr, "Selection Sort", N);
    
    mergeSort.sort(arr, N);
    printArray(arr, "Merge Sort", N);

    

    return 0;
}










