#include<iostream>
#include<fstream> 

using namespace std;

struct Student
{		
	unsigned int num;		
	char name[10];
	char campus[10];
	char major[20];
	unsigned int Class;
		
};
const Student mark ={0,"noName\0",0,0,0};

int main ()
{

	Student stu;
	fstream f;
	
	f.open("D:\\a.dat",ios::out|ios::binary);
	
	cout<<"������ѧ����Ϣ������ѧ�ţ�������ѧԺ��רҵ���༶(����)��˳��"<<endl;
	
	while (cin>>stu.num>>stu.name>>stu.campus>>stu.major>>stu.Class)
	{
		f.write((char *)&stu,sizeof(Student) );
	}
	
	//	���û����һ��д���ա������һ����¼��д��������ļ����Ρ� 
	//	���ı��ĵ���ȡ���ݣ�������һ�䣬Ҳ����ͬ��������� 
	f.write((char *)&mark,sizeof(Student));
	f.close();

	f.open("D:\\a.dat",ios::out|ios::in|ios::binary);
	do
	{
		f.read((char *)&stu,sizeof(Student));
		if(stu.num!=0)
		{
			cout<<stu.num<<'\t' <<stu.name<<'\t'<<stu.campus
			<<'\t'<<stu.major<<'\t'<<stu.Class<< '\n';
		}
	}while(f&&stu.num!=0);
	f.close();
	
	system("pause");
}
