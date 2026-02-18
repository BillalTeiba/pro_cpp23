# Most notable C++ Compiler Flags 

-c  Compile or assemble the source files, but do not link.  The
    linking stage simply is not done.  The ultimate output is in
    the form of an object file for each source file.

    By default, the object file name for a source file is made by
    replacing the suffix .c, .i, .s, etc., with .o.

    Unrecognized input files, not requiring compilation or
    assembly, are ignored.

-S  Stop after the stage of compilation proper; do not assemble.
    The output is in the form of an assembler code file for each
    non-assembler input file specified.

    By default, the assembler file name for a source file is made
    by replacing the suffix .c, .i, etc., with .s.

    Input files that don't require compilation are ignored.

-E  Stop after the preprocessing stage; do not run the compiler
    proper.  The output is in the form of preprocessed source
    code, which is sent to the standard output.

    Input files that don't require preprocessing are ignored.

-o file
    Place output in file file.  This applies to whatever sort of
    output is being produced, whether it be an executable file, an
    object file, an assembler file or preprocessed C code.

    If -o is not specified, the default is to put an executable
    file in a.out, the object file for source.suffix in source.o,
    its assembler file in source.s, a precompiled header file in
    source.suffix.gch, and all preprocessed C source on standard
    output.

-v  Print (on standard error output) the commands executed to run
    the stages of compilation.  Also print the version number of
    the compiler driver program and of the preprocessor and the
    compiler proper.

    the use of gcc does not add the C++ library.  g++ is a
    program that calls GCC and automatically specifies linking against
    the C++ library.  It treats .c, .h and .i files as C++ source
    files instead of C source files unless -x is used.  This program
    is also useful when precompiling a C header file with a .h
    extension for use in C++ compilations.  On many systems, g++ is
    also installed with the name c++.

-ansi
    In C mode, this is equivalent to -std=c90. In C++ mode, it is
    equivalent to -std=c++98.

-std= 
    c++98
    c++03
        The 1998 ISO C++ standard plus the 2003 technical
        corrigendum and some additional defect reports. Same as
        -ansi for C++ code.

    gnu++98
    gnu++03
        GNU dialect of -std=c++98.

    c++11
    c++0x
        The 2011 ISO C++ standard plus amendments.  The name c++0x
        is deprecated.

    gnu++11
    gnu++0x
        GNU dialect of -std=c++11.  The name gnu++0x is
        deprecated.

    c++14
    c++1y
        The 2014 ISO C++ standard plus amendments.  The name c++1y
        is deprecated.

    gnu++14
    gnu++1y
        GNU dialect of -std=c++14.  This is the default for C++
        code.  The name gnu++1y is deprecated.

    c++17
    c++1z
        The 2017 ISO C++ standard plus amendments.  The name c++1z
        is deprecated.

    gnu++17
    gnu++1z
        GNU dialect of -std=c++17.  The name gnu++1z is
        deprecated.

    c++2a
        The next revision of the ISO C++ standard, tentatively
        planned for 2020.  Support is highly experimental, and
        will almost certainly change in incompatible ways in
        future releases.

    gnu++2a
        GNU dialect of -std=c++2a.  Support is highly
        experimental, and will almost certainly change in
        incompatible ways in future releases.

-lstdc++	A specialized option to link against the C++ standard library.

-Wall	Enables a wide range of common and easy-to-avoid warning messages, such as those about unused variables or functions that don't return a value.

-Wextra	Enables an extra set of warnings not covered by -Wall.

-Werror	Treats all warnings as errors, causing the compilation to fail.

-Olevel	Sets the optimization level. Common levels are -O0 (no optimization), -O1, -O2 (a good balance), -O3 (more aggressive), and -Os (optimizes for code size).

-g	Generates debugging information in the standard format for the operating system.

-l library	Tells the linker to link against a specific library. For example, -lm links the math library.

-L dir	Adds a directory to the list of paths where the linker will search for libraries specified with the -l flag.

-D macro[=defn]	Defines a preprocessor macro. For example, -DNDEBUG is commonly used to disable assert() calls in release builds.

-i include a header file 

-I include headers dir

-fsanitize
    address	(Modern Must-Have) Enables the AddressSanitizer, a powerful runtime tool that detects memory errors like buffer overflows (heap, stack, global), use-after-free, and memory leaks. It's an indispensable tool for debugging memory-related bugs.

    undefined	Enables the UndefinedBehaviorSanitizer (UBSan). This tool adds runtime checks to detect various forms of C++ undefined behavior, such as signed integer overflow, misaligned pointers, and more. It can save you from heisenbugs that behave differently in debug vs. release builds.

-flto	(Link Time Optimization) This powerful flag tells g++ to perform optimization across the entire program at link time, rather than just within individual source files. It allows for much better inlining and other cross-file optimizations, often resulting in a significant performance boost for release builds.

-fprofile-generate...-fprofile-use	(Profile Guided Optimization - PGO) This is a two-step process to create a highly optimized build. First, you compile with -fprofile-generate. Then you run your program with typical workloads, which generates profiling data. Finally, you re-compile with -fprofile-use, and the compiler uses that real-world data to make much smarter optimization decisions (e.g., better branch prediction and inlining). This is a top-tier technique for performance tuning.

-march
    native	Optimizes the code specifically for the CPU architecture of the machine you are compiling on. This allows the compiler to use modern CPU instruction sets (like AVX2, AVX-512) that can make your code run dramatically faster, especially for numerical or scientific computing.
-mcpu
        Tunes the code for a specific CPU core (e.g., -mcpu=cortex-a72). This tells the compiler to optimize instruction scheduling and pipeline usage for that specific core, but it will not use instructions that aren't available in the specified -march.

    A common strategy is to combine them:
    g++ -march=armv8-a+crc -mcpu=cortex-a53
    This sets the baseline architecture to ARMv8-A with CRC extensions and then tunes specifically for the Cortex-A53 core.
