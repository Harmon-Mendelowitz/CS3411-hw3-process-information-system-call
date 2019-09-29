#include "types.h"
#include "stat.h"
#include "fcntl.h"
#include "user.h"
#include "x86.h"
#include "pstat.h"

char *
strcpy(char *s, char *t)
{
	char *os;

	os = s;
	while ((*s++ = *t++) != 0)
		;
	return os;
}

int
strcmp(const char *p, const char *q)
{
	while (*p && *p == *q) p++, q++;
	return (uchar)*p - (uchar)*q;
}

uint
strlen(char *s)
{
	int n;

	for (n = 0; s[n]; n++)
		;
	return n;
}

void *
memset(void *dst, int c, uint n)
{
	stosb(dst, c, n);
	return dst;
}

char *
strchr(const char *s, char c)
{
	for (; *s; s++)
		if (*s == c) return (char *)s;
	return 0;
}

char *
gets(char *buf, int max)
{
	int  i, cc;
	char c;

	for (i = 0; i + 1 < max;) {
		cc = read(0, &c, 1);
		if (cc < 1) break;
		buf[i++] = c;
		if (c == '\n' || c == '\r') break;
	}
	buf[i] = '\0';
	return buf;
}

int
stat(char *n, struct stat *st)
{
	int fd;
	int r;

	fd = open(n, O_RDONLY);
	if (fd < 0) return -1;
	r = fstat(fd, st);
	close(fd);
	return r;
}

int
atoi(const char *s)
{
	int n;

	n = 0;
	while ('0' <= *s && *s <= '9') n= n * 10 + *s++ - '0';
	return n;
}

void *
memmove(void *vdst, void *vsrc, int n)
{
	char *dst, *src;

	dst = vdst;
	src = vsrc;
	while (n-- > 0) *dst++= *src++;
	return vdst;
}

void
ps(void)
{
	//loop procstat call using myproc() - syscall
	//int x = 7;
	//struct pstat *ps = (struct pstat*);

	struct pstat* p[64];
	
		//ps->pid = 0;
		//ps->ppid = 0;
		//ps->state = 0;
		//memset(&ps->name[0], 0, sizeof(ps->name));
	//if (argfd(0, 0, &ps) < 0 || argint(1, &x) < 0)
		//return;

	//if (argptr(1, (void *)&ps, sizeof(*ps)) < 0)
	//	return;
	printf(1, "ps\n");
	for(int x=0; x<64; x++){
		p[x] = (struct pstat*)sbrk(sizeof(struct pstat));
		int a = procstat(x, p[x]);
		if(a == 1){
			x = 64;
		}
		else{
			if(a != -10){
				printf(1, "ps %d\n", a);
				if(p[x] != 0)
					printf(1, "%d %d %c %s\n", p[x]->pid, p[x]->ppid, p[x]->state, p[x]->name);
			}
		}
	}
	//printf(1, "%d %d %c %s\n", ps->pid, ps->ppid, ps->state, ps->name);
	//printf(1, "%d %d \n", (ps)->pid, (ps)->ppid);
	return;
}
