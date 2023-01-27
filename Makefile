VECTORSRCS = testVector.cpp
STACKSRCS = testStack.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -fsanitize=address -g3
VECTORNAME = testVector
STACKNAME = testStack

all: $(VECTORNAME) $(STACKNAME)

$(VECTORNAME): $(VECTORSRCS)
	$(CC) -g $(CPPFLAGS) $(VECTORSRCS) -o $(VECTORNAME)

$(STACKNAME): $(STACKSRCS)
	$(CC) -g $(CPPFLAGS) $(STACKSRCS) -o $(STACKNAME)

runv:
	./$(VECTORNAME)

runs:
	./$(STACKNAME)

clean:
	rm -f $(VECTORNAME) $(STACKNAME)

fclean: clean

re: fclean all