#include "user.h"
#include "types.h"
#include "pstat.h"

int
main(int argc, char **argv)
{
    int f1 = fork();

    /* 
    * create a child of a child of a child... 8 times 
    * then have the last child call ps and make the parents 
    * wait for the children to finish.
    */
    if(f1 == 0){
        if(fork() == 0){
            if(fork() == 0){
                if(fork() == 0){
                    if(fork() == 0){
                        if(fork() == 0){
                            if(fork() == 0){
                                if(fork() == 0){
                                    ps();
                                    exit();
                                }
                                else{
                                    wait();
                                    exit();
                                }
                            }
                            else{
                                wait();
                                exit();
                            }
                        }
                        else{
                            wait();
                            exit();
                        }
                    }
                    else{
                        wait();
                        exit();
                    }
                }
                else{
                    wait();
                    exit();
                }
            }
            else{
                wait();
                exit();
            }
        }
        else{
            wait();
            exit();
        }
    }
    else{
        wait();
        exit();
    }
    
    return 0;
}

