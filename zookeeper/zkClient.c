#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<zookeeper/zookeeper.h>
#include<unistd.h>
static zhandle_t *zh;
void watcher(zhandle_t*zzh,int type,int state, const char*path,void *watcherCtx){}
int main(int argc, char** argv)
{
	char buffer[512];
	char p[2048];
	char *cert=0;
	char appId[64];
	strcpy(p, "dummy");
	zoo_set_debug_level(ZOO_LOG_LEVEL_DEBUG);
	zh = zookeeper_init("localhost:2181", watcher, 10000,0,0,0);
	if(zoo_add_auth(zh,"foo",p,strlen(p),0,0)!=ZOK)
		return 2;
	int rc = zoo_create(zh, "/xyz","value",5,&ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL,buffer, sizeof(buffer) -1);

	int buflen = sizeof(buffer);
	struct Stat stat;
	rc = zoo_get(zh, "/xyz", 0, buffer, &buflen, &stat);
	if(rc)
	{
		fprintf(stderr, "Error %d, for %d\n",rc, __LINE__);
	}

	printf("%s", buffer);
	sleep(100000);
	return 0;
}
