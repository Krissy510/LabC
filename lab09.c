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
