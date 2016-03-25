// A company pays its employees as managers (who receive a fixed weekly salary),
// hourly workers (who receive a fixed hourly wage for up to the first 40 hours they
// work and "time-and-a-half"1.5 times their hourly wagefor overtime hours worked),
// commission workers (who receive $250 plus 5.7 percent of their gross weekly sales),
// or pieceworkers (who receive a fixed amount of money per item for each of the
// items they produce - each pieceworker in this company works on only one type of
// item). Write a program to compute the weekly pay for each employee. You do not
// know the number of employees in advance. Each type of employee has its own pay
// code: Managers have code 1, hourly workers have code 2, commission workers have
// code 3 and pieceworkers have code 4. Use a switch to compute each employee's pay
// according to that employee's paycode. Within the switch, prompt the user (i.e., the
// payroll clerk) to enter the appropriate facts your program needs to calculate each
// employee's pay according to that employee's paycode. 



#include <iostream>
using namespace std;

int main()

{
    int paycode;
    double managerWeeklySalary;
    double totalSalary=0;
    double hourlyPayRate;
    int hoursWorked;
    double grossSales;
    int itemsProduced;
    double itemCost;
    
    

    
    cout << "Please enter the paycode for the worker or -1 to exit: ";
    cin >> paycode;
    
    while ( paycode != -1)
    {
        switch (paycode)
        
        {
            case 1:
                cout << "Enter fixed weekly salary for the manager: ";
                cin >> managerWeeklySalary;
                totalSalary = managerWeeklySalary;
                break;
            
            case 2:
                cout << "Enter hours worked by the hourly worker: ";
                cin >> hourlyPayRate;
                cout << "Enter fixed hourly wage for the worker: ";
                cin >> hoursWorked;
                if (hoursWorked > 40)
                    totalSalary = (hourlyPayRate * 1.5) * hoursWorked;
                else
                    totalSalary = hourlyPayRate * hoursWorked;
                break;
                
                
            case 3:
                cout << "Enter gross sales of the comission worker:  ";
                cin >> grossSales;
                totalSalary= 250 + (0.057* grossSales);
                break;
                
            case 4:
                cout << "Enter number of items produced by the piece worker: ";
                cin >> itemsProduced;
                cout << "Enter fixed wage for the item: ";
                cin >> itemCost;
                totalSalary= itemsProduced * itemCost;
                break;
            
            default:
                cout << "Invalid input!!!Please try again";
                break;
       
        }
    
        cout << "The total weekly pay is $" << totalSalary << endl;
        cout << "Please enter the paycode for the worker or -1 to exit: ";
        cin >> paycode;
    }

    
    
    
    
}
