TARGET := main
SRC := main.cpp
HDR := queue.hpp
OBJ := $(SRC:.cpp=.o)

CXX := g++

CXXFLAGS := -Wall -g -O0
LDFLAGS := 

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ) : $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -c $<

all : $(TARGET)

clean :
	rm -rf $(TARGET) $(OBJ)

.PHONY: all clean run

run: $(TARGET)
	./$(TARGET)

