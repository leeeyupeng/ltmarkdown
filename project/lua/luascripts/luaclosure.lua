function foo()
	local n = 1
	local function printn()
		print(tostring(n))
	end
	local function setn(_n)
		n = _n
	end
	print(tostring(n))
	printn()
	setn(10)
	print(tostring(n))
	printn()
	return printn,setn
end

f1,f2 = foo()

f1()
f2(100)
f1()
f2(200)
f1()

print("--------------------")

function foo(n)
	local function printn()
		print(tostring(n))
	end
	local function setn(_n)
		n = _n
	end
	print(tostring(n))
	printn()
	setn(10)
	print(tostring(n))
	printn()
	return printn,setn
end
local n = 1
f1,f2 = foo(n)
print(tostring(n))
f1()
f2(100)
f1()
f2(200)
f1()
print(tostring(n))

print("--------------------")

function foo(n)
	n=n+1
	print(tostring(n))
end

local n = 1
f = foo(n)
print(tostring(n))

print("--------------------")
function foo()
	local data={name="test",value=1}
	print(data)
	local function getdata()
		return data
	end
	local function setdata(value)
		data.value = value
	end
	return getdata,setdata
end
local getdata,setdata = foo(data)
local data2 = getdata()
print(data2)
setdata(2)
print(data2)
print(data2.name..":"..data2.value)

print("--------------------")
function foo(data)
	print(data)
	local function getdata()
		return data
	end
	local function setdata(value)
		data.value = value
	end
	return getdata,setdata
end
local getdata=nil 
local setdata=nil

function f()	
	local data={name="test",value=1}
	print(data)
	print(data.name..":"..data.value)
	getdata,setdata = foo(data)
end
f()
print(data)

print(data)
--print(data.name..":"..data.value)

local data2 = getdata()
print(data2)
setdata(2)
print(data2)
print(data2.name..":"..data2.value)

print(data)
--print(data.name..":"..data.value)