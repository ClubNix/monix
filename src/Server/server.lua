#!/usr/bin/luajit

zmq = require "lzmq"

local context = zmq.init(1)

local socket = context:socket(zmq.REP)
socket:bind("tcp://*:5555")

local nstick = 9

print("Start server")
print("Actual number of sticks " .. nstick)

while true do
	local request = socket:recv()
	print("Decrease by one")
	nstick = nstick -1
	print("Actual number of sticks " .. nstick)

	socket:send("Number of sticks decreased")
end

socket:close()
context:term()
