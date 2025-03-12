# Compiler tous les fichiers .cpp du dossier
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	g++ -o $@ $^

%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)