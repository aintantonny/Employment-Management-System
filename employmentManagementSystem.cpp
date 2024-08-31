#include <iostream>
#include <iomanip>

using namespace std;

// Global Variables for Employee
int employeeId[100];
string employeeName[100];
float employeeSalary[100];

// Count number of employees
int employeeCount = 0;

// Display Menu
void displayMenu(){
    cout << "=======| Employee Management System |=======" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Update Employee" << endl;
    cout << "3. Delete Employee" << endl;
    cout << "4. Sort Employees By Salary (Ascending)" << endl;
    cout << "5. Display all Employees" << endl;
    cout << "0. Exit" << endl;
    cout << "============================================" << endl;
    cout << "Enter your option: ";
}

// Add Employee
void addEmployee(){
    system("cls");
    cout << "=======| Add Employee |=======" << endl;
    // auto increment employee id
    employeeId[employeeCount] = employeeCount + 1;
    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, employeeName[employeeCount]);
    cout << "Enter Employee Salary: ";
    cin >> employeeSalary[employeeCount];
    employeeCount++;
    cout << "Employee Added Successfully!" << endl;
}

// Update Employee
void updateEmployee() {
    system("cls");
    cout << "=======| Update Employee |=======" << endl;
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;
    if(id <= 0 || id > employeeCount) {
        cout << "Invalid Employee ID!" << endl;
    } else {
        int index = id - 1;
        cout << "Enter New Name: ";
        cin.ignore();
        getline(cin, employeeName[index]);
        cout << "Enter New Salary: ";
        cin >> employeeSalary[index];
        cout << "Employee Updated Successfully!" << endl;
    }
}

// Delete Employee
void deleteEmployee() {
    system("cls");
    cout << "=======| Delete Employee |=======" << endl;
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;
    if(id <= 0 || id > employeeCount) {
        cout << "Invalid Employee ID!" << endl;
    } else {
        int index = id - 1;
        for(int i = index; i < employeeCount - 1; i++) {
            employeeId[i] = employeeId[i + 1];
            employeeName[i] = employeeName[i + 1];
            employeeSalary[i] = employeeSalary[i + 1];
        }
        employeeCount--;
        cout << "Employee Deleted Successfully!" << endl;
    }
}

// Sort Employees by Salary (Ascending)
void sortEmployeesBySalary() {
    system("cls");
    cout << "=======| Sort Employees By Salary |=======" << endl;
    for(int i = 0; i < employeeCount; i++) {
        for(int j = 0; j < employeeCount - 1; j++) {
            if(employeeSalary[j] > employeeSalary[j + 1]) {
                // Swap salaries
                float tempSalary = employeeSalary[j];
                employeeSalary[j] = employeeSalary[j + 1];
                employeeSalary[j + 1] = tempSalary;

                // Swap IDs
                int tempId = employeeId[j];
                employeeId[j] = employeeId[j + 1];
                employeeId[j + 1] = tempId;

                // Swap names
                string tempName = employeeName[j];
                employeeName[j] = employeeName[j + 1];
                employeeName[j + 1] = tempName;
            }
        }
    }
    cout << "Employees Sorted by Salary in Ascending Order!" << endl;
}

// Display all Employees
void displayAllEmployee(){
    system("cls");
    cout << "=======| Display All Employees |=======" << endl;
    cout << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Salary" << endl;
    for(int i = 0; i < employeeCount; i++){
        cout << setw(5) << employeeId[i] << setw(20) << employeeName[i] << setw(10) << employeeSalary[i] << endl;
    }
    cout << "Total Employees: " << employeeCount << endl;
}

int main(){
    system("cls");

    int option;
    do{
        displayMenu();
        cin >> option;
        switch(option){
            case 1:
                addEmployee();
                break;
            case 2:
                updateEmployee();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                sortEmployeesBySalary();
                break;
            case 5:
                displayAllEmployee();
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid Option! Please try again." << endl;
        }
    }while(option != 0);

    return 0;
}
