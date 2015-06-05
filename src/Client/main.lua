ButtonManager = require("Gui/ButtonManager")

function love.load()
end

function love.update(dt)
end

local testButton = ButtonManager:newButton()
testButton.click = function(self)
	print(self, "i am click")
end

function love.draw()
	testButton:draw()
end

