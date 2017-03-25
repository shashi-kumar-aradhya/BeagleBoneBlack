MEMORY
{
	ram : ORIGIN = 0X0, LENGTH = 0X18400
}
SECTIONS
{
	.text : { *(.text*) } > ram
	.bss : { *(.bss*) } > ram
}
