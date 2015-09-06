local M = {}

local iterator = function()
	local x,y = M.offset.x, M.offset.y
	card_count = 0
	while (y + M.cardHeight + M.padding) < M.windowHeight do
		while (x + M.cardWidth + M.padding) < M.windowWidth do
			coroutine.yield(x,y)
			card_count = card_count + 1
			if card_count < 10 then
				x = x + M.cardWidth + M.padding
			else
				x = M.offset.x
				y = M.offset.y
				card_count = 0
			end
		end
		x = M.offset.x
		y = y+ M.cardHeight + M.padding
	end
end

function M:init(dimension)
	if dimension then
		if dimension.card then
			self.cardWidth	= dimension.card.width or 120
			self.cardHeight	= dimension.card.height or 80
		else
			self.cardWidth	= 120
			self.cardHeight	= 80
		end
		
		if dimension.window then
			self.windowWidth	= dimension.window.width or 800
			self.windowHeight	= dimension.window.height or 600
		else
			self.windowWidth	= 800
			self.windowHeight	= 600
		end

		if dimension.offset then
			self.offset = {x=dimension.offset.x or 0, y= dimension.offset.y or 0}
		else
			self.offset = {x=0, y=0}
		end
		
		self.padding =	dimension.padding or 10
	else
		self.offset	= {x=0, y=0}
		self.padding	= 10
		self.cardWidth	= 120
		self.cardHeight	= 80
		self.windowWidth	= 800
		self.windowHeight	= 600
	end
	
	return coroutine.wrap(iterator)
end

return M

