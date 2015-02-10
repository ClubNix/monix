#include "ServerSocket.h"
#include <iostream>

ServerSocket::ServerSocket() : pushSocket_(context_,ZMQ_PUSH), pullSocket_(context_,ZMQ_PULL){
	pullSocket_.bind("tcp://*:42923");
	pushSocket_.connect("tcp://localhost:42924");
}

std::string ServerSocket::message() const{
	return message_;
}

int ServerSocket::operator>>(std::string& message){
	zmq::message_t zmessage;
	pullSocket_.recv(&zmessage);
	message = std::string(static_cast<char*>(zmessage.data()), zmessage.size());
	return message == "quit";
}

void ServerSocket::operator<<(std::string request){
	zmq::message_t zmessage(request.size());
	memcpy(zmessage.data(), request.data(), request.size());
	pushSocket_.send(zmessage);
}

