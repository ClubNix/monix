#include "ClientSocket.h"
#include <iostream>

ClientSocket::ClientSocket():
pushSocket_(context_,ZMQ_PUSH),
pullSocket_(context_,ZMQ_PULL),
subSocket_(context_,ZMQ_SUB){
	subSocket_.connect("tcp://localhost:42922");
	subSocket_.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	pushSocket_.connect("tcp://localhost:42923");
	pullSocket_.bind("tcp://*:42924");
}

std::string ClientSocket::message() const{
	return message_;
}

int ClientSocket::operator>>(std::string& message){
	zmq::message_t zmessage;
	pullSocket_.recv(&zmessage);
	message = std::string(static_cast<char*>(zmessage.data()), zmessage.size());
	return message == "quit";
}

void ClientSocket::operator<<(std::string request){
	zmq::message_t zmessage(request.size());
	memcpy(zmessage.data(), request.data(), request.size());
	pushSocket_.send(zmessage);
}

std::string ClientSocket::receiveSubscription(){
	zmq::message_t zmessage;
	subSocket_.recv(&zmessage);
	std::string message(static_cast<char*>(zmessage.data()), zmessage.size());
	return message;
}

