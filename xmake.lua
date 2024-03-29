add_rules("mode.debug", "mode.release")

set_toolchains("gcc")
set_languages("cxx20")

-- Executable binaries
--target("app")
--    set_kind("binary")
--    add_files("app/*.cpp")
--    add_includedirs("lib/")

--    add_deps("context")

--    if is_mode("debug") then
--      add_defines("DEBUG")
--    end

target("tests")
  set_kind("binary")
  add_files("tests/*.cpp")
  add_includedirs("lib/")

  add_deps("mem", "isa", "core")

  if is_mode("debug") then
    add_defines("DEBUG")
  end


-- Library binaries
target("mem")
  set_kind("static")
  add_files("src/mem/*.cpp")
  add_includedirs("lib/")

  if is_mode("debug") then
    add_defines("DEBUG")
  end

target("isa")
  set_kind("static")
  add_files("src/isa/*.cpp")
  add_includedirs("lib/")

  add_deps("core")

  if is_mode("debug") then
    add_defines("DEBUG")
  end

target("core")
  set_kind("static")
  add_files("src/core/*.cpp")
  add_includedirs("lib/")

  if is_mode("debug") then
    add_defines("DEBUG")
  end

--target("control")
--  set_kind("static")
--  add_files("src/control/*.cpp")

--  if is_mode("debug") then
--    add_defines("DEBUG")
--  end

--target("core")
--  set_kind("static")
--  add_files("src/core/*.cpp")

--  if is_mode("debug") then
--    add_defines("DEBUG")
--  end

--target("logic")
--  set_kind("static")
--  add_files("src/logic/*.cpp")

--  if is_mode("debug") then
--    add_defines("DEBUG")
--  end
