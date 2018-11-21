#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <drv.h>
#include <sysc.h>

#if ENABLE_DEBUG
int verbose = 1;
#else
int verbose = 0;
#endif

int
LLVMFuzzerTestOneInput(const uint8_t*, size_t);

int
main(int argc, char**argv)
{
    int ret = 0;
    int count = 0;

    // Read payload from stdin
    size_t size = 1024;
    uint8_t *data = malloc(size);
    memset(data, 0, size);
    count = read(0, data, size);

    // Run test
    ret = LLVMFuzzerTestOneInput(data, size);

    return ret;
}

static int
test_func(int one, int two, int three, int four, int five, int six)
{
    return 0;
}

int
LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    int err = 0;

    struct sysRec calls[2];
    int ncalls = 0;

    // Parse Fuzz Arguments
    err = parse_call_args(data, size, calls, &ncalls);
    if (err) {
	perror("parse_call_args");
    }

    // Call function with fuzzed agruments
    test_func(calls[0].args[0],
	      calls[0].args[1],
	      calls[0].args[2],
	      calls[0].args[3],
	      calls[0].args[4],
	      calls[0].args[5]);

    return err;
}
