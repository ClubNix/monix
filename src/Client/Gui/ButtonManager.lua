local Card = require "Gui/Card"
local ButtonManager = {}

ButtonManager.buttonList = {}
ButtonManager.pages = 0
ButtonManager.currentPage = 1
ButtonManager.defaultButton = Card:new{
	color=	{0,139,0,255},
	size=	{height=60, width=120},
	position=	{x=100,y=100},
	title=	"Compte",
	account=	"root",
	credit=	"-1",
}
ButtonManager.selectedButton = nil

function ButtonManager:setSelected(button)
	self.selectedButton = button
end

function ButtonManager:default(buttonAttribute)
	for k,v in pairs(buttonAttribute) do
		self.defaultButton[k] = v
	end
end

function ButtonManager:manage(button)
	table.insert(self.buttonList, button)
end

function ButtonManager:newButton(o)
	local newButton = {
		position= {
			x=	o.x or self.defaultButton.position.x,
			y=	o.y or self.defaultButton.position.y
		},
		size= {
			width=	o.width or self.defaultButton.size.width,
			height=	o.height or self.defaultButton.size.height
		},
		color= {
			unpack(o.color or self.defaultButton.color)
		},
		title = o.title or self.defaultButton.title,
		account = o.account or self.defaultButton.account,
		credit = o.credit or self.defaultButton.credit
	}
	
	local button = Card:new(newButton)
	self:manage(button)
	
	return button
end

function ButtonManager:pagination()
	self.pages = math.ceil(#self.buttonList / 10)
end

love.mousepressed = function(x, y, button)
	if button == "l" or button == 1 then
		for k,v in ipairs(ButtonManager.buttonList) do
			if v:isIn(x,y) then
				v.isPressed = true
			end
		end
	end
end

love.mousereleased = function(x, y, button)
	if button == "l" or button == 1 then
		for k,v in ipairs(ButtonManager.buttonList) do
			if v:isIn(x,y) then
				if v.isPressed then
					love.event.push("buttonevent","click",k)
				end
			end
			v.isPressed = false
		end
	end
end

love.handlers.buttonevent = function(what, key, c, d)
	local object = ButtonManager.buttonList[key]
	if type(object[what]) == "function" then
		object[what](object,c,d)
	end
--	print(object,"is "..what)
end

love.keypressed = function(key)
	if key == "p" then
		ButtonManager:updatePage("next")
	end
	if key == "o" then
		ButtonManager:updatePage("prev")
	end
end

function ButtonManager:updatePage(action)
	if action == "next" then
		if self.currentPage < self.pages then
			self.currentPage = self.currentPage + 1
		end
	end
	if action == "prev" then
		if self.currentPage > 1 then
			self.currentPage = self.currentPage - 1
		end
	end
end

local drawHighlightRectangle = function(button)
	-- for highlight effect, make a rectangle a little bit larger than the card
	local highlight = {
		x= button.position.x,
		y= button.position.y - button.size.height/3,
		w= button.size.width,
		h= button.size.height + button.size.height/3,
	}
	
	local fivePercentOfACard = {
		w= 0.1 * (button.size.width),
		h= 0.1 * (button.size.height + button.size.height/3)
	}
	
	-- increase highliht rectangle size
	highlight.x = highlight.x - fivePercentOfACard.w
	highlight.y = highlight.y - fivePercentOfACard.h
	highlight.w = highlight.w + fivePercentOfACard.w*2
	highlight.h = highlight.h + fivePercentOfACard.h*2
	
	-- and draw it under the card with shader effect
	local rect = love.graphics.newMesh({
		{highlight.x,	highlight.y,	0,	0},
		{highlight.x+highlight.w,	highlight.y,	1,	0},
		{highlight.x+highlight.w,	highlight.y+highlight.h,	1,	1},
		{highlight.x,	highlight.y+highlight.h, 0, 1}
	})

	love.graphics.setShader(Shader.highlight)
	love.graphics.draw(rect)
	love.graphics.setShader()
end

function ButtonManager:draw()
	if self.currentPage == self.pages then
		for i = (self.currentPage-1)*10+1, #self.buttonList do
			local button = self.buttonList[i]
			if button == self.selectedButton then
				drawHighlightRectangle(button)
			end
			button:draw()
		end
	else
		for i = (self.currentPage-1)*10+1, self.currentPage*10 do
			local button = self.buttonList[i]
			if button == self.selectedButton then
				drawHighlightRectangle(button)
			end
			button:draw()
		end
	end
end

return ButtonManager
