CXXFLAGS += -std=c++11

ifdef MAP
CXXFLAGS += -DMAP
endif

# -----------------------------

analog: build/main.o build/Parser.o build/Statistics.o build/Grapher.o
	g++ $(CXXFLAGS) -o analog build/main.o build/Parser.o build/Statistics.o build/Grapher.o

build/main.o: src/main.cpp | build
	g++ $(CXXFLAGS) -c src/main.cpp -Iinclude -o build/main.o

build/Parser.o: src/Parser.cpp | build
	g++ $(CXXFLAGS) -c src/Parser.cpp -Iinclude -o build/Parser.o

build/Grapher.o: src/Grapher.cpp | build
	g++ $(CXXFLAGS) -c src/Grapher.cpp -Iinclude -o build/Grapher.o

build/Statistics.o: src/Statistics.cpp | build
	g++ $(CXXFLAGS) -c src/Statistics.cpp -Iinclude -o build/Statistics.o

# -----------------------------

build:
	mkdir -p build

clean:
	rm -rf build analog