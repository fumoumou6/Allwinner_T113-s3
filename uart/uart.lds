OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
	. = 0x20000;
	. = ALIGN(4);

	/* .head   :
	{
		main/boot0_head.o	(.rodata)
	}
    . = ALIGN(1); */
	.text :
	{
		start.o 
        main.o
		*(.text)
	}
	. = ALIGN(16);
  	.rodata : { *(.rodata) }
	. = ALIGN(16);
  	.data : { *(.data) }

	. = ALIGN(4);
	.bss :
	{
	__bss_start = .;
		*(.bss)
	}
	. = ALIGN(4);
	__bss_end = .;

	_end = .;
	ASSERT(. <= (0x20000 + 0x8000), "boot0 image has exceeded its limit.")
}