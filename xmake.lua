-- project
includes("deps/flecs.lua")
add_requires("flecs 2.3.*")

set_project("Cutil")

local lang = "c"

-- set xmake minimum version
set_xmakever("2.3.2")

set_version("0.0.1", {build = "%Y%m%d%H%M"})

set_warnings("everything", "more", "error")

local release = {
    compile = {
        "-march=native", "-fwhole-program", "-fprofile-use", "-flto",
        "-fomit-frame-pointer",
    },
    link = {
        "--gc-sections", "-flto",
    },
}

function add_flags()
    if is_mode("release") then
        set_strip("all")
        add_cflags(release.compile)
        add_ldflags(release.link)
        set_optimize("fastest")
    end
end

-- add build modes
add_rules("mode.release", "mode.debug", "mode.profile", "mode.coverage")

modules = {"error", "string", "memory", "result", "common"}

local fmt = string.format

set_languages("c99")

option("openmp")
    add_cflags("-fopenmp")
    add_defines("CUTIL_OPENMP")

target("cutil")
    for _, module in pairs(modules) do
        tpl_src = "src/%s/*.c"
        tpl_hdr = "include/%s/(*.h)"
        add_files(fmt(tpl_src, module))
        add_headerfiles(fmt(tpl_hdr, module))
    end
    -- add_flags()
    set_kind("static")
    add_packages("flecs")
    add_includedirs("include", {public = true})

target("test")
    add_files("src/bin/test.c")
    for _, module in pairs(modules) do
        tpl_src = "src/%s/*_test.c"
        add_files(fmt(tpl_src, module))
        add_headerfiles("include/tests.h")
    end
    set_kind("binary")
    add_deps("cutil")


-- include sub-projects
-- includes("standalone", "test")
