ButtonManager = require "Gui/ButtonManager"
local zmq = require "lzmq"

function love.load()
	local context = zmq.context()
	local socketPush,err = context:socket{zmq.PUSH, connect = "tcp://localhost:42923"}
	local socketPull,err = context:socket{zmq.PULL, bind = "tcp://*:42924"}
	socketPush:send("addUser(Suwako,23)")
	socketPush:send("displayMembers()")
	print(socketPull:recv())
end

function love.update(dt)
end

ButtonManager:default({color= {0,255,0,255}, size={height=60, width=100}})
local testButton2 = ButtonManager:newButton(400,400)
testButton2.click = function(self)
	print(self, "button2 click")
end
function love.draw()
	testButton2:draw()
end

