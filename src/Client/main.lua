ButtonManager = require "Gui.ButtonManager"
ZMQDriver = require "Model.ZMQDriver"
Model = require "Model.Parser"

function love.load()
	ButtonManager:default({color= {0,255,0,255}, size={height=60, width=100}, position={x=100,y=100}, title="Club*Nix"})
	Model:init(ZMQDriver)
	for memberString in Model:memberList() do
		local pseudo, money = Model:parse(memberString)
		ButtonManager:newButton{x= money*10, account= pseudo}
	end
end

function love.update(dt)
end

function love.draw()
	ButtonManager:draw()
end

