#include "sys_log.h"
#include "stdarg.h"

#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)


/**
 * @brief Output an unsigned long (32-bit) in decimal format
 *
 * Output an unsigned long on output installed by platform at init time. Only
 * works with 32-bit values.
 * @param num Number to output
 *
 * @return N/A
 */
static void _printk_dec_ulong(out_func_t out,
		const unsigned long num, int pad_zero,
		int min_width)
{
	/*
	unsigned long pos = 999999999;
	unsigned long remainder = num;
	*/
	long pos = 999999999;
	long remainder = num;
	int found_largest_digit = 0;
	int remaining = 10; /* 10 digits max */

	/* make sure we don't skip if value is zero */
	if (min_width <= 0) {
		min_width = 1;
	}

	while (pos >= 9) {
		if (found_largest_digit || remainder > pos) {
			found_largest_digit = 1;
			out((char)((remainder / (pos + 1)) + 48));
		} else if (remaining <= min_width) {
			out((char)(pad_zero ? '0' : ' '));
		}
		remaining--;
		remainder %= (pos + 1); 
		pos /= 10; 
	}
	out((char)(remainder + 48));
}

/**
 * @brief Output an unsigned long in hex format
 *
 * Output an unsigned long on output installed by platform at init time. Should
 * be able to handle an unsigned long of any size, 32 or 64 bit.
 * @param num Number to output
 *
 * @return N/A
 */
static void _printk_hex_ulong(out_func_t out,
		const unsigned long num, int pad_zero,
		int min_width)
{
	int size = sizeof(num) * 2;
	int found_largest_digit = 0;
	int remaining = 8; /* 8 digits max */

	for (; size; size--) {
		char nibble = (num >> ((size - 1) << 2) & 0xf);

		if (nibble || found_largest_digit || size == 1) {
			found_largest_digit = 1;
			nibble += nibble > 9 ? 87 : 48;
			out((char)nibble);
			continue;
		}

		if (remaining-- <= min_width) {
			out((char)(pad_zero ? '0' : ' '));
		}
	}
}



/**
 * @brief Printk internals
 *
 * See printk() for description.
 * @param fmt Format string
 * @param ap Variable parameters
 *
 * @return N/A
 */
void _vprintk(out_func_t out, const char *fmt, va_list ap)
{
	int might_format = 0; /* 1 if encountered a '%' */
	int pad_zero = 0;
	int min_width = -1;

	/* fmt has already been adjusted if needed */

	while (*fmt) {
		if (!might_format) {
			if (*fmt != '%') {
				out((char)*fmt);
			} else {
				might_format = 1;
				min_width = -1;
				pad_zero = 0;
			}
		} else {
			switch (*fmt) {
				case '0':
					if (min_width < 0 && pad_zero == 0) {
						pad_zero = 1;
						goto still_might_format;
					}
					/* Fall through */
				case '1' ... '9':
					if (min_width < 0) {
						min_width = *fmt - '0';
					} else {
						min_width = 10 * min_width + *fmt - '0';
					}
					goto still_might_format;
				case 'z':
				case 'l':
				case 'h':
					/* FIXME: do nothing for these modifiers */
					goto still_might_format;
				case 'd':
				case 'i': {
						  long d = va_arg(ap, long);

						  if (d < 0) {
							  out((char)'-');
							  d = -d;
							  min_width--;
						  }
						  _printk_dec_ulong(out, d, pad_zero,
								  min_width);
						  break;
					  }
				case 'u': {
						  unsigned long u = va_arg(
								  ap, unsigned long);
						  _printk_dec_ulong(out, u, pad_zero,
								  min_width);
						  break;
					  }
				case 'p':
					  out('0');
					  out('x');
					  /* left-pad pointers with zeros */
					  pad_zero = 1;
					  min_width = 8;
					  /* Fall through */
				case 'x':
				case 'X': {
						  unsigned long x = va_arg(
								  ap, unsigned long);
						  _printk_hex_ulong(out, x, pad_zero,
								  min_width);
						  break;
					  }
				case 's': {
						  char *s = va_arg(ap, char *);

						  while (*s)
							  out((char)(*s++));
						  break;
					  }
				case 'c': {
						  int c = va_arg(ap, int);

						  out(c);
						  break;
					  }
				case '%': {
						  out((char)'%');
						  break;
					  }
				default:
					  out((char)'%');
					  out((char)*fmt);
					  break;
			}
			might_format = 0;
		}
still_might_format:
		++fmt;
	}
}
