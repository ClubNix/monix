local Button = {miaou= function() print("Button") end}

function Button:new()
	local button = {}
	button.position = {x=0, y=0}
	button.size = {width=80, height=60}
	button.color = {0,0,255,255}
	return setmetatable(button, {__index = self})
end

function Button:draw()
	local color = {love.graphics.getColor()}
	love.graphics.setColor(unpack(self.color))
	love.graphics.rectangle("fill", self.position.x, self.position.y, self.size.width, self.size.height)
	love.graphics.setColor(unpack(color))
end

function Button:isIn(x, y)
	local isInX = (self.position.x <= x and x <= self.position.x + self.size.width)
	local isInY = (self.position.y <= y and y <= self.position.y + self.size.height)
	if isInX and isInY then
		return true
	else
		return false
	end
end

return Button
