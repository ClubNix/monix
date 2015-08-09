ButtonManager = require "Gui.ButtonManager"
ZMQDriver = require "Model.ZMQDriver"
Model = require "Model.Parser"
Grid = require "Gui.Grid"

function love.load()
	Model:init(ZMQDriver)
	local position = Grid:init()
	for memberString in Model:memberList() do
		local pseudo, money = Model:parse(memberString)
		local x,y = position()
		print(x,y)
		ButtonManager:newButton{x=x, y=y, account= pseudo, credit= money}
	end
end

function love.update(dt)
end

function love.draw()
	ButtonManager:draw()
end

