ButtonManager = require "Gui/ButtonManager"
local zmq = require "lzmq"

local Model = {}
Model.context = zmq.context()

function Model:connect(uri_)
	local uri = uri_ or "tcp://localhost"
	self.socketPush = self.context:socket{zmq.PUSH, connect = uri..":42923"}
	self.socketPull = self.context:socket{zmq.PULL, bind = "tcp://*:42924"}
end

function Model:addUser(name, credit)
	self.socketPush:send("addUser(Suwako,23)")
end

function Model:displayMembers()
	self.socketPush:send("displayMembers()")
	return self.socketPull:recv()
end

function Model:addUser(pseudo, money)
end

function Model:removeUser(pseudo)
	self.socketPush:send("removeUser("..pseudo..")")
end

function Model:renameUser(pseudo, newPseudo)
	self.socketPush:send("renameUser("..pseudo..","..newPseudo..")")
end

function Model:setUserBalance(pseudo, money)
	self.socketPush:send("setUserBalance("..pseudo..","..money..")")
end

function Model:incUserBalance(pseudo, money)
	self.socketPush:send("incUserBalance("..pseudo..","..money..")")
end

function Model:incUserBalanceByOne(pseudo)
	self.socketPush:send("incUserBalanceByOne("..pseudo..")")
end

function Model:decUserBalance(pseudo, money)
	self.socketPush:send("decUserBalance("..pseudo..","..money..")")
end

function Model:decUserBalanceByOne(pseudo)
	self.socketPush:send("decUserBalanceByOne("..pseudo..")")
end

function Model:displaySum()
	self.socketPush:send("displaySum()")
end

function Model:getUserBalance(pseudo)
	self.socketPush:send("getUserBalance("..pseudo..")")
	return self.socketPull:recv()
end

function Model:hasMember(pseudo)
	self.socketPush:send("hasMember("..pseudo..")")
	return self.socketPull:recv()
end

return Model

