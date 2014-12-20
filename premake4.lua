solution "Monix"
	configurations ""
   project "monix"
      kind "ConsoleApp"
      language "C++"
      files({ "src/*.h", "src/*.cpp" })
      excludes({"src/mongo/"})
      includedirs({"src/"})
      
      flags({"Symbols", "ExtraWarnings", })
      links({"mongoclient", "boost_thread-mt", "boost_system", "boost_regex", "pthread", "boost_filesystem", "zmq"})
      libdirs({"Driver/"})
      
      buildoptions({"-std=c++11"})
      linkoptions({"-std=c++11"})


