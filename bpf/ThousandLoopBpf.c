#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

char LICENSE[] SEC("license") = "GPL";

SEC("kprobe/sys_getpid")
int bpf_prog(struct pt_regs *ctx) {
    //start time
    __u64 start = bpf_ktime_get_ns();

    int i;

    for (i = 0; i < 1000; i++) {
        bpf_get_current_pid_tgid(); //although it is same pid, I want to call inside loop
    }

    //end time
    __u64 end = bpf_ktime_get_ns();
    __u64 delta_ns = end - start;
    bpf_printk("Elapsed time: %lld nanoseconds\n", delta_ns);

    return 0;
}

