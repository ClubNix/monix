#!/usr/bin/luajit

zmq = require "lzmq"

local context = zmq.init(1)

local socket = context:socket(zmq.REQ)
socket:connect("tcp://localhost:5555")

print("Request: Decreased stick number")
socket:send("dec")
local reply = socket:recv()
print("Ack: " .. reply)

socket:close()
context:term()
