CC = clang
CFLAGS = -g -target bpf -Wall -O2
INCLUDES = -I$(shell realpath ~/CLionProjects/decoupling/linux/tools/lib) -I$(shell realpath ~/CLionProjects/decoupling/linux/usr/include) -I$(shell realpath ~/CLionProjects/decoupling/linux/tools/include)

# Define source files
SRCS := $(filter-out template.c,$(wildcard *.c))
OBJS = $(SRCS:.c=.o)

# Define targets, first run $(OBJS) and then generate-and-make
all: $(OBJS) generate-and-make

# Rule to compile any .c file into a .o file and generate skeleton file
%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Generating skeleton file for $@"
	bpftool gen skeleton $@ name $(basename $@) | tee ./output/$(basename $@).skel.h > /dev/null 2>&1
	@echo "Generating skel.c file for $@"
	cat template.c | sed 's/%s/$(basename $@)/g' > ./output/$(basename $@).skel.c

# Target to generate Makefile in the output directory and run make
# it first run generate-makefile because it is prerequisite and then go to generate-and-make
generate-and-make: generate-makefile
	@echo "Running make in output directory"
	@$(MAKE) -C output -f Makefile

# Target to generate Makefile in the output directory
generate-makefile:
	@echo "Generating Makefile in output directory"
	cp finalMakefile output/Makefile

# Define a rule to clean up generated files
clean:
	rm -f $(OBJS)
	rm -rf ./output/*
	rm -f *.skel.c


.PHONY: all clean generate-makefile generate-and-make
