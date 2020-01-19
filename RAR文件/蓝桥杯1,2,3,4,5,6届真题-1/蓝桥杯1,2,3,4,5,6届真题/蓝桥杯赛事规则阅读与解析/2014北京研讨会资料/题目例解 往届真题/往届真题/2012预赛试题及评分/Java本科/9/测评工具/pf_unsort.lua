
local t_score={}
local t_out={}
local t_std={}

myread = function(t,filename)
local f = io.open(filename)
for line in f:lines() do
	table.insert(t,line)
end
f:close()
end


--���ļ��ж��룺�����𰸣���׼�𰸣���׼����
myread(t_score,"score.txt")
myread(t_out,"out.txt")
myread(t_std,"std.txt")

-- ��t_std, t_score ���ɼ�ֵmap
t2_std = {}
for i, k in ipairs(t_std) do
	t2_std[k] = t_score[i]
end

--��t_out�еļ�¼���ɵ�ֵmap���൱��set��
--�ڼ�Ҫѹ��������Ҫ�Ŀհ�
t2_out = {}
for i,v in ipairs(t_out) do
	v = string.gsub(v,"%s", "")  --����հ�
	t2_out[v] = 1  --��1�� ��ֵû���壬ֻ�Ǹ�ռλ��
end

--��ʼ�Ʒ�
sum = 0
for k in pairs(t2_out) do
	local a = t2_std[k] or -2  --�ҵ���Ǹ÷������������ 2 ��
	print(k,a)
	sum = sum + a
end

print("�ܷ�=" .. sum)
