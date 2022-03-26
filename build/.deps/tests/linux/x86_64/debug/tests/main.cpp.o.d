{
    depfiles_gcc = "build/.objs/tests/linux/x86_64/debug/tests/main.cpp.o: tests/main.cpp   lib/cpu/context/memory.hpp\
",
    files = {
        "tests/main.cpp"
    },
    values = {
        "/usr/bin/clang++",
        {
            "-Qunused-arguments",
            "-m64",
            "-g",
            "-O0",
            "-std=c++2a",
            "-Ilib",
            "-DDEBUG"
        }
    }
}