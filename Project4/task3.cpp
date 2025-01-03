#include<iostream>
using namespace std;

int main() 
{
    int a[20][20];
     int i, j, n;
    int transpose;

    cout << "Enter Row & Column : ";
    cin >> n;

    cout << "Enter The Elements :";
    cout << endl;
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++) 
        {
            cout << "Enter Value a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }

    for(i = 0; i < n; i++) 
    {
        for(j = i + 1; j < n; j++) 
        {
            transpose = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = transpose;
        }
            cout << endl;
    }


    cout << "Transpose Matrix :";
    cout << endl;
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++) 
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}