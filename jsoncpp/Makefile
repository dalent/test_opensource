files=$(shell ls *.cpp)
objs=$(addsuffix .o, $(basename $(files)))
all:$(objs)
	echo $(objs)

%.o:%.cpp
	g++ -o $@ $< -ljsoncpp -lcurl

