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
    files = {
        "src/context/memory.cpp"
    },
    depfiles_gcc = "build/.objs/context/linux/x86_64/debug/src/context/memory.cpp.o:   src/context/memory.cpp lib/cpu/context/memory.hpp   lib/cpu/utils/assertions.hpp\
"
}