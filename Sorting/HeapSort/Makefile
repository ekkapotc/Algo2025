TARGET := main
SRC := main.cpp
HDR := heap.hpp heap_sort.hpp
OBJ := $(SRC:.cpp=.o)

CXX := g++
FORMAT := clang-format

CXXFLAGS := -Wall -Werror -Wpedantic -g -O0
LDFLAGS :=  
FORMATFLAGS := -i


$(TARGET) : $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ) : $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all clean run reformat

all : $(TARGET)

clean :
	rm -rf $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

reformat:
	$(FORMAT) $(FORMATFLAGS) $(SRC) $(HDR)

