There are several C programs in c_src directory. 
  We can compile all the C programs in c_src using
     # cmake -S . -B build
     # cmake --build build
  Their compile output inside c_src/build directory



There are BPF C programs inside bpf directory. These are equivalent to C program from c_src.  
As, you can see in bpf, we have vmlinux.h, template.c, Makefile and BPF C programs.   

Makefile has all the build automation logic. It does multiple things.   
  (1) It does first compile BPF C to .o file  
  (2) Using .o generated files, it generates .skel.h (libbpf skeleton header) files inside bpf/output directory  
  (3) Using template.c, it first creates corresponding .skel.c files with the same name as .skel.h.   
      In those .skel.c files it imports .skel.h files, and substitue %s with real generated name.  
      For example, for HundredLoopBpf.skel.c, it replaces %s with HundredLoopBpf.   
  (4) Then, it compiles those all .skel.c to output files appending "Final" suffix.   
      For example, for HundredLoopBpf.skel.c, it compiles HundredLoopBpfFinal, which we then run inside qemu  

      
