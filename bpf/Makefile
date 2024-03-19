CC = clang
CFLAGS = -g -target bpf -Wall -O2
INCLUDES = -I$(shell realpath ~/CLionProjects/decoupling/linux/tools/lib) -I$(shell realpath ~/CLionProjects/decoupling/linux/usr/include)

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
	@echo '## Define directories\nLIB_DIR := $$(shell realpath ~/CLionProjects/decoupling/linux/tools/lib)\nINCLUDE_DIR := $$(shell realpath ~/CLionProjects/decoupling/linux/usr/include)\nBPF_LIB_DIR := $$(shell realpath ~/CLionProjects/decoupling/linux/tools/lib/bpf)\n\n## Define source files\nSKEL_SRCS := $$(wildcard *.skel.c)\nSKEL_BINS := $$(SKEL_SRCS:.skel.c=Final)\n\n## Compiler options\nCC := clang\nCFLAGS := -g\nLIBS := -lbpf\n\n## Targets\nall: $$(SKEL_BINS)\n\n## Rule to compile any .skel.c file into a binary\n%Final: %.skel.c\n\t$$(CC) $$(CFLAGS) -I"$$INCLUDE_DIR" -I"$$LIB_DIR" -L"$$BPF_LIB_DIR" $$< $$(LIBS) -o $$@\n\n## Target to run all generated binaries\nrun: $$(SKEL_BINS)\n\t@for bin in $$(SKEL_BINS); do \\\n\t\t./$$bin; \\\n\tdone\n\n## Clean up generated files\nclean:\n\trm -f $$(SKEL_BINS)' > output/Makefile


# Define a rule to clean up generated files
clean:
	rm -f $(OBJS)
	rm -rf ./output/*
	rm -f *.skel.c


.PHONY: all clean generate-makefile generate-and-make
