#include<stdio.h>

int main() {
    int marks[5], grossmarks = 0;
    float percentage;
    int i;

    printf("Enter student's marks for the 5 subjects: ");
    
    for(i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
        grossmarks += marks[i];
    }

    percentage = ((float)grossmarks / 500) * 100;

    printf("Gross marks of the student are: %d\n", grossmarks);
    printf("The percentage of the student is: %.2f\n", percentage);

    return 0;
}
