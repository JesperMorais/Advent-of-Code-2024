#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    The levels are either all increasing or all decreasing.
    Any two adjacent levels differ by at least one and at most three.
*/

void main(int arg, char *argv[])
{
    FILE *file_ptr;
    char buffer[256];
    // Checks distance
    int safe = 0;

    // Array to store the parsed integers 
    int numbers[50];
    int count = 0;

    bool isSafe = false;
    bool increase = false;

    file_ptr = fopen("input.txt", "r");

    while(fgets(buffer, sizeof(buffer), file_ptr) != NULL){
        count = 0; // Resetar count för varje rad
        memset(numbers, 0, sizeof(numbers)); // Rensar int arrayen för varje rad

        //strtok delar upp en sträng i mindre bitar(tokens), vi säger till den att kör tills du hittar en " " och då pausar den där.
        char* token = strtok(buffer, " "); //HÄR BLIR TOKEN 25 (första gången)
        
        //Sen går vi in i en while loop som kör på tills vi inte hittar fler giltiga bitar.
        while(token){
            numbers[count++] = atoi(token); //Gör om 25 (SOm är en sträng till int) och sedan slänger in den i en int array som vi kan jobba med
            token = strtok(NULL, " "); //Återupptar strtok där vi avslutade, och hittar nästa number! Skulle vi INTE hitta något mer nummer kommer strtok retunera NULL och whileloopen hoppar ut
        }   

        //Kollar om det är en increase eller inte
        if(numbers[0] > numbers[1]){
            increase = false;
        }else{
            increase = true;
        }

        isSafe = true;
        for (int i = 0; i < count - 1; i++)
        {
            int temp = numbers[i + 1] - numbers[i];

            //Kollar om det är inrease eller decrease och gemför därefter
            if ((increase && (temp < 1 || temp > 3)) || (!increase && (temp > -1 || temp < -3)))
            {
                printf("between %i and %i\n", numbers[i], numbers[i + 1]);
                isSafe = false;
                break;
            }
        }
        
        if(isSafe){
            safe += 1;
        }

        printf("\n");
    }

    printf("Total safe was: %i", safe);
    fclose(file_ptr);


}