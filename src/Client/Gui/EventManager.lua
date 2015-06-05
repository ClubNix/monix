local EventManager = {}

EventManager.button = {}

function EventManager:addButton(button)
	table.insert(self.button, button)
end

love.mousepressed = function(x, y, button)
	for k,v in ipairs(EventManager.button) do
		if v:isIn(x,y) then
			v.isPressed = true
		end
	end
end

love.mousereleased = function(x, y, button)
	for k,v in ipairs(EventManager.button) do
		if v:isIn(x,y) then
			if v.isPressed then
				print(v,"is Click")
			end
			v.isPressed = false
		end
	end
end

return EventManager

