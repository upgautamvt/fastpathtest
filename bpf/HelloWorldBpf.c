#include "vmlinux.h"
#include "/home/upgautam/CLionProjects/libbpf/src/bpf_helpers.h"

SEC("tracepoint/syscalls/sys_enter_execve")
int bpf_prog(void *ctx) {
    bpf_trace_printk("Hello World!", 10);
    return 0;
}
