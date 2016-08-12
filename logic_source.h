//模仿医院诊断系统
class Deque {
public:
	Deque(size_t st): kwbcnt(st), kbcnt(st), money(st),ghcnt(st){};
	//Deque(initializer_list<initializer_list<string>> il, size_t st) :dv(il), cnt(st) {};
	//挂号看病总人数
	void guahao(initializer_list<string> il);
	//看完病人数
	void zhenduan();
	//看病人数
	size_t currcnt();
	//当前排队人数
	size_t currghcnt();
	//剩余人数
	size_t currsycnt();
	//盈利情况
	double gtmoney();
	//爽约记录
	void syjl();
	//爽约查询
	size_t shycx(string s);
	

private:
	//以队列为原型，参数为vector模板记录患者信息
	deque<vector<string>> dv;
	//备份所有登记的人及其信息
	deque<vector<string>> dvcnt;
	//爽约池
	map<string, int> shycnt;
	////记录实际到达人编号
	//vector<string> sjdd;
	//看完病人数
	size_t kwbcnt;
	//看病人数
	size_t kbcnt;
	//挂号人数
	size_t ghcnt;
	//盈利
	double money;	

};

void Deque::guahao(initializer_list<string> il)
{
	//原本需要将列表参数细化，之后if(shycnt[s] ==3){puts("你爽约3次，拜拜！;break;);}
	dv.push_back(il);
	dvcnt.push_back(il);
	++kbcnt;
	
}

double Deque::gtmoney()
{
	size_t st = dvcnt.size();
	for (int i = 0; i != st; i++)
	{
		money += stod(dvcnt[i][3]);
	}
	return money;
}

void Deque::zhenduan()
{
	dv.pop_front();
	++kwbcnt;
}

size_t Deque::currcnt()
{
	return kwbcnt;
}

size_t Deque::currghcnt()
{
	return dv.size();
}

size_t Deque::currsycnt()
{
	return kbcnt - kwbcnt;
}

size_t Deque::shycx(string s)
{
	return shycnt[s];
}

void Deque::syjl()
{
	auto beg = dv.begin();
	for (; beg != dv.end(); beg++)
	{
		//此处通过身份证号这种id信息来做，此处模拟以人名记录
		++(shycnt[(*beg)[1]]);
	}
}
