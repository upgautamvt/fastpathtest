#include "vmlinux.h"
#include <bpf/bpf_helpers.h>

char LICENSE[] SEC("license") = "GPL";

//this gets triggered something like clear command from terminal
SEC("kprobe/do_exit")
int bpf_prog(struct pt_regs *ctx) {
    //start time
    __u64 start = bpf_ktime_get_ns();



    int i;

    //sleep simulation
    // Define the sleep duration in nanoseconds (500 milliseconds)
    __u64 sleep_duration_ns = 450000 * 1000000;

    // Get the current time in nanoseconds
    __u64 start_time = bpf_ktime_get_ns();
    __u64 end_time = start_time + sleep_duration_ns;

    for (i = 0; i < 250; i++) {
        //bpf_printk("\n");
        bpf_get_current_pid_tgid() & 0xffffffff; //or bpf_get_current_pid_tgid() >> 32

        // Sleep loop
        while (1) {
            __u64 current_time = bpf_ktime_get_ns();
            if (current_time >= end_time) {
                break;
            }
        }

    }

    //end time
    __u64 end = bpf_ktime_get_ns();
    __u64 delta_ns = end - start;
    bpf_printk("Elapsed time: %lld nanoseconds\n", delta_ns);

    return 0;
}

