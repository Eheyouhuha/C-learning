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
	
	cout<<"输入课程信息：课程号、课程名称、任课教师"<<endl;
	while (cin>>le.number>>le.name>>le.teacher)
	{
		f.write((char *)&le,sizeof(Lesson));
	}
	//	如果没有下一句写“空”，最后一条记录会写入二进制文件两次。 
	//	从文本文档读取数据，不加下一句，也是有同样的情况。 
	
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
