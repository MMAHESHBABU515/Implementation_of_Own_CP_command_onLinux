# Implementation_of_Own_CP_command_onLinux
This program uses a buffer to read and write chunks of data, which is more efficient than reading and writing byte-by-byte.
The cp command functionality can be implemented in C using system calls or standard C library functions (File I/O). Using system calls (open, read, write, close) is generally preferred for implementing shell commands like cp on Unix-like systems as it operates closer to the OS kernel and allows for byte-level control.
Here is a C program implementing a simplified cp command using system calls that takes the source and destination file names as command-line arguments.
