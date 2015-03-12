#!/usr/bin/python2.7

import zmq

context = zmq.Context()

pullSocket = context.socket(zmq.PULL)
pullSocket.bind("tcp://*:42924")

pushSocket = context.socket(zmq.PUSH)
pushSocket.connect("tcp://localhost:42923")

message = ""

pushSocket.send("addUser(Suwako,23)")
pushSocket.send("displayMembers()")
print(pullSocket.recv())

