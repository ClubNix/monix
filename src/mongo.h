#ifndef __mongo_H__
#define __mongo_H__

class Mongo{
	private:
		std::string dbName_;
		mongo::DBClientConnection* connection_;
		
	public:
		Mongo();
		void addUser(std::string pseudo, float money);
		void removeUser(std::string pseudo);
		void renameUser(std::string pseudo, std::string newPseudo);
		void setUserBalance(std::string pseudo, float money);
		void incUserBalance(std::string pseudo, float money);
		void incUserBalanceByOne(std::string pseudo);
		void decUserBalance(std::string pseudo, float money);
		void decUserBalanceByOne(std::string pseudo);
		void displayMembers();
		void displaySum();
		float getUserBalance(std::string pseudo);
};

#endif /* __mongo_H__ */

