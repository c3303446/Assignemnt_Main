#include <stdio.h>

//include function for each question on project notes where user inputs in a menu system in the main function
int taskOne();
int taskTwo();
int taskThree();
int taskFour();

int main() {
    
    int choice;
    
    printf("Hello!\n");
    
    printf("Welcome to the Decryption/Encryption program!\n\n");
    
    printf("Please select from the following options:\n");
    
    printf("_____________________________________________________________________________________________________\n\n");
    
    printf("1 - Encryption of a message with a rotation cipher given the message text and rotation amount\n");
    
    printf("_____________________________________________________________________________________________________\n\n");
    
    printf("2 - Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    
    printf("_____________________________________________________________________________________________________\n\n");
    
    printf("3 - Encryption of a message with a substitution cipher given message text and alphabet substitution\n");
    
    printf("_____________________________________________________________________________________________________\n\n");
    
    printf("4 - Decryption of a message encrypted with a substitution cipher given cipher text and substitutions\n");
    
    printf("_____________________________________________________________________________________________________\n\n");
    
   choice = 1;
    
    switch(choice){
        
        case 1:
        
            taskOne();
        
            break;
        
        /*case 2:
        
            taskTwo();
            
            break;
        */
        /*case 3:
            
            taskThree();
            
            break;
        */
        /*case 4:
            
            taskFour();
            
            break;
        */
        default:
        
            printf("Your choice does not match any of the listed tasks!");
            
        }
        
    
        return 0;
    }
    

int taskOne(){
    
    FILE *input;
    
    int i = 0;
    
    char inp[100];
    
    input = fopen("input.txt", "r");
     
     while(!feof(input)){
         
         fscanf(input, "%c", &inp[i]);
         
         printf("%c", inp[i]);
         
         i++;
         
     }
         return 0;
    }