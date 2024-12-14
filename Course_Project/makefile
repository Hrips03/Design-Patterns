# Source files
SRC_FILES = main.cpp controller/*.cpp model/*.cpp view/*.cpp

# Compiler and flags
CXX = g++
CXXFLAGS = -I"G:/Hripsime/Education/UNI/4rd kurs/Design-Patterns/Course_Project/include"  # Adjusted include path
LDFLAGS = -L"G:/Hripsime/Education/UNI/4rd kurs/Design-Patterns/Course_Project/lib" -lsqlite3  # Adjusted library path

# Target
all: game

# Build the game executable
game: $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Clean the build
clean:
	del /f /q game.exe  # Windows command to delete the game executable
