#include<libaio.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<inttypes.h>
int main()
{
	io_context_t ctx;
	struct iocb cb;
	struct iocb * cbs[1];
	char data[4096];
	struct io_event events[1];
	int ret;
	int fd;
	fd = open("./testfile", O_RDWR|O_CREAT);
	if(fd < 0)
	{
		perror("open error");
		return -1;
	}

	ctx = 0;
	ret = io_setup(128, &ctx);
	if(ret < 0)
	{
		perror("io_setup error");
		return -1;
	}
	memset(&cb,0,sizeof(cb));
	cb.aio_fildes = fd;
	cb.aio_lio_opcode = IO_CMD_PWRITE;
	cb.u.c.buf = (void*)data;
	cb.u.c.offset = 0;
	cb.u.c.nbytes = 4096;
	cbs[0] = &cb;
	ret =io_submit(ctx, 1, cbs);
	if(ret != 1)
	{
		if(ret < 0)
			perror("io_submit error");
		else
			fprintf(stderr, "could not submit");
		return -1;
	}

	ret=io_getevents(ctx, 1,1,events,NULL);
	printf("%d\n",ret);
	ret = io_destroy(ctx);
	if(ret < 0)
	{perror("io_destroy error");
		return -1;}
	return 0;

}
