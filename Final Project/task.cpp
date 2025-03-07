#include<iostream>
using namespace std;

struct Element{
	int data;
	Element* next;
};
// linked list
class linkedList {
	private:
		Element* head;
		
	public:
		linkedList() {head = nullptr ;}
		
		void insert(int num) 
		{
		Element* newElement	= new Element {num, nullptr};
		if(!head)
		{
			head = newElement;
		}
		else {
			Element* temp = head;
			while (temp->next) temp = temp->next;
			temp->next = newElement;	
		}
	}
	
	void display()
	{
		Element* temp = head;
		while (temp) {
		cout << temp->data << " -> ";
		temp = temp->next;
		}
		cout << "NULL" << endl;

	}
	
	int* Array (int & size) {
		size = 0;
		Element* temp = head;
		while (temp){
			size++;
			temp = temp->next;
		}
		
	int* arr = new int[size];
	temp = head;
	for (int i = 0; i < size; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }
        return arr;
	}
	
};

// merge & merge sort
void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1, n2 = right - mid;
    int Le[n1], Ri[n2];
    
    for (int i = 0; i < n1; i++) Le[i] = arr [left + 1];
    for (int i = 0; i < n2; i++) Ri[i] = arr [mid + 1 + i];
    
    int i = 0 , j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (Le[i] <= Ri[j]) ? Le[i++] : Ri[j++];
    while (i < n1) arr[k++] = Le[i++];
    while (j < n2) arr[k++] = Ri[j++];
}

 void mergeSort(int arr[], int left ,int right){
 	if(left < right){
 		int mid = left + (right - left) / 2;
 		mergeSort(arr , left , mid);
 		mergeSort(arr , mid + 1 , right);
 		merge(arr , left , mid , right);
	 }
 }
 
 int part(int arr[] ,int small, int big) {
 	int pivot = arr[big], i = small - 1;
    for (int j = small ; j < big ; j++) {
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[big]);
    return i + 1;
 }
//Quick sort
 void quickSort(int arr[] , int small , int big){
 	if(small < big) {
 		int pi = part(arr , small , big);
 		quickSort(arr, small, pi - 1);
 		quickSort(arr , pi + 1 , big);
 		
	 }
 }
// Binary search
 int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void menu()
{
	linkedList list;
	int num , choice;
	
	
	while (true)
	{
		cout << endl << " MENU :" << endl;
		cout << endl;
		cout << "1.Insert Element(linked list)" << endl;
		cout << "2.Display Element(linked list)" << endl;
		cout << "3.Merge Sort" << endl;
		cout << "4.Quick Sort" << endl;
		cout << "5.Binary Search" << endl;
		cout << "6.EXIT" << endl;
		cout << "Enter choice: ";
		cin >> choice ;
		
		if (choice == 1)
		{
			cout << "Enter Number :";
			cin >> num;
			list.insert(num);
		}
		
		else if (choice == 2)
		{
			cout << "Linked List" << endl;
			list.display();
		}
		
		else if (choice == 3 || choice == 4) {
            int size;
            int* arr = list.Array(size);
            if (size == 0) {
                cout << "List is empty!" << endl;
                continue;
            }
            if (choice == 3) mergeSort(arr, 0, size - 1);
            else quickSort(arr, 0, size - 1);
            cout << "Sorted Array: ";
            for (int i = 0; i < size; i++) cout << arr[i] << " ";
            cout << endl;
            delete[] arr;
        }
        
        else if (choice == 5) {
            int size, key;
            int* arr = list.Array(size);
            if (size == 0) {
                cout << "List is empty!!!" << endl;
                continue;
            }
            mergeSort(arr, 0, size - 1);
            cout << "Enter value to search: ";
            cin >> key;
            int index = binarySearch(arr, 0, size - 1, key);
            if (index != -1) cout << "Value found at index " << index << endl;
            else cout << "Value not found!!!" << endl;
            delete[] arr;
        }
        
        else if (choice == 6) break;
        else cout << "Invalid choice!!!" << endl;
	}

}
 

int main () 
{
	menu ();
	return 0;	
}