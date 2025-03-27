/*
 * EECS 348 7 - C program for Temperature Converison
 * Author: Viren Padarthi
 * Collaborators: None
 * Sources: Lecture slides, w3Schools, VSCode, GeeksforGeeks
 * Created: 3/20/2025
 * Last Modified: 3/26/2025
 */

 #include <stdio.h> // for input/output

 // Conversion formulas
 float c_to_f(float c) { // Celsius to Fahrenheit
     return c * 9.0/5.0 + 32;
 }
 
 float f_to_c(float f) { // Fahrenheit to Celsius
     return (f - 32) * 5.0/9.0;
 }
 
 float c_to_k(float c) { // Celsius to Kelvin
     return c + 273.15;
 }
 
 float k_to_c(float k) { // Kelvin to Celsius
     return k - 273.15;
 }
 
 // Categorize temperature and print advice
 void check_temp(float temp) {
     printf("\n%.2f°C is ", temp);
     if (temp < 0) printf("FREEZING! Wear heavy jacket.\n");
     else if (temp < 10) printf ("Cold. Bundle up!\n");
     else if (temp < 25) printf("Comfortable. Nice weather!\n");
     else if (temp < 35) printf("Hot. Stay hydrated.\n");
     else printf("EXTREME HEAT! Avoid outdoors.\n");
 }
 
 int main() {
     float temp;
     int choice;
     
     while (1) {
         // menu type
         printf("\nTemperature Converter\n");
         printf("1. Fahrenheit to Celsius\n");
         printf("2. Celsius to Fahrenheit\n");
         printf("3. Celsius to Kelvin\n");
         printf("4. Kelvin to Celsius\n");
         printf("5. Fahrenheit to Kelvin\n");
         printf("6. Kelvin to Fahrenheit\n");
         printf("0. EXIT\n");
         printf("Enter choice: ");
         scanf("%d", &choice);
         
         if (choice == 0) break; // Exit condition
         
         printf("Enter temperature: ");//Input temperature from userr
         scanf("%f", &temp);
         
         float converted;
         switch (choice) {
             case 1: // F to C
                 converted = f_to_c(temp);
                 printf("\n%.2f°F = %.2f°C", temp, converted);
                 check_temp(converted);
                 break;
             case 2: // C to F
                 converted = c_to_f(temp);
                 printf("\n%.2f°C = %.2f°F", temp, converted);
                 check_temp(temp);
                 break;
             case 3: // C to K
                 converted = c_to_k(temp);
                 printf("\n%.2f°C = %.2fK", temp, converted);
                 check_temp(temp);
                 break;
             case 4: // K to c
                 if (temp < 0) printf("Kelvin cannot be negative!\n");
                 else {
                     converted = k_to_c(temp);
                     printf("\n%.2fK = %.2f°C", temp, converted);
                     check_temp(converted);
                 }
                 break;
             case 5: // F to K
                 converted = c_to_k(f_to_c(temp));
                 printf("\n%.2f°F = %.2fK", temp, converted);
                 check_temp(f_to_c(temp));
                 break;
             case 6: // K to F
                 if (temp < 0) printf("Kelvin cannot be negative!\n");
                 else {
                     converted = c_to_f(k_to_c(temp));
                     printf("\n%.2fK = %.2f°F", temp, converted);
                     check_temp(k_to_c(temp));
                 }
                 break;
             default:
                 printf("Invalid choice! Try again.\n");
         }
     }
     return 0;
 }