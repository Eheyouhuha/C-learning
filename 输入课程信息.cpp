#include<iostream>
#include<fstream> 
using namespace std;
struct Lesson
{
	unsigned int number;
	char name[20];
	char teacher[10];
};
const Lesson mark ={0,"noName\0",0};

int main ()
{
	Lesson le;
	fstream f;

	f.open("D:\\lesson.dat",ios::out|ios::binary);
	
	cout<<"����γ���Ϣ���γ̺š��γ����ơ��ον�ʦ"<<endl;
	while (cin>>le.number>>le.name>>le.teacher)
	{
		f.write((char *)&le,sizeof(Lesson));
	}
	//	���û����һ��д���ա������һ����¼��д��������ļ����Ρ� 
	//	���ı��ĵ���ȡ���ݣ�������һ�䣬Ҳ����ͬ��������� 
	
	f.write((char *)&mark,sizeof(Lesson));
	f.close();
	
	f.open("D:\\lesson.dat",ios::in|ios::out|ios::binary);
	do 
	{
		f.read((char *)&le,sizeof(Lesson));
		if(le.number!=0)
		{
			cout<<le.number<<'\t'<<le.name<<'\t'<<le.teacher<<endl;
		}
		
	}while(f!=0);
	f.close();
	system("pause");
	
	
}
