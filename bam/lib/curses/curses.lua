lib = {
	path = PathDir(ModuleFilename()),
}

function lib:configure()
end

function lib:apply(settings)
	settings.cc.includes:Add("usr/include")
	settings.link.libs:Add("curses")
end
