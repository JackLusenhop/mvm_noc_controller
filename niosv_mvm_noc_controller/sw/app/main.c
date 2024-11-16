#include <stdio.h>
#include <system.h>
#include <io.h>
#include <unistd.h>

// Using usleep as the delay funciton
int usleep(useconds_t usec);

int main(void)
{
	printf("Application to run the mvm noc \n");

	printf("Sending mvm noc input data \n");
	// Write input data
	IOWR(MVM_NOC_BASE, 1, 0x01010101);
	IOWR(MVM_NOC_BASE, 2, 0x01020102);
	IOWR(MVM_NOC_BASE, 3, 0x03010301);
	IOWR(MVM_NOC_BASE, 4, 0x01010104);

	// Read back data that was just written
	printf("DATA READBACK FROM MVM_INPUT_REG_1 is 0x%x \n",IORD(MVM_NOC_BASE, 1));
	printf("DATA READBACK FROM MVM_INPUT_REG_2 is 0x%x \n",IORD(MVM_NOC_BASE, 2));
	printf("DATA READBACK FROM MVM_INPUT_REG_3 is 0x%x \n",IORD(MVM_NOC_BASE, 3));
	printf("DATA READBACK FROM MVM_INPUT_REG_4 is 0x%x \n",IORD(MVM_NOC_BASE, 4));

	// Send input
	IOWR(MVM_NOC_BASE, 0, 0x00000043);

	printf("Sending mvm noc instruction\n");
	// Write instruction data
	IOWR(MVM_NOC_BASE, 5, 0x80C0200C);

	// Read back instuction data that was written
	printf("DATA READBACK FROM MVM_INSTR_REG_1 is 0x%x \n",IORD(MVM_NOC_BASE, 5));

	// Send instruction
	IOWR(MVM_NOC_BASE, 0, 0x00000003);

	usleep(20);

	printf("DATA READBACK FROM MVM_OUTPUT_REG_1 is 0x%x \n",IORD(MVM_NOC_BASE, 6));
	printf("DATA READBACK FROM MVM_OUTPUT_REG_1 is 0x%x \n",IORD(MVM_NOC_BASE, 7));
	printf("DATA READBACK FROM MVM_OUTPUT_REG_1 is 0x%x \n",IORD(MVM_NOC_BASE, 8));
	printf("DATA READBACK FROM MVM_OUTPUT_REG_1 is 0x%x \n",IORD(MVM_NOC_BASE, 9));

	return 0;
}
