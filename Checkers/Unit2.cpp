//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream>
#include "Unit2.h"
#include<iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

using namespace std;



//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
return;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
//Form2->tresc->Lines->LoadFromFile("plik.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::z1Click(TObject *Sender)
{
tresc->Lines->SaveToFile("plik.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::trescKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Shift.Contains(ssCtrl))
{
 if((Key == 's') || (Key == 'S'))
 {
  tresc->Lines->SaveToFile("plik.txt");
 }
}
}
//---------------------------------------------------------------------------


