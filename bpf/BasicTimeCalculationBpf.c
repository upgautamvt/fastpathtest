#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <linux/sched.h>

char LICENSE[] SEC("license") = "GPL";

SEC("tracepoint/syscalls/sys_enter_execve")
int bpf_prog(struct pt_regs *ctx) {
    __u64 start = bpf_ktime_get_ns();


    __u64 end = bpf_ktime_get_ns();
    __u64 delta_ns = end - start;
    bpf_printk("Elapsed time: %lld nanoseconds\n", delta_ns);

    return 0;
}
