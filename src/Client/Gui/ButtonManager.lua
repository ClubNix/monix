local Button = require "Gui/Button"
local Card = require "Gui/Card"
Button = Card
local ButtonManager = {}

ButtonManager.buttonList = {}
ButtonManager.defaultButton = Button:new()

function ButtonManager:default(buttonAttribute)
	for k,v in pairs(buttonAttribute) do
		self.defaultButton[k] = v
	end
end

function ButtonManager:newButton(x,y,width,height)
	if x then self.defaultButton.position.x = x end
	if y then self.defaultButton.position.y = y end
	if width then self.defaultButton.size.width = width end
	if height then self.defaultButton.size.height = height end
	
	local button = Button:new(self.defaultButton)
	table.insert(self.buttonList, button)
	return button
end

love.mousepressed = function(x, y, button)
	if button == "l" then
		for k,v in ipairs(ButtonManager.buttonList) do
			if v:isIn(x,y) then
				v.isPressed = true
			end
		end
	end
end

love.mousereleased = function(x, y, button)
	if button == "l" then
		for k,v in ipairs(ButtonManager.buttonList) do
			if v:isIn(x,y) then
				if v.isPressed then
					love.event.push("buttonevent","click",k)
				end
			end
			v.isPressed = false
		end
	end
end

love.handlers.buttonevent = function(what, key, c, d)
	local object = ButtonManager.buttonList[key]
	if type(object[what]) == "function" then
		object[what](object,c,d)
	end
--	print(object,"is "..what)
end

function ButtonManager:draw()
	for k,v in ipairs(self.buttonList) do
		v:draw()
	end
end

return ButtonManager
