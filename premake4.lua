solution "Monix"
	configurations ""
   project "monix"
      kind "ConsoleApp"
      language "C++"
      files({ "src/*.h", "src/*.cpp" })
 
      flags({"Symbols", "ExtraWarnings", })
      links({"mongoclient"})
      libdirs({"Driver/libmongoclient.a"})
