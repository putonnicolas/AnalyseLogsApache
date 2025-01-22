ifdef MAP
CXXFLAGS += -DMAP
endif

# -----------------------------

analog: build/main.o build/Parser.o
	g++ $(CXXFLAGS) -o analog build/main.o build/Parser.o

build/main.o: src/main.cpp 
	g++ $(CXXFLAGS) -c src/main.cpp -Iinclude -o build/main.o

build/Parser.o: src/Parser.cpp 
	g++ $(CXXFLAGS) -c src/Parser.cpp -Iinclude -o build/Parser.o

# -----------------------------

build:
	mkdir -p build

clean:
	rm -rf build analog