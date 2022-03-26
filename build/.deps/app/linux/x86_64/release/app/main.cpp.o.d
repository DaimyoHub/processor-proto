{
    depfiles_gcc = "build/.objs/app/linux/x86_64/release/app/main.cpp.o: app/main.cpp\
",
    files = {
        "app/main.cpp"
    },
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