local Button = require("Gui/Button")
local ButtonManager = {}

ButtonManager.button = {}

function ButtonManager:newButton()
	local button = Button:new()
	table.insert(self.button, button)
	return button
end

love.mousepressed = function(x, y, button)
	if button == "l" then
		for k,v in ipairs(ButtonManager.button) do
			if v:isIn(x,y) then
				v.isPressed = true
			end
		end
	end
end

love.mousereleased = function(x, y, button)
	if button == "l" then
		for k,v in ipairs(ButtonManager.button) do
			if v:isIn(x,y) then
				if v.isPressed then
					love.event.push("buttonevent","click",k)
				end
				v.isPressed = false
			end
		end
	end
end

love.handlers.buttonevent = function(what, key, c, d)
	local object = ButtonManager.button[key]
	if object[what] then
		object[what](object,c,d)
	end
--	print(object,"is "..what)
end

return ButtonManager

