{
    files = {
        "build/.objs/app/linux/x86_64/debug/app/main.cpp.o",
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