# List of source files
SRCS = application.cpp Catalogue.cpp TrajetSimple.cpp Trajet.cpp TableauDynamique.cpp TrajetCompose.cpp DirectedGraph.cpp

# List of object files (generated during compilation)
OBJS = $(SRCS:.cpp=.o)

# Compiler
CC = g++

# Compiler flags
CFLAGS = -c -Wall

# Linker flags
LFLAGS = 

# Executable name
EXECUTABLE = trajets

# Target: build the executable
$(EXECUTABLE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXECUTABLE)

# Target: compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

# Target: clean up generated files
clean:
	rm -f $(OBJS) $(EXECUTABLE)
