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
		void setMoney(std::string pseudo, float money);
		void incMoney(std::string pseudo, float money);
		void displayMembers();
};

#endif /* __mongo_H__ */

