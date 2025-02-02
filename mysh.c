#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//mysh.c

//This literally is pretty much what we need to do, 
//we can use this annd basically go through most of the project
//          I
//          V
// https://brennan.io/2015/01/16/write-a-shell-in-c/

void turtle_mode(){
    int exit_found = 0;
    do{
        const char delim[2] = " ";
        char buf[512];
        char *token;
        char **array;
        array = malloc(sizeof(char *));

        printf("> ");
        //get line
        fgets(buf, sizeof buf, stdin);

        //parse line
        token = strtok(buf, delim);
        int i = 0;
        while(token != NULL) {
            printf( "%s\n", token );
            array[i] = malloc(sizeof(token));
            strncpy(array[i], token, sizeof(token));
            token = strtok(NULL, delim);
            i++;
        }
        
        //fork bs with array bs 
        
        //fork()bs
        //do command

        pid_t pid = fork();
        int status;
        pid_t wait;
        if(pid == 0){
            //Child
            execvp(array[0], array);
            _exit(0);

        }else if(pid <0){
            //Error 
            exit(1);
        }else{
            do {
                wait = waitpid(pid, &status, 0);
            } while (!WIFSIGNALED(status) && !WIFEXITEDg(status));
        }

        exit_found = 1;
        for(int i = 0; i<array; i++){
            free(array[i]);
        }

        free(array);

    }while(exit_found == 0);
    _exit(0);
}

int main(int argc, char **argv)
{
    if(argc == 1){
        //shell mode
        turtle_mode();
    }else if(argc == 2){
        //batch mode
    }else{
        //ERROR
    }


  // Perform any shutdown/cleanup.

  return 0;
}
