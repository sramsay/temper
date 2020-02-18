# How to contribute

To be honest, this is mostly a way for me to test out various kinds of tooling -- continuous integration systems, build tools, compiler chains, and that kind of thing.

Nonetheless, it is a real program that I actually do use and maintain.

Despite its simplicity, this project strives to adhere to good coding standards, to be as efficient and fault tolerant as possible, and to be generally portable across UNIX-like platforms.  All contributions to that end will be warmly welcomed.

I have toyed with the idea of adding a variety of different temperature conversions to the program, but still haven't worked out an interface that works while preserving the essential simplicity of the program.  If you have ideas about this, I'd love to hear them.

## Prerequisites

First, check to make sure that your issue isn't [already addressed](https://github.com/sramsay/temper/issues/) somewhere.  If you're reasonably confident that it isn't, [create an issue](https://github.com/sramsay/temper/issues/new/choose).  Please note that you need a [GitHub account](https://github.com/signup/free) in order to do this.

## Describe your issue

Try to describe your issue as clearly as possible.

  - If it is a bug, please describe how to **reproduce** it. If possible, attach a complete example which demonstrates the error. Please also state what you **expected** to happen instead of the error.

  - If you propose a change or addition, try to give an **example** how the improved code miight look or how to use it.

  - If you found a compilation error, please tell us which **compiler** (version and operating system) you used and paste the (relevant part of) the error messages to the ticket.

## Processes

I generally test all code using the latest stable versions of clang and gcc, and do my best to keep up with the latest versions of all dependencies.  I also run clang_tidy using the .clang_tidy config in the root directory of the project (this file is automatically copied into the meson build directory on each new build) and run valgrind on the resulting binary with various options.  Code that produces issues with either static analyzer that cannot be satisfactorily resolved is very unlikely to be merged.

In other words, I am not particularly interested in code that is meant to run on old compilers or previous incarnations of the C++ standard.  If you are interested in doing this, you are welcome to fork the project.  I say that without the least bit of sarcasm.  In fact, if you do fork the project for these reasons, please let me know so I can link to it!
