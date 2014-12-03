#include "Socket.h"
#include <iostream>

Socket::Socket() : socket_(context_, ZMQ_PULL){
	socket_.bind("ipc:///tmp/monix.ipc");
}

int Socket::receive(){
	zmq::message_t zmessage;
	socket_.recv(&zmessage);

	std::string message(static_cast<char*>(zmessage.data()), zmessage.size());
	std::cout << message << std::endl;
	return 0;
}

