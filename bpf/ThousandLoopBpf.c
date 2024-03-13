#include "vmlinux.h"
#include <bpf/bpf_helpers.h>

char LICENSE[] SEC("license") = "GPL";

SEC("tracepoint/syscalls/sys_enter_execve")
int bpf_prog(struct pt_regs *ctx) {
    __u64 sum = 0;
    int i;

    for (i = 0; i < 2; i++) {
        sum += bpf_get_current_pid_tgid(); //although it is same pid, I want to call inside loop
    }

    bpf_printk("Answer is %lld\n", sum);
    return 0;
}
