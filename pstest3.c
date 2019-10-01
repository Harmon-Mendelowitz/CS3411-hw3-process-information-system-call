#include "user.h"
#include "types.h"
#include "pstat.h"

int
main(int argc, char **argv)
{
    //first child
    if(fork() == 0){
        //first grandchild
        if(fork() == 0){
            sleep(10);
            exit();
        }
        //second grandchild
        if(fork() == 0){
            sleep(10);
            exit();
        }
        //sleep(10);
        wait();
        wait();
        exit();
    }
    //parent
    else{
    //second child
        if(fork() == 0){
            //third grandchild
            if(fork() == 0){
                sleep(10);
                exit();
            }
            //fourth grandchild
            if(fork() == 0){
                sleep(10);
                exit();
            }
            wait();
            wait();
            exit();
        }
        sleep(2);
        ps();
        wait();
        wait();
        exit();
    }
    
    return 0;
}

