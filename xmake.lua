-- project
set_project("Cutil")

-- set xmake minimum version
set_xmakever("2.3.2")

set_version("0.0.1", {build = "%Y%m%d%H%M"})

set_warnings("all", "error")

set_languages("c")

-- add build modes
add_rules("mode.release", "mode.debug", "mode.profile", "mode.coverage")

modules = {"error", "string", "array"}

target("cutil")
    for _, module in pairs(modules) do
        local dir =
        add_files(string.format("src/%s/*.c", module))
        add_headerfiles(string.format("include/%s/*.c", module))
    end
    set_kind("static")
    add_includedirs("include", {public = true})


-- include sub-projects
-- includes("standalone", "test")
