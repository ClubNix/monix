ButtonManager = require("Gui/ButtonManager")

function love.load()
end

function love.update(dt)
end

local testButton = ButtonManager:newButton()

function love.draw()
	testButton:draw()
end

