solution "Monix"
	configurations ""
   project "server"
      kind "ConsoleApp"
      language "C++"
      files({ "src/Server/*.h", "src/Server/*.cpp" })
      includedirs({"src/Server/", "includes"})
      
      flags({"Symbols", "ExtraWarnings", })
      links({"mongoclient", "boost_thread-mt", "boost_system", "boost_regex", "pthread", "boost_filesystem", "zmq"})
      libdirs({"Driver/"})
      
      buildoptions({"-std=c++11"})
      linkoptions({"-std=c++11"})

   project "client"
      kind "ConsoleApp"
      language "C++"
      files{
      	"src/Client/*.h",
      	"src/Client/*.cpp",
      	"src/Server/Socket.cpp"
      }
      includedirs({"src/Client/"})
      
      flags({"Symbols", "ExtraWarnings", })
      links({"zmq", "ncurses"})
      
      buildoptions({"-std=c++11"})
      linkoptions({"-std=c++11"})


