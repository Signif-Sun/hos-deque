#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include "logic_source.h"

void deque_t()
{
	Deque deq(0);
	//病号挂号
	deq.guahao({"No-1","Sxh","Bzhang","7.0"});
	deq.guahao({ "No-2","Xs","Bzhang","2.6" });
	deq.guahao({ "No-3","Wc","Bzhang","9.2" });
	//病号诊断
	deq.zhenduan();
	//记录爽约
	deq.syjl();
	//爽约次数查询
	size_t sycnt = deq.shycx("Wc");
	//挂号总数目
	size_t currentcnt = deq.currcnt();
	//未看完病数目
	size_t mkwb = deq.currsycnt();
	//收入
	double shouru = deq.gtmoney();
	
	
}
