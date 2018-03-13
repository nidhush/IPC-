#include"header.h"
#include"ds.h"
#include"decleration.h"
int main()
{
	int wfd,rfd,count;
	Request r;
	Result a;
	printf("rec2 with pid %d: is begin\n",getpid());
	r.pid=getpid();
	r.opr='-';
	r.oper1=33;
	r.oper2=12;
	wfd=open("fifo1",O_WRONLY);
	printf("wfd of rec2 -->%d\n",wfd);
	write(wfd,&r,sizeof(Request));
	close(wfd);
	rfd=open("fifo4",O_RDONLY);
	printf("rfd of rec2-->%d\n",rfd);
	count=read(rfd,&a,sizeof(Result));
	printf("result sub--->%d\n",a.result);
	printf("count sub--->%d\n",count);
	printf("rec2 with pid %d: is end\n",getpid());
	close(rfd);
	return 0;
}
