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

//3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void uparray(char* ary) {
	for (int i = 0; i < strlen(ary); i++) {
		ary[i] = toupper(ary[i]);
	}
}

int checkSpelling(char* word) {
	FILE* fp = fopen("dict.txt","r");
	char readline[1000];
	int check = 0;
	while (1) {
		fscanf(fp, "%s ", readline);
		if (strcmp(readline,word) == 0) {
			check = 1;
			break;
		}
		if (strcmp(readline, "ZZZ") == 0)
			break;
	}
	return check;
}

int checkFile(char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) 
		return 0;
	else {
		fclose(fp);
		return 1;
	}
}

void main() {	
	char readline[1000];
	char user_file[1000];
	int line = 0;
	printf("Enter a filename: ");
	gets(user_file);
	if (checkFile(user_file) == 0) {
		printf("ERROR: Find not found.\n");
		return 0;
	}
	else {
		FILE* fp = fopen(user_file, "r");
		while (fgets(readline, 1000, fp) != NULL)
		{
			line++;
			char* token;
			token = strtok(readline, " ,.");
			while (token != NULL)
			{
				if (strcmp(token, "\n") != 0) {
					char temp[1000];
					strcpy(temp, token);
					uparray(token);
					if (checkSpelling(token) == 0)
						printf("Line %d: %s\n", line, temp);
				}
				token = strtok(NULL, " ,.\n");
			}
		}
		fclose(fp);
	}
}


// 4
#include <stdio.h>

int main(){

    FILE *fptr;
    char fname[30];
    unsigned char c;

    printf("Enter a filename: ");
    gets(fname);

    fptr = fopen(fname, "r");

    if( fptr == NULL ){
        printf("Error: Cannot open the file.\n");
        return 0;
    }

    while( fread(&c,1,1,fptr) == 1 ){
        printf("%02X ",c);
        for( int i = 0; i < 9; i++){
            fread(&c,1,1,fptr);
            printf("%02X ",c);
        }
        printf("\n");
    }
}


//Q5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COL 128
#define ROW 10

int checkName(char* filename) {
    FILE* inFile;

    inFile = fopen(filename, "r");

    if (inFile == NULL) {
        printf("Error: Cannot open the file to read.\n");

        return 0;
    }
    else
        fclose(inFile);
    return 1;

}

void readFile(char* Filename) {
    FILE* inFile;
    inFile = fopen(Filename, "r");
    unsigned char C;
    unsigned char arr[] = { 0x0A,0x13,0x6F,0x29,0x35,0x18,0x70,0x00,0x03,0x35,0x42,0x73,0x9C,0xAD,0xFA,0x6C,0xAD };

    int count = 0;

    while (fread(&C, 1, 1, inFile)) {
        if (C == arr[count])
        {
            count += 1;
            if (count == 17) {
                printf("Infected\n");
                return;
            }
        }
        else
        {
            count = 0;
            continue;
        }

    }
    printf("Clean\n");
    fclose(inFile);

}


void main() {
    char fileName[1000];

    for (int i = 0; i < 4;i++) {
        printf("Enter the filename: ");
        gets(fileName);

        if (checkName(fileName) == 1) {
            readFile(fileName);
        }
    }
}
