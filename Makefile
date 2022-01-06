FILENAME = F04066028_hw3-

GCC = gcc
CLANG = clang++
LLVMFLAGS = -std=c++11 -stdlib=libc++
CXXFLAGS += -lstdc++

1: $(FILENAME)1.cpp
	$(CLANG) $(LLVMFLAGS) $^ -o 1

$(GCC)1: $(FILENAME)1.cpp
	$(GCC) $^ -o 1 $(CXXFLAGS)

clean:
	rm *.o 1