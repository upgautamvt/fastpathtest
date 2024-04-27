/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED BY BPFTOOL! */
#ifndef __MILLIONLOOPBPF_SKEL_H__
#define __MILLIONLOOPBPF_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct MillionLoopBpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *bpf_prog;
	} progs;
	struct {
		struct bpf_link *bpf_prog;
	} links;

#ifdef __cplusplus
	static inline struct MillionLoopBpf *open(const struct bpf_object_open_opts *opts = nullptr);
	static inline struct MillionLoopBpf *open_and_load();
	static inline int load(struct MillionLoopBpf *skel);
	static inline int attach(struct MillionLoopBpf *skel);
	static inline void detach(struct MillionLoopBpf *skel);
	static inline void destroy(struct MillionLoopBpf *skel);
	static inline const void *elf_bytes(size_t *sz);
#endif /* __cplusplus */
};

static void
MillionLoopBpf__destroy(struct MillionLoopBpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
MillionLoopBpf__create_skeleton(struct MillionLoopBpf *obj);

static inline struct MillionLoopBpf *
MillionLoopBpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct MillionLoopBpf *obj;
	int err;

	obj = (struct MillionLoopBpf *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = MillionLoopBpf__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	MillionLoopBpf__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct MillionLoopBpf *
MillionLoopBpf__open(void)
{
	return MillionLoopBpf__open_opts(NULL);
}

static inline int
MillionLoopBpf__load(struct MillionLoopBpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct MillionLoopBpf *
MillionLoopBpf__open_and_load(void)
{
	struct MillionLoopBpf *obj;
	int err;

	obj = MillionLoopBpf__open();
	if (!obj)
		return NULL;
	err = MillionLoopBpf__load(obj);
	if (err) {
		MillionLoopBpf__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
MillionLoopBpf__attach(struct MillionLoopBpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
MillionLoopBpf__detach(struct MillionLoopBpf *obj)
{
	bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *MillionLoopBpf__elf_bytes(size_t *sz);

static inline int
MillionLoopBpf__create_skeleton(struct MillionLoopBpf *obj)
{
	struct bpf_object_skeleton *s;
	int err;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)	{
		err = -ENOMEM;
		goto err;
	}

	s->sz = sizeof(*s);
	s->name = "MillionLoopBpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps) {
		err = -ENOMEM;
		goto err;
	}

	s->maps[0].name = "MillionL.rodata";
	s->maps[0].map = &obj->maps.rodata;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs) {
		err = -ENOMEM;
		goto err;
	}

	s->progs[0].name = "bpf_prog";
	s->progs[0].prog = &obj->progs.bpf_prog;
	s->progs[0].link = &obj->links.bpf_prog;

	s->data = MillionLoopBpf__elf_bytes(&s->data_sz);

	obj->skeleton = s;
	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return err;
}

static inline const void *MillionLoopBpf__elf_bytes(size_t *sz)
{
	static const char data[] __attribute__((__aligned__(8))) = "\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x98\x13\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x16\0\
\x01\0\xb7\x07\0\0\x40\x42\x0f\0\x85\0\0\0\x05\0\0\0\xbf\x06\0\0\0\0\0\0\x85\0\
\0\0\x0e\0\0\0\x07\x07\0\0\xff\xff\xff\xff\x55\x07\xfd\xff\0\0\0\0\x85\0\0\0\
\x05\0\0\0\x1f\x60\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\0\
\x20\0\0\0\xbf\x03\0\0\0\0\0\0\x85\0\0\0\x06\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\
\0\0\0\0\x47\x50\x4c\0\x45\x6c\x61\x70\x73\x65\x64\x20\x74\x69\x6d\x65\x3a\x20\
\x25\x6c\x6c\x64\x20\x6e\x61\x6e\x6f\x73\x65\x63\x6f\x6e\x64\x73\x0a\0\x18\0\0\
\0\0\0\0\0\x20\0\0\0\0\0\0\0\x0b\0\x77\0\x11\xc0\x84\x3d\x1c\x11\x7f\x1b\x9f\
\x20\0\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\x0e\0\x77\0\x11\xc0\x84\x3d\x1c\x11\x7f\
\x1b\x11\x01\x22\x9f\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x78\0\0\
\0\0\0\0\0\x01\0\x56\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x78\0\0\
\0\0\0\0\0\x03\0\x11\x01\x9f\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\0\0\0\0\0\0\0\
\x40\0\0\0\0\0\0\0\x01\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\
\x68\0\0\0\0\0\0\0\x01\0\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\x11\x01\x25\
\x0e\x13\x05\x03\x0e\x10\x17\x1b\x0e\x11\x01\x12\x06\0\0\x02\x34\0\x03\x0e\x49\
\x13\x3f\x19\x3a\x0b\x3b\x0b\x02\x18\0\0\x03\x01\x01\x49\x13\0\0\x04\x21\0\x49\
\x13\x37\x0b\0\0\x05\x24\0\x03\x0e\x3e\x0b\x0b\x0b\0\0\x06\x24\0\x03\x0e\x0b\
\x0b\x3e\x0b\0\0\x07\x2e\x01\x11\x01\x12\x06\x40\x18\x97\x42\x19\x03\x0e\x3a\
\x0b\x3b\x0b\x27\x19\x49\x13\x3f\x19\0\0\x08\x34\0\x03\x0e\x49\x13\x3a\x0b\x3b\
\x0b\x02\x18\0\0\x09\x05\0\x03\x0e\x3a\x0b\x3b\x0b\x49\x13\0\0\x0a\x34\0\x02\
\x17\x03\x0e\x3a\x0b\x3b\x0b\x49\x13\0\0\x0b\x26\0\x49\x13\0\0\x0c\x34\0\x03\
\x0e\x49\x13\x3a\x0b\x3b\x0b\0\0\x0d\x0f\0\x49\x13\0\0\x0e\x15\0\x49\x13\x27\
\x19\0\0\x0f\x16\0\x49\x13\x03\x0e\x3a\x0b\x3b\x0b\0\0\x10\x34\0\x03\x0e\x49\
\x13\x3a\x0b\x3b\x05\0\0\x11\x15\x01\x49\x13\x27\x19\0\0\x12\x05\0\x49\x13\0\0\
\x13\x18\0\0\0\x14\x13\x01\x03\x0e\x0b\x0b\x3a\x0b\x3b\x05\0\0\x15\x0d\0\x03\
\x0e\x49\x13\x3a\x0b\x3b\x05\x38\x0b\0\0\0\x8c\x02\0\0\x04\0\0\0\0\0\x08\x01\0\
\0\0\0\x1d\0\x2c\0\0\0\0\0\0\0\x3d\0\0\0\0\0\0\0\0\0\0\0\x78\0\0\0\x02\x6d\0\0\
\0\x3f\0\0\0\x01\x04\x09\x03\0\0\0\0\0\0\0\0\x03\x4b\0\0\0\x04\x52\0\0\0\x04\0\
\x05\x75\0\0\0\x06\x01\x06\x7a\0\0\0\x08\x07\x07\0\0\0\0\0\0\0\0\x78\0\0\0\x01\
\x5a\x02\x01\0\0\x01\x08\x61\x01\0\0\x08\x8e\0\0\0\xde\0\0\0\x01\x18\x09\x03\0\
\0\0\0\0\0\0\0\x09\x26\x01\0\0\x01\x08\x68\x01\0\0\x0a\0\0\0\0\x0f\x01\0\0\x01\
\x0c\x43\x01\0\0\x0a\x4d\0\0\0\x11\x01\0\0\x01\x0a\x04\x01\0\0\x0a\x70\0\0\0\
\x17\x01\0\0\x01\x0d\x61\x01\0\0\x0a\x95\0\0\0\x19\x01\0\0\x01\x16\x04\x01\0\0\
\x0a\xb8\0\0\0\x1d\x01\0\0\x01\x17\x04\x01\0\0\0\x03\xea\0\0\0\x04\x52\0\0\0\
\x20\0\x0b\x4b\0\0\0\x0c\x96\0\0\0\xfa\0\0\0\x03\x72\x0d\xff\0\0\0\x0e\x04\x01\
\0\0\x0f\x0f\x01\0\0\xba\0\0\0\x02\x12\x05\xa7\0\0\0\x07\x08\x10\xc0\0\0\0\xfa\
\0\0\0\x03\x70\x01\x0c\xd9\0\0\0\x2d\x01\0\0\x03\xb1\x0d\x32\x01\0\0\x11\x43\
\x01\0\0\x12\x4a\x01\0\0\x12\x4f\x01\0\0\x13\0\x05\xea\0\0\0\x05\x08\x0d\xea\0\
\0\0\x0f\x5a\x01\0\0\xfc\0\0\0\x02\x0e\x05\xef\0\0\0\x07\x04\x05\x0b\x01\0\0\
\x05\x04\x0d\x6d\x01\0\0\x14\x85\x01\0\0\xa8\x02\x2e\x04\x15\x2a\x01\0\0\x88\
\x02\0\0\x02\x2f\x04\0\x15\x3c\x01\0\0\x88\x02\0\0\x02\x30\x04\x08\x15\x40\x01\
\0\0\x88\x02\0\0\x02\x31\x04\x10\x15\x44\x01\0\0\x88\x02\0\0\x02\x32\x04\x18\
\x15\x48\x01\0\0\x88\x02\0\0\x02\x33\x04\x20\x15\x4b\x01\0\0\x88\x02\0\0\x02\
\x34\x04\x28\x15\x4e\x01\0\0\x88\x02\0\0\x02\x35\x04\x30\x15\x52\x01\0\0\x88\
\x02\0\0\x02\x36\x04\x38\x15\x56\x01\0\0\x88\x02\0\0\x02\x37\x04\x40\x15\x59\
\x01\0\0\x88\x02\0\0\x02\x38\x04\x48\x15\x5c\x01\0\0\x88\x02\0\0\x02\x39\x04\
\x50\x15\x5f\x01\0\0\x88\x02\0\0\x02\x3a\x04\x58\x15\x62\x01\0\0\x88\x02\0\0\
\x02\x3b\x04\x60\x15\x65\x01\0\0\x88\x02\0\0\x02\x3c\x04\x68\x15\x68\x01\0\0\
\x88\x02\0\0\x02\x3d\x04\x70\x15\x6b\x01\0\0\x88\x02\0\0\x02\x3e\x04\x78\x15\
\x73\x01\0\0\x88\x02\0\0\x02\x3f\x04\x80\x15\x76\x01\0\0\x88\x02\0\0\x02\x40\
\x04\x88\x15\x79\x01\0\0\x88\x02\0\0\x02\x41\x04\x90\x15\x7f\x01\0\0\x88\x02\0\
\0\x02\x42\x04\x98\x15\x82\x01\0\0\x88\x02\0\0\x02\x43\x04\xa0\0\x05\x2e\x01\0\
\0\x07\x08\0\x63\x6c\x61\x6e\x67\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x31\x37\
\x2e\x30\x2e\x36\x20\x28\x46\x65\x64\x6f\x72\x61\x20\x31\x37\x2e\x30\x2e\x36\
\x2d\x32\x2e\x66\x63\x33\x39\x29\0\x4d\x69\x6c\x6c\x69\x6f\x6e\x4c\x6f\x6f\x70\
\x42\x70\x66\x2e\x63\0\x2f\x68\x6f\x6d\x65\x2f\x75\x70\x67\x61\x75\x74\x61\x6d\
\x76\x74\x2f\x43\x4c\x69\x6f\x6e\x50\x72\x6f\x6a\x65\x63\x74\x73\x2f\x66\x61\
\x73\x74\x70\x61\x74\x68\x74\x65\x73\x74\x2f\x62\x70\x66\0\x4c\x49\x43\x45\x4e\
\x53\x45\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\
\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x62\x70\x66\x5f\
\x6b\x74\x69\x6d\x65\x5f\x67\x65\x74\x5f\x6e\x73\0\x75\x6e\x73\x69\x67\x6e\x65\
\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x5f\x5f\x75\x36\x34\0\x62\x70\
\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\x64\x5f\x74\
\x67\x69\x64\0\x62\x70\x66\x5f\x74\x72\x61\x63\x65\x5f\x70\x72\x69\x6e\x74\x6b\
\0\x6c\x6f\x6e\x67\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x5f\x5f\
\x75\x33\x32\0\x62\x70\x66\x5f\x70\x72\x6f\x67\0\x69\x6e\x74\0\x69\0\x73\x74\
\x61\x72\x74\0\x61\0\x65\x6e\x64\0\x64\x65\x6c\x74\x61\x5f\x6e\x73\0\x63\x74\
\x78\0\x72\x31\x35\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\0\x72\
\x31\x34\0\x72\x31\x33\0\x72\x31\x32\0\x62\x70\0\x62\x78\0\x72\x31\x31\0\x72\
\x31\x30\0\x72\x39\0\x72\x38\0\x61\x78\0\x63\x78\0\x64\x78\0\x73\x69\0\x64\x69\
\0\x6f\x72\x69\x67\x5f\x61\x78\0\x69\x70\0\x63\x73\0\x66\x6c\x61\x67\x73\0\x73\
\x70\0\x73\x73\0\x70\x74\x5f\x72\x65\x67\x73\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\
\0\0\x02\0\0\0\x02\0\0\x5e\x02\0\0\0\0\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\x15\0\
\0\x04\xa8\0\0\0\x09\0\0\0\x03\0\0\0\0\0\0\0\x0d\0\0\0\x03\0\0\0\x40\0\0\0\x11\
\0\0\0\x03\0\0\0\x80\0\0\0\x15\0\0\0\x03\0\0\0\xc0\0\0\0\x19\0\0\0\x03\0\0\0\0\
\x01\0\0\x1c\0\0\0\x03\0\0\0\x40\x01\0\0\x1f\0\0\0\x03\0\0\0\x80\x01\0\0\x23\0\
\0\0\x03\0\0\0\xc0\x01\0\0\x27\0\0\0\x03\0\0\0\0\x02\0\0\x2a\0\0\0\x03\0\0\0\
\x40\x02\0\0\x2d\0\0\0\x03\0\0\0\x80\x02\0\0\x30\0\0\0\x03\0\0\0\xc0\x02\0\0\
\x33\0\0\0\x03\0\0\0\0\x03\0\0\x36\0\0\0\x03\0\0\0\x40\x03\0\0\x39\0\0\0\x03\0\
\0\0\x80\x03\0\0\x3c\0\0\0\x03\0\0\0\xc0\x03\0\0\x44\0\0\0\x03\0\0\0\0\x04\0\0\
\x47\0\0\0\x03\0\0\0\x40\x04\0\0\x4a\0\0\0\x03\0\0\0\x80\x04\0\0\x50\0\0\0\x03\
\0\0\0\xc0\x04\0\0\x53\0\0\0\x03\0\0\0\0\x05\0\0\x56\0\0\0\0\0\0\x01\x08\0\0\0\
\x40\0\0\0\0\0\0\0\x01\0\0\x0d\x05\0\0\0\x64\0\0\0\x01\0\0\0\x68\0\0\0\0\0\0\
\x01\x04\0\0\0\x20\0\0\x01\x6c\0\0\0\x01\0\0\x0c\x04\0\0\0\x1c\x02\0\0\0\0\0\
\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x07\0\0\0\x09\0\0\0\x04\0\
\0\0\x21\x02\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\x35\x02\0\0\0\0\0\x0e\x08\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\x0a\x07\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0b\0\0\0\x09\
\0\0\0\x20\0\0\0\x3d\x02\0\0\0\0\0\x0e\x0c\0\0\0\0\0\0\0\x4e\x02\0\0\x01\0\0\
\x0f\0\0\0\0\x0d\0\0\0\0\0\0\0\x20\0\0\0\x56\x02\0\0\x01\0\0\x0f\0\0\0\0\x0a\0\
\0\0\0\0\0\0\x04\0\0\0\0\x70\x74\x5f\x72\x65\x67\x73\0\x72\x31\x35\0\x72\x31\
\x34\0\x72\x31\x33\0\x72\x31\x32\0\x62\x70\0\x62\x78\0\x72\x31\x31\0\x72\x31\
\x30\0\x72\x39\0\x72\x38\0\x61\x78\0\x63\x78\0\x64\x78\0\x73\x69\0\x64\x69\0\
\x6f\x72\x69\x67\x5f\x61\x78\0\x69\x70\0\x63\x73\0\x66\x6c\x61\x67\x73\0\x73\
\x70\0\x73\x73\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x6c\x6f\x6e\x67\0\x63\x74\
\x78\0\x69\x6e\x74\0\x62\x70\x66\x5f\x70\x72\x6f\x67\0\x6b\x70\x72\x6f\x62\x65\
\x2f\x64\x6f\x5f\x65\x78\x69\x74\0\x2f\x68\x6f\x6d\x65\x2f\x75\x70\x67\x61\x75\
\x74\x61\x6d\x76\x74\x2f\x43\x4c\x69\x6f\x6e\x50\x72\x6f\x6a\x65\x63\x74\x73\
\x2f\x66\x61\x73\x74\x70\x61\x74\x68\x74\x65\x73\x74\x2f\x62\x70\x66\x2f\x4d\
\x69\x6c\x6c\x69\x6f\x6e\x4c\x6f\x6f\x70\x42\x70\x66\x2e\x63\0\x69\x6e\x74\x20\
\x62\x70\x66\x5f\x70\x72\x6f\x67\x28\x73\x74\x72\x75\x63\x74\x20\x70\x74\x5f\
\x72\x65\x67\x73\x20\x2a\x63\x74\x78\x29\x20\x7b\0\x20\x20\x20\x20\x5f\x5f\x75\
\x36\x34\x20\x73\x74\x61\x72\x74\x20\x3d\x20\x62\x70\x66\x5f\x6b\x74\x69\x6d\
\x65\x5f\x67\x65\x74\x5f\x6e\x73\x28\x29\x3b\0\x20\x20\x20\x20\x20\x20\x20\x20\
\x62\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\x64\
\x5f\x74\x67\x69\x64\x28\x29\x20\x26\x20\x30\x78\x66\x66\x66\x66\x66\x66\x66\
\x66\x3b\x20\x2f\x2f\x6f\x72\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\
\x72\x65\x6e\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\x64\x28\x29\x20\x3e\x3e\x20\
\x33\x32\0\x20\x20\x20\x20\x66\x6f\x72\x20\x28\x69\x20\x3d\x20\x30\x3b\x20\x69\
\x20\x3c\x20\x31\x30\x30\x30\x30\x30\x30\x3b\x20\x69\x2b\x2b\x29\x20\x7b\0\x20\
\x20\x20\x20\x5f\x5f\x75\x36\x34\x20\x65\x6e\x64\x20\x3d\x20\x62\x70\x66\x5f\
\x6b\x74\x69\x6d\x65\x5f\x67\x65\x74\x5f\x6e\x73\x28\x29\x3b\0\x20\x20\x20\x20\
\x5f\x5f\x75\x36\x34\x20\x64\x65\x6c\x74\x61\x5f\x6e\x73\x20\x3d\x20\x65\x6e\
\x64\x20\x2d\x20\x73\x74\x61\x72\x74\x3b\0\x20\x20\x20\x20\x62\x70\x66\x5f\x70\
\x72\x69\x6e\x74\x6b\x28\x22\x45\x6c\x61\x70\x73\x65\x64\x20\x74\x69\x6d\x65\
\x3a\x20\x25\x6c\x6c\x64\x20\x6e\x61\x6e\x6f\x73\x65\x63\x6f\x6e\x64\x73\x5c\
\x6e\x22\x2c\x20\x64\x65\x6c\x74\x61\x5f\x6e\x73\x29\x3b\0\x20\x20\x20\x20\x72\
\x65\x74\x75\x72\x6e\x20\x30\x3b\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\
\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x4c\x49\x43\x45\x4e\x53\
\x45\0\x62\x70\x66\x5f\x70\x72\x6f\x67\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x2e\
\x72\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\0\0\0\x9f\xeb\x01\0\x20\
\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x9c\0\0\0\xb0\0\0\0\0\0\0\0\x08\0\0\0\x75\0\
\0\0\x01\0\0\0\0\0\0\0\x06\0\0\0\x10\0\0\0\x75\0\0\0\x09\0\0\0\0\0\0\0\x84\0\0\
\0\xc5\0\0\0\0\x20\0\0\x08\0\0\0\x84\0\0\0\xe9\0\0\0\x13\x28\0\0\x18\0\0\0\x84\
\0\0\0\x0f\x01\0\0\x09\x44\0\0\x20\0\0\0\x84\0\0\0\x66\x01\0\0\x13\x3c\0\0\x28\
\0\0\0\x84\0\0\0\x66\x01\0\0\x05\x3c\0\0\x30\0\0\0\x84\0\0\0\x8a\x01\0\0\x11\
\x58\0\0\x38\0\0\0\x84\0\0\0\xae\x01\0\0\x1a\x5c\0\0\x40\0\0\0\x84\0\0\0\xd0\
\x01\0\0\x05\x60\0\0\x68\0\0\0\x84\0\0\0\x0e\x02\0\0\x05\x68\0\0\0\0\0\0\x0c\0\
\0\0\xff\xff\xff\xff\x04\0\x08\0\x08\x7c\x0b\0\x14\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x78\0\0\0\0\0\0\0\x8d\0\0\0\x04\0\x5d\0\0\0\x08\x01\x01\xfb\x0e\x0d\0\x01\
\x01\x01\x01\0\0\0\x01\0\0\x01\x2e\0\x2f\x75\x73\x72\x2f\x69\x6e\x63\x6c\x75\
\x64\x65\x2f\x62\x70\x66\0\0\x4d\x69\x6c\x6c\x69\x6f\x6e\x4c\x6f\x6f\x70\x42\
\x70\x66\x2e\x63\0\0\0\0\x76\x6d\x6c\x69\x6e\x75\x78\x2e\x68\0\x01\0\0\x62\x70\
\x66\x5f\x68\x65\x6c\x70\x65\x72\x5f\x64\x65\x66\x73\x2e\x68\0\x02\0\0\0\0\x09\
\x02\0\0\0\0\0\0\0\0\x19\x05\x13\x0a\x22\x05\x09\x35\x05\x13\x1e\x05\x05\x06\
\x20\x05\x11\x06\x27\x05\x1a\x21\x05\x05\x21\x5a\x02\x02\0\x01\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xac\0\0\0\x04\0\xf1\xff\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xe6\0\0\0\0\0\x03\0\x18\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x22\0\0\0\x01\0\x06\0\
\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\x03\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x03\0\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x08\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x0b\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x03\0\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x12\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\x78\0\
\0\0\0\0\0\0\xde\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x40\0\0\0\
\0\0\0\0\x01\0\0\0\x05\0\0\0\x06\0\0\0\0\0\0\0\x03\0\0\0\x07\0\0\0\x0c\0\0\0\0\
\0\0\0\x03\0\0\0\x08\0\0\0\x12\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x16\0\0\0\0\0\
\0\0\x03\0\0\0\x0a\0\0\0\x1a\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x1e\0\0\0\0\0\0\
\0\x02\0\0\0\x02\0\0\0\x2b\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x37\0\0\0\0\0\0\0\
\x02\0\0\0\x0c\0\0\0\x4c\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x53\0\0\0\0\0\0\0\
\x03\0\0\0\x08\0\0\0\x5a\0\0\0\0\0\0\0\x02\0\0\0\x02\0\0\0\x68\0\0\0\0\0\0\0\
\x03\0\0\0\x08\0\0\0\x73\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x7f\0\0\0\0\0\0\0\
\x02\0\0\0\x05\0\0\0\x88\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x93\0\0\0\0\0\0\0\
\x03\0\0\0\x06\0\0\0\x97\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xa2\0\0\0\0\0\0\0\
\x03\0\0\0\x06\0\0\0\xa6\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xb1\0\0\0\0\0\0\0\
\x03\0\0\0\x06\0\0\0\xb5\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xc0\0\0\0\0\0\0\0\
\x03\0\0\0\x06\0\0\0\xc4\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xcf\0\0\0\0\0\0\0\
\x03\0\0\0\x06\0\0\0\xd3\0\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xf0\0\0\0\0\0\0\0\
\x03\0\0\0\x08\0\0\0\x09\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x10\x01\0\0\0\0\0\
\0\x03\0\0\0\x08\0\0\0\x17\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x23\x01\0\0\0\0\
\0\0\x03\0\0\0\x08\0\0\0\x44\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x54\x01\0\0\0\
\0\0\0\x03\0\0\0\x08\0\0\0\x5b\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x62\x01\0\0\
\0\0\0\0\x03\0\0\0\x08\0\0\0\x6e\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x77\x01\0\
\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x84\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x91\x01\
\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x9e\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xab\
\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xb8\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\
\xc5\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xd2\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\
\0\xdf\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\xec\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\
\0\0\xf9\x01\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x06\x02\0\0\0\0\0\0\x03\0\0\0\x08\
\0\0\0\x13\x02\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x20\x02\0\0\0\0\0\0\x03\0\0\0\
\x08\0\0\0\x2d\x02\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x3a\x02\0\0\0\0\0\0\x03\0\0\
\0\x08\0\0\0\x47\x02\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x54\x02\0\0\0\0\0\0\x03\0\
\0\0\x08\0\0\0\x61\x02\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x6e\x02\0\0\0\0\0\0\x03\
\0\0\0\x08\0\0\0\x7b\x02\0\0\0\0\0\0\x03\0\0\0\x08\0\0\0\x89\x02\0\0\0\0\0\0\
\x03\0\0\0\x08\0\0\0\xf8\x01\0\0\0\0\0\0\x03\0\0\0\x05\0\0\0\x10\x02\0\0\0\0\0\
\0\x04\0\0\0\x0c\0\0\0\x2c\0\0\0\0\0\0\0\x04\0\0\0\x02\0\0\0\x40\0\0\0\0\0\0\0\
\x04\0\0\0\x02\0\0\0\x50\0\0\0\0\0\0\0\x04\0\0\0\x02\0\0\0\x60\0\0\0\0\0\0\0\
\x04\0\0\0\x02\0\0\0\x70\0\0\0\0\0\0\0\x04\0\0\0\x02\0\0\0\x80\0\0\0\0\0\0\0\
\x04\0\0\0\x02\0\0\0\x90\0\0\0\0\0\0\0\x04\0\0\0\x02\0\0\0\xa0\0\0\0\0\0\0\0\
\x04\0\0\0\x02\0\0\0\xb0\0\0\0\0\0\0\0\x04\0\0\0\x02\0\0\0\xc0\0\0\0\0\0\0\0\
\x04\0\0\0\x02\0\0\0\x14\0\0\0\0\0\0\0\x03\0\0\0\x09\0\0\0\x18\0\0\0\0\0\0\0\
\x02\0\0\0\x02\0\0\0\x6a\0\0\0\0\0\0\0\x02\0\0\0\x02\0\0\0\x0b\x0c\x04\0\x2e\
\x64\x65\x62\x75\x67\x5f\x61\x62\x62\x72\x65\x76\0\x2e\x74\x65\x78\x74\0\x2e\
\x72\x65\x6c\x2e\x42\x54\x46\x2e\x65\x78\x74\0\x62\x70\x66\x5f\x70\x72\x6f\x67\
\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x2e\x72\x65\x6c\x6b\x70\x72\x6f\x62\x65\x2f\
\x64\x6f\x5f\x65\x78\x69\x74\0\x2e\x64\x65\x62\x75\x67\x5f\x73\x74\x72\0\x2e\
\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x69\x6e\x66\x6f\0\x62\x70\x66\x5f\x70\
\x72\x6f\x67\0\x2e\x6c\x6c\x76\x6d\x5f\x61\x64\x64\x72\x73\x69\x67\0\x6c\x69\
\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x6c\x69\x6e\
\x65\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x66\x72\x61\x6d\x65\0\x2e\
\x64\x65\x62\x75\x67\x5f\x6c\x6f\x63\0\x4d\x69\x6c\x6c\x69\x6f\x6e\x4c\x6f\x6f\
\x70\x42\x70\x66\x2e\x63\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\
\x61\x62\0\x2e\x72\x6f\x64\x61\x74\x61\0\x2e\x72\x65\x6c\x2e\x42\x54\x46\0\x4c\
\x49\x43\x45\x4e\x53\x45\0\x4c\x42\x42\x30\x5f\x31\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\xbd\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xab\x12\0\0\0\0\0\0\xed\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x0f\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x37\0\0\
\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x78\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x33\0\0\0\x09\0\0\0\x40\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\x0e\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x15\0\0\0\
\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x78\0\0\0\x01\0\0\0\x03\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xb8\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xcd\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\xbc\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xa1\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xdc\0\0\0\0\
\0\0\0\xdb\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\
\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\xff\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x55\0\0\0\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb6\x02\0\0\0\0\0\0\x90\x02\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x51\0\0\0\x09\0\0\0\x40\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x28\x0e\0\0\0\0\0\0\x90\x03\0\0\0\0\0\0\x15\0\0\0\x09\0\0\
\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x46\0\0\0\x01\0\0\0\x30\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x46\x05\0\0\0\0\0\0\x8d\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\
\0\0\0\0\0\x01\0\0\0\0\0\0\0\xd9\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xd4\x06\0\0\0\0\0\0\x76\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\xd5\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\x11\0\
\0\0\0\0\0\x20\0\0\0\0\0\0\0\x15\0\0\0\x0c\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\
\0\0\0\x19\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4c\x0b\0\0\0\0\0\0\
\xd0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x15\0\0\0\
\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd8\x11\0\0\0\0\0\0\xa0\0\0\0\0\0\
\0\0\x15\0\0\0\x0e\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x94\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x0c\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x90\0\0\0\x09\0\0\0\x40\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x78\x12\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x15\0\0\0\x10\0\0\0\
\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x84\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x48\x0c\0\0\0\0\0\0\x91\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x80\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x98\
\x12\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x15\0\0\0\x12\0\0\0\x08\0\0\0\0\0\0\0\x10\0\
\0\0\0\0\0\0\x6a\0\0\0\x03\x4c\xff\x6f\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\xa8\
\x12\0\0\0\0\0\0\x03\0\0\0\0\0\0\0\x15\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xc5\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\x0c\0\0\0\0\0\
\0\x38\x01\0\0\0\0\0\0\x01\0\0\0\x0b\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0";

	*sz = sizeof(data) - 1;
	return (const void *)data;
}

#ifdef __cplusplus
struct MillionLoopBpf *MillionLoopBpf::open(const struct bpf_object_open_opts *opts) { return MillionLoopBpf__open_opts(opts); }
struct MillionLoopBpf *MillionLoopBpf::open_and_load() { return MillionLoopBpf__open_and_load(); }
int MillionLoopBpf::load(struct MillionLoopBpf *skel) { return MillionLoopBpf__load(skel); }
int MillionLoopBpf::attach(struct MillionLoopBpf *skel) { return MillionLoopBpf__attach(skel); }
void MillionLoopBpf::detach(struct MillionLoopBpf *skel) { MillionLoopBpf__detach(skel); }
void MillionLoopBpf::destroy(struct MillionLoopBpf *skel) { MillionLoopBpf__destroy(skel); }
const void *MillionLoopBpf::elf_bytes(size_t *sz) { return MillionLoopBpf__elf_bytes(sz); }
#endif /* __cplusplus */

__attribute__((unused)) static void
MillionLoopBpf__assert(struct MillionLoopBpf *s __attribute__((unused)))
{
#ifdef __cplusplus
#define _Static_assert static_assert
#endif
#ifdef __cplusplus
#undef _Static_assert
#endif
}

#endif /* __MILLIONLOOPBPF_SKEL_H__ */
