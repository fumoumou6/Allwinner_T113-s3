OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)	/*指明运行的第一个文件中的_start*/
SECTIONS
{
	. = 0x00000000;

	. = ALIGN(4);
	.text :
	{
		start.o(.text*) 	/*指明运行的第一个文件是start.o*/
		*(.text*)
	}

	. = ALIGN(4);
	.data :
	{
		*(.data*)
	}

	. = ALIGN(4);
	bss_start = .;
	.bss :
	{
		*(.bss*)
	}
	bss_end = .;
	
}

