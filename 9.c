#include <stdio.h>
#include <stdlib.h>

int sum_of_digits(int number) {
    int total_sum = 0;
    while (number > 0) {
        total_sum += number % 10;  // Add the last digit to the total_sum
        number /= 10;              // Remove the last digit from the number
    }
    return total_sum;
}

int main() {
    char input[12];  // Buffer to store user input, allowing for up to 10 digits plus newline and null terminator
    int number;
    
    while (1) {
        printf("Please enter a positive integer (1 to 10 digits): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Check if the input is a valid integer
            if (sscanf(input, "%d", &number) == 1 && number > 0) {
                // Check if the number has between 1 and 10 digits
                if (number <= 9999999999) {
                    int result = sum_of_digits(number);
                    printf("The sum of the digits of %d is %d.\n", number, result);
                    break;
                } else {
                    printf("Invalid input. Please enter a positive integer with one to ten digits.\n");
                }
            } else {
                printf("Invalid input. Please enter a valid positive integer.\n");
            }
        } else {
            printf("Error reading input. Please try again.\n");
        }
    }
    
    return 0;
}
