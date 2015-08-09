local M = {}

function M:init(model)
	model:connect()
	local mt = {__index= model}
	return setmetatable(self, mt)
end

function M:print()
	print(self:displayMembers())
end

return M