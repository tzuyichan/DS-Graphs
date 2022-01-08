FILENAME = F04066028_hw3-

GCC = gcc
CLANG = clang++
LLVMFLAGS = -std=c++11 -stdlib=libc++
CXXFLAGS += -lstdc++

1: $(FILENAME)1.cpp
	$(CLANG) $(LLVMFLAGS) $^ -o 1

$(GCC)1: $(FILENAME)1.cpp
	$(GCC) $^ -o 1 $(CXXFLAGS)

2: $(FILENAME)2.cpp
	$(CLANG) $(LLVMFLAGS) $^ -o 2

$(GCC)2: $(FILENAME)2.cpp
	$(GCC) $^ -o 2 $(CXXFLAGS)

3: $(FILENAME)3.cpp
	$(CLANG) $(LLVMFLAGS) $^ -o 3

$(GCC)3: $(FILENAME)3.cpp
	$(GCC) $^ -o 3 $(CXXFLAGS)

4: $(FILENAME)4.cpp
	$(CLANG) $(LLVMFLAGS) $^ -o 4

$(GCC)4: $(FILENAME)4.cpp
	$(GCC) $^ -o 4 $(CXXFLAGS)

5: $(FILENAME)5.cpp
	$(CLANG) $(LLVMFLAGS) $^ -o 5

$(GCC)5: $(FILENAME)5.cpp
	$(GCC) $^ -o 5 $(CXXFLAGS)

clean:
	rm *.o 1 2 3 4 5 *.txt