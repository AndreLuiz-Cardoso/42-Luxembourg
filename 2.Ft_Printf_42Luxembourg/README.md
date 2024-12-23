<h1 align=center>
	<b>ft_printf</b>
</h1>

<p align=center>
	Welcome to the ft_printf project! This project is part of the curriculum at 42 Luxembourg and aims to develop your understanding of variadic functions and string formatting in the C programming language. ft_printf is a custom implementation of the printf function, which allows for formatted output to the standard output stream.
	The <b>printf</b> function is one of the most versatile and well-known functions in the C language. From a testing aid to tabulation method, printf is a very powerful and important tool in every dev's kit. This project aims to recreate the behaviour of the original printf, including its basic error management, some of its flags, minimum field width stipulation and most of its basic conversions.

---
<div align="center">
    <img src="https://github.com/AndreLuiz-Cardoso/42_badges_utils/blob/main/ft_printfm.png?raw=true" alt="cado-car's 42Project Badge"/>
</div>

---

<h3 align=center>
Mandatory
</h3>

The ft_printf function supports a wide range of format specifiers, allowing you to format and print various types of data. Some of the commonly used format specifiers include:
<br/>
<br/>
<div align="center">
%c: Character <br/>
%s: String <br/>
%d or %i: Signed decimal integer <br/>
%u: Unsigned decimal integer <br/>
%x or %X: Unsigned hexadecimal integer <br/>
%f: Floating-point number <br/>
%p: Pointer address <br/>
</div>
<br/>
<br/>
These format specifiers enable you to print data in a specific format, making it easier to display and interpret different types of information.

Width and Precision
You can specify the width and precision of the output using optional flags in the format specifier. The width determines the minimum number of characters to be printed, while the precision specifies the maximum number of characters to be printed for strings or the number of decimal places for floating-point numbers.

<br/>
---
<div align="center">
<h2>
The project
</h2>
</div>

### Implementation files
	
- [`Makefile`](Makefile)
- [`libft functions`](libft/)
- [`header file`](ft_printf.h)

Main functions
	
- [`ft_printf.c`](ft_printf.c)
- [`print_char.c`](print_char.c)
- [`print_hex.c`](print_hex.c)
- [`print_init.c`](print_init.c)
- [`print_pointer.c`](print_pointer.c)
- [`print_string.c`](print_string.c)
- [`print_unsigned.c`](print_unsigned.c)
<div align="center">
<h2> How it Works </h2>
</div>
<br/>
The ft_printf function follows a systematic process to handle the provided format string and corresponding arguments:
<br/>
Parse the format string and identify format specifiers, flags, width, precision, and modifiers.
Retrieve the arguments based on the format specifiers and perform necessary data conversions.
Generate the formatted output according to the specified format and desired appearance.
Print the final output to the standard output stream.
<br/>
By following this process, ft_printf ensures accurate formatting and printing of the provided data, mimicking the behavior
