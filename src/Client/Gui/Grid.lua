local M = {}

local iterator = function()
	local x,y = M.offset.x, M.offset.y
	while y + M.cardHeight + M.padding < M.windowHeight do
		while x + M.cardWidth + M.padding < M.windowWidth do
			coroutine.yield(x,y)
			x = x+ M.cardWidth + M.padding
		end
		y = y+ M.cardHeight + M.padding
	end
end

function M.init(dimension, offset)
	if dimension then
		if dimension.card then
			M.cardWidth	= dimension.card.width
			M.cardHeight	= dimension.card.height
		else
			M.cardWidth	= 120
			M.cardHeight	= 60
		end
		
		if dimension.window then
			M.windowWidth	= dimension.window.width 
			M.windowHeight	= dimension.window.height
		else
			M.windowWidth	= 800
			M.windowHeight	= 600
		end
		M.padding =	dimension.padding or 10
	else
		M.padding	= 10
		M.cardWidth	= 120
		M.cardHeight	= 60
		M.windowWidth	= 800
		M.windowHeight	= 600
	end
	
	if offset then
		M.offset = {x=offset.x, y= offset.y}
	else
		M.offset = {x=0, y=0}
	end
	
	return coroutine.wrap(iterator)
end

return M

