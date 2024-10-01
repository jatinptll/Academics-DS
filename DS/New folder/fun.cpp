#include <iostream>
using namespace std; 

void printFun(int test) 
{   
    if (test < 1) 
        return; 
    else { 
        cout << test << " ";          // Print the value of test
        printFun(test - 1);           // Recursively call printFun with test - 1
        cout << test << " ";          // Print the value of test again after the recursive call
        return; 
    } 
}

int main() { 
    int test = 3;                     // Example value
    printFun(test);                   // Call the function
    return 0; 
}
