C - Variadic functions
defination:
A variadic function is one that takes a variable number of arguments. A common example is the printf() function defined in the <stdio. h> header. The declaration of a variadic function uses ellipses as the last parameter.2.2.2 Receiving the Argument Values
Ordinary fixed arguments have individual names, and you can use these names to access their values. But optional arguments have no names—nothing but ‘…’. How can you access them?

The only way to access them is sequentially, in the order they were written, and you must use special macros from stdarg.h in the following three step process:

You initialize an argument pointer variable of type va_list using va_start. The argument pointer when initialized points to the first optional argument.
You access the optional arguments by successive calls to va_arg. The first call to va_arg gives you the first optional argument, the next call gives you the second, and so on.
You can stop at any time if you wish to ignore any remaining optional arguments. It is perfectly all right for a function to access fewer arguments than were supplied in the call, but you will get garbage values if you try to access too many arguments.


