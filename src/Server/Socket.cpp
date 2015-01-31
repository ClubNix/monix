#include "Socket.h"
#include <iostream>

Socket::Socket(std::string role, int type) : socket_(context_, type){
	if(role == "server"){
		socket_.bind("tcp://*:42923");
	}
	else{
		socket_.connect("tcp://localhost:42923");
	}
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

int Socket::operator>>(std::string& message){
	zmq::message_t zmessage;
	socket_.recv(&zmessage);
	message = std::string(static_cast<char*>(zmessage.data()), zmessage.size());
	return message == "quit";
}

void Socket::operator<<(std::string request){
	zmq::message_t zmessage(request.size());
	memcpy(zmessage.data(), request.data(), request.size());
	socket_.send(zmessage);
}


