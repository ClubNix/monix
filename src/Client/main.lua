ButtonManager = require "Gui.ButtonManager"
ZMQDriver = require "Model.ZMQDriver"
Model = require "Model.Parser"
Grid = require "Gui.Grid"

function love.load()
	Model:init(ZMQDriver)
	local position = Grid:init({offset={x=50, y=200}})
	for memberString in Model:memberList() do
		local pseudo, money = Model:parse(memberString)
		local x,y = position()
		ButtonManager:newButton{x=x, y=y, account= pseudo, credit= money}
	end
	ButtonManager:pagination()
	love.graphics.setBackgroundColor(13, 64, 126)

end

function love.update(dt)
end

function love.draw()
	ButtonManager:draw()
end

