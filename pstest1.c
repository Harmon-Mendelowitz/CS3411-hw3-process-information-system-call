#include "user.h"
#include "types.h"
#include "pstat.h"

int
main(int argc, char **argv)
{
    int f1 = fork();

    if(f1 == 0){
        sleep(10);
        exit();
    }
    else{
        if(fork() != 0){
            if(fork() != 0){
                if(fork() != 0){
                    if(fork() != 0){
                        if(fork() != 0){
                            if(fork() != 0){
                                if(fork() != 0){
                                    ps();
                                    wait();
                                    exit();
                                }
                                else{
                                    sleep(10);
                                    exit();
                                }
                            }
                            else{
                                sleep(10);
                                exit();
                            }
                        }
                        else{
                            sleep(10);
                            exit();
                        }
                    }
                    else{
                        sleep(10);
                        exit();
                    }
                }
                else{
                    sleep(10);
                    exit();
                }
            }
            else{
                sleep(10);
                exit();
            }
        }
        else{
            sleep(10);
            exit();
        }
    }
    
    return 0;
}

