#include <stdio.h>

int main() {
    int fiveDigitNo, sum = 0;
    int fnumber[5];
    printf("Enter any 5-digit number: ");
    scanf("%d", &fiveDigitNo);    
    for (int i = 4; i >= 0; i--) {
        fnumber[i] = (fiveDigitNo % 10) - 1;
        if (fnumber[i] < 0) {  
            fnumber[i] = 9;
        }
        fiveDigitNo /= 10;
    }
    printf("Number with each digit decremented by 1 is: ");
    for (int i = 0; i < 5; i++) {
        printf("%d", fnumber[i]); 
    }

    return 0;
}
