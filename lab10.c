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

