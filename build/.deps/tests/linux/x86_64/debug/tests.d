{
    files = {
        "build/.objs/tests/linux/x86_64/debug/tests/main.cpp.o",
        "build/linux/x86_64/debug/libcontext.a"
    },
    values = {
        "/usr/bin/clang++",
        {
            "-m64",
            "-Lbuild/linux/x86_64/debug",
            "-lcontext"
        }
    }
}