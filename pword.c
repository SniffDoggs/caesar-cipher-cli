#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(char *password, int key){

    // reduce key to fit within the 26-letter alphabet limit
    key = key % 26;

    for (int i = 0; password[i] != '\0'; i++){
        // perform the Caesar Cipher
        if (isupper(password[i])){
            // map ASCII to a 0-25 index, apply the shift, wrap around, and restore ASCII
            password[i] = ((password[i] - 'A') + key) % 26 + 'A';
        } else if (islower(password[i])){
            password[i] = ((password[i] - 'a') + key) % 26 + 'a';
        }
    }
    printf("%s\n", password);
}

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("ERROR: please provide the following after the program name: [password] [key]\n");
        return 1;
    }

    char *password = NULL;
    int key = 0;

    for (int i = 1; i < argc; i++){
        if (i == 1){
            password = argv[i];
        }
        else if (i == 2){
            for (int j = 0; argv[i][j] != '\0'; j++){
            if (argv[i][j] < '0' || argv[i][j] > '9'){
                printf("ERROR: please provide a number\n");
                return 1;
                }
            }

            // convert the validated string into an integer
            key = atoi(argv[i]);

            }
        }
    if (password != NULL){
        encrypt(password, key);
    }

    return 0;
}
