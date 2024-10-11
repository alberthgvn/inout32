#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <hw/inout.h>
#include <string.h>

int main(int argc, char *argv[]) {
	uint32_t base;
	uint32_t value;
	uintptr_t vbase;

	if (argv[1])
		base = strtol(argv[1], NULL, 16);
	else {
		printf ("Illegal option!");
		return EXIT_FAILURE;
	}
	
	vbase = mmap_device_io (4, base);

	if (argv[2]) {
		value = strtol(argv[2], NULL, 16);
		printf ("Write 0x%x: 0x%x\n", base, value);
		out32(vbase, value);
	} else {
		printf ("Read 0x%x: 0x%x\n", base, in32(vbase));
	}

	munmap ((void *)vbase,4);
	
	return EXIT_SUCCESS;
}
