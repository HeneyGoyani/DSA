#include<iostream>
using namespace std;

void calculator ()
{
	int a,b,c;
	
	do
	{
		cout << "1.Addition" << endl;
		cout << "2.Subtraction" << endl;
		cout << "3.Multiplication" << endl;
		cout << "4.Division" << endl;
		cout << "5.Modulus" << endl;
		cout << "6.Exit" << endl;
		
		cout << "Enter Your Number :";
		cin  >> c;
		
		if(c>=1 && c<=5)
		{
			cout <<"Enter Any Number:";
			cin  >> a;
			
			cout <<"Enter Any Number:";
			cin  >> b;
		
		
		switch(c)
		{
		  	case 1:
				cout << "Addition is :" << a + b << endl;
				break;
			case 2:
				cout << "Subtraction is :" << a - b << endl;
				break;
			case 3:
     			cout <<"Multiplication is :" << a * b << endl;
				 break;
			case 4:
			    if (b != 0) 
					{
                        cout << "Division is: " << a / b << endl;
                    } else 
					{
                        cout << "Error! Division by zero." << endl;
                    }
			    break;
			case 5:
				cout << "Modulus is :" << a % b << endl;
				break;
		    }
		} else 
		{
			cout << "INVALID NUMBER..." << endl;
			
		}
		
	} while (c!=6);
}

int main ()
{
	calculator();
}