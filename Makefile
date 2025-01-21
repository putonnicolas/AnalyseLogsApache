ifdef MAP
CXXFLAGS += -DMAP
endif

# -----------------------------

logs: build/main.o 
	g++ $(CXXFLAGS) -o log build/main.o

build/main.o: src/main.cpp 
	g++ $(CXXFLAGS) -c src/main.cpp -Iinclude -o build/main.o

# -----------------------------

build:
	mkdir -p build

clean:
	rm -rf build log