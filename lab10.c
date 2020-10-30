// 1.3
#include <stdio.h>

int displayFile(char* filename){

    FILE *inFile;
    char a;

    inFile = fopen(filename,"r");

    if( inFile == NULL ){
        printf("Error: Cannot open the file to read.\n");
        return 0;
    }

    while(fscanf(inFile,"%c",&a) != EOF){
        printf("%c",a);
    }
    printf("\n");

    fclose(inFile);
    return 1;
}

void main() {
    displayFile("myData.txt");
}

// 1.4
#include <stdio.h>

int displayFile(char* filename){

    FILE *inFile;
    char a;

    inFile = fopen(filename,"r");

    if( inFile == NULL ){
        printf("Error: Cannot open the file to read.\n");
        return 0;
    }

    while(fscanf(inFile,"%c",&a) != EOF){
        printf("%c",a);
    }
    printf("\n");

    fclose(inFile);
    return 1;
}

int writeFile(char* filename, char* text){

    FILE* outFile;
    outFile = fopen(filename,"w");

    if (outFile == NULL) {
        printf("Error: Cannot open the file to write.\n");
        return 0;
    }

    fprintf(outFile,"%s",text);
    fclose(outFile);
    return 1;
}

void main() {
    char user_text[1000];

    printf("Enter text: ");
    gets(user_text);

    writeFile("newFile.txt", user_text);

    printf("Content of the file after writing:\n");
    displayFile("newFile.txt");
}

//1.5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int displayFile(char* filename) {

    FILE* inFile;
    char a;

    inFile = fopen(filename, "r");

    if (inFile == NULL) {
        printf("Error: Cannot open the file to read.\n");
        return 0;
    }

    while (fscanf(inFile, "%c", &a) != EOF) {
        printf("%c", a);
    }
    printf("\n");

    fclose(inFile);
    return 1;
}

int writeFile_over(char* filename, char* text) {

    FILE* outFile;
    outFile = fopen(filename, "w");

    if (outFile == NULL) {
        printf("Error: Cannot open the file to write.\n");
        return 0;
    }

    fprintf(outFile, "%s", text);
    fclose(outFile);
    return 1;
}

int writeFile_append(char* filename, char* text) {

    FILE* outFile;
    outFile = fopen(filename, "a");

    if (outFile == NULL) {
        printf("Error: Cannot open the file to write.\n");
        return 0;
    }

    fprintf(outFile, "%s", text);
    fclose(outFile);
    return 1;
}

int check_File_exist(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    else {
        return 1;
    }
}

void main() {
    char user_text[1000];
    char file_name[1000];
    int check;

    printf("Enter a filename: ");
    gets(file_name);

    printf("Enter text: ");
    gets(user_text);

    if (check_File_exist(file_name) == 1) {
        printf("File %s already exists.\n", file_name);
        printf("Would you like to append (a) or overwrite (o)? ");
        char choice;
        choice = getchar();
        if (choice == 'a' || choice == 'o') {
            if (choice == 'a') {
                writeFile_append(file_name, user_text);
            }else
                writeFile_over(file_name, user_text);
        }
    }
    else {
        writeFile_over(file_name, user_text);
    }

    printf("Content of the file after writing:\n");
    displayFile(file_name);
}

//2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXCHAR 1000



int check_File_exist(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    else {
        return 1;
    }
}



void main() {
    char property[1000];
    char file_name[1000];
    char read[1000];
    int check;
    char choice[100];

    printf("Enter the name of an INI file: ");//"setting.ini"
    gets(file_name);
    if (check_File_exist(file_name) == 0)
    {
        printf("Error: Cannot open the file.\n");
        return 0;
    }
    while (1)
    {
        FILE* fp = fopen(file_name, "r");
        int check2 = 0;
        check = 0;
        printf("Enter a property name: ");
        gets(property);
        int size = strlen(property);
        while (fgets(read, MAXCHAR, fp) != NULL) {
            if (read[0] != ';' || read[0] != '[') {
                for (int i = 0; i < size; i++) {
                    if (read[i] == property[i]) {
                        check++;
                    }
                }
            }
            if (check == size) {
                check2 = 1;
                size = strlen(read);
                for (int i = check; i < size;i++) {
                    if (read[i] != '=')
                    {
                        printf("%c", read[i]);
                    }
                }
            }
            else if (check != size) {
                check = 0;
            }
        }
        fclose(fp);
        if (check2 == 0) {
            printf("ERROR:PROPERTY NOT FOUND.\n");
        }
        printf("Query another property (y/n): ");
        gets(choice);
        if (choice[0] != '\n') {
            if (choice[0] == 'y')
                printf("\n");
            else if (choice[0] == 'n')
                break;
        }
    }
}