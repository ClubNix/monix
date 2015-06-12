Button = require "Gui/Button"

local Card = Button:new()

function Card:new(defaultCard)
	local card = Button:new(defaultCard)
	self.__index = self
	return setmetatable(card,self)
end

function Card:draw()
	local color = {love.graphics.getColor()}
	love.graphics.setColor(unpack(self.color))
	local width,height = self.size.width/2, self.size.height/2
	love.graphics.circle("fill", self.position.x, self.position.y, math.sqrt(width^2 + height^2), 100);
	love.graphics.setColor(unpack(color))
end

return Card

