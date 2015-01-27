#include "Socket.h"
#include <iostream>

Socket::Socket(std::string role, int type) : socket_(context_, type){
	if(role == "./server"){
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

int Socket::send(std::string request){
	zmq::message_t zmessage(request.length());
	memcpy((void*)zmessage.data(), request.c_str(), request.length());
	socket_.send(zmessage);
	return 0;
}
