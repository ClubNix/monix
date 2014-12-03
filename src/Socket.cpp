#include "Socket.h"
#include <iostream>

Socket::Socket() : socket_(context_, ZMQ_PULL){
	socket_.bind("tcp://*:42923");
}

int Socket::receive(){
	zmq::message_t zmessage;
	socket_.recv(&zmessage);

	message_ = std::string(static_cast<char*>(zmessage.data()), zmessage.size());
	return message_ == "quit";
}

std::string Socket::message() const{
	return message_;
}

