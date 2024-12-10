//Noe Rios, Nicholas Love, Brennan Graham
#include <stdio.h>
// File containing the Mad Libs template
#define FILENAME "madlib1.txt" 
// Maximum length of a word, including the null character
#define MAXWORDLENGTH 20 
//function prototypes
void readMadlib(FILE*, int*, int*, int*);
void readMadlibWords(FILE*, int acounter, char [acounter][MAXWORDLENGTH], int ncounter, char [ncounter][MAXWORDLENGTH], int vcounter, char [vcounter][MAXWORDLENGTH]);
void readMadlibPrint(FILE*, int acounter, char [acounter][MAXWORDLENGTH], int ncounter, char [ncounter][MAXWORDLENGTH], int vcounter, char [vcounter][MAXWORDLENGTH]);
void prompt(int, int cols, char [][cols], char[]);
void resetFilePointer(FILE**);
//main function
int main(){
    //file pointer 
    FILE* madlib;
    //initilazing variables 
    int acounter=0,ncounter=0,vcounter=0;
    // Open the Mad Libs file for reading
    madlib = fopen(FILENAME, "r");
    //check if file is NULL
    if(madlib == NULL){
        // Handle error if the file cannot be opened
        printf("Error\n");
        return 0;
    }
    
    readMadlib(madlib, &acounter, &ncounter, &vcounter);
    // Allocate arrays to hold user inputs
    char awords[acounter][MAXWORDLENGTH], nwords[ncounter][MAXWORDLENGTH], vwords[vcounter][MAXWORDLENGTH];
     // Reopen the file to reset its position 
    resetFilePointer(&madlib);
    //Prompts the user for their words 
    readMadlibWords(madlib, acounter, awords, ncounter, nwords, vcounter, vwords);
    //Reopens the file to reset its position for printing 
    resetFilePointer(&madlib);
    //Replace the placeholders with the users inputs and print the whole madlib 
    readMadlibPrint(madlib, acounter, awords, ncounter, nwords, vcounter, vwords);
    //close the file 
    fclose(madlib);
    return 0;
}
void prompt(int col, int cols, char words[cols][MAXWORDLENGTH], char str[]){
    //promts the user for words and stores it in an array 
    printf("%s", str);
    scanf("%s", words[col]);
}
void readMadlib(FILE* madlib, int* acounter, int* ncounter, int* vcounter){
    char word[MAXWORDLENGTH];
    // Reads the file to count the number of placeholders for adjectives, nouns, and verbs
    while(fscanf(madlib, "%s", word) == 1){
        if(word[0] == 'A' && word[1] == '\0'){
            *acounter += 1;
        }else if(word[0] == 'N' && word[1] == '\0'){
            *ncounter += 1;
        }else if(word[0] == 'V' && word[1] == '\0'){
            *vcounter += 1;
        }
    }
}
void readMadlibWords(FILE* madlib, int acounter, char awords[acounter][MAXWORDLENGTH], int ncounter, char nwords[ncounter][MAXWORDLENGTH], int vcounter, char vwords[vcounter][MAXWORDLENGTH]){
    char word[MAXWORDLENGTH]; int a = 0,n = 0,v = 0;
   // Prompts the user to input words for each placeholder and stores them in respective arrays
    while(fscanf(madlib, "%s", word) == 1){
        if(word[0] == 'A' && word[1] == '\0'){
            //promts for adjective
            prompt(a, acounter, awords, "Please enter an adjective: ");
            a++;
        }else if(word[0] == 'N' && word[1] == '\0'){
            //promts for a noun
            prompt(n, ncounter, nwords, "Please enter a noun: ");
            n++;
        }else if(word[0] == 'V' && word[1] == '\0'){
            //promts for verb 
            prompt(v, vcounter, vwords, "Please enter a verb: ");
            v++;
        }
    }
}
void readMadlibPrint(FILE* madlib, int acounter, char awords[acounter][MAXWORDLENGTH], int ncounter, char nwords[ncounter][MAXWORDLENGTH], int vcounter, char vwords[vcounter][MAXWORDLENGTH]){
    char word[MAXWORDLENGTH]; int a = 0, n = 0, v = 0, check = 0;
    // Reads the file, replaces placeholders with user inputs, and prints the completed Mad Lib
    while(fscanf(madlib, "%s", word) == 1){
        if(word[0] == 'A' && word[1] == '\0'){
            printf("%s", awords[a]);
            a++;
            check = 1;
        }else if(word[0] == 'N' && word[1] == '\0'){
            printf("%s", nwords[n]);
            n++;
            check = 1;
        }else if(word[0] == 'V' && word[1] == '\0'){
            printf("%s", vwords[v]);
            v++;
            check = 1;
        }else if(check == 0){
            printf("%s ", word);
        }else if(check == 1){
            if(word[0] == '.' || word[0] == ',' || word[0] == '!' || word[0] == '?' || word[0] == '"'){
                printf("%s ", word);
            }else {
                printf(" %s ", word);
            }
            check = 0;
        }
    }
    // Print a newline after the final result
    printf("\n");
}
void resetFilePointer(FILE** madlib) {
	fclose(*madlib);                     // Close the current file
	*madlib = fopen(FILENAME, "r");      // Reopen the file
	if (madlib == NULL) {               // Check for errors
        	printf("Error\n");
    }

}
