Our team project involves the creation of a customized printf function in the C programming language known as _printf. Specifically optimized to handle diverse inputs and optional arguments, it closely mirrors the functionality of the standard library function printf. As part of the ALX software engineering course, we've submitted this project for evaluation.

###Overview

The _printf() function is designed to produce output to the standard output stream (stdout) while adhering to specified formats and options, all without relying on any standard library files. It utilizes a local 1024-byte buffer for printing, although it's capable of handling larger datasets.

Upon successful execution, the _printf() function returns the total count of characters printed to stdout, excluding the null byte at the end of strings.

In the event of an output error, the function returns a negative value of -1.

The function's prototype is as follows: int _printf(const char format, ...);

This prototype demands one mandatory format argument, allowing for an additional variable number of arguments, ranging from none to many.
