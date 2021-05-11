-- project
includes("deps/flecs.lua")
add_requires("flecs 2.3.*")

set_project("Cutil")

local lang = "c"

-- set xmake minimum version
set_xmakever("2.3.2")

set_version("0.0.1", {build = "%Y%m%d%H%M"})

set_warnings("everything", "more", "error")


-- add build modes
add_rules("mode.release", "mode.debug", "mode.profile", "mode.coverage")

modules = {"error", "string", "memory", "result"}

local fmt = string.format

set_languages("c99")

target("cutil")
    for _, module in pairs(modules) do
        tpl_src = "src/%s/*.c"
        tpl_hdr = "include/%s/(*.h)"
        add_files(fmt(tpl_src, module))
        add_headerfiles(fmt(tpl_hdr, module))
    end
    set_kind("static")
    add_packages("flecs")
    add_includedirs("include", {public = true})


-- include sub-projects
-- includes("standalone", "test")
