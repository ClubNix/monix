#!/usr/bin/luajit

zmq = require "lzmq"
local MongoClient = require("mongorover.MongoClient")

local context = zmq.init(1)

local socket = context:socket(zmq.REP)
socket:bind("tcp://*:5555")

local mongoClient = MongoClient.new("mongodb://localhost:27017/")
local database = mongoClient:getDatabase("monix")
local collection = database:getCollection("account")

result = collection:find_one({name = "LIST"})

local nstick = result.amount

print("Start server")

while true do
	local request = socket:recv()
	if request ~= "start" then
		nstick = nstick - request
		local result = collection:update_one(
			{name = "LIST"}, {["$set"] = {amount = nstick}}
		)
	end

	socket:send(nstick)
end

socket:close()
context:term()
