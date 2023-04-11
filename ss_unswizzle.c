// Code from Ack, June 13,2020. Source: https://www.arcade-projects.com/threads/samurai-shodown-v-perfect-on-real-hardware.13565/page-2
// C Source Code
// indent -bl -bli0 -fc1 -cli2 -ts2 ss_unswizzle.c
// gcc -o ss_unswizzle ss_unswizzle.c
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
int
main (int argc, char **argv)
{
	FILE *input, *output1, *output2;
	uint8_t tile[128];
	uint8_t *offset;
	uint8_t x_offset, y_offset, block, data, row;
	int i;
	uint8_t planes[4];
	if (argc < 4)
	{
		printf ("ss-unsizzle <input file> <output odd> <ouput even>\n");
		return 1;
	}
	input = fopen (argv[1], "r");
	if (!input)
	{
		printf ("Error: unable to open %s for reading.\n", argv[1]);
		return 1;
	}
	output1 = fopen (argv[2], "w");
	if (!output1)
	{
		printf ("Error: unable to open %s for writing.\n", argv[2]);
		return 1;
	}
	output2 = fopen (argv[3], "w");
	if (!output2)
	{
		printf ("Error: unable to open %s for writing.\n", argv[3]);
		return 1;
	}
	while (fread (tile, 1, 128, input) == 128)
	{
		for (block = 0; block < 4; block++)
		{
			// x/y_offset get us into the correct block
			switch (block)
			{
				case 0:
					x_offset = 4;
					y_offset = 0;
					break;
				case 1:
					x_offset = 4;
					y_offset = 8;
					break;
				case 2:
					x_offset = 0;
					y_offset = 0;
					break;
				case 3:
					x_offset = 0;
					y_offset = 8;
					break;
			}
			// traverse each row of the block
			for (row = 0; row < 8; row++)
			{
				planes[0] = 0;
				planes[1] = 0;
				planes[2] = 0;
				planes[3] = 0;

				offset = &tile[x_offset + (y_offset * 8) + (row * 8)];

				for (i = 3; i >= 0; i--)
				{
					data = offset[i];
					planes[0] = planes[0] << 1;
					planes[0] = planes[0] | ((data >> 4) & 0x1);
					planes[0] = planes[0] << 1;
					planes[0] = planes[0] | ((data >> 0) & 0x1);
					planes[1] = planes[1] << 1;
					planes[1] = planes[1] | ((data >> 5) & 0x1);
					planes[1] = planes[1] << 1;
					planes[1] = planes[1] | ((data >> 1) & 0x1);
					planes[2] = planes[2] << 1;
					planes[2] = planes[2] | ((data >> 6) & 0x1);
					planes[2] = planes[2] << 1;
					planes[2] = planes[2] | ((data >> 2) & 0x1);
					planes[3] = planes[3] << 1;
					planes[3] = planes[3] | ((data >> 7) & 0x1);
					planes[3] = planes[3] << 1;
					planes[3] = planes[3] | ((data >> 3) & 0x1);
				}
				fwrite (&planes[0], 1, 1, output1);
				fwrite (&planes[1], 1, 1, output1);
				fwrite (&planes[2], 1, 1, output2);
				fwrite (&planes[3], 1, 1, output2);
			}
		}
	}
	fclose (input);
	fclose (output1);
	fclose (output2);
}

// You would wanna do something like this
//$ ./ss_unswizzle SamuraiShodown5_FE.sprites.swizzled odd even




