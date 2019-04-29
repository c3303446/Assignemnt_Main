#include <stdio.h> //inlcuding libraries that will be used within the programe

//include function for each question on project notes where user inputs in a menu system in the main function
int taskOne();      //Declaration of function for task one
int taskTwo();      //Declaration of function for task two   
void taskThree();   //Declaration of function for task three
void taskFour();    //Declaration of function for task four

int main() {        //beginning of main function
    
    int choice;     //holder for users choice of encrytion/decryption function
    
    printf("Hello!\n"); //basic printf functions to display choices for the user followered by a ouput template
    
    printf("Welcome to the Decryption/Encryption program!\n\n");
    
    printf("Ensure that the you have placed the message you would like to encrypt/decrypt in the input.txt file before continuing.\n\n");
    
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
    
    printf("Selection: ");
    
    scanf("%d", &choice); //receives input from user as per function choice
    
    switch(choice){       // start switch function for user choice
        
        case 1:           // if choice is = 1
        
            taskOne();    // 
        
            break;
        
        case 2:         
        
            taskTwo();
            
            break;
        
        case 3:
            
            taskThree();
            
            break;
        
        case 4:
            
            taskFour();
            
            break;
        
        default:
        
            printf("Your choice does not match any of the listed tasks!\n");
            
        }
    
        return 0;
    }
    

int taskOne(){
    
    FILE *input;
    
    int key;
    
    int i = 0;
    
    char inp[100];
    
    char hold;
    
    printf("Please enter the key you would like to use: ");
    
    scanf("%d", &key);

    input = fopen("input.txt", "r");
     
     while(!feof(input)){
         
         fscanf(input, "%c", &inp[i]);
         
         if(inp[i] == 32 ){
             
            printf("%c", inp[i]);
            
            i++;
         
         } 
         else {
             
            if(inp[i] >= 'A' && inp[i] <= 'Z'){
                
                hold = (inp[i] - key + 65) % 26;
                
                printf("%c", (hold + 65));
                
                i++;
                
            }
            
            else {
                printf("%c", inp[i]);
            }

         }

     }
     printf("\n");
         return 0;
    }
    
    int taskTwo(){
        
        FILE *input;
    
        int key;
    
        int i = 0;
    
        char inp[100];
    
        char hold;
    
        printf("Please enter the key you would like to use: ");
    
        scanf("%d", &key);

        input = fopen("input.txt", "r");
     
        while(!feof(input)){
         
            fscanf(input, "%c", &inp[i]);
         
            if(inp[i] == 32 ){
             
                printf("%c", inp[i]);
            
                i++;
         
            } 
            else {
             
            if(inp[i] >= 'A' && inp[i] <= 'Z'){
                
                hold = (inp[i] + key - 65) % 26;
                
                printf("%c", (hold + 65));
                
                i++;
                
            }
            
            else {
                
                printf("%c", inp[i]);
                
            }
            
         }
    
    }

printf("\n");

return 0;
}

void taskThree(){
    
    FILE *input;
    
    int i = 0, x, hold;
    
    char keyArr[100];
    
    char inp[100];
    
    printf("Please enter the sub you would like to use: ");
    
    scanf("%s", keyArr);

    input = fopen("input.txt", "r");
    
    while(!feof(input)){
         
        fscanf(input, "%c", &inp[i]);
         
        if(inp[i] == 32 ){
             
            printf("%c", inp[i]);
            
            i++;
            
        }
    
        else{
        
                for(x = 0; x < 26; x++){
            
                    hold = x + 65;
            
                    if(inp[i] == hold){
                    
                        inp[i] = keyArr[x];
                        
                        printf("%c", inp[i]);
                        
                        break;
                        
                    }
                
                }
                
            i++;
        
        }

    }
    
    printf("\n");
    
return;

}

void taskFour(){
    
    FILE *input;
    
    int i = 0, x;
    
    char keyArr[100];
    
    char inp[100];
    
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    printf("Please enter the sub you would like to use: ");
    
    scanf("%s", keyArr);

    input = fopen("input.txt", "r");
    
    while(!feof(input)){
         
        fscanf(input, "%c", &inp[i]);
         
        if(inp[i] == 32 ){
             
            printf("%c", inp[i]);
            
            i++;
            
        }
    
        else{
        
                for(x = 0; x < 26; x++){
            
                    if(inp[i] == keyArr[x]){
                        
                        inp[i] = alpha[x];
                        
                        printf("%c", inp[i]);
                        
                        break;
                        
                    }
                
                }
                
            i++;
        
        }

    }
    
    printf("\n");
    
return;
}