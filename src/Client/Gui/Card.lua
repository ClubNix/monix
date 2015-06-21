Button = require "Gui/Button"

local Card = Button:new()

function Card:new(defaultCard)
	local card = Button:new(defaultCard)
	card.title = "miaou"
	card.account = "cirno"
	card.credit = "9"
	self.__index = self
	return setmetatable(card,self)
end

function Card:draw()
	local color = {love.graphics.getColor()}
	local headerColor = {unpack(self.color)} --copy
	headerColor[4] = 0.5*255
	love.graphics.setColor(unpack(headerColor))
	love.graphics.rectangle(
		"fill",
		self.position.x,
		self.position.y-self.size.height/4,
		self.size.width,
		self.size.height/4
	)
	love.graphics.setColor(unpack(color))
	Button.draw(self)
end

function Card:isInHeader(x,y)
	local isInX = (self.position.x <= x and x <= self.position.x + self.size.width)
	local isInY = (self.position.y-self.size.height/4 <= y and y <= self.position.y-self.size.height/4 + self.size.height/4)
	return isInX and isInY
end

function Card:isIn(x, y)
	local isInHeader = self:isInHeader(x,y)
	return Button.isIn(self,x,y) or isInHeader
end

return Card

