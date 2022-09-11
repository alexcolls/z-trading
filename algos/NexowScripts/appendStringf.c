
#include <nexow.h> 

string arr[10];

void appendString( string *array, string str ){

    int i = 0;
    while( TRUE ){
        if( array[i] == NULL )
            break;
        i++;       
    }
    array[i] = strf("%c%c%c%c%c%c%c%c%c%c");
    strcpy(array[i], str);

}

void printstrarr( string *array, int startidx, int endidx ){
    int i = startidx;
    for( i = 0; i < endidx; i++ ){
        if( array[i] == NULL )
			break;
        printf("\n%s",array[i]);
    }
}


int main(){

    arr[0] = "A";
    arr[1] = "A";
    arr[2] = "B";
    arr[3] = "C";

    appendString(arr, "C" );

    printstrarr(arr,1,4);

    

}




