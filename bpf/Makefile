CC = clang
CFLAGS = -g -target bpf -Wall -O2
INCLUDES = -I$(shell realpath ~/CLionProjects/decoupling/linux/tools/lib) -I$(shell realpath ~/CLionProjects/decoupling/linux/usr/include)

# Define source files
SRCS := $(filter-out template.c,$(wildcard *.c))
OBJS = $(SRCS:.c=.o)

# Define targets
all: $(OBJS)

# Rule to compile any .c file into a .o file and generate skeleton file
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	# Generate skeleton file and redirect stdout to the specified file
	bpftool gen skeleton $@ name $(basename $@) | tee ./output/$(basename $@).skel.h > /dev/null 2>&1
	# Generate skel.c file with content and replace occurrences of "ThousandLoopBpf" with the basename of the target
	cat template.c | sed 's/%s/$(basename $@)/g' > ./$(basename $@).skel.c


# Define a rule to clean up generated files
clean:
	rm -f $(OBJS)
