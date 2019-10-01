#include "user.h"
#include "types.h"
#include "pstat.h"

int
main(int argc, char **argv)
{
    int f1 = fork();

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

