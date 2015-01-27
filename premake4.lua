solution "Monix"
	configurations ""
   project "server"
      kind "ConsoleApp"
      language "C++"
      files({ "src/*.h", "src/*.cpp" })
      excludes({"src/mongo/", "src/Client.cpp"})
      includedirs({"src/"})
      
      flags({"Symbols", "ExtraWarnings", })
      links({"mongoclient", "boost_thread-mt", "boost_system", "boost_regex", "pthread", "boost_filesystem", "zmq", "ncurses"})
      libdirs({"Driver/"})
      
      buildoptions({"-std=c++11"})
      linkoptions({"-std=c++11"})

   project "client"
      kind "ConsoleApp"
      language "C++"
      files({ "src/*.h", "src/*.cpp" })
      excludes({"src/mongo/", "src/Server.cpp"})
      includedirs({"src/"})
      
      flags({"Symbols", "ExtraWarnings", })
      links({"mongoclient", "boost_thread-mt", "boost_system", "boost_regex", "pthread", "boost_filesystem", "zmq", "ncurses"})
      libdirs({"Driver/"})
      
      buildoptions({"-std=c++11"})
      linkoptions({"-std=c++11"})


