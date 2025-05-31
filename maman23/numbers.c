#include "numbers.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int num;
    if (argc == 1) { 
        do{
            printf("enter a number: ");
            scanf("%d", &num);
            printf("%s", transcript_numbers(num));
        }while(num != EOF);
    }
    else if (argc == 2) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "Could not open file %s\n", argv[1]);
            return 1;
        }
        while(fscanf(file, "%d", &num) != EOF) {
            printf("%s", transcript_numbers(num));
        }
        fclose(file);
    }else if (argc == 3) {
        FILE *file1 = fopen(argv[1], "r");
        FILE *file2 = fopen(argv[2], "a");
        if (file1 == NULL) {
            fprintf(stderr, "Could not open file %s\n", argv[1]);
            return 1;
        }
        while(fscanf(file1, "%d", &num) != EOF) {
            fprintf(file2, "%s", transcript_numbers(num));
        }
        fclose(file1);
        fclose(file2);
    }
    else {
        printf("too many number of arguments.\n");
        return 1;
    }
    return 0;
}

char* transcript_numbers(int num) {
    static char buffer[50];
    buffer[0] = '\0';
    if(num>11 && num < 20){
        if (num == 10) {
            strcat(buffer, "ten");
        }else if (num == 11) {
            strcat(buffer, "eleven");
        }else if (num == 12) {
            strcat(buffer, "twelve");
        }else if (num == 13) {
            strcat(buffer, "thirteen");
        }else if (num == 14) {
            strcat(buffer, "fourteen");
        }else if (num == 15) {
            strcat(buffer, "fifteen");
        }else if (num == 16) {
            strcat(buffer, "sixteen");
        }else if (num == 17) {
            strcat(buffer, "seventeen");
        }else if (num == 18) {
            strcat(buffer, "eighteen");
        }else if (num == 19) {
            strcat(buffer, "nineteen");
        }
    }else{
        if (num / 10 == 2) {
            strcat(buffer, "twenty ");
        }else if (num / 10 == 3) {
            strcat(buffer, "thirty ");
        }else if (num / 10 == 4) {
            strcat(buffer, "forty ");
        }else if (num / 10 == 5) {
            strcat(buffer, "fifty ");
        }else if (num / 10 == 6) {
            strcat(buffer, "sixty ");
        }else if (num / 10 == 7) {
            strcat(buffer, "seventy ");
        }else if (num / 10 == 8) {
            strcat(buffer, "eighty ");
        }else if (num / 10 == 9) {
            strcat(buffer, "ninety ");
        }
        if(num % 10 == 1) {
            strcat(buffer, "one");
        } else if(num % 10 == 2) {
            strcat(buffer, "two");
        } else if(num % 10 == 3) {
            strcat(buffer, "three");
        } else if(num % 10 == 4) {
            strcat(buffer, "four");
        } else if(num % 10 == 5) {
            strcat(buffer, "five");
        } else if(num % 10 == 6) {
            strcat(buffer, "six");
        } else if(num % 10 == 7) {
            strcat(buffer, "seven");
        } else if(num % 10 == 8) {
            strcat(buffer, "eight");
        } else if(num % 10 == 9) {
            strcat(buffer, "nine");
        }
    }
    if (num == 0) {
        strcat(buffer, "zero");
    }
    strcat(buffer, "\n");
    return buffer;
}