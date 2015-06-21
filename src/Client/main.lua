ButtonManager = require "Gui/ButtonManager"
Model = require "Model"


function love.load()
	Model:connect()
	print(Model:displayMembers())
end

function love.update(dt)
end

ButtonManager:default({color= {0,255,0,255}, size={height=60, width=100}})
local testButton2 = ButtonManager:newButton(400,400)
testButton2.click = function(self)
	print(self, "button2 click")
	Model:displaySum()
end
function love.draw()
	testButton2:draw()
end

