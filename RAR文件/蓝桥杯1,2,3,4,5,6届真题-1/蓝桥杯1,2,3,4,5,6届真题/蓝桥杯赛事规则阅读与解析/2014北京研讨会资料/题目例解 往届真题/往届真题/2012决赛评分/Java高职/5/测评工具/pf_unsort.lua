
myread = function(t,filename)
local f = io.open(filename)
for line in f:lines() do
	table.insert(t,line)
end
f:close()
end

-- ����䵥��
myturn = function (t)
	local r = {}
	local ri = 1
	for _,v in ipairs(t) do
		--print (v)
		v = string.gsub(v,"%s", "")  --����հ�
		if v=="" then 
			if r[ri] then ri = ri + 1 end 
		else
			r[ri] = (r[ri] or "") .. v
		end
	end
	
	return r
end

---------------------------------------
---------------------------------------

t_score={}
t_out={}
t_std={}

--���ļ��ж��룺�����𰸣���׼�𰸣���׼����
myread(t_score,"score.txt")
myread(t_out,"out.txt")
myread(t_std,"std.txt")

-- ��t_std, t_out ����ϲ�Ϊ����
t_std2 = myturn(t_std)
t_out2 = myturn(t_out)

-- ��t_std2, t_score ���ɼ�ֵmap
map_std = {}
for i, k in ipairs(t_std2) do
	map_std[k] = t_score[i]
end

--��t_out2�еļ�¼���ɵ�ֵmap���൱��set��
map_out = {}
for i,v in ipairs(t_out2) do
	v = string.gsub(v,"%s", "")  --����հ�
	--print (v)
	map_out[v] = 1  --��1�� ��ֵû���壬ֻ�Ǹ�ռλ��
end

--��ʼ�Ʒ�
sum = 0
for k in pairs(map_out) do
	--print (k)
	local a = map_std[k] or -5  --�ҵ���Ǹ÷������������ 5 ��
	print(k,a)
	sum = sum + a
end

print("�ܷ�=" .. sum)
