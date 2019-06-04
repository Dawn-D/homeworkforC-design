#include <iostream>
using namespace std; 
class CDocument{
	CDocument(){
		AddPage(); 
	}	
	Vector<PPTPage*> pptpages;  //新建容器 ,pptpages：数组 
	Addpage()
	{
		CPPTPage * p = new PPTPage();
		pptpages.pushback(p);
	} 
    Save(fsteram& file){}//保存一页page 
	Open(fstream& file){}//读入一页page 
	Display(){} //显示page 
	Copy Paste Cut Delete Insert 
};
CDocument::Save(fstream& file)
{
	Foreach PPTPage in pptpages
	pptpage.Save(file);
}
CDocument::Open(fstream& file)
{
	pptpages.clear();
	while(file.eof()){
		PPTPage* page = new PPTPage();
		pptpage.Load(file);
		PPTPages.pushback(page);
    }
}
class PPTPage{
	PPTPage(){}
		int PageNum;  //页码 
		char Logo[50]; //Bitmap/icon
		Vector <Graph*> graphs;  
		//TextBox textBox; //文本框 
		Save(fstream& file)
		{
			file<<PageNum;
			file<<Logo;
			textBox.Save(file)
		}
		Load(fstream& file)
		{
			Vector <Graph*> graphs; 
			Graphs.load()
			file>>PageNum;
			file>>Logo;
			textBox.Load(file)
		}
		Copy Paste Cut Delete Insert 
		
		PPTPage::Display(){
			Vector <Graph*> graphs; 
			*Graphs->Display();
        }
};
class Graph{ //页面 
	int Type;
	int linecolor;
	int fillcolor;
	int linewidth;
	virtual Save(fstream& file){
		
	}
	virtual Load(fstream& file){
		
	}
	virtual Display() = 0
};
class TextBox:Graph{
	int Width,Height,left,top;
	string text;
	Save(fstream& file){
		file<<width<<height<<left<<top<<text;
	}
	Load(fstream& file){
		file>>width>>height>>left>>top>>text;
	}
	Textbox::Display()
	{
		cout<<width<<height<<left<<top<<text;
	}
};
int main() {
	char filename[100];  //文件名 
	CDocument * doc = null;
	cin>>type;
	type == 1 //new document
	doc = new document;
	type == 2 //save document 
	cin>>filename;
	fstream file = ...filename...; //流 
	doc.save(fsteream& file);
	type == 3 //open
	cin>>filename;
	fstream file = ...filename...;
	doc.open(fstream& file);
	type == 4 //display
	doc.display();
}
