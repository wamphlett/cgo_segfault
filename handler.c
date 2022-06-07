#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <execinfo.h>

int *p;
// testSig is a helper fxn that causes an intention SIGSEGV, it can be used to test
// that signals are handled as expected.
void testSig(int i) {
	// Call testSig recursively a few times to build up the stack for more
	// interesting backtrace output.
	if (i == 3) {
		printf("Causing intention SIGSEGV\n");
		fflush(stdout);
		// Assignment to undefined memory address causes segfault.
		*p = 1;
	}
	testSig(++i);
}
