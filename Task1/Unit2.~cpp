//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        form1 =(TForm1*)Owner;
}
//---------------------------------------------------------------------------
AnsiString dt;
AnsiString sysDt;
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    //获取设置的date & time
       AnsiString date =DataTimePicker1->DateTime.DateString().TrimLeft();
       AnsiString time =DateTimePicker2->DateTime.TimeString().TrimLeft();
       dt =date+" "+time;//how to trim? Trim() dosen't run.
       sysDt = Date().CurrentDateTime().DateTimeString();
        //最后隐藏窗体
       //this->Visible=false;
       form1->Visible=false;
       form1->Begin();
       while(dt!=sysDt){
       Sleep(5000);
       sysDt = Date().CurrentDateTime().DateTimeString();//当前线程会阻塞,不能干别的事.如何避免
    }
      form1->Visible=true;
}
//---------------------------------------------------------------------------

