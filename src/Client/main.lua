ButtonManager = require "Gui.ButtonManager"
ZMQDriver = require "Model.ZMQDriver"
Model = require "Model.Parser"
Grid = require "Gui.Grid"

function love.load()
	Model:init(ZMQDriver)
	local position = Grid:init({offset={x=50, y=200}})
	selectedButton = nil
	for memberString in Model:memberList() do
		local pseudo, money = Model:parse(memberString)
		local x,y = position()
		local button = ButtonManager:newButton{x=x, y=y, account= pseudo, credit= money}
		button.click = function(self)
			selectedButton = self
		end
	end
	ButtonManager:pagination()
	love.graphics.setBackgroundColor(13, 64, 126)
	
	logo = love.graphics.newImage("resource/logo.png")
end

function love.update(dt)
end

function love.draw()
	love.graphics.draw(
		logo,
		love.graphics.getWidth()/2,	
		10,
		0,
		0.5,
		0.5,
		logo:getWidth()/2
	)
	ButtonManager:draw()
end

