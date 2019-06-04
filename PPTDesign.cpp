#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
using namespace std; 
class Graph{ //页面 
public:
	//int Type;//三种类型的图形 
	int linecolor;
	int filecolor;
	int linewidth;
	virtual void Add() = 0;
	virtual void Save(fstream &file) = 0;
	virtual void Load(fstream &file) = 0; 
	virtual void Display() = 0; 
};
class TextBox: virtual public Graph{  //文本框 
private:
	int width,height,left,top;
	string text;
public:
	void Add(){
		int width,height,left,top;
		string text;
		cout<<"input width,height,left,top: ";
		cin>>width>>height>>left>>top;
		cout<<"input text: ";
		cin>>text;
		this->width = width;
		this->height = height;
		this->left = left;
		this->top = top;
		this->text = text;
	}
	void Save(fstream &file){
		file<<width<<height<<left<<top<<text<<endl;
	}
	void Load(fstream &file){
		file>>width>>height>>left>>top>>text;
	}
	void Display(){
	cout<<width<<height<<left<<top<<text<<endl;
	}
};	
class Circle: virtual public Graph{
private:
	double radius;
	double x,y;
	string text;
public:
	void Add()
	{
		double r,x,y;
		string text;
		cout << "input x,y radius and text: ";
		cin>>x>>y>>radius>>text;
		r = radius;
		this->x = x;
		this->y = y;
		this->text = text;
	}
	void Load(fstream &file)//file.read()
	{	
		file>>x>>y>>radius>>text;
		cout<<x<<y<<radius<<text<<endl;
	}
	void Save(fstream &file)
	{
		file<<x<<y<<radius<<text<<endl;
	}
	void Display()
	{
		cout<<x<<y<<radius<<text<<endl;
	} 
};
class Recentage: virtual public Graph{
	private:
		double length,width;
		string text;
		public:
			Recentage(){
			}
			void Add(){
				double itslength,itswidth;
				string text;
				cout<<"input length,width and text: ";
				cin>>itslength>>itswidth>>text;
				itslength = length;
				itswidth = width;
				this ->text = text;
			}
			void Load(fstream &file)//file.read()
        	{	
	    	file>>length>>width>>text;
	    	cout<<length<<width<<text<<endl;
	        }
			void Save(fstream &file)
			{
				file<<length<<width<<text<<endl;
			}
			void Display()
			{
				cout<<length<<width<<text<<endl;
			} 
};
//TextBox::Display()	
class PPTPage{
private:
		int I,J,K;
		int PageNum;  //页码 
		char Logo[50]; //Bitmap/icon
		vector <Graph*> graphs; //s
public:
 	PPTPage(){}
	~PPTPage(){
		PageNum--;
	}
 	void Creat()
	{
		reset();
		AddGraph();	
	}
	void reset()
	{
		int i,j,k;
		cout << "input the number of textbox, circle and recentage: ";
		cin>>i>>j>>k;
		I = i;
		J = j;
		K = k;
	}
 	void AddGraph()
	{
		for(int m = 0;m < I;m++)
		{
			Graph *G = new TextBox();
			G->Add();
			graphs.push_back(G);
		}
		for(int n = I;n < I+J ;n++)//n不能从0开始
		{
			Graph *G = new Circle();
			G->Add();
			graphs.push_back(G);
		}
		for(int l = I+J;l < I+J+K ;l++)
		{
			Graph *G = new Recentage();
			G->Add();
			graphs.push_back(G);
		}
	}
	void Open(fstream &file)
	{
		int I,J,K;
		file>>I;
		file>>J;
		file>>K;
		cout<<I<<J<<K<<endl;
		//cout << I << J << endl;
		for(int m = 0;m < I;m++)
		{
			Graph *G = new TextBox();
			G ->Load(file);
			graphs.push_back(G);
		}		
		for(int n = I;n < I+J ;n++)
		{
			Graph *G = new Circle();
			
			G->Load(file);
			graphs.push_back(G);
		}
		for(int l = I+J;l < I+J+K;l++)
		{
			Graph *G = new Recentage();
			G ->Load(file);
			graphs.push_back(G);
		}			
	}
    void Save(fstream& file)
	{
	//	file << pptpages.size() << endl;
	//	file << I << endl<< J << endl;
		for(int m = 0;m < I;m++)
		{
			graphs[m]->Save(file);
		}
		for(int n = I;n < I+J ;n++)
		{
			graphs[n]->Save(file);
		}
		for(int l = I+J;l < I+J+K;l++)
		{
			graphs[l]->Save(file);
		}
	}
	/*void Load(fstream& file)
	{
		vector <Graph* > graphs; 
		for(int i = 0;i < I+J+K;i++)//graphs.size()
			graphs[i]->Graph.Load(); 
		file>>PageNum;
		file>>Logo;
	}*/
	void Display(){
		//vector <Graph*> graphs; 
		for(int i = 0;i < I;i++)
			graphs[i]->Display();
		for(int j = I;j < I+J;j++)
			graphs[j]->Display();
		for(int k = I+J;k < I+J+K;k++)
			graphs[k]->Display();
	}
	//Copy Paste Cut Delete Insert 
};
class CDocument{
	private:
		vector<PPTPage* > pptpages;  //新建容器 ,pptpages：数组
		int Page;
	public:
	CDocument(){
		AddPage(); 
	}	
	void AddPage()
	{
		while(1)
		{
			cout << "add new PPT:(YES-1；NO-0)"<<endl;
			int q;
			cin >> q;
			if(q == 1)
			{
				PPTPage *p = new PPTPage();
				p->Creat();
				pptpages.push_back(p);
				++Page;
			}
			else break;
	} 
    void Save(fstream& file);//保存一页page 
	void Open(fstream& file);//读入一页page 
	void Display(); //显示page 
	//Copy Paste Cut Delete Insert 
};
void CDocument::Save(fstream& file)
{
    for(int i = 0;i < pptpages.size();i++)
    	pptpages[i]->Save(file);
	//For each PPTPage in pptpages
	//pptpage.Save(file);
}
void CDocument::Open(fstream& file)
{
	pptpages.clear();//清除容器内元素 
	int Page;
	file>>Page;
	vector<PPTPage *>().swap(pptpages);
    for(int i = 0;i < Page;i++){
    	PPTPage *page = new PPTPage();
		page->Open(file);
		pptpages.push_back(page);
	}
	/*while(file.eof()){
		PPTPage *page = new PPTPage();
		page->Load(file);
		pptpages.push_back(page);	
    }*/
}
void CDocument::Display()
{
	for(int i = 0;i < Page;i++)
		pptpages[i]->Display();
	//PPTPages.size(page);
 } 

int PPTPage::PageNum = 0;
int CDocument::Page = 0;

int main() {
	char filename[100];  //文件名 
	CDocument * doc = NULL;
	int type;
	while(type != 0){
		cout<<"type = 1(new) 2(save) 3(open) 4(display) 0(exit): ";
		cin>>type;
	if(type == 1) //new document
		doc = new CDocument();
	else if(type == 2) //save document 
	{   
		cout<<"input a filename: "<<endl;
		cin>>filename;	
		fstream file;
		file.open(filename,ios::out|ios::trunc);
		if(!file){
			cerr<<"open or create error."<<endl;
			exit(1);
		}
    	//fstream file;
		doc->Save(file);
		file.close();
	}
	//fstream file = ...filename...; //流 
	else if(type == 3) //open
	{
		cout<<"input a filename: "<<endl;
		cin>>filename;
		fstream file;
		file.open(filename,ios::in);
        if(!file){
        	cerr<<"open error!"<<endl;
        	exit(1);
		}
		doc->Open(file);
		file.close();
	}
	//fstream file = ...filename...;
	else if(type == 4) //display
		doc->Display();
	else
		return 0;
	}
	return 0;
}
