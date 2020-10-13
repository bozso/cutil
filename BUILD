c_library(
    name = "error",
    srcs = glob(["cutil/error/**.c"]),
    hdrs = glob(["cutil/error/**.h"]),
)

c_library(
    name = "memory",
    srcs = glob(["cutil/memory/**.c"]),
    hdrs = glob(["cutil/memory/**.h"]),
    deps = [":error"],
)

c_library(
    name = "refcount",
    srcs = glob(["cutil/refcount/**.c"]),
    hdrs = glob(["cutil/refcount/**.h"]),
    deps = [":error", ":memory"],
)

cc_library(
    name = "util",
    srcs = glob(["util/**.cc"]),
    hdrs = glob(["util/**.hh"]),
)
