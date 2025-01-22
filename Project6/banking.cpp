#include <iostream>
#include <string>
using namespace std;

class BankAcc 
{
	protected :
		string accountNumber;
		string accountholderName;
		double balance;
		
	public :
		BankAcc (string accNumber , string accholderName , double initalBalance )
		: accountNumber(accNumber) , accountholderName(accholderName) , balance(initalBalance) {
		}
	
	void deposit(double amount)
	{
		if (amount < 0)
		{
			balance = balance + amount;
			cout << "Deposited..." << amount << endl;
		}
		else 
		{
			cout << "INVALID....Enter the Valid Amount!! " << endl;
		}	
	}
	
	virtual void withdraw(double amount)
	{
		if(amount <= balance && amount > 0)
		{
			balance = balance - amount;
			cout << "Withdraw :" << amount << endl;	
		}
		else 
		{
			cout << "Invalid Amount!!" << endl;
		}
	}
	
	void displayInfo ()
	{
		cout << " Account Name :" << accountNumber << endl;
		cout << " Account Holder :" << accountholderName <<endl;
		cout << "Balance :" << balance << endl;
	}
	
	virtual void cacluInterest ()
	{
		cout << "NO calculation of interest for this ...." << endl;
	}
	
	 virtual ~BankAcc () {}
};

// Checking Account
class CheckingAccount : public BankAcc{
    double overdraftLimit;

public:
    CheckingAccount(string accNum, string holderName, double initialBalance, double limit)
        : BankAcc(accNum, holderName, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount > 0 && balance - amount >= -overdraftLimit) {
            balance = balance - amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "You Exceeds overdraft limit!" << endl;
        }
    }
};

// Savings Account
class SavingsAccount : public BankAcc{
    double interestRate;

public:
    SavingsAccount(string accNum, string holderName, double initialBalance, double rate)
        : BankAcc(accNum, holderName, initialBalance), interestRate(rate) {}

    void cacluInterest() override {
        double interest = balance * (interestRate / 100);
        cout << "Interest (Savings Account): " << interest << endl;
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAcc{
    int term;  
    double interestRate;

public:
    FixedDepositAccount(string accNum, string holderName, double initialBalance, int termDuration, double rate)
        : BankAcc(accNum, holderName, initialBalance), term(termDuration), interestRate(rate) {}

    void cacluInterest() override {
        double interest = balance * (interestRate / 100) * (term / 12);
        cout << "Interest (Fixed Deposit): " << interest << endl;
    }
};

// Main Function
int main() {
    BankAcc* account = nullptr;
    int choice;

    do {
        cout << "--- Bank Account ---" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Fixed Deposit Account" << endl;
        cout << "3. Create Checking Account" << endl;
        cout << "4. Display Account Info "<< endl;
        cout << "5. Deposit Money "<< endl;
        cout << "6. Withdraw Money" << endl;
        cout << "7. Calculate Interest"<< endl;
        cout << "8. Exit"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string accNumber, holderName;
                double balance, rate;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, holderName);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                account = new SavingsAccount(accNumber, holderName, balance, rate);
                cout << "Savings Account Created.\n";
                break;
            }
            
            case 2: {
                string accNumber, holderName;
                double balance, rate;
                int term;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, holderName);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Term (months): ";
                cin >> term;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                account = new FixedDepositAccount(accNumber, holderName, balance, term, rate);
                cout << "Fixed Deposit Account Created.\n";
                break;
            }
            
            case 3: {
                string accNum, holderName;
                double balance, limit;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, holderName);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                cout << "Enter Overdraft Limit: ";
                cin >> limit;
                account = new CheckingAccount(accNum, holderName, balance, limit);
                cout << "Checking Account Created.\n";
                break;
            }
            
            case 4: {
                if (account) {
                    account->displayInfo();
                } else {
                    cout << "No reation of account.."<< endl;
                }
                break;
            }
            
            case 5: {
                if (account) {
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "No reation of account.."<< endl;;
                }
                break;
            }
            
            case 6: {
                if (account) {
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "No reation of account.."<< endl;
                }
                break;
            }
            
            case 7: {
                if (account) {
                    account->cacluInterest();
                } else {
                    cout << "No creation of account .." << endl;
                }
                break;
            }
            
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!!." << endl;
        }
    } while (choice != 8);

    delete account;
    return 0;
};