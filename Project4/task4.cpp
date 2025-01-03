#include<iostream>
using namespace std;

int main() 
{
    int row, col;

    cout << "Enter The Row: ";
    cin >> row;
    
    cout << "Enter The Column: ";
    cin >> col;

    int a[row][col]; 
    int i, j;

    cout << endl;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            cout << "Enter a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
        cout << endl;
    }

    int r, r_sum = 0;
    cout << "Enter Row Number: ";
    cin >> r;

    for(j = 0; j < col; j++) 
    {
        cout << a[r][j] << " ";
        r_sum += a[r][j];
    }
    
    cout << endl;
    cout << "The Sum of Row " << r << ": " << r_sum << endl;

    
    int c, c_sum = 0;
    cout << "Enter Column Number: ";
    cin >> c;

    for(i = 0; i < row; i++) 
    {
        cout << a[i][c] << " ";
        c_sum += a[i][c];
    }
    cout << endl;
    cout << "THE SUM OF COLUMN " << c << ": " << c_sum << endl;

}