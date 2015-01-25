#ifndef __MongoWrapper_H__
#define __MongoWrapper_H__
#include "mongo.h"

class MongoWrapper : public Mongo{
public:
	static void addUser(std::vector<std::string> parameter);
};

#endif /* __MongoWrapper_H__ */

