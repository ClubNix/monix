local Button = require "Gui.Button"

Menu = {}

-- we need to have a shared manager or love.handlers.buttonevent get erased
function Menu:setManager(m)
	Menu.manager = m
	return self
end

function Menu:setModel(m)
	Menu.model = m
	return self
end

function Menu:new(o)
	local menu = {}
	if o then
		menu.position = {
			x = o.position.x,
			y = o.position.y
		}
		menu.size = {
			width = o.size.width,
			height = o.size.height
		}
		menu.color = {unpack(o.color)}
	else
		menu.position = {x=80, y=120}
		menu.size = {width=800-(80*2), height=60}
		menu.color = {255,255,0,255}
	end
	
	local spaceBetweenButton = menu.size.width/7
	local marginOffsetWidth = (spaceBetweenButton - 40)/2
	local marginOffsetHeight = (menu.size.height - 40)/2
	
	for i=0,6 do
		local buttonTemplate = {
			position= {
				x=(i*spaceBetweenButton) + menu.position.x + marginOffsetWidth,
				y=menu.position.y + marginOffsetHeight
			},
			size= {width=40, height=40},
			color= {235,20,20,255}
		}
		
		local button = Button:new(buttonTemplate)
		self.manager:manage(button)
		button.click = function(self)
			local selectedButton = Menu.manager.selectedButton
			if selectedButton then
				print(selectedButton.account)
				Menu.manager:setSelected(nil)
			else
				print(i,self)
			end
		end
		table.insert(menu,button)
	end
	self.__index = self
	return setmetatable(menu, self)
end


function Menu:draw()
	local color = {love.graphics.getColor()}
	love.graphics.setColor(unpack(self.color))
	love.graphics.rectangle("fill", self.position.x, self.position.y, self.size.width, self.size.height)
	love.graphics.setColor(unpack(color))
	for i,v in ipairs(self) do
		v:draw()
	end
end

return Menu
