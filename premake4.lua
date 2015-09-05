solution "Monix"
	configurations ""
   project "server"
      kind "ConsoleApp"
      language "C++"
      files({ "src/Server/*.h", "src/Server/*.cpp" })
      includedirs({"src/Server/", "includes"})
      
      flags({"Symbols", "ExtraWarnings", })
      links({"mongoclient", "boost_thread", "boost_system", "boost_regex", "pthread", "boost_filesystem", "zmq"})
      libdirs({"Driver/"})
      
      buildoptions({"-std=c++11",
		    "-Wno-deprecated-declarations",
		    "-Wno-undefined-bool-conversion"
      })
      linkoptions({"-std=c++11"})
