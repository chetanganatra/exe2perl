/* Reverse Engineered by Chetan Ganatra
	Email: ganatrac@infotech.icici.com
	18 Jan,2002
	Here's a small C code which I have written to extract the perl scripts
	from
	the .exe generated by perl2exe module Ver 5.03 on Windows
	You will find perl2exe at www.perl2exe.com or at www.indigostar.com
	Enjoy !!!!
	[TOOL] Perl2Exe Reverse Perl Extractor

	Pass the generated exe file name as a parameter to the program and
	it will give the output on screen! u can redirect it to .pl

	exec2pl [exe.file] > [pl.file]

	For any suggestions and improvements do email me at
	ganatrac@infotech.icici.com
*/

#include <stdio.h>
#include <stdlib.h>
unsigned int ctrl[3][46]={
		{	0x4c,0x65,0x78,0x2a,0x67,0x65,0x78,0x6f,0x2a,0x63,0x64,0x6c,0x65,0x78,0x67,0x6b,0x7e,0x63,0x65,0x64,0x2a},
		{	0x4b,0x62,0x7f,0x2d,0x60,0x62,0x7f,0x68,0x2d,0x64,0x63,0x6b,0x62,0x7f,0x60,0x6c,0x79,0x64,0x62,0x63,0x2d},
		{	0x66,0x4f,0x52,0x0,0x4d,0x4f,0x52,0x45,0x0,0x49,0x4e,0x46,0x4f,0x52,0x4d,0x41,0x54,0x49,0x4f,0x4e,0x0,0x56}
	};

unsigned int cipher[96][46]={
		{ 0x66,0x4f,0x52, 0x0,0x4d,0x4f,0x52,0x45,0x0,0x49,0x4e,0x46,0x4f,0x52,0x4d,0x41,0x54,0x49,0x4f,0x4e, 0x0,0x56,0x49,0x53,0x49,0x54,0x0,0x57,0x57, 0x57,0xe,0x49,0x4e,0x44,0x49,0x47,0x4f,0x53,0x54,0x41,0x52,0xe,0x43,0x4f,0x4d,0x66 },
		{ 0x67,0x4e,0x53, 0x1,0x4c,0x4e,0x53,0x44,0x1,0x48,0x4f,0x47,0x4e,0x53,0x4c,0x40,0x55,0x48,0x4e,0x4f, 0x1,0x57,0x48,0x52,0x48,0x55,0x1,0x56,0x56, 0x56,0xf,0x48,0x4f,0x45,0x48,0x46,0x4e,0x52,0x55,0x40,0x53,0xf,0x42,0x4e,0x4c,0x67 },
		{ 0x64,0x4d,0x50, 0x2,0x4f,0x4d,0x50,0x47,0x2,0x4b,0x4c,0x44,0x4d,0x50,0x4f,0x43,0x56,0x4b,0x4d,0x4c, 0x2,0x54,0x4b,0x51,0x4b,0x56,0x2,0x55,0x55, 0x55,0xc,0x4b,0x4c,0x46,0x4b,0x45,0x4d,0x51,0x56,0x43,0x50,0xc,0x41,0x4d,0x4f,0x64 },
		{ 0x65,0x4c,0x51, 0x3,0x4e,0x4c,0x51,0x46,0x3,0x4a,0x4d,0x45,0x4c,0x51,0x4e,0x42,0x57,0x4a,0x4c,0x4d, 0x3,0x55,0x4a,0x50,0x4a,0x57,0x3,0x54,0x54, 0x54,0xd,0x4a,0x4d,0x47,0x4a,0x44,0x4c,0x50,0x57,0x42,0x51,0xd,0x40,0x4c,0x4e,0x65 },
		{ 0x62,0x4b,0x56, 0x4,0x49,0x4b,0x56,0x41,0x4,0x4d,0x4a,0x42,0x4b,0x56,0x49,0x45,0x50,0x4d,0x4b,0x4a, 0x4,0x52,0x4d,0x57,0x4d,0x50,0x4,0x53,0x53, 0x53,0xa,0x4d,0x4a,0x40,0x4d,0x43,0x4b,0x57,0x50,0x45,0x56,0xa,0x47,0x4b,0x49,0x62 },
		{ 0x63,0x4a,0x57,0x5,0x48,0x4a,0x57,0x40,0x5,0x4c,0x4b,0x43,0x4a,0x57,0x48,0x44,0x51,0x4c,0x4a,0x4b,0x5,0x53 },
		{ 0x60,0x49,0x54, 0x6,0x4b,0x49,0x54,0x43,0x6,0x4f,0x48,0x40,0x49,0x54,0x4b,0x47,0x52,0x4f,0x49,0x48, 0x6,0x50,0x4f,0x55,0x4f,0x52,0x6,0x51,0x51, 0x51,0x8,0x4f,0x48,0x42,0x4f,0x41,0x49,0x55,0x52,0x47,0x54,0x8,0x45,0x49,0x4b,0x60 },
		{ 0x61,0x48,0x55, 0x7,0x4a,0x48,0x55,0x42,0x7,0x4e,0x49,0x41,0x48,0x55,0x4a,0x46,0x53,0x4e,0x48,0x49, 0x7,0x51,0x4e,0x54,0x4e,0x53,0x7,0x50,0x50, 0x50,0x9,0x4e,0x49,0x43,0x4e,0x40,0x48,0x54,0x53,0x46,0x55,0x9,0x44,0x48,0x4a,0x61 },
		{ 0x6e,0x47,0x5a, 0x8,0x45,0x47,0x5a,0x4d,0x8,0x41,0x46,0x4e,0x47,0x5a,0x45,0x49,0x5c,0x41,0x47,0x46, 0x8,0x5e,0x41,0x5b,0x41,0x5c,0x8,0x5f,0x5f, 0x5f,0x6,0x41,0x46,0x4c,0x41,0x4f,0x47,0x5b,0x5c,0x49,0x5a,0x6,0x4b,0x47,0x45,0x6e },
		{ 0x6f,0x46,0x5b, 0x9,0x44,0x46,0x5b,0x4c,0x9,0x40,0x47,0x4f,0x46,0x5b,0x44,0x48,0x5d,0x40,0x46,0x47, 0x9,0x5f,0x40,0x5a,0x40,0x5d,0x9,0x5e,0x5e, 0x5e,0x7,0x40,0x47,0x4d,0x40,0x4e,0x46,0x5a,0x5d,0x48,0x5b,0x7,0x4a,0x46,0x44,0x6f },
		{ 0x6c,0x45,0x58, 0xa,0x47,0x45,0x58,0x4f,0xa,0x43,0x44,0x4c,0x45,0x58,0x47,0x4b,0x5e,0x43,0x45,0x44, 0xa,0x5c,0x43,0x59,0x43,0x5e,0xa,0x5d,0x5d, 0x5d,0x4,0x43,0x44,0x4e,0x43,0x4d,0x45,0x59,0x5e,0x4b,0x58,0x4,0x49,0x45,0x47,0x6c },
		{ 0x6d,0x44,0x59, 0xb,0x46,0x44,0x59,0x4e,0xb,0x42,0x45,0x4d,0x44,0x59,0x46,0x4a,0x5f,0x42,0x44,0x45, 0xb,0x5d,0x42,0x58,0x42,0x5f,0xb,0x5c,0x5c, 0x5c,0x5,0x42,0x45,0x4f,0x42,0x4c,0x44,0x58,0x5f,0x4a,0x59,0x5,0x48,0x44,0x46,0x6d },
		{ 0x6a,0x43,0x5e, 0xc,0x41,0x43,0x5e,0x49,0xc,0x45,0x42,0x4a,0x43,0x5e,0x41,0x4d,0x58,0x45,0x43,0x42, 0xc,0x5a,0x45,0x5f,0x45,0x58,0xc,0x5b,0x5b, 0x5b,0x2,0x45,0x42,0x48,0x45,0x4b,0x43,0x5f,0x58,0x4d,0x5e,0x2,0x4f,0x43,0x41,0x6a },
		{ 0x6b,0x42,0x5f, 0xd,0x40,0x42,0x5f,0x48,0xd,0x44,0x43,0x4b,0x42,0x5f,0x40,0x4c,0x59,0x44,0x42,0x43, 0xd,0x5b,0x44,0x5e,0x44,0x59,0xd,0x5a,0x5a, 0x5a,0x3,0x44,0x43,0x49,0x44,0x4a,0x42,0x5e,0x59,0x4c,0x5f,0x3,0x4e,0x42,0x40,0x6b },
		{ 0x68,0x41,0x5c, 0xe,0x43,0x41,0x5c,0x4b,0xe,0x47,0x40,0x48,0x41,0x5c,0x43,0x4f,0x5a,0x47,0x41,0x40, 0xe,0x58,0x47,0x5d,0x47,0x5a,0xe,0x59,0x59, 0x59,0x0,0x47,0x40,0x4a,0x47,0x49,0x41,0x5d,0x5a,0x4f,0x5c,0x0,0x4d,0x41,0x43,0x68 },
		{ 0x69,0x40,0x5d, 0xf,0x42,0x40,0x5d,0x4a,0xf,0x46,0x41,0x49,0x40,0x5d,0x42,0x4e,0x5b,0x46,0x40,0x41, 0xf,0x59,0x46,0x5c,0x46,0x5b,0xf,0x58,0x58, 0x58,0x1,0x46,0x41,0x4b,0x46,0x48,0x40,0x5c,0x5b,0x4e,0x5d,0x1,0x4c,0x40,0x42,0x69 },
		{ 0x76,0x5f,0x42,0x10,0x5d,0x5f,0x42,0x55,0x10,0x59,0x5e,0x56,0x5f,0x42,0x5d,0x51,0x44,0x59,0x5f,0x5e,0x10,0x4 },
		{ 0x77,0x5e,0x43,0x11,0x5c,0x5e,0x43,0x54,0x11,0x58,0x5f,0x57,0x5e,0x43,0x5c,0x50,0x45,0x58,0x5e,0x5f,0x11,0x0 },
		{ 0x74,0x5d,0x40,0x12,0x5f,0x5d,0x40,0x57,0x12,0x5b,0x5c,0x54,0x5d,0x40,0x5f,0x53,0x46,0x5b,0x5d,0x5c,0x12,0x0 },
		{ 0x75,0x5c,0x41,0x13,0x5e,0x5c,0x41,0x56,0x13,0x5a,0x5d,0x55,0x5c,0x41,0x5e,0x52,0x47,0x5a,0x5c,0x5d,0x13,0x0 },
		{ 0x72,0x5b,0x46,0x14,0x59,0x5b,0x46,0x51,0x14,0x5d,0x5a,0x52,0x5b,0x46,0x59,0x55,0x40,0x5d,0x5b,0x5a,0x14,0x0 },
		{ 0x73,0x5a,0x47,0x15,0x58,0x5a,0x47,0x50,0x15,0x5c,0x5b,0x53,0x5a,0x47,0x58,0x54,0x41,0x5c,0x5a,0x5b,0x15,0x0 },
		{ 0x70,0x59,0x44,0x16,0x5b,0x59,0x44,0x53,0x16,0x5f,0x58,0x50,0x59,0x44,0x5b,0x57,0x42,0x5f,0x59,0x58,0x16,0x0 },
		{ 0x71,0x58,0x45,0x17,0x5a,0x58,0x45,0x52,0x17,0x5e,0x59,0x51,0x58,0x45,0x5a,0x56,0x43,0x5e,0x58,0x59,0x17,0x0 },
		{ 0x7e,0x57,0x4a,0x18,0x55,0x57,0x4a,0x5d,0x18,0x51,0x56,0x5e,0x57,0x4a,0x55,0x59,0x4c,0x51,0x57,0x56,0x18,0x0 },
		{ 0x7f,0x56,0x4b,0x19,0x54,0x56,0x4b,0x5c,0x19,0x50,0x57,0x5f,0x56,0x4b,0x54,0x58,0x4d,0x50,0x56,0x57,0x19,0x0 },
		{ 0x7c,0x55,0x48,0x1a,0x57,0x55,0x48,0x5f,0x1a,0x53,0x54,0x5c,0x55,0x48,0x57,0x5b,0x4e,0x53,0x55,0x54,0x1a,0x0 },
		{ 0x7d,0x54,0x49,0x1b,0x56,0x54,0x49,0x5e,0x1b,0x52,0x55,0x5d,0x54,0x49,0x56,0x5a,0x4f,0x52,0x54,0x55,0x1b,0x0 },
		{ 0x7a,0x53,0x4e,0x1c,0x51,0x53,0x4e,0x59,0x1c,0x55,0x52,0x5a,0x53,0x4e,0x51,0x5d,0x48,0x55,0x53,0x52,0x1c,0x0 },
		{ 0x7b,0x52,0x4f,0x1d,0x50,0x52,0x4f,0x58,0x1d,0x54,0x53,0x5b,0x52,0x4f,0x50,0x5c,0x49,0x54,0x52,0x53,0x1d,0x0 },
		{ 0x78,0x51,0x4c,0x1e,0x53,0x51,0x4c,0x5b,0x1e,0x57,0x50,0x58,0x51,0x4c,0x53,0x5f,0x4a,0x57,0x51,0x50,0x1e,0x0 },
		{ 0x79,0x50,0x4d,0x1f,0x52,0x50,0x4d,0x5a,0x1f,0x56,0x51,0x59,0x50,0x4d,0x52,0x5e,0x4b,0x56,0x50,0x51,0x1f,0x0 },
		{ 0x6,0x2f,0x32,0x60,0x2d,0x2f,0x32,0x25,0x60,0x29,0x2e,0x26,0x2f,0x32,0x2d,0x21,0x34,0x29,0x2f,0x2e,0x60,0x36 },
		{ 0x7,0x2e,0x33,0x61,0x2c,0x2e,0x33,0x24,0x61,0x28,0x2f,0x27,0x2e,0x33,0x2c,0x20,0x35,0x28,0x2e,0x2f,0x61,0x3 },
		{ 0x4,0x2d,0x30,0x62,0x2f,0x2d,0x30,0x27,0x62,0x2b,0x2c,0x24,0x2d,0x30,0x2f,0x23,0x36,0x2b,0x2d,0x2c,0x62,0x3 },
		{ 0x5,0x2c,0x31,0x63,0x2e,0x2c,0x31,0x26,0x63,0x2a,0x2d,0x25,0x2c,0x31,0x2e,0x22,0x37,0x2a,0x2c,0x2d,0x63,0x3 },
		{ 0x2,0x2b,0x36,0x64,0x29,0x2b,0x36,0x21,0x64,0x2d,0x2a,0x22,0x2b,0x36,0x29,0x25,0x30,0x2d,0x2b,0x2a,0x64,0x0 },
		{ 0x3,0x2a,0x37,0x65,0x28,0x2a,0x37,0x20,0x65,0x2c,0x2b,0x23,0x2a,0x37,0x28,0x24,0x31,0x2c,0x2a,0x2b,0x65,0x3 },
		{ 0x0,0x29,0x34,0x66,0x2b,0x29,0x34,0x23,0x66,0x2f,0x28,0x20,0x29,0x34,0x2b,0x27,0x32,0x2f,0x29,0x28,0x66,0x3 },
		{ 0x1,0x28,0x35,0x67,0x2a,0x28,0x35,0x22,0x67,0x2e,0x29,0x21,0x28,0x35,0x2a,0x26,0x33,0x2e,0x28,0x29,0x67,0x3 },
		{ 0xe,0x27,0x3a,0x68,0x25,0x27,0x3a,0x2d,0x68,0x21,0x26,0x2e,0x27,0x3a,0x25,0x29,0x3c,0x21,0x27,0x26,0x68,0x3 },
		{ 0xf,0x26,0x3b,0x69,0x24,0x26,0x3b,0x2c,0x69,0x20,0x27,0x2f,0x26,0x3b,0x24,0x28,0x3d,0x20,0x26,0x27,0x69,0x3 },
		{ 0xc,0x25,0x38,0x6a,0x27,0x25,0x38,0x2f,0x6a,0x23,0x24,0x2c,0x25,0x38,0x27,0x2b,0x3e,0x23,0x25,0x24,0x6a,0x3 },
		{ 0xd,0x24,0x39,0x6b,0x26,0x24,0x39,0x2e,0x6b,0x22,0x25,0x2d,0x24,0x39,0x26,0x2a,0x3f,0x22,0x24,0x25,0x6b,0x3 },
		{ 0xa,0x23,0x3e,0x6c,0x21,0x23,0x3e,0x29,0x6c,0x25,0x22,0x2a,0x23,0x3e,0x21,0x2d,0x38,0x25,0x23,0x22,0x6c,0x3 },
		{ 0xb,0x22,0x3f,0x6d,0x20,0x22,0x3f,0x28,0x6d,0x24,0x23,0x2b,0x22,0x3f,0x20,0x2c,0x39,0x24,0x22,0x23,0x6d,0x3 },
		{ 0x8,0x21,0x3c,0x6e,0x23,0x21,0x3c,0x2b,0x6e,0x27,0x20,0x28,0x21,0x3c,0x23,0x2f,0x3a,0x27,0x21,0x20,0x6e,0x3 },
		{ 0x9,0x20,0x3d,0x6f,0x22,0x20,0x3d,0x2a,0x6f,0x26,0x21,0x29,0x20,0x3d,0x22,0x2e,0x3b,0x26,0x20,0x21,0x6f,0x3 },
		{ 0x16,0x3f,0x22,0x70,0x3d,0x3f,0x22,0x35,0x70,0x39,0x3e,0x36,0x3f,0x22,0x3d,0x31,0x24,0x39,0x3f,0x3e,0x70,0x2 },
		{ 0x17,0x3e,0x23,0x71,0x3c,0x3e,0x23,0x34,0x71,0x38,0x3f,0x37,0x3e,0x23,0x3c,0x30,0x25,0x38,0x3e,0x3f,0x71,0x0 },
		{ 0x14,0x3d,0x20,0x72,0x3f,0x3d,0x20,0x37,0x72,0x3b,0x3c,0x34,0x3d,0x20,0x3f,0x33,0x26,0x3b,0x3d,0x3c,0x72,0x0 },
		{ 0x15,0x3c,0x21,0x73,0x3e,0x3c,0x21,0x36,0x73,0x3a,0x3d,0x35,0x3c,0x21,0x3e,0x32,0x27,0x3a,0x3c,0x3d,0x73,0x0 },
		{ 0x12,0x3b,0x26,0x74,0x39,0x3b,0x26,0x31,0x74,0x3d,0x3a,0x32,0x3b,0x26,0x39,0x35,0x20,0x3d,0x3b,0x3a,0x74,0x0 },
		{ 0x13,0x3a,0x27,0x75,0x38,0x3a,0x27,0x30,0x75,0x3c,0x3b,0x33,0x3a,0x27,0x38,0x34,0x21,0x3c,0x3a,0x3b,0x75,0x0 },
		{ 0x10,0x39,0x24,0x76,0x3b,0x39,0x24,0x33,0x76,0x3f,0x38,0x30,0x39,0x24,0x3b,0x37,0x22,0x3f,0x39,0x38,0x76,0x0 },
		{ 0x11,0x38,0x25,0x77,0x3a,0x38,0x25,0x32,0x77,0x3e,0x39,0x31,0x38,0x25,0x3a,0x36,0x23,0x3e,0x38,0x39,0x77,0x0 },
		{ 0x1e,0x37,0x2a,0x78,0x35,0x37,0x2a,0x3d,0x78,0x31,0x36,0x3e,0x37,0x2a,0x35,0x39,0x2c,0x31,0x37,0x36,0x78,0x0 },
		{ 0x1f,0x36,0x2b,0x79,0x34,0x36,0x2b,0x3c,0x79,0x30,0x37,0x3f,0x36,0x2b,0x34,0x38,0x2d,0x30,0x36,0x37,0x79,0x0 },
		{ 0x1c,0x35,0x28,0x7a,0x37,0x35,0x28,0x3f,0x7a,0x33,0x34,0x3c,0x35,0x28,0x37,0x3b,0x2e,0x33,0x35,0x34,0x7a,0x0 },
		{ 0x1d,0x34,0x29,0x7b,0x36,0x34,0x29,0x3e,0x7b,0x32,0x35,0x3d,0x34,0x29,0x36,0x3a,0x2f,0x32,0x34,0x35,0x7b,0x0 },
		{ 0x1a,0x33,0x2e,0x7c,0x31,0x33,0x2e,0x39,0x7c,0x35,0x32,0x3a,0x33,0x2e,0x31,0x3d,0x28,0x35,0x33,0x32,0x7c,0x0 },
		{ 0x1b,0x32,0x2f,0x7d,0x30,0x32,0x2f,0x38,0x7d,0x34,0x33,0x3b,0x32,0x2f,0x30,0x3c,0x29,0x34,0x32,0x33,0x7d,0x0 },
		{ 0x18,0x31,0x2c,0x7e,0x33,0x31,0x2c,0x3b,0x7e,0x37,0x30,0x38,0x31,0x2c,0x33,0x3f,0x2a,0x37,0x31,0x30,0x7e,0x0 },
		{ 0x19,0x30,0x2d,0x7f,0x32,0x30,0x2d,0x3a,0x7f,0x36,0x31,0x39,0x30,0x2d,0x32,0x3e,0x2b,0x36,0x30,0x31,0x7f,0x0 },
		{ 0x26,0xf,0x12,0x40,0xd,0xf,0x12,0x5,0x40,0x9,0xe,0x6,0xf,0x12,0xd,0x1,0x14,0x9,0xf,0xe,0x40,0x16,0x9,0x13,0x9 },
		{ 0x27,0xe,0x13,0x41,0xc,0xe,0x13,0x4,0x41,0x8,0xf,0x7,0xe,0x13,0xc,0x0,0x15,0x8,0xe,0xf,0x41,0x17,0x8,0x12,0x8 },
		{ 0x24,0xd,0x10,0x42,0xf,0xd,0x10,0x7,0x42,0xb,0xc,0x4,0xd,0x10,0xf,0x3,0x16,0xb,0xd,0xc,0x42,0x14,0xb,0x11,0x0 },
		{ 0x25,0xc,0x11,0x43,0xe,0xc,0x11,0x6,0x43,0xa,0xd,0x5,0xc,0x11,0xe,0x2,0x17,0xa,0xc,0xd,0x43,0x15,0xa,0x10,0xa },
		{ 0x22,0xb,0x16,0x44,0x9,0xb,0x16,0x1,0x44,0xd,0xa,0x2,0xb,0x16,0x9,0x5,0x10,0xd,0xb,0xa,0x44,0x12,0xd,0x17,0x0 },
		{ 0x23,0xa,0x17,0x45,0x8,0xa,0x17,0x0,0x45,0xc,0xb,0x3,0xa,0x17,0x8,0x4,0x11,0xc,0xa,0xb,0x45,0x13,0xc,0x16,0x0 },
		{ 0x20,0x9,0x14,0x46,0xb,0x9,0x14,0x3,0x46,0xf,0x8,0x0,0x9,0x14,0xb,0x7,0x12,0xf,0x9,0x8,0x46,0x10,0xf,0x15,0xf },
		{ 0x21,0x8,0x15,0x47,0xa,0x8,0x15,0x2,0x47,0xe,0x9,0x1,0x8,0x15,0xa,0x6,0x13,0xe,0x8,0x9,0x47,0x11,0xe,0x14,0x0 },
		{ 0x2e,0x7,0x1a,0x48,0x5,0x7,0x1a,0xd,0x48,0x1,0x6,0xe,0x7,0x1a,0x5,0x9,0x1c,0x1,0x7,0x6,0x48,0x1e,0x1,0x1b,0x0 },
		{ 0x2f,0x6,0x1b,0x49,0x4,0x6,0x1b,0xc,0x49,0x0,0x7,0xf,0x6,0x1b,0x4,0x8,0x1d,0x0,0x6,0x7,0x49,0x1f,0x0,0x1a,0x0 },
		{ 0x2c,0x5,0x18,0x4a,0x7,0x5,0x18,0xf,0x4a,0x3,0x4,0xc,0x5,0x18,0x7,0xb,0x1e,0x3,0x5,0x4,0x4a,0x1c,0x3,0x19,0x3 },
		{ 0x2d,0x4,0x19,0x4b,0x6,0x4,0x19,0xe,0x4b,0x2,0x5,0xd,0x4,0x19,0x6,0xa,0x1f,0x2,0x4,0x5,0x4b,0x1d,0x2,0x18,0x0 },
		{ 0x2a,0x3,0x1e,0x4c,0x1,0x3,0x1e,0x9,0x4c,0x5,0x2,0xa,0x3,0x1e,0x1,0xd,0x18,0x5,0x3,0x2,0x4c,0x1a,0x5,0x1f,0x5 },
		{ 0x2b,0x2,0x1f,0x4d,0x0,0x2,0x1f,0x8,0x4d,0x4,0x3,0xb,0x2,0x1f,0x0,0xc,0x19,0x4,0x2,0x3,0x4d,0x1b,0x4,0x1e,0x4 },
		{ 0x28,0x1,0x1c,0x4e,0x3,0x1,0x1c,0xb,0x4e,0x7,0x0,0x8,0x1,0x1c,0x3,0xf,0x1a,0x7,0x1,0x0,0x4e,0x18,0x7,0x1d,0x7 },
		{ 0x29,0x0,0x1d,0x4f,0x2,0x0,0x1d,0xa,0x4f,0x6,0x1,0x9,0x0,0x1d,0x2,0xe,0x1b,0x6,0x0,0x1,0x4f,0x19,0x6,0x1c,0x6 },
		{ 0x36,0x1f,0x2,0x50,0x1d,0x1f,0x2,0x15,0x50,0x19,0x1e,0x16,0x1f,0x2,0x1d,0x11,0x4,0x19,0x1f,0x1e,0x50,0x6,0x1 },
		{ 0x37,0x1e,0x3,0x51,0x1c,0x1e,0x3,0x14,0x51,0x18,0x1f,0x17,0x1e,0x3,0x1c,0x10,0x5,0x18,0x1e,0x1f,0x51,0x7,0x1 },
		{ 0x34,0x1d,0x0,0x52,0x1f,0x1d,0x0,0x17,0x52,0x1b,0x1c,0x14,0x1d,0x0,0x1f,0x13,0x6,0x1b,0x1d,0x1c,0x52,0x4,0x0 },
		{ 0x35,0x1c,0x1,0x53,0x1e,0x1c,0x1,0x16,0x53,0x1a,0x1d,0x15,0x1c,0x1,0x1e,0x12,0x7,0x1a,0x1c,0x1d,0x53,0x5,0x0 },
		{ 0x32,0x1b,0x6,0x54,0x19,0x1b,0x6,0x11,0x54,0x1d,0x1a,0x12,0x1b,0x6,0x19,0x15,0x0,0x1d,0x1b,0x1a,0x54,0x2,0x0 },
		{ 0x33,0x1a,0x7,0x55,0x18,0x1a,0x7,0x10,0x55,0x1c,0x1b,0x13,0x1a,0x7,0x18,0x14,0x1,0x1c,0x1a,0x1b,0x55,0x3,0x0 },
		{ 0x30,0x19,0x4,0x56,0x1b,0x19,0x4,0x13,0x56,0x1f,0x18,0x10,0x19,0x4,0x1b,0x17,0x2,0x1f,0x19,0x18,0x56,0x0,0x0 },
		{ 0x31,0x18,0x5,0x57,0x1a,0x18,0x5,0x12,0x57,0x1e,0x19,0x11,0x18,0x5,0x1a,0x16,0x3,0x1e,0x18,0x19,0x57,0x1,0x0 },
		{ 0x3e,0x17,0xa,0x58,0x15,0x17,0xa,0x1d,0x58,0x11,0x16,0x1e,0x17,0xa,0x15,0x19,0xc,0x11,0x17,0x16,0x58,0xe,0x0 },
		{ 0x3f,0x16,0xb,0x59,0x14,0x16,0xb,0x1c,0x59,0x10,0x17,0x1f,0x16,0xb,0x14,0x18,0xd,0x10,0x16,0x17,0x59,0xf,0x1 },
		{ 0x3c,0x15,0x8,0x5a,0x17,0x15,0x8,0x1f,0x5a,0x13,0x14,0x1c,0x15,0x8,0x17,0x1b,0xe,0x13,0x15,0x14,0x5a,0xc,0x1 },
		{ 0x3d,0x14,0x9,0x5b,0x16,0x14,0x9,0x1e,0x5b,0x12,0x15,0x1d,0x14,0x9,0x16,0x1a,0xf,0x12,0x14,0x15,0x5b,0xd,0x0 },
		{ 0x3a,0x13,0xe,0x5c,0x11,0x13,0xe,0x19,0x5c,0x15,0x12,0x1a,0x13,0xe,0x11,0x1d,0x8,0x15,0x13,0x12,0x5c,0xa,0x1 },
		{ 0x3b,0x12,0xf,0x5d,0x10,0x12,0xf,0x18,0x5d,0x14,0x13,0x1b,0x12,0xf,0x10,0x1c,0x9,0x14,0x12,0x13,0x5d,0xb,0x1 },
		{ 0x38,0x11,0xc,0x5e,0x13,0x11,0xc,0x1b,0x5e,0x17,0x10,0x18,0x11,0xc,0x13,0x1f,0xa,0x17,0x11,0x10,0x5e,0x8,0x1 },
		{ 0x39,0x10,0xd,0x5f,0x12,0x10,0xd,0x1a,0x5f,0x16,0x11,0x19,0x10,0xd,0x12,0x1e,0xb,0x16,0x10,0x11,0x5f,0x9,0x1 }
	};

main(int argc, char * argv[]) {
    FILE * fs;
    int k, i, j;
    char csize[10];
    int isize;
    int flag = 0;
    int uch;
    if (argc == 1) {
      printf("Exec2pl by Chetan Ganatra. Email: ganatrac @infotech.icici.com\ n ");
       printf("Extracts perl scripts from .exe files created by www.perl2exe.com\ n ");
        printf("Works on executables generated by Perl2Exe Ver 5.03 for Win32\ n ");
         printf("Usage: exec2pl [exefile] > [plfile]\n"); exit(1);
        }
		fs = fopen(argv[1], "rb"); fseek(fs, 0x50DE, 0); i = 0; j = 0;
		while (i <= 3) {
		  uch = fgetc(fs);
		  csize[j++] = uch;
		  if (uch == 0xa) {
			i++;
			csize[j] = 0;
			j = 0;
		  }
		  if (i == 3) break;
		}
		csize[0] = '0'; isize = atoi(csize); i = 0; k = 0;
		while (!feof(fs) && k++ <= isize) {
		  uch = fgetc(fs);
		  flag = 0;
		  for (j = 0; j < 96; j++)
			if (uch == cipher[j][i]) {
			  flag = 1;
			  printf("%c", j + 32);
			}
		  if (flag == 0)
			for (j = 0; j < 2; j++)
			  if (uch == ctrl[j][i]) {
				flag = 1;
				if (j == 0)
				  printf("%c", 0x0a);
				if (j == 1)
				  printf("%c", 0x0d);
				if (j == 2)
				  printf("%c", 0x20);
			  }
		  i++;
		  if (i > 44) i = 0;
		}
		fclose(fs);
		return 0;
	  }
/* exec2pl */
