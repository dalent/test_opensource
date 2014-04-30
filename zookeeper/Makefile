SRCS=$(wildcard ./*.c ./*.cpp)
OBJS=$(addsuffix .o, $(basename $(SRCS)))
APP=main
all:$(OBJS)
	echo $(OBJES)
%.o:%.c
	g++ -o  $@ $^ -lzookeeper_mt

%.o:%.cpp
	g++ -o  $@ $^ -lzookeeper_mt

