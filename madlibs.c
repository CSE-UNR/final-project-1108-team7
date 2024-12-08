//Noe Rios, Brennan Graham
#include <stdio.h>
#define FILENAME "madlib1.txt" 
#define MAXWORDLENGTH 20

void readMadlib(FILE*, int*, int*, int*);
void readMadlibWords(FILE*, int acounter, char [acounter][MAXWORDLENGTH], int ncounter, char [ncounter][MAXWORDLENGTH], int vcounter, char [vcounter][MAXWORDLENGTH]);
void readMadlibPrint(FILE*, int acounter, char [acounter][MAXWORDLENGTH], int ncounter, char [ncounter][MAXWORDLENGTH], int vcounter, char [vcounter][MAXWORDLENGTH]);
void prompt(int, int cols, char [][cols], char[]);

int main(){
    FILE* madlib;
    int acounter=0,ncounter=0,vcounter=0;
    madlib = fopen(FILENAME, "r");
    if(madlib == NULL){
        printf("Error\n");
        return 0;
    }
    readMadlib(madlib, &acounter, &ncounter, &vcounter);
    char awords[acounter][MAXWORDLENGTH], nwords[ncounter][MAXWORDLENGTH], vwords[vcounter][MAXWORDLENGTH];
    madlib = fopen(FILENAME, "r");
    readMadlibWords(madlib, acounter, awords, ncounter, nwords, vcounter, vwords);
    madlib = fopen(FILENAME, "r");
    readMadlibPrint(madlib, acounter, awords, ncounter, nwords, vcounter, vwords);
    fclose(madlib);
    return 0;
}
void prompt(int col, int cols, char words[cols][MAXWORDLENGTH], char str[]){
    printf("%s", str);
    scanf("%s", words[col]);
}
void readMadlib(FILE* madlib, int* acounter, int* ncounter, int* vcounter){
    char word[MAXWORDLENGTH];
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
    while(fscanf(madlib, "%s", word) == 1){
        if(word[0] == 'A' && word[1] == '\0'){
            prompt(a, acounter, awords, "Please enter an adjective: ");
            a++;
        }else if(word[0] == 'N' && word[1] == '\0'){
            prompt(n, ncounter, nwords, "Please enter a noun: ");
            n++;
        }else if(word[0] == 'V' && word[1] == '\0'){
            prompt(v, vcounter, vwords, "Please enter a verb: ");
            v++;
        }
    }
}
void readMadlibPrint(FILE* madlib, int acounter, char awords[acounter][MAXWORDLENGTH], int ncounter, char nwords[ncounter][MAXWORDLENGTH], int vcounter, char vwords[vcounter][MAXWORDLENGTH]){
    char word[MAXWORDLENGTH]; int a = 0, n = 0, v = 0, check = 0;
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
    printf("\n");
}
