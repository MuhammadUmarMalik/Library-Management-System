#include<iostream>
#include<fstream>
using namespace std;

main()
{
	string name;
	int n,age;
	ofstream out("sample.txt",ios::ate|ios::in |ios::out);
	cout<<"tell how name you want to enter in file:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin.ignore();
		cout<<"Enter your name: "<<endl;
		getline(cin,name);
		out<<name;
		
		cout<<"Enter your age: "<<endl;
		cin>>age;
		out<<age;
	}
	out.close();
	ifstream in("sample.txt");
	int i=0;
	while(i<n)
	{
		getline(in,name);
		in>>age;
		i++;
	}
	if(EOF!=NULL)
	{
		cout<<name<<"\t"<<age<<"\t"<<endl;
	}
}
