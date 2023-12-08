#include "main.h"

/**
 * is_print_percent - Prints percent signs
 * @types: Lists arguments
 * @buffer: Buffer array handles print
 * @flags: May calculate active flags
 * @width: width.
 * @precision: specification
 * @size: Size
 * Return: No. of characters are printed
 */
int is_print_percent(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        UNUSED(types);
        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);
        return (write(1, "%%", 1));
}
