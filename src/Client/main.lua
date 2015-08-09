ButtonManager = require "Gui.ButtonManager"
ZMQDriver = require "Model.ZMQDriver"
Model = require "Model.Parser"

function love.load()
	Model:init(ZMQDriver)
	local i=1
	for memberString in Model:memberList() do
		local pseudo, money = Model:parse(memberString)
		ButtonManager:newButton{x= i*130, account= pseudo, credit= money}
		i = i+1
	end
end

function love.update(dt)
end

function love.draw()
	ButtonManager:draw()
end

