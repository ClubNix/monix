Button = require("Gui/Button")
EventManager = require("Gui/EventManager")

function love.load()
end

function love.update(dt)
end

local testButton = Button:new()
EventManager:addButton(testButton)
EventManager:manage()

function love.draw()
	testButton:draw()
end

