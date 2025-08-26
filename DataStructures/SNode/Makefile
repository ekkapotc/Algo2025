TARGET := main
SRC := main.cpp
HDR := snode.hpp
OBJ := $(SRC:.cpp=.o)

CXX := g++

CXXFLAGS := -Wall -Werror -Wpedantic -g -O0
LDFLAGS := 

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ) : $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all clean run

all : $(TARGET)

clean :
	rm -rf $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

