#include "ServerSocket.h"
#include <iostream>

ServerSocket::ServerSocket():
pushSocket_(context_,ZMQ_PUSH),
pullSocket_(context_,ZMQ_PULL),
pubSocket_(context_,ZMQ_PUB){
	pubSocket_.bind("tcp://*:42922");
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

void ServerSocket::publish(std::string message){
	zmq::message_t zmessage(message.size());
	memcpy(zmessage.data(), message.data(), message.size());
	pubSocket_.send(zmessage);
}

