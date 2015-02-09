#ifndef __ServerSocket_H__
#define __ServerSocket_H__

#include <zmq.hpp>

class ServerSocket{
	zmq::context_t context_;
	zmq::socket_t pushSocket_;
	zmq::socket_t pullSocket_;
	std::string message_;
public:
	ServerSocket();
	std::string message() const;
	int operator>>(std::string& message);
	void operator<<(std::string request);
};

#endif /* __ServerSocket_H__ */

