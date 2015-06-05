Button = require("Gui/Button")
ButtonManager = require("Gui/ButtonManager")

function love.load()
end

function love.update(dt)
end

local testButton = Button:new()
ButtonManager:addButton(testButton)

function love.draw()
	testButton:draw()
end

