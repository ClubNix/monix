#!/usr/bin/luajit

local zmq = require "lzmq"
local MongoClient = require("mongorover.MongoClient")

local context = zmq.init(1)

local socket = context:socket(zmq.REP)
local uri = "tcp://*:5555"
socket:bind(uri)

local mongoClient = MongoClient.new("mongodb://localhost:27017/")
local database = mongoClient:getDatabase("monix")
local collection = database:getCollection("account")


local nstick = 0
local account = collection:find_one({name= "LIST"})
if account then
	nstick = account.amount
else
	collection:insert_one({name= "LIST", amount= 0})
end

print("server started on "..uri)

while true do
	local request = socket:recv()
	if request ~= "start" then
		nstick = nstick + request
		local result = collection:update_one(
			{name= "LIST"}, {["$set"]= {amount= nstick}}
		)
	end

	socket:send(nstick)
end

socket:close()
context:term()
