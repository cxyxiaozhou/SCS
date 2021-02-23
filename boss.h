#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class  Boss :public Worker
{
public:
	Boss(int id,string name,int dId)
	{
		this->m_Id=id;
		this->m_Name=name;
		this->m_DeptId=dId;
	}
	virtual void showInfo()
	{
		cout<<"ID:"<<this->m_Id
		    <<"\tname: "<<this->m_Name
		    <<"\tcreer: "<<this->getDeptName()
		    <<"\tstandard:managements company"<<endl;

	}
	virtual string getDeptName()
	{
		return string("Boss");
	}

};

