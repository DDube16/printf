#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * mi_print_unsigned - Prints a unsigned number
 * @types: Lists of arguments
 * @buffer: Buffer array handles print
 * @flags: Calculate active flags
 * @width: width
 * @precision: specification
 * @size: Size
 * Return: No. of characters are printed.
 */
int mi_print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * we_print_octal - Printed a unsigned number in octal notation
 * @types: Lists of arguments
 * @buffer: Buffer array may handle print
 * @flags: Calculate active flags
 * @width: width
 * @precision: specification
 * @size: Size
 * Return: No. of characters are printed
 */
int we_print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * ma_print_hexadecimal - Prints unsigned number in hexadecimal notation
 * @types: Lists of arguments
 * @buffer: Buffer array handles print
 * @flags: Calculate active flags
 * @width: width
 * @precision: specification
 * @size: Size
 * Return: No. of characters are to be  printed
 */
int ma_print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * vi_print_hexa_upper - Prints unsigned number in upper hexadecimal notation
 * @types: Lists of arguments
 * @buffer: Buffer array handles print
 * @flags:  Calculate active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: No. of characters are to be  printed
 */
int vi_print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * hi_print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the no.
 * @buffer: Buffer array handles print
 * @flags: Calculate active flags
 * @flag_ch: Calculate active flags
 * @width: width
 * @precision: specification
 * @size: specifier
 * @size: Size
 * Return: No. of characters are to be  printed
 */
int hi_print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


