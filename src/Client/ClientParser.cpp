#include <regex>
#include <iostream>
#include "ClientParser.h"

ClientParser::NameMoneyList ClientParser::parse(std::string string){
	std::vector<ClientParser::PairName_Money> pairList;
	replaceAll(string, "\n", ";");
	std::string base_regex_string("(?:. _id: \"(.+?)\", money: (.+?) .;)");
//	std::string base_regex_string("\\{ _id: \"(.+?)\", money: ([\\d\\.]+?) \\}");
	std::regex base_regex(base_regex_string, std::regex::ECMAScript);
	std::smatch base_match;
	while(std::regex_search(string, base_match, base_regex)){
		pairList.push_back({base_match[1], base_match[2]});
		string = base_match.suffix().str();
	}
	return pairList;
}

//  http://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
void ClientParser::replaceAll(std::string& str, std::string from, std::string to){
	if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}
