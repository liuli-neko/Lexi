-- 设置编译选项
add_rules("mode.debug","mode.release","mode.asan")

-- 依赖
add_repositories("btk-project https://github.com/Btk-Project/xmake-repo")
add_requires("btk")
add_packages("btk")
add_requires("eigen")
add_packages("eigen")

-- 设置c++版本
set_languages("c++17")

-- 平台依赖
if is_plat("linux") then 
    add_requires("pango", "pangocairo", "cairo", "libsdl", "libx11", "X11", "pthread")
    add_packages("pango", "pangocairo", "cairo", "libsdl", "libx11", "X11", "pthread")
elseif is_plat("windows") then
    add_cxxflags("/utf-8")
end

-- common file
add_files("common/log/*.cpp")

-- main target
target("main")
    add_includedirs(".")
    add_files("core/glyph/*.cc")
    add_files("core/window/*.cc")
    add_files("core/window/layout/*.cc")
    set_kind("binary")
    add_files("main.cc")
target_end()

-- test target
if not is_mode("release") then
    target("iterator_test")
        add_includedirs(".")
        add_files("core/glyph/*.cc")
        add_files("core/window/*.cc")
        add_files("core/window/layout/*.cc")
        set_kind("binary")
        add_files("test/iterator_test.cc")
    target_end()

    target("win_test")
        if is_plat("linux") then
            add_links("X11", "pthread")
        end
        add_includedirs(".")
        add_files("core/glyph/*.cc")
        add_files("core/window/*.cc")
        add_files("core/window/layout/*.cc")
        set_kind("binary")
        add_files("test/win_test.cc")
    target_end()
end
--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

