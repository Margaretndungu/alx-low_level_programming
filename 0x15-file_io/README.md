0x15. C - File I/O
Understanding file manipulation and system calls in details

1.creating, opening, closing, reading and writing files
creating a file involves generating a new file in the file system, while opening a file involves gaining access to an existing file. closing a file releases the resources associated with it.reading from a file allows retrieving its contents and writing to a file involves adding or modifying its contents.
2.file descriptors
file descriptor are unique identifiers used by operating systems to track open files. they represent the connection between a file and a process that has it open.file descriptors are typically small non negative intergers
3.standard file descriptor and their POSIX names
the three standard file descriptors are
*standard input(stdin)
represented by file descriptor 0. its POSIX name is STDIN_FILENO.
*standard output(stdout)
represented by file descriptor 1. its POSIX name is STDOUT_FILENO.
*standard error(stderr)
representeed by file descriptor 2. its POSIX name is STDERR_FILENO.
these standard file descriptos serves specific purposes:
->stdin is for input
->stdout is for output
->stderr is for error messages


