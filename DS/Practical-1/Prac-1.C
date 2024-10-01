#include<stdio.h>

int main()
{
    float salary, grossSalary;

    printf("Enter the employee basic salary : ");
    if (scanf("%f", &salary) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    grossSalary = salary * 1.60;
    printf("The employee gross salary is : %.2f\n", grossSalary);
    
    return 0;
}
