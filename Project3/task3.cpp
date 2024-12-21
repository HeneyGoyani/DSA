#include<iostream>
using namespace std;

int main ()
{
    int i, j, k;

    for(i = 5; i >= 1; i--)
    {
        for(k = 5; k > i; k--)
        {
            cout <<" ";
        }
        for(j = 1; j <= i; j++)
        {
            cout << j%2;
        }

        cout << endl;
    }

    return 0;
}