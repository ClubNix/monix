#ifndef __ClientSocket_H__
#define __ClientSocket_H__

#include <zmq.hpp>

class ClientSocket{
	zmq::context_t context_;
	zmq::socket_t pushSocket_;
	zmq::socket_t pullSocket_;
	zmq::socket_t subSocket_;
	std::string message_;
	
public:
	ClientSocket();
	std::string message() const;
	int operator>>(std::string& message);
	void operator<<(std::string request);
	std::string receiveSubscription();
};

#endif /* __ClientSocket_H__ */

