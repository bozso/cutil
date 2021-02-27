
libs = {
    "io": "io",
}

c_library(
    name = "io",
    srcs = glob(["src/io/*.src"]),
    hdrs = glob(["src/io/*.src"]),
)


c_binary(
    name = "test",
    srcs = glob(["src/test/*.c"]),
    hdrs = glob(["src/test/*.h"]),
    deps = ["io"],
)
