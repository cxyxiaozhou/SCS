#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class  Manager :public Worker
{
public:
	Manager(int id,string name,int dId)
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
		    <<"\tstandard:boss task over train technology"<<endl;

	}
	virtual string getDeptName()
	{
		return string("manager");
	}

};

