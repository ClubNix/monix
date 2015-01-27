#!/usr/bin/lua

local zmq = require "lzmq"
local context = zmq.context()
--local socket,err = context:socket{zmq.PUSH, connect = "ipc://miaou.ipc"}
--local socket,err = context:socket{zmq.PUSH, connect = "ipc:///tmp/monix.ipc"}
local socket,err = context:socket{zmq.PUSH, connect = "tcp://localhost:42923"}
--local socket,err = context:socket{zmq.PUSH, connect = "udp://localhost:424242"}

--local message = ""
--repeat
--	message = io.read()
--	socket:send(message)
--until message == "quit"
if err then
	print(err)
end
socket:send("addUser(Cirno,9)")
socket:send("displayMembers()")
socket:send("quit")
