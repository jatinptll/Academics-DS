#include<stdio.h>

int main() {
    float distance, dfeet, dmeter, dinches, dcentimeter;

    printf("Enter the distance in km : ");
    scanf("%f", &distance);

    dfeet = distance * 3280.8399;
    dmeter = distance * 1000;
    dinches = distance * 39370.0787;
    dcentimeter = dmeter * 100;

    printf("Distance in feet : %.2f\n", dfeet);
    printf("Distance in meters : %.2f\n", dmeter);
    printf("Distance in inches : %.2f\n", dinches);
    printf("Distance in centimeters : %.2f\n", dcentimeter);

    return 0;
}
