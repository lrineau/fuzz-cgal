# fuzz-cgal

Compile with a recent `clang` compiler. Tried with clang version 8.0.

- With no argument, the program starts the fuzzing algorithms. Can use threads (see [the documentation](https://llvm.org/docs/LibFuzzer.html#parallel-fuzzing)).
- With one argument, the program uses the bytes of the file as first input (see the [possible options](https://llvm.org/docs/LibFuzzer.html#options)).
