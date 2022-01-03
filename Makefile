CXX = g++

INCLUDE = src/Include/*.h
SRC = $(Get-ChildItem *.cpp)

OBJS = $(patsubst $(SRC)/%.cpp,%.o,$(wildcard $(SRC)/*.cpp))

%.o:
	$(CXX) $(SRC)/$(patsubst %.o,%,$@).cpp -c -I$(INCLUDE) -o obj/$(patsubst %.o,%,$@).o -fPIC

$(SRC)/%.cpp: $(patsubst %.cpp,%,$@).o

all: $(OBJS)
	$(CXX) obj/*.o -o bin/libscrape.so -shared -fPIC

clean:
	rm -rf obj	