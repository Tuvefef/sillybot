BIN = sllbin
SOURCES = core.cc coredef.cc 
CXX = g++
CXXVER = -std=c++20
LDFL = -ldpp

all:
	$(CXX) $(CXXVER) $(SOURCES) -o $(BIN) $(LDFL)

run:
	./$(BIN)

clean:
	rm -f $(BIN)