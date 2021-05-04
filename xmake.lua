-- project
set_project("Cutil")

local lang = "cpp"

-- set xmake minimum version
set_xmakever("2.3.2")

set_version("0.0.1", {build = "%Y%m%d%H%M"})

set_warnings("all", "error")


-- add build modes
add_rules("mode.release", "mode.debug", "mode.profile", "mode.coverage")

modules = {"error", "string", "array", "memory"}

c = {
    src="c",
    hdr="h",
    name="cutil",
}

cpp = {
    src="cpp",
    hdr="hpp",
    name="cpputil",
}

local conf = c
local fmt = string.format

if lang == "cpp" then
    conf = cpp
end

set_languages(lang)

local name = conf.name

target(name)
    for _, module in pairs(modules) do
        tpl_src = fmt("%s/src/%%s/*.%s", name, conf.src)
        tpl_hdr = fmt("%s/include/%%s/(*.%s)", name, conf.hdr)
        add_files(fmt(tpl_src, module))
        add_headerfiles(fmt(tpl_hdr, module))
    end
    set_kind("static")
    add_includedirs(fmt("%s/include", name), {public = true})

-- include sub-projects
-- includes("standalone", "test")
