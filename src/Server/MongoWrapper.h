#ifndef __MongoWrapper_H__
#define __MongoWrapper_H__

#include "Mongo.h"

class MongoWrapper : public Mongo{
public:
	static Mongo& database();
	static std::string addUser(std::vector<std::string> parameter);
	static std::string removeUser(std::vector<std::string> parameter);
	static std::string renameUser(std::vector<std::string> parameter);
	static std::string setUserBalance(std::vector<std::string> parameter);
	static std::string incUserBalance(std::vector<std::string> parameter);
	static std::string decUserBalance(std::vector<std::string> parameter);
	static std::string incUserBalanceByOne(std::vector<std::string> parameter);
	static std::string decUserBalanceByOne(std::vector<std::string> parameter);
	static std::string displayMembers(std::vector<std::string> parameter);
	static std::string displaySum(std::vector<std::string> parameter);
	
	static std::string getUserBalance(std::vector<std::string> parameter);
//	static bool hasMember(std::string pseudo);
};

#endif /* __MongoWrapper_H__ */

