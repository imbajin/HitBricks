#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit2.cpp"
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;
//define iterator
list<TForm1 *>::iterator it;
//init STL list
list<TForm1 *> noteList;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

static int countForm = 0;
void __fastcall TForm1::A1Click(TObject *Sender)
{
         //新建note
        TForm1 *newForm =new TForm1(this);
        newForm->Visible=true;
        newForm->Caption=AnsiString("Note")+(++countForm); //设置新标签名字
        newForm->TrayIcon1->Visible=false; //设置其他note托盘不显示
        newForm->Button1->Visible=false;
        newForm->Edit1->Visible=false;
        newForm->Memo1->Clear();
        //最后存入list中
        noteList.push_back(newForm);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
        Close();//关闭form
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DelNote1Click(TObject *Sender)
{
        it=noteList.begin();
        while(it!=noteList.end()){
        if(*it!=NULL){
        delete (*it++);
        }
       }
        noteList.clear();//为什么不能直接清空list所有元素,因为堆中note还在
}

//循环输出所有note
void __fastcall TForm1::HideNote1Click(TObject *Sender)
{
        it=noteList.begin();//返回iterator 迭代器遍历
        while(it!=noteList.end()){
            if(*it!=NULL){
            (*it)->Show();
            }
            it++;
        }


}

//初始化颜色选择框
void __fastcall TForm1::SetBgcolor1Click(TObject *Sender)
{
          ColorDialog1->Execute();
          Memo1->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetFont1Click(TObject *Sender)
{
          ColorDialog1->Execute();//同上
          Memo1->Font->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CloseNote1Click(TObject *Sender)
{
         //从list中清除当前note
         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HideNote2Click(TObject *Sender)
{
        //隐藏当前note
         Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
     ShowWindow(Application->Handle,SW_HIDE);
     Application->ShowMainForm=false;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::SetTitle1Click(TObject *Sender)
{
      this->Button1->Visible=true;
      this->Edit1->Visible=true;
      this->Caption = Edit1->Text;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
     this->Caption = Edit1->Text;
     Button1->Visible=false;
     Edit1->Visible=false;
}

//删除当前note
void __fastcall TForm1::DelNote2Click(TObject *Sender)
{

    noteList.remove(this); //①从list中删除
    this->DestroyWnd() ; //②从heap中清掉窗体,貌似Close()也行.
//  this->Visible=false;  //③在②没有想到的时候可以直接隐藏掉.只要list中没有就行


}

void __fastcall TForm1::SetAlert1Click(TObject *Sender)
{
       //设置定时弹出note提醒,先导入Unit2.h
       //关键是如何在Form2中获取Form1的对象指针,这里考虑改写默认的构造方法
        TForm2 *setTime=new TForm2(this);
        setTime->Show();

}

//定时器时间
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        AnsiString sysDt = Date().CurrentDateTime().DateTimeString();
        if(dt==sysDt) this->Visible=true;
}
//---------------------------------------------------------------------------


