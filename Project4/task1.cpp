#include<iostream>
using namespace std;

int main()
{
	int size;
	
	cout << "Enter The Value :" ;
	cin >> size;
	
	int a[size];
	int i;
	
	cout << "ENTER ARRAY'S ELEMENTS :";
	cout << endl;
	for(i = 0; i < size; i++)
	{
		cout << "Enter Element a[" << i << "] = " ;
		cin >> a[i];
	}
	
	cout << endl;
	cout <<"Negative elements from an Array:";
	cout << endl;
	for(i = 0; i < size; i++)
	{
		if(a[i] < 0)
		{
			cout << "Negative Elements are : "<< a[i] <<endl;
		}
	}
	return 0;
}