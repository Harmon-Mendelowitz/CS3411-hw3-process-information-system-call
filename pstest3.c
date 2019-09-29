#include "user.h"
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
        else{}
        //second grandchild
        if(fork() == 0){
            sleep(10);
            exit();
        }
        else{}
        sleep(10);
        exit();
    }
    //second child
    if(fork() == 0){
        //third grandchild
        if(fork() == 0){
            sleep(10);
            exit();
        }
        else{}
        //fourth grandchild
        if(fork() == 0){
            sleep(10);
            exit();
        }
        else{}
        sleep(10);
        exit();
    }  
    //parent
    else{
        ps();
        wait();
        exit();
    }
    
    return 0;
}

