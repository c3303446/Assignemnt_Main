//Name: Isaac Fleury
//Student No.: 3303446

#include <stdio.h> //inlcuding libraries that will be used within the program

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
    
    scanf("%d", &choice);   //receives input from user as per function choice
    
    switch(choice){         // start switch function for user choice
        
        case 1:             // if choice is = 1
        
            taskOne();      // call function taskOne()
        
            break;          // end program after taskOne has completed
        
        case 2:             // if choice is = 2
        
            taskTwo();      // call function taskTwo()
            
            break;          // end program after taskTwo has completed
        
        case 3:             // is choice is = 3
            
            taskThree();    // call function taskThree()
            
            break;          // end program after taskThree has completed  
        
        case 4:             // if choice is = 4
            
            taskFour();     // call function taskFour()
            
            break;          // end program after taskFour has completed
        
        default:            // if another choice value has been inputed then printf
        
            printf("Your choice does not match any of the listed tasks!\n");
            
        }
    
        return 0;           // return 0 to main function (nothing happens)
    }
    

int taskOne(){              // function taskOne
    
    FILE *input;            // declare file variable
    
    int key;                // delcare variable of key value
    
    int i = 0;              // declare count variable
    
    char inp[100];          // declare input array and size
    
    char hold;              // declare hold variable for loop
    
    printf("Please enter the key you would like to use: ");
    
    scanf("%d", &key);      // get user input and assign to variable 'key'

    input = fopen("input.txt", "r");        // open input file from given directory for reading 
     
     while(!feof(input)){                   // begin while loop while does not = EOF
         
         fscanf(input, "%c", &inp[i]);      // file scan positon of character in the 'i' position
         
         if(inp[i] == 32 ){                 // if the character = ' ' then print and end loop for character position
             
            printf("%c", inp[i]);
            
            i++;                            // loop increment for i + 1
         
         } 
         else {                                         // if inp[i] != 32 then...
             
            if(inp[i] >= 'A' && inp[i] <= 'Z'){         // ifinp[i] is between and including A and Z then...
                
                hold = (inp[i] - key + 65) % 26;        // implementing formula (m + k)(mod 26) 
                
                printf("%c", (hold + 65));              // print characte the lines with hold + 65
                
                i++;                                    // loop increment for i + 1
                
            }
            
            else {
                printf("%c", inp[i]);                   // if is outside A and Z then do not change and print character
            }

         }

     }
     printf("\n");                                      // keep output looning nice
         return 0;                                      // return value set
    }
    
    int taskTwo(){                                      // function taskTwo
        
        FILE *input;                                    // set file variable
    
        int key;                                        // declare key variable
    
        int i = 0;                                      // declare i count variable to 0
    
        char inp[100];                                  // declare input array and size
    
        char hold;                                      // declare hold variable
    
        printf("Please enter the key you would like to use: ");
    
        scanf("%d", &key);                              // get user input for key and set to key variable

        input = fopen("input.txt", "r");                // open file from given directory for reading
     
        while(!feof(input)){                            // begin while loop while input does not = EOF
         
            fscanf(input, "%c", &inp[i]);               // file scan position i as character to array inp[i]
         
            if(inp[i] == 32 ){                          // if position i = 32 do not change and print inp[i]
             
                printf("%c", inp[i]);
            
                i++;                                    // increment i + 1
         
            } 
            else if(inp[i] >= 'A' && inp[i] <= 'Z'){    // if inp[i] is between and including A and Z then...
                
                    hold = (inp[i] + key - 65) % 26;    // implemented (c - k)(mod 26) and set value to variable hold
                
                    printf("%c", (hold + 65));          // print value of hold and + 65 to bring back to capital values
                
                    i++;                                // increment i for next loop
                
            }

            else {                                      // if inp[i] is not between A and Z then do not change adn print character inp[i]
                
                printf("%c", inp[i]);
                
            }
            
         }

printf("\n");                                           // new line to structure output

return 0;                                               // return 0 to function

}

void taskThree(){                                       // function taskThree
    
    FILE *input;                                        // file variable declaratoin
    
    int i = 0, x, hold;                                 // declare integer variables: count to 0, x, hold 
    
    char keyArr[100];                                   // declare character keyArr array and size
    
    char inp[100];                                      // declare character inp array and size
    
    printf("Please enter the sub you would like to use: "); //ask user to enter a alphabet sub
    
    scanf("%s", keyArr);                                // scan user alphabet sub into keyArr 

    input = fopen("input.txt", "r");                    // assign input file to file directory as a read file
    
    while(!feof(input)){                                // begin while loop: while input  
         
        fscanf(input, "%c", &inp[i]);                   // file scan from input as a character to inp[i] position
         
        if(inp[i] == 32 ){                              // if inp[i] = 32 (space bar) then do no change and print this position
             
            printf("%c", inp[i]);
            
            i++;                                        // increment i for next loop
            
        }
    
        else{                                           // if it is not then...
        
                for(x = 0; x < 26; x++){                // start for loop until x is 26 
            
                    hold = x + 65;                      // make hold = x + 65 to be within the capitals alphabet
            
                    if(inp[i] == hold){                 // if inp[i] = our value for hold then...
                    
                        inp[i] = keyArr[x];             // make inp[i] = keyArr[x] to set the encrytped sub to our input
                        
                        printf("%c", inp[i]);           // print the encrypted character from previous set position inp[i]
                        
                        break;                          // break for loop 
                        
                    }
                
                }
                
            i++;                                        // i increment for while loop
        
        }

    }
    
    printf("\n");                                       // output structure
        
return;                                                 // void function return

}

void taskFour(){                                        // function taskFour
    
    FILE *input;                                        // declare file variable
    
    int i = 0, x;                                       // declare integer i = 0, x
    
    char keyArr[100];                                   // declare character arry key Arr and size
    
    char inp[100];                                      // delcare character array inp and size
    
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";      // declare character array alpha and size for comparison to inp[]
    
    printf("Please enter the sub you would like to use: "); // ask user for keyArr[]
    
    scanf("%s", keyArr);                                // scan for user input and set to keyArr

    input = fopen("input.txt", "r");                    // set variable 'input' to file directory as a read file
    
    while(!feof(input)){                                // begin while loop while input does not = EOF
         
        fscanf(input, "%c", &inp[i]);                   // scan file for per position and set as character into position inp[i]
         
        if(inp[i] == 32 ){                              // if inp[i] = 32 (space) do not change
             
            printf("%c", inp[i]);                       // print unchanged inp[i]
            
            i++;                                        // i incrememnt i + 1
            
        }
    
        else{                                           // if not 32 then... 
        
                for(x = 0; x < 26; x++){                // start for loop until x = 26
            
                    if(inp[i] == keyArr[x]){            // if inp[i] = keyArr[x] then... if not then keep looping until keyArr[x] is the same as inp[i]
                        
                        inp[i] = alpha[x];              // make inp[i] equal the position that alligns with the array alpha
                        
                        printf("%c", inp[i]);           // print the decrypted character in position inp[i]
                        
                        break;                          // stop for loop once a match has been found
                        
                    }
                
                }
                
            i++;                                        // increment i within while loop i + 1
        
        }

    }
    
    printf("\n");                                       // new line for structure
    
return;                                                 // return void function
}