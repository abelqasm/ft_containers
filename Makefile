VECTORSRCS = testVector.cpp
STACKSRCS = testStack.cpp
MAPSRCS = testMap.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -fsanitize=address -g3
VECTORNAME = testVector
STACKNAME = testStack
MAPNAME = testMap

all: $(VECTORNAME) $(STACKNAME) $(MAPNAME)

$(VECTORNAME): $(VECTORSRCS)
	$(CC) -g $(CPPFLAGS) $(VECTORSRCS) -o $(VECTORNAME)

$(STACKNAME): $(STACKSRCS)
	$(CC) -g $(CPPFLAGS) $(STACKSRCS) -o $(STACKNAME)

$(MAPNAME): $(MAPSRCS)
	$(CC) -g $(CPPFLAGS) $(MAPSRCS) -o $(MAPNAME)

runm:
	./$(MAPNAME)

runv:
	./$(VECTORNAME)

runs:
	./$(STACKNAME)

clean:
	rm -f $(VECTORNAME) $(STACKNAME)

fclean: clean

re: fclean all