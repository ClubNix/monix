ButtonManager = require "Gui/ButtonManager"
local zmq = require "lzmq"

local M = {}
M.context = zmq.context()

function M:connect(uri_)
	local uri = uri_ or "tcp://localhost"
	self.socketPush = self.context:socket{zmq.PUSH, connect = uri..":42923"}
	self.socketPull = self.context:socket{zmq.PULL, bind = "tcp://*:42924"}
end

function M:addUser(name, credit)
	self.socketPush:send("addUser(Suwako,23)")
end

function M:displayMembers()
	self.socketPush:send("displayMembers()")
	return self.socketPull:recv()
end

function M:addUser(pseudo, money)
end

function M:removeUser(pseudo)
	self.socketPush:send("removeUser("..pseudo..")")
end

function M:renameUser(pseudo, newPseudo)
	self.socketPush:send("renameUser("..pseudo..","..newPseudo..")")
end

function M:setUserBalance(pseudo, money)
	self.socketPush:send("setUserBalance("..pseudo..","..money..")")
end

function M:incUserBalance(pseudo, money)
	self.socketPush:send("incUserBalance("..pseudo..","..money..")")
end

function M:incUserBalanceByOne(pseudo)
	self.socketPush:send("incUserBalanceByOne("..pseudo..")")
end

function M:decUserBalance(pseudo, money)
	self.socketPush:send("decUserBalance("..pseudo..","..money..")")
end

function M:decUserBalanceByOne(pseudo)
	self.socketPush:send("decUserBalanceByOne("..pseudo..")")
end

function M:displaySum()
	self.socketPush:send("displaySum()")
end

function M:getUserBalance(pseudo)
	self.socketPush:send("getUserBalance("..pseudo..")")
	return self.socketPull:recv()
end

function M:hasMember(pseudo)
	self.socketPush:send("hasMember("..pseudo..")")
	return self.socketPull:recv()
end

return M

