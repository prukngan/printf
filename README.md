# ft_printf — Custom printf implementation in C

This project is part of the 42 Bangkok curriculum, focused on strengthening low-level C programming and system fundamentals by reimplementing the standard `printf` function from scratch.

## Objective

Recreate the behavior of the standard C `printf` function without using the original implementation, in order to deeply understand:

* Variadic functions in C (`stdarg.h`)
* Memory and buffer management
* Format string parsing
* Type handling and conversion
* Low-level output control using `write`

## Features

* Supports common format specifiers:

  * `%c` character
  * `%s` string
  * `%d` / `%i` integer
  * `%u` unsigned integer
  * `%x` / `%X` hexadecimal
  * `%p` pointer
  * `%%` percent sign
* Custom handling of formatting and conversion logic
* Built only with standard C and allowed system calls (42 school constraints)

## Purpose

This project was built as part of my systems programming foundation and embedded/low-level engineering path.
It emphasizes understanding how core standard library functions work internally and improving control over memory and output behavior.

## Tech Stack

* Language: C
* Standard: GCC / Unix environment
* Tools: Makefile, static library (`ar`), manual memory management

## Author

Former 42 Bangkok student with a Computer Engineering background.
Focused on embedded systems, robotics, and low-level software development.
