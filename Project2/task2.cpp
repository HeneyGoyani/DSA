#include <iostream>
using namespace std;

int main()
{
	int num , digits = 0;
	
	cout <<"Enter Any Number :";
	cin >> num;
	
	if(num == 0)
	{
		digits = 1;
	}
	else
	{
		while(num != 0)
		{
			num /= 10;
			digits++;
		}
	}
	
	cout <<"Total Number Of Digits :" << digits ;
	return 0;
}