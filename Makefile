CFLAGS ?= -Wall -Wextra -std=gnu99 -Werror

OBJS = murmurhash3.o spookyhash2.o

all: $(OBJS)

clean:
	rm -f $(OBJS)
