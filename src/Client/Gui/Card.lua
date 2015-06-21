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
	local header = {}
	header.color = {unpack(self.color)} --copy
	header.color[4] = 0.5*255
	header.position = {x= self.position.x, y= self.position.y-self.size.height/4}
	header.size = {width= self.size.width, height= self.size.height/4}
	
	love.graphics.setColor(header.color)
	love.graphics.rectangle(
		"fill",
		header.position.x,
		header.position.y,
		header.size.width,
		header.size.height
	)
	love.graphics.setColor(unpack(color))
	local titleSize = #self.title
	local flushedRightTitle = math.floor(header.size.width-(titleSize*8)) --TODO use monospace font
	love.graphics.print(self.title,header.position.x, header.position.y,0,1,1,-flushedRightTitle)
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

