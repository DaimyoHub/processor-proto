add_rules("mode.debug", "mode.release")

-- Executable binaries
target("app")
    set_kind("binary")
    set_languages("cxx20")
    add_files("app/*.cpp")
    add_includedirs("lib/")

    add_deps("context")

    if is_mode("debug") then
      add_defines("DEBUG")
    end

target("tests")
  set_kind("binary")
  set_languages("cxx20")
  add_files("tests/*.cpp")
  add_includedirs("lib/")

  add_deps("context")

  if is_mode("debug") then
    add_defines("DEBUG")
  end


-- Library binaries
target("context")
  set_kind("static")
  set_languages("cxx20")
  add_files("src/context/*.cpp")
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
