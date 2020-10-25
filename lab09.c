// Q.1.1
#include<stdio.h>
#include<string.h>
#define NUMSTR 7
#define MAXLEN 30

void searchString(char list[NUMSTR][MAXLEN], char query[] ){
    int i;
    char message[MAXLEN];
    strcpy( message, query );
    for( i=0; i<NUMSTR; i++ )
        if( strcmp( list[i], query ) == 0 ) {
        strcat( message, " is in the list.");
        puts( message );
        return;
        }
    strcat( message, " is NOT in the list.");
        puts( message );
}
void main(){
    char nameList[NUMSTR][MAXLEN] = {"Joe", "Jane", "Joe","John","Jim", "Joe", "Jim"};
    puts("\n----------Searching----------");
    searchString( nameList, "Joe");
    searchString( nameList, "Jack");
    searchString( nameList, "Jim");
}

Output:
----------Searching----------
Joe is in the list.
Jack is NOT in the list.
Jim is in the list.

Process finished with exit code 0

//Q.1.2
#include<stdio.h>
#include<string.h>
#define NUMSTR 7
#define MAXLEN 30

int searchString(char list[NUMSTR][MAXLEN], char query[] ){
    int i,count = 0;
    char message[MAXLEN];
    strcpy( message, query );
    for( i=0; i<NUMSTR; i++ )
        if( strcmp( list[i], query ) == 0 ) {
            count++;
        }
    return count;
    strcat( message, " is NOT in the list.");
        puts( message );
}
void main(){
    char nameList[NUMSTR][MAXLEN] = {"Joe", "Jane", "Joe","John","Jim", "Joe", "Jim"};
    puts("\n----------Searching----------");
    printf("Joe:%d\n",searchString( nameList, "Joe"));
    printf("Jack:%d\n",searchString( nameList, "Jack"));
    printf("Jim:%d\n",searchString( nameList, "Jim"));
}

Output:
----------Searching----------
Joe:3
Jack:0
Jim:2

Process finished with exit code 0

//Q.2.1
#include <stdio.h>
#include <string.h>
int main() {
    char str[] ="-Hi, how are you?    -I'm fine. Thank you.";
    char *token;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    token = strtok (str," ,.-");
    while(token != NULL){
        puts(token);
        token = strtok (NULL, "- ,?.");
    }
    return 0;
}

Output:
Splitting string "-Hi, how are you?    -I'm fine. Thank you." into tokens:
Hi
 how are you

I'm fine
 Thank you
 
 //Q.2.2
#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define MAXWORD 10

int count=0;

void splitString(char inStr[MAXLEN],char wordList[MAXWORD][MAXLEN]){
    char *token;
    token = strtok (inStr," ,.-");
    while(token != NULL){
        if (count == 10)
            break;
        sscanf(token, "%s", wordList[count]);
        count++;
        token = strtok (NULL,"- ,?.");
    }
    while (count != 10){
        sscanf("", "%s", wordList[count]);
        count++;
    }
}

int main() {
    char wordList1[MAXWORD][MAXLEN];
    char strd[MAXLEN] ="-Hi, how are you?  -I'm fine. Thank you do .";
    splitString(strd,wordList1);
    for (int i = 0; i < 10; i++){
        printf("%s\n",wordList1[i]);
    }
    return 0;
}

Output:
Hi
how
are
you
I'm
fine
Thank
you
do
∟C♣v`

Process finished with exit code 0

//Q3
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count=0;

int countVowelWord(char inStr[]){
    char temp1[strlen(inStr)],temp2[strlen(inStr)];
    strcpy(temp1, inStr);
    char *token;
    token = strtok (temp1," ,.-");
    while(token != NULL){
        token[0] = tolower(token[0]);
        if(token[0] == 'a' || token[0] == 'e' || token[0] == 'i' || token[0] == 'o' || token[0] == 'u')
            count++;
        token = strtok (NULL,"- ,?.");
    }
    return count;
}
int main() {
    char td[] = "   This is a test input";
    printf("%d\n",countVowelWord(td));
}

//Q4
