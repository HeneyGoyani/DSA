# include<iostream>
using namespace std;

int main()
{
    int marks;
    char grade;

    cout <<"Enter Your score : ";
    cin >> marks;
    
    grade = (marks >= 90) ? 'A' :
            (marks >= 80) ? 'B' :
            (marks >= 70) ? 'C' :
            (marks >= 60) ? 'D' :
			(marks >= 50) ? 'E' :'F';
            
            
            
            cout <<"Your Grade is : " << grade << endl;
            
            
            switch (grade)
            {
            	case 'A':
            		cout << "Excellent Work..!" << endl;
            		break;
            	case 'B':
            		cout << "Very Well Done..." << endl;
            		break;
            	case 'C':
            		cout << "Good Job.. " << endl;
            		break;
            	case 'D':
            		cout << "Prefect Work!" << endl;
            		break;
            	case 'E':
            		cout << "YOU PASSED, BUT YOU COULD DO BETTER." << endl;
            		break;
            	case 'F':
            		cout << "Sorry..You FAILED!!." << endl;
            		break;
            	default:
            		cout << "INVALID GRADE.." << endl;
            
			}
			
			 if(grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'E')
			 {
			 	cout << "Congratulations! You are eligible for the next Grade!!." << endl;
			 }
			 else
			 {
			 	cout << "Please Try Next Time.." << endl;
			 }
        
        return 0;
}