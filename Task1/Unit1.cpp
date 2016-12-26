//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
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

static int countForm = 0; //��Ϊ��̬��,����ɾ��ĳ��note������
void __fastcall TForm1::A1Click(TObject *Sender)
{
         //�½�note
        TForm1 *newForm =new TForm1(this);
        newForm->Visible=true;
        newForm->Caption=AnsiString("Note")+(++countForm); //�����±�ǩ����
        newForm->TrayIcon1->Visible=false; //��������note���̲���ʾ
        newForm->Button1->Visible=false;
        newForm->Edit1->Visible=false;
        newForm->Memo1->Clear();

        //������list��
        noteList.push_back(newForm);
        //ShowMessage(Date().CurrentDateTime());
        //ShowMessage(AnsiString("Note Count:")+noteList.size()); //print to test list-save
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
        Close();//�ر�form
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
        noteList.clear();//Ϊʲô����ֱ�����list����Ԫ��,��Ϊ����note����
}
//---------------------------------------------------------------------------

void __fastcall TForm1::HideNote1Click(TObject *Sender)
{
        it=noteList.begin();//����iterator ����������
        while(it!=noteList.end()){
            if(*it!=NULL){
            (*it)->Show();    //ѭ���������form
            }
            it++;
        }


}
//---------------------------------------------------------------------------



void __fastcall TForm1::SetBgcolor1Click(TObject *Sender)
{
          ColorDialog1->Execute();//��ʼ����ɫѡ���
          Memo1->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetFont1Click(TObject *Sender)
{
          ColorDialog1->Execute();//ͬ��
          Memo1->Font->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CloseNote1Click(TObject *Sender)
{
         //��list�������ǰnote
         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetTimeout1Click(TObject *Sender)
{
        //һ��Form��˼·,����ȡ�ɵķ���,���ǲ�������,֮���д��ݸ���ָ��Ľ���취
        TForm1 *timeForm = new TForm1(Application);
        timeForm->Visible=true;
        timeForm->Caption=AnsiString("SetTime");
        timeForm->TrayIcon1->Visible=false;
        timeForm->DateTimePicker1->Visible=true;
        timeForm->DateTimePicker2->Visible=true;
        timeForm->SetTime->Visible=true;
        timeForm->Button1->Visible=false;
        timeForm->Edit1->Visible=false;
        timeForm->Memo1->Visible=false;

        if(timeForm!=NULL){
           this->Hide();
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::HideNote2Click(TObject *Sender)
{
        //���ص�ǰnote
         Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Memo1Change(TObject *Sender)
{
         // Memo1->Text;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
     // Hide();
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
//---------------------------------------------------------------------------

void __fastcall TForm1::DelNote2Click(TObject *Sender)
{
    //ɾ����ǰnote
    noteList.remove(this); //�ٴ�list��ɾ��
    this->DestroyWnd() ; //�ڴ�heap���������,ò��Close()Ҳ��.
//  this->Visible=false;  //���ڢ�û���뵽��ʱ�����ֱ�����ص�.ֻҪlist��û�о���


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetTimeClick(TObject *Sender)
{
        //��ȡ���õ�date & time
       AnsiString date =DateTimePicker1->DateTime.DateString();
       AnsiString time =DateTimePicker2->DateTime.TimeString();
       AnsiString dt =date+time;
        //��ȡ��ǰdate&time,Ȼ���ö�ʱ��ѭ���ȶ�
       AnsiString sysDt = Date().CurrentDateTime().DateTimeString();
        if(dt!=sysDt){
          ShowMessage("SetTime:"+dt);
        }

        //��ͬ,���ñ�ǩVisible=true


        //������ش���
        this->Visible=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetAlert1Click(TObject *Sender)
{
       //���ö�ʱ����note����,�ȵ���Unit2.h
       //�ؼ��������Form2�л�ȡForm1�Ķ���ָ��,���￼�Ǹ�дĬ�ϵĹ��췽��
        TForm2 *setTime=new TForm2(this);
        setTime->Show();

}
//---------------------------------------------------------------------------



