local MenuManager = {}
MenuManager.map = {
	[0]= "-1",
	[1]= "+1",
	[2]= "+2",
	[3]= "+4",
	[4]= "+10",
	[5]= "NULL",
	[6]= "custom"
}

love.handlers.menuevent = function(buttonNumber, accountName)
	local translation = MenuManager.map[buttonNumber]
	if translation then
		print(accountName, translation)
	else
		print("unknown button")
	end
end

return MenuMap
