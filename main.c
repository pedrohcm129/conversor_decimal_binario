#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* reverseString(char string[]) {
    int sizeOfString = strlen(string);
    int count = 0;
    char stringAux[sizeOfString];
    for(int i = sizeOfString - 1; i >= 0; i--) {
        stringAux[count] = string[i];
        count++;
    }

    stringAux[count] = '\0';

    return strdup(stringAux);
}


const char* decimalToBinary(float number) {
    int iterations = 6;
    
    char valueIntegerBinary[4] = "";
    char valueFractionalBinary[4] = "";
    char valueBinary[8] = "";
    int integerNumber = number;
    double fractionalNumber = number - integerNumber;

    while(integerNumber) {
        if (integerNumber % 2 == 1)
            strcat(valueIntegerBinary, "1");
        else
            strcat(valueIntegerBinary, "0");
        
        integerNumber /= 2;
    }

    strcat(valueBinary, reverseString(valueIntegerBinary));
    strcat(valueBinary, ".");

    while(iterations) {
        fractionalNumber *= 2;
        iterations--;

        if (fractionalNumber >= 1) {
            strcat(valueFractionalBinary, "1");
            fractionalNumber -= 1;
        }
        else
            strcat(valueFractionalBinary, "0");
    }

    strcat(valueBinary, valueFractionalBinary);

    printf("%s", valueBinary);

    return strdup(valueBinary);
}

int main() {

    // char string[] = "Pedro";
    // reverseString(string);
    // printf("%s", string);
    decimalToBinary(43.25);

    return 0;
}