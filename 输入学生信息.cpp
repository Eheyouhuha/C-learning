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
	
	cout<<"请输入学生信息，按照学号，姓名，学院，专业，班级(数字)的顺序"<<endl;
	
	while (cin>>stu.num>>stu.name>>stu.campus>>stu.major>>stu.Class)
	{
		f.write((char *)&stu,sizeof(Student) );
	}
	
	//	如果没有下一句写“空”，最后一条记录会写入二进制文件两次。 
	//	从文本文档读取数据，不加下一句，也是有同样的情况。 
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
