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
        token = strtok (NULL, "-,?.");
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
