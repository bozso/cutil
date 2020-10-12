c_library(
    name = "cutil",
    srcs = glob(["cutil/**.c"]),
    hdrs = glob(["cutil/**.h"]),
)

c_library(
    name = "error",
    srcs = glob(["error/**.c"]),
    hdrs = glob(["error/**.h"]),
)

c_library(
    name = "memory",
    srcs = glob(["memory/**.c"]),
    hdrs = glob(["memory/**.h"]),
    deps = [":error"],
)

c_library(
    name = "refcount",
    srcs = glob(["refcount/**.c"]),
    hdrs = glob(["refcount/**.h"]),
    deps = [":error", ":memory"],
)

cc_library(
    name = "util",
    srcs = glob(["util/**.cc"]),
    hdrs = glob(["util/**.hh"]),
)
