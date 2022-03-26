{
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
    },
    depfiles_gcc = "build/.objs/app/linux/x86_64/debug/app/main.cpp.o: app/main.cpp\
",
    files = {
        "app/main.cpp"
    }
}