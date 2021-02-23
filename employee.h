#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:
	Employee(int id,string name,int dId)
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
		    <<"\tstandard:manager task over"<<endl;
	}
	virtual string getDeptName()
	{
		return string("staff");
	}
};
