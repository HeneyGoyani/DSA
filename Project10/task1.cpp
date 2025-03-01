#include<iostream>
#include <vector>

using namespace std;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> leftArr(n1), rightArr(n2);
    
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Linear Search
int linearSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Binary Search
int binarySearch(vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Display Array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}



int main() {
    vector<int> arr;
    int choice, size, key, index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter array\n";
        cout << "2. Selection Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Linear Search\n";
        cout << "5. Binary Search\n";
        cout << "6. Display Array\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter size of array: ";
                cin >> size;
                arr.resize(size);
                cout << "Enter elements: ";
                for (int i = 0; i < size; i++) cin >> arr[i];
                break;
                
            case 2:
                selectionSort(arr);
                cout << "Array sorted using Selection Sort." << endl;
                break;
                
            case 3:
                mergeSort(arr, 0, arr.size() - 1);
                cout << "Array sorted using Merge Sort." << endl;
                break;
                
            case 4:
                cout << "Enter element to search: ";
                cin >> key;
                index = linearSearch(arr, key);
                if (index != -1) 
				{
				cout << "Element found at index " << index << endl;
			    }
                else 
				{
				cout << "Element not found." << endl;
                }
				break;
				
            case 5:
                cout << "Enter element to search: ";
                cin >> key;
                index = binarySearch(arr, key);
                if (index != -1) 
				{
				cout << "Element found at index " << index << endl;
			    }
                else 
				{
				cout << "Element not found..." << endl;
			    }
                break;
                
            case 6:
                cout << "Array: ";
                displayArray(arr);
                break;
                
            case 7:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}