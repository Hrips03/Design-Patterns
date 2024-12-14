# Source files
SRC_FILES = main.cpp controller/*.cpp model/*.cpp view/*.cpp

# Compiler and flags
CXX = g++
CXXFLAGS = -I/usr/include/                        # Add the include path for sqlite3.h
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lsqlite3   # Add the library path and link sqlite3

# Target
all: game

# Build the game executable
game: $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Clean the build
clean:
	rm -f game
