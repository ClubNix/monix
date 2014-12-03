#ifndef __socket_H__
#define __socket_H__

#include <zmq.hpp>

class Socket{
	zmq::context_t context_;
	zmq::socket_t socket_;
	
public:
	Socket();
	int receive();
};

#endif /* __socket_H__ */

