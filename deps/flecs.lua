package("flecs")
    set_homepage("https://github.com/SanderMertens/flecs")
    set_description([[Flecs is a fast and lightweight Entity Component
    System with a focus on high performance game development.
    ]])

    add_urls("https://github.com/SanderMertens/flecs/archive/refs/tags/$(version).zip",
             {alias = "github"})

    add_versions("github:v2.3.2", "ab13d33026836392331406398755d42cc1062f93f05f8a056c0a120c251592db")

    -- TODO(bozso): set up configuration options

    on_install(function (package)
        io.writefile("xmake.lua", [[
            add_rules("mode.debug", "mode.release")
            target("flecs")
                set_kind("$(kind)")
                add_files("flecs.c")
                add_headerfiles("flecs.h")
        ]])
        local configs = {}
        if package:config("shared") then
            configs.kind = "shared"
        end
        import("package.tools.xmake").install(package, configs)
    end)
