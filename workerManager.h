#pragma once 
#include<iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#include<string>
#define FILENAME "record.txt"
class WorkerManager
{
public:
	WorkerManager()
    {
	    this->m_EmpNum=0;
	    this->m_EmpArray=NULL;
	    int num=this->get_EmpNum();
	    cout<<"staff number:"<<num<<endl;
	    this->m_EmpNum=num;
	    this->m_EmpArray=new Worker*[this->m_EmpNum];
	    this->init_Emp();
	    for(int i=0;i<this->m_EmpNum;i++)
	    {
	    	cout<<"id"<<this->m_EmpArray[i]->m_Id<<endl;
	    }

    }
	
	void Show_Menu()
    {
        cout<<"----------------------------------------"<<endl;
        cout<<"|	欢迎使用职工管理系统          |"<<endl;
        cout<<"|	    0.退出管理	              |"<<endl;
        cout<<"|           1.增加职工信息            |"<<endl;
        cout<<"|	    2.显示职工信息            |"<<endl;
        cout<<"|	    3.删除离职职工信息        |"<<endl;
        cout<<"|	    4.修改职工信息            |"<<endl;
        cout<<"|           5.查找职工信息            |"<<endl;
        cout<<"|	    6.按照编号排              |"<<endl;
        cout<<"|	    7.清空所有文档            |"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<endl;

    } 
	void ExitSystem()
	{
		cout<<"exit"<<endl;
		exit(0);
	
	}

	int m_EmpNum;
	//pointer array
	Worker ** m_EmpArray;
	void Add_Emp()
	{
		cout<<this->m_EmpNum<<endl;
		cout<<"add Num:"<<endl;
		int addNum=0;
		cin>>addNum;
		if(addNum>0)
		{
		int newSize=this->m_EmpNum+addNum;
		Worker ** newSpace=new Worker*[newSize];
		if(this->m_EmpArray!=NULL)
		{
			for(int i=0;i<this->m_EmpNum;i++)
			{
				newSpace[i]=this->m_EmpArray[i];
			
			}
		
		}
		for(int i=0;i<addNum;i++)
		{
			int id;
			string name;
			int dSelect;

			cout<<"current people num:"<<i+1<<"id"<<endl;
			cin>>id;
			cout<<":"<<i+1<<"name"<<endl;
			cin>>name;

			cout<<"please choice[1-3]"<<endl;
			cout<<"1 staff"<<endl;
			cout<<"2 manager"<<endl;
			cout<<"3 Boss"<<endl;
			cin>>dSelect;

			Worker *worker=NULL;
			switch(dSelect)
			{
				case 1:
					worker=new Employee(id,name,1);
					break;
				case 2:
					worker=new Manager(id,name,2);
					break;
				case 3:
					worker=new Boss(id,name,3);
					break;
				default:
					break;

			
			}
			newSpace[this->m_EmpNum+i]=worker;
		
		
		}
		delete [] this->m_EmpArray;
		this->m_EmpArray=newSpace;
		this->m_EmpNum=newSize;

		cout<<"add:"<<addNum<<"worker !"<<endl;

		this->save();
		}
		else
		{
			cout<<"wrong !"<<endl;
		
		}
	
	}
	void save()
	{
	
		ofstream ofs;
		ofs.open(FILENAME,ios::out);
		for(int i=0;i<this->m_EmpNum;i++)
		{
		
		
		ofs<<this->m_EmpArray[i]->m_Id<<" "
		   <<this->m_EmpArray[i]->m_Name<<" \n"
		   <<this->m_EmpArray[i]->m_DeptId<<endl;
		}
		ofs.close();

	}
	int get_EmpNum()
	{
		
		ifstream ifs;
		ifs.open(FILENAME,ios::in);
		int id;
		string name;
		int dId;
		int num=0;
		while(ifs>>id &&ifs>>name &&ifs>>dId)
		{
			num++;
		
		}
		return num;
	}
	void init_Emp()
	{
		//set file content subject in the varible inside
		//subject paramater by newload function Employee 
		ifstream ifs;
		ifs.open(FILENAME,ios::in);
		int id;
		string name;
		int dId;
		int index=0;
		while(ifs>>id&&ifs>>name&&ifs>>dId)
		{
			Worker * worker=NULL;
			if(dId==1)
			{
				worker=new Employee(id,name,dId);
	
			
			}
			else if(dId==2)
			{
				worker=new Manager(id,name,dId);
			
			}
			else
			{
				worker=new Boss(id,name,dId);
			
			}
			this->m_EmpArray[index]=worker;
			index++;

		
		
		}
		
		ifs.close();
	}
	void  Show_Emp()
	{
			
			for(int i=0;i<m_EmpNum;i++)
			{
				this->m_EmpArray[i]->showInfo();

			}


		
	}
	void Del_Emp()
	{
	

		cout<<"ID:"<<endl;
		int id=0;
		cin>>id;
		int index=this->IsExist(id);
		if(index!=-1)
		{
			for(int i=index;i<this->m_EmpNum-1;i++)
			{
				this->m_EmpArray[i]=this->m_EmpArray[i+1];
			}
			this->m_EmpNum--;
			this->save();
			cout<<"delete sucess"<<endl;


		}
		else
		{
			cout<<"filire!:not person"<<endl;
		}

	}
	int IsExist(int id)
	{
		int index=-1;
		for(int i=0;i<this->m_EmpNum;i++)
		{
			if(this->m_EmpArray[i]->m_Id==id)
			{
				index=i;
				break;
			}
		}
		return index;

	}

	
	void Mod_Emp()
	{
	
			
			cout<<"id:"<<endl;
			int id;
			cin>>id;
			int ret=this->IsExist(id);
			if(ret!=-1)
			{
				
				delete  this->m_EmpArray[ret];
				int newId=0;
				string newName="";
				int dSelect=0;

				cout<<"FINED:"<<id<<"staff"<<endl;
				cin>>newId;

				cout<<"name:"<<endl;
				cin>>newName;

				cout<<"please"<<endl;
				cout<<"1.staff"<<endl;
				cout<<"2.manager"<<endl;
				cout<<"3.boss"<<endl;

				cin>>dSelect;

				Worker * worker=NULL;
				switch(dSelect)
				{
					
					case 1:
						worker=new Employee(newId,newName,dSelect);
						break;
					case 2:
						worker=new Manager(newId,newName,dSelect);
						break;
					case 3:
						worker=new Boss(newId,newName,dSelect);
						break;
					default:
						break;
				}
				this->m_EmpArray[ret]=worker;
				cout<<"sucess!"<<endl;

				this->save();

			}
			else
			{
				cout<<"wrong!"<<endl;
			}
		}
	

	
	void Find_Emp()
	{
		
		cout<<"pealse input find way:"<<endl;
		cout<<"ID"<<endl;
		cout<<"name"<<endl;

		int select=0;
		cin>>select;
		if(select==1)
		{
			int id;
			cout<<"id"<<endl;
			cin>>id;

			int ret=IsExist(id);
			if(ret!=-1)
			{
			
				cout<<"FINDED"<<endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
			
				
				cout<<"find wrong"<<endl;
			}



		}
		else if(select==2)
		{
		
			string name;
			cout<<"name:"<<endl;
			cin>>name;
			bool flag=false;
			
			for(int i=0;i<m_EmpNum;i++)
			{
				
				if(this->m_EmpArray[i]->m_Name==name)
				{
				
				cout<<"success!"<<this->m_EmpArray[i]->m_Id<<endl;
				
				
			flag=true;
				this->m_EmpArray[i]->showInfo();
			
				}
			
			}
			if(flag==false)
			{
				
				cout<<"fault!"<<endl;
			}
		
		}
		else
		{
		
			
			cout<<"wrong"<<endl;
		}
	}

	
	void Sort_Emp()
	{
		
		cout<<"arrange way:[1-2]"<<endl;
		cout<<"1.positive"<<endl;
		cout<<"2.negative"<<endl;

		int select=0;
		cin>>select;
		for(int i=0;i<m_EmpNum;i++)
		{
			
			int minOrMax=i;
		   for(int j=i+1;j<this->m_EmpNum;j++)
		   {
			if(select==1)
			{
				
				if(this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
				{
					
					minOrMax=j;
				}
		
			}
			else
			{
				if(this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
				{
					
					minOrMax=j;
				}
			}	
		   }
		if(i!=minOrMax)
		{
			
			Worker *temp=this->m_EmpArray[i];
			this->m_EmpArray[i]=this->m_EmpArray[minOrMax];
			this->m_EmpArray[minOrMax]=temp;
	

		}
	
	}
	cout<<"sucess"<<endl;
	this->save();
	this->Show_Emp();
	
}
	
	void Clean_File()
	{
		
		cout<<"NULL?"<<endl;
		cout<<"1.ok"<<endl;
		cout<<"2.exit"<<endl;

		int select=0;
		cin>>select;
		if(select==1)
		{
			
			ofstream ofs(FILENAME,ios::trunc);
			ofs.close();

			if(this->m_EmpArray!=NULL)
			{
			
				for(int i=0;i<this->m_EmpNum;i++)
				{
					
					delete this->m_EmpArray[i];
					this->m_EmpArray[i]=NULL;
				}
				delete[] this->m_EmpArray;
				this->m_EmpArray=NULL;
				this->m_EmpNum=0;
			}
	
			cout<<"NULLED!"<<endl;
		}
	
	}

	~WorkerManager()
    {
	    //delete stack region data
 	if(this->m_EmpArray!=NULL)
	{
	 delete [] this->m_EmpArray;
	 this->m_EmpArray=NULL;
	
	}	

    }
};
