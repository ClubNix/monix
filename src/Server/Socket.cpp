#include "Socket.h"
#include <iostream>

Socket::Socket(std::string role) : pushSocket_(context_,ZMQ_PUSH), pullSocket_(context_,ZMQ_PULL){
	if(role == "server"){
		pullSocket_.bind("tcp://*:42923");
		pushSocket_.connect("tcp://localhost:42924");
	}
	else{
		pushSocket_.connect("tcp://localhost:42923");
		pullSocket_.bind("tcp://*:42924");
	}
}

std::string Socket::message() const{
	return message_;
}

int Socket::operator>>(std::string& message){
	zmq::message_t zmessage;
	pullSocket_.recv(&zmessage);
	message = std::string(static_cast<char*>(zmessage.data()), zmessage.size());
	return message == "quit";
}

void Socket::operator<<(std::string request){
	zmq::message_t zmessage(request.size());
	memcpy(zmessage.data(), request.data(), request.size());
	pushSocket_.send(zmessage);
}


