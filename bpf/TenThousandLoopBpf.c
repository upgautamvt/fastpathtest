#include "vmlinux.h"
#include <bpf/bpf_helpers.h>

char LICENSE[] SEC("license") = "GPL";

//this gets triggered something like clear command from terminal
SEC("kprobe/do_exit")
int bpf_prog(struct pt_regs *ctx) {
    //start time
    __u64 start = bpf_ktime_get_ns();

    int i;

    for (i = 0; i < 10000; i++) {
        bpf_printk("");
    }

    //end time
    __u64 end = bpf_ktime_get_ns();
    __u64 delta_ns = end - start;
    bpf_printk("Elapsed time: %lld nanoseconds\n", delta_ns);

    return 0;
}

