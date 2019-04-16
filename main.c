#include <stdio.h>

int fileOpen();

int main() {
    
    fileOpen();
    
	return 0;
	
}

int fileOpen(){
    
    FILE *input;
    
    input = fopen("input.txt", "r");
    
    if(input == NULL){
        printf("the file was not opened");
    }
    else{
        printf("the file was opened");
    }
    
    return(0);
    
}