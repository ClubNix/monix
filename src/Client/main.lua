ButtonManager = require "Gui/ButtonManager"
ZMQDriver = require "Model"
Model = require "ModelParser"

function love.load()
	Model:init(ZMQDriver)
	Model:print()
end

function love.update(dt)
end

ButtonManager:default({color= {0,255,0,255}, size={height=60, width=100}})
local testButton2 = ButtonManager:newButton(400,400)
ButtonManager:newButton(500,500)

testButton2.click = function(self)
	print(self, "button2 click")
	Model:displaySum()
end

function love.draw()
	ButtonManager:draw()
end

