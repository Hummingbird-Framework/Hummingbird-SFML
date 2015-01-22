CC        := g++
ARCH      := $(shell getconf LONG_BIT)

CFLAGS    := -std=c++11 -Wall -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

STATIC_LIB_NAME := Hummingbird-SFML-2.1

SOURCES   := $(shell find ./ -name '*.cpp')
INCLUDES  := $(shell find ./ -name '*.h')

OBJ       := $(addprefix ./,$(SOURCES:./%.cpp=%.o))

all: $(OBJ)

%.o: %.cpp Hummingbird-Base
	$(CC) -c -o $@ $< $(CFLAGS) ../Hummingbird-Base/Hummingbird-Base.a
	ar rvs $(STATIC_LIB_NAME).a $@

Hummingbird-Base: ../Hummingbird-Base/Hummingbird-Base.a
	make -C ../Hummingbird-Base/

.PHONY: clean

clean:
	rm -rf *~ *.o *.a
