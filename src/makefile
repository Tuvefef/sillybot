BIN = sllbin
SOURCES = core.cc coredef.cc 
CXX = g++
CXXVER = -std=c++20 
LDFL = -ldpp
LDFL1 = -lcpr 

all: dicor
dicor:
	$(CXX) $(CXXVER) $(SOURCES) -o $(BIN) $(LDFL) $(LDFL1)

run:
	./$(BIN)

clean:
	rm -f $(BIN)