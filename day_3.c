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

    file_ptr = fopen("input.txt", "r");

    while(fgetc(file_ptr) != NULL){
        if()
        memset(numbers, 0, sizeof(numbers)); // Rensar int arrayen för varje rad

        //strtok delar upp en sträng i mindre bitar(tokens), vi säger till den att kör tills du hittar en " " och då pausar den där.
        char* token = strtok(buffer, ")"); //HÄR BLIR TOKEN 25 (första gången)
        
        //Sen går vi in i en while loop som kör på tills vi inte hittar fler giltiga bitar.
        while(token){

            token = strtok(NULL, " "); //Återupptar strtok där vi avslutade, och hittar nästa number! Skulle vi INTE hitta något mer nummer kommer strtok retunera NULL och whileloopen hoppar ut
        }   


    }

    printf("Total safe was: %i", safe);
    fclose(file_ptr);


}