# Simple Shell
The Shell is a programm that allowed the user to interact with the kernel and operating system through a command line.

## Description
In this project we recreates a simple shell using the knowledge gathered during this semester as a Holberton students, using C programming language.

## General Requirements
- Text editors allowed are vi, vim and Emacs.
- It should be Betty approved.
- The header file should be include guarded.
- The shell shouldn't have memory leaks.
- No more than 5 functions per file.
- All the files should be compiled on Ubuntu 20.04 LTS using the gcc compiler.
- Files should be compiled as follow
> gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## List of allowed functions and macros
- access
- chdir
- close
- closedir
- execve
- exit
- _exit
- fflush
- fork
- free
- getcwd
- getline
- getpid
- isatty
- kill
- malloc
- open
- opendir
- perror
- read
- readdir
- signal
- stat
- lstat
- fstat
- strtok
- wait
- waitpid
- wait3
- wait4
- write

## Leaks
A way to double check the leaks in our case is using valgrind. To run valgrind, we just need to type in our prompt "valgrind ./filename, and press enter. Through valgrind you could see the error messages, these are going to give you 
the address where the leak is and a posible reason. Sometime it's hard to understand the error messages that valgrind shows. To help with this process or to make the messages a little bit more clearer we use the -g flag when we compile as follow:
> gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh

## Project Tasks
As part of the tasks for this project the shell should work in an non-interactive way and an interactive way. The non-interactive way is through pipes or redirections. The interactive way should work similar to the shell that we uaccess through our terminal.

## Our simple shell version
It run some commands, and work mostly in the interactive mode. Only runs commands related to the path in the non-interactive mode. Still have leaks, it doesn't handle errors all the way through.

## Resources
- https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-1
- https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-2
- https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-3
- https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-4
- The Linuz programming interface
- geek for geeks
- Tutorialpoint
- stackoverflow
- dillinger.io

 
