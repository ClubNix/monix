local EventManager = {}

EventManager.button = {}

function EventManager:addButton(button)
	table.insert(self.button, button)
end

love.mousepressed = function(x, y, button)
	if button == "l" then
		for k,v in ipairs(EventManager.button) do
			if v:isIn(x,y) then
				v.isPressed = true
			end
		end
	end
end

love.mousereleased = function(x, y, button)
	if button == "l" then
		for k,v in ipairs(EventManager.button) do
			if v:isIn(x,y) then
				if v.isPressed then
					love.event.push("eventmanager","click",k)
				end
				v.isPressed = false
			end
		end
	end
end

love.handlers.eventmanager = function(what, key)
	local object = EventManager.button[key]
	print(object,"is "..what)
end

return EventManager

