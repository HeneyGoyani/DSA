#include<iostream>
using namespace std;

int main()
{
	int a[20][20];
	int i,j,n;
	int row,col;
	
	cout << "Enter Row Size : ";
	cin >> row;
	
	cout <<"Enter Column Size : ";
	cin >> col;
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			cout << "Enter Value of a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
	
	n = a[0][0];
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			if(n < a[i][j]) 
            {
                n = a[i][j];
            }
		}
		cout << endl;
	}
	
	cout << "The Largest Element is: " << n << endl;
	
}