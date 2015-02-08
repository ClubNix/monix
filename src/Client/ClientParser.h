#ifndef __ClientParser_H__
#define __ClientParser_H__

#include <vector>
#include <utility>
#include <string>

struct ClientParser{
	using PairName_Money = std::pair<std::string, std::string>;
	using NameMoneyList = std::vector<PairName_Money>;
	static NameMoneyList parse(std::string);
	static void replaceAll(std::string& str, std::string from, std::string to);
};

#endif /* __ClientParser_H__ */

