#include "vmlinux.h"
#include <bpf/bpf_helpers.h>

char LICENSE[] SEC("license") = "GPL";

SEC("tracepoint/syscalls/sys_enter_execve")
int bpf_prog(void *ctx) {
    ////bpf_printk("Hello World!");
    bpf_trace_printk("Hello World!\n", 14);
    return 0;
}
