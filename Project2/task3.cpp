#include<iostream>
using namespace std;

int main() {
    int num,last,first,sum=0;
    
    cout << "ENTER ANY NUMBER: ";
    cin >> num;
    
    last = num % 10;
	
	while(num>=10)
	{
		num=num/10;
	}
	first = num;
	
	sum = last + first;
    
    cout << "SUM OF DIGITS: " << sum << endl;
    
    return 0;
}