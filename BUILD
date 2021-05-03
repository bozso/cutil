<<<<<<< HEAD

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
=======
c_library(
    name = "io",
    srcs = glob(["cutil/io/**.c"]),
    hdrs = glob(["cutil/io/**.h"]),
)

c_library(
    name = "error",
    srcs = glob(["cutil/error/**.c"]),
    hdrs = glob(["cutil/error/**.h"]),
)

# c_library(
#     name = "error",
#     srcs = glob(["error/**.c"]),
#     hdrs = glob(["error/**.h"]),
# )
# 
# c_library(
#     name = "memory",
#     srcs = glob(["memory/**.c"]),
#     hdrs = glob(["memory/**.h"]),
#     deps = [":error"],
# )
# 
# c_library(
#     name = "refcount",
#     srcs = glob(["refcount/**.c"]),
#     hdrs = glob(["refcount/**.h"]),
#     deps = [":error", ":memory"],
# )
# 
# cc_library(
#     name = "util",
#     srcs = glob(["util/**.cc"]),
#     hdrs = glob(["util/**.hh"]),
# )
>>>>>>> f0ff2e7
