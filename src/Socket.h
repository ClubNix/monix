#ifndef __socket_H__
#define __socket_H__

#include <zmq.hpp>

class Socket{
	zmq::context_t context_;
	zmq::socket_t socket_;
	std::string message_;
public:
	Socket();
	int receive();
	std::string message() const;
	int operator>>(std::string& message);
};

#endif /* __socket_H__ */

