{
    files = {
        "tests/main.cpp"
    },
    depfiles_gcc = "build/.objs/tests/linux/x86_64/release/tests/main.cpp.o: tests/main.cpp\
",
    values = {
        "/usr/bin/clang++",
        {
            "-Qunused-arguments",
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-DNDEBUG"
        }
    }
}