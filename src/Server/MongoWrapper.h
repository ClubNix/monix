#ifndef __MongoWrapper_H__
#define __MongoWrapper_H__

#include "Mongo.h"

class MongoWrapper : public Mongo{
public:
	static Mongo& database();
	static void addUser(std::vector<std::string> parameter);
	static void removeUser(std::vector<std::string> parameter);
	static void renameUser(std::vector<std::string> parameter);
	static void setUserBalance(std::vector<std::string> parameter);
	static void incUserBalance(std::vector<std::string> parameter);
	static void decUserBalance(std::vector<std::string> parameter);
	static void incUserBalanceByOne(std::vector<std::string> parameter);
	static void decUserBalanceByOne(std::vector<std::string> parameter);
	static void displayMembers(std::vector<std::string> parameter);
	static void displaySum(std::vector<std::string> parameter);
	
	static std::string getUserBalance(std::vector<std::string> parameter);
//	static bool hasMember(std::string pseudo);
};

#endif /* __MongoWrapper_H__ */

