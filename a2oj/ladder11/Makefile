CC := g++

SRCS := $(wildcard *.cpp)
PROGS := $(patsubst %.cpp,%,$(SRCS))

all : $(PROGS)

%: %.cpp
	$(CC) -o $@ $<

clean :
	rm $(PROGS) 
