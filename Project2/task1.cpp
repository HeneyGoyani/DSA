#include<iostream>
using namespace std;

int main() 
{
    char ch = 'a';
    
    do {
        cout << ch << " \t";
        ch = ch + 4;
    } while(ch <= 'z');
    
    return 0;
}