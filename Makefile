VECTORSRCS = testVector.cpp
STACKSRCS = testStack.cpp
MAPSRCS = testMap.cpp
CC = c++
CPPFLAGS = -std=c++98
LDFLAGS = -fsanitize=address -g3
VECTORNAME = testVector
STACKNAME = testStack
MAPNAME = testMap

all: $(VECTORNAME) $(STACKNAME) $(MAPNAME)

$(VECTORNAME): $(VECTORSRCS)
	$(CC) $(CPPFLAGS) $(VECTORSRCS) -o $(VECTORNAME)

$(STACKNAME): $(STACKSRCS)
	$(CC) $(CPPFLAGS) $(STACKSRCS) -o $(STACKNAME)

$(MAPNAME): $(MAPSRCS)
	$(CC) $(LDFLAGS) $(CPPFLAGS) $(MAPSRCS) -o $(MAPNAME)

runm:
	./$(MAPNAME)

runv:
	./$(VECTORNAME)

runs:
	./$(STACKNAME)

clean:
	rm -f $(VECTORNAME) $(STACKNAME) $(MAPNAME)

fclean: clean

re: fclean all