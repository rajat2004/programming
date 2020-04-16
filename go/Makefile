# Basic GO commands
GOCMD := go
GOBUILD=$(GOCMD) build
GOCLEAN=$(GOCMD) clean
GOTEST=$(GOCMD) test
GOGET=$(GOCMD) get

SRCS := $(wildcard *.go)
PROGS := $(patsubst %.go,%,$(SRCS))

all : $(PROGS)

%: %.go
	$(GOBUILD) -o $@ $<

clean :
	rm $(PROGS)
