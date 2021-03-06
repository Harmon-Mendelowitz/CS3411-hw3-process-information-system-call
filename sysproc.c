#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "pstat.h"


/*static int
argps(int n, int *pfd, struct pstat **pf)
{
	int          fd;
	struct pstat *f;

	if (argint(n, &fd) < 0) return -2;
	if (fd < 0) return -3;
	if (pfd) *pfd = fd;
	f = (struct pstat*)(&n + 4);
	//f = *pf;
	if (pf) *pf = f;
	return 0;
}*/
int
argps(int n, struct pstat **pp, int size)
{
	int          i;
	struct proc *curproc = myproc();

	if (argint(n, &i) < 0) return -1;
	if (size < 0 || (uint)i >= curproc->sz || (uint)i + size > curproc->sz) return -1;
	*pp = (struct pstat *)i;
	return 0;
}

int
sys_fork(void)
{
	return fork();
}

int
sys_exit(void)
{
	exit();
	return 0; // not reached
}

int
sys_wait(void)
{
	return wait();
}

int
sys_kill(void)
{
	int pid;

	if (argint(0, &pid) < 0) return -1;
	return kill(pid);
}

int
sys_getpid(void)
{
	return myproc()->pid;
}

int
sys_sbrk(void)
{
	int addr;
	int n;

	if (argint(0, &n) < 0) return -1;
	addr = myproc()->sz;
	if (growproc(n) < 0) return -1;
	return addr;
}

int
sys_sleep(void)
{
	int  n;
	uint ticks0;

	if (argint(0, &n) < 0) return -1;
	acquire(&tickslock);
	ticks0 = ticks;
	while (ticks - ticks0 < n) {
		if (myproc()->killed) {
			release(&tickslock);
			return -1;
		}
		sleep(&ticks, &tickslock);
	}
	release(&tickslock);
	return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
	uint xticks;

	acquire(&tickslock);
	xticks = ticks;
	release(&tickslock);
	return xticks;
}

int
sys_procstat(void)
{
	int x;
	struct pstat *ps;

	if (argint(0, &x) < 0 || argps(1, &ps, x) < 0)
		return -1;
	
	return procstat(x, ps);

}