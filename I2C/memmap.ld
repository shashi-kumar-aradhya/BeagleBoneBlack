MEMORY
{
	ram : ORIGIN = 0x80000000, LENGTH = 0x20000000
}
SECTIONS
{
	.text : { *(.text*) } > ram
	.bss : { *(.bss*) } > ram
}
