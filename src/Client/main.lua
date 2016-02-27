#!/usr/bin/luajit

zmq = require "lzmq"
local utf8 = require "utf8"
local context = zmq.init(1)

local socket = context:socket(zmq.REQ)

input = "Input: "
var = ""
nstick = 0

function love.load()
	input = "Input:  "
	socket:send("start")
	nstick = socket:recv()
end

function love.textinput(t)
	var = var .. t
	love.keyboard.setKeyRepeat(true)
end

function love.keypressed(key)
	if key == "backspace" then
		local byteoffset = utf8.offset(var, -1)

		if byteoffset then
			var = string.sub(var, 1, byteoffset - 1)
		end
	elseif key == "return" then
		if tonumber(var) == nil then
			return
		end
		socket:send(var)
		nstick = socket:recv()
		var = ""
	end
	
end

function love.draw()
	love.graphics.setColor(255, 255, 255)
	love.graphics.printf(nstick, 10, 20, love.graphics.getWidth())
	love.graphics.printf(input .. var, 10, 50, love.graphics.getWidth())
end

socket:connect("tcp://localhost:5555")

love.load()
love.draw()

