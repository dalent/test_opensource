#include<event2/event.h>
#include<stdio.h>
void cb_func(evutil_socket_t fd, short  what, void *arg)
{
	printf("get alerted !");
}
int main()
{
	struct event_base * base;
	struct event *ev1,*ev2;
	struct timeval five_seconds = {5,0};
	base = event_base_new();
	if(!base)
		return 0;
	ev1 = event_new(base, -1, EV_TIMEOUT,cb_func,NULL);
	ev2 = event_new(base, -1, EV_TIMEOUT, cb_func,NULL);
//	event_add(ev1,&five_seconds);
//	struct timeval five_seconds1 = {15,0};
//	event_add(ev2,&five_seconds1);
   event_active(ev1,EV_TIMEOUT,0);
   int tmp =	event_base_dispatch(base);
   printf("%d",tmp);
	return 1;
}
