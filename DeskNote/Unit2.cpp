//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
AnsiString dt;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        form1 =(TForm1*)Owner;
}

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        AnsiString date  = DataTimePicker1->DateTime.DateString();
        AnsiString time  = DateTimePicker2->DateTime.TimeString();
        dt  = date+" "+time;  //how to trim? Trim() dosen't run.
        //������ش���
       form1->Visible=false;
       form1->Timer1->Enabled=true;

}
        //form1->Begin();
      /* while(dt!=sysDt){
       Sleep(5000);
       sysDt = Date().CurrentDateTime().DateTimeString();//��ǰ�̻߳�����,���ܸɱ����.��α���
    }
      form1->Visible=true; */
