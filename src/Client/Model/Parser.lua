local M = {}
local parseFormat = '{ _id: "([%w_]+)", money: (-?%d+.%d+) }'

function M:init(model)
	model:connect()
	local mt = {__index= model}
	return setmetatable(self, mt)
end

function M:parse(s)
	local id,money = s:match(parseFormat)
	money = tonumber(money)
	return id,money
end

function M:memberList()
	return self:displayMembers():gmatch("%b{}")
end

function M:print()
	print(self:displayMembers())
end

return M
