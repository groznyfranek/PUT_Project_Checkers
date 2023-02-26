//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Szachy.h"
#include <string>
#include<iostream>
#include <fstream>
#include <ctime>
#include <time.h>
#define VCL_IOSTREAM
#include <vcl.h>
#include <shellapi.h>
#include <graphics.hpp>
#include "Unit2.h"
#include <stdlib.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1* Form1;

int czasbialych;
int czasczarnych;
bool na_ruchu;
int posuniecie;
int etap_ruchu;
bool zdejmowanie;
bool wynik;
string gracz1;
string gracz2;

fstream plik;

class Pole
{
public:
    char wypelnienie;    
    Pole();
};

Pole::Pole()
{
    this->wypelnienie = 'E';
}

Pole A1; Pole A3; Pole A5; Pole A7;Pole B2; Pole B4; Pole B6; Pole B8;
Pole C1; Pole C3; Pole C5; Pole C7;Pole D2; Pole D4; Pole D6; Pole D8;
Pole E1; Pole E3; Pole E5; Pole E7;Pole F2; Pole F4; Pole F6; Pole F8;
Pole G1; Pole G3; Pole G5; Pole G7;Pole H2; Pole H4; Pole H6; Pole H8;

void TForm1::white_win_check()
{
if( A1.wypelnienie!='R' &&  A3.wypelnienie!='R' &&  A5.wypelnienie!='R' &&  A7.wypelnienie!='R' && B2.wypelnienie!='R' &&  B4.wypelnienie!='R' &&  B6.wypelnienie!='R' &&
B8.wypelnienie!='R' && C1.wypelnienie!='R' &&  C3.wypelnienie!='R' &&  C5.wypelnienie!='R' &&  C7.wypelnienie!='R' && D2.wypelnienie!='R' &&  D4.wypelnienie!='R' &&  D6.wypelnienie!='R' &&
D8.wypelnienie!='R' && E1.wypelnienie!='R' &&  E3.wypelnienie!='R' &&  E5.wypelnienie!='R' &&  E7.wypelnienie!='R' &&  F2.wypelnienie!='R' &&  F4.wypelnienie!='R' &&
 F6.wypelnienie!='R' &&  F8.wypelnienie!='R' && G1.wypelnienie!='R' &&  G3.wypelnienie!='R' &&  G5.wypelnienie!='R' &&  G7.wypelnienie!='R' && H2.wypelnienie!='R' &&
  H4.wypelnienie!='R' &&  H6.wypelnienie!='R' &&  H8.wypelnienie!='R')
  {
    Wynik->Caption = "Wygrana bialych";
    draw->Enabled = false;
    endmove->Enabled = false;
    newgame->Enabled = true;
    newgame->Cursor = crHandPoint;
    startgame->Enabled = false;


    blacktime->Enabled = false;
    whitetime->Enabled = false;
    timewhite->Caption = "00:00:00";
    whitetime->Enabled = false;
    timeblack->Caption = "00:00:00";
    blacktime->Enabled = false;
    Application->MessageBoxA("Bia³e wygrywaja!", "Koniec partii", MB_OK);
    White_resing->Enabled=false;
    Red_resing->Enabled=false;

    a1->Enabled = false;  a3->Enabled = false;  a5->Enabled = false;  a7->Enabled = false;    b2->Enabled = false;  b4->Enabled = false;  b6->Enabled = false;  b8->Enabled = false;
    c1->Enabled = false;  c3->Enabled = false;  c5->Enabled = false;  c7->Enabled = false;    d2->Enabled = false;  d4->Enabled = false;  d6->Enabled = false;  d8->Enabled = false;
    e1->Enabled = false;  e3->Enabled = false;  e5->Enabled = false;  e7->Enabled = false;    f2->Enabled = false;  f4->Enabled = false;  f6->Enabled = false;  f8->Enabled = false;
    g1->Enabled = false;  g3->Enabled = false;  g5->Enabled = false;  g7->Enabled = false;    h2->Enabled = false;  h4->Enabled = false;  h6->Enabled = false;  h8->Enabled = false;

    plik << " 1-0" << endl;
    wynik = true;
  }
}
void TForm1::red_win_check()
{
 if( A1.wypelnienie!='W' &&  A3.wypelnienie!='W' &&  A5.wypelnienie!='W' &&  A7.wypelnienie!='W' && B2.wypelnienie!='W' &&  B4.wypelnienie!='W' &&  B6.wypelnienie!='W' &&
B8.wypelnienie!='W' && C1.wypelnienie!='W' &&  C3.wypelnienie!='W' &&  C5.wypelnienie!='W' &&  C7.wypelnienie!='W' && D2.wypelnienie!='W' &&  D4.wypelnienie!='W' &&  D6.wypelnienie!='W' &&
D8.wypelnienie!='W' && E1.wypelnienie!='W' &&  E3.wypelnienie!='W' &&  E5.wypelnienie!='W' &&  E7.wypelnienie!='W' &&  F2.wypelnienie!='W' &&  F4.wypelnienie!='W' &&
 F6.wypelnienie!='W' &&  F8.wypelnienie!='W' && G1.wypelnienie!='W' &&  G3.wypelnienie!='W' &&  G5.wypelnienie!='W' &&  G7.wypelnienie!='W' && H2.wypelnienie!='W' &&
  H4.wypelnienie!='W' &&  H6.wypelnienie!='W' &&  H8.wypelnienie!='W') {
    Wynik->Caption = "Wygrana czerwonych";
    draw->Enabled = false;
    endmove->Enabled = false;
    newgame->Enabled = true;
    newgame->Cursor = crHandPoint;
    startgame->Enabled = false;

    blacktime->Enabled = false;
    whitetime->Enabled = false;
    timewhite->Caption = "00:00:00";
    whitetime->Enabled = false;
    timeblack->Caption = "00:00:00";
    blacktime->Enabled = false;
    Application->MessageBoxA("Czerwone wygrywaja", "Koniec partii", MB_OK);
    White_resing->Enabled=false;
    Red_resing->Enabled=false;


    a1->Enabled = false;  a3->Enabled = false;  a5->Enabled = false;  a7->Enabled = false;    b2->Enabled = false;  b4->Enabled = false;  b6->Enabled = false;  b8->Enabled = false;
    c1->Enabled = false;  c3->Enabled = false;  c5->Enabled = false;  c7->Enabled = false;    d2->Enabled = false;  d4->Enabled = false;  d6->Enabled = false;  d8->Enabled = false;
    e1->Enabled = false;  e3->Enabled = false;  e5->Enabled = false;  e7->Enabled = false;    f2->Enabled = false;  f4->Enabled = false;  f6->Enabled = false;  f8->Enabled = false;
    g1->Enabled = false;  g3->Enabled = false;  g5->Enabled = false;  g7->Enabled = false;    h2->Enabled = false;  h4->Enabled = false;  h6->Enabled = false;  h8->Enabled = false;

    plik << " 0-1" << endl;
    wynik = true;
    }
}


void TForm1::zegar()
{
    if (na_ruchu == true)
    {
        reka->Picture = NULL;
        whitetime->Enabled = false;
        whitetime->Interval = 0;
        blacktime->Enabled = true;
        blacktime->Interval = 1000;
        tura->Picture->LoadFromFile("img/czerwony_pion_maly.bmp");
        na_ruchu = false;
        return;
    }
    else if (na_ruchu == false)
    {
        reka->Picture = NULL;
        whitetime->Enabled = true;
        whitetime->Interval = 1000;
        blacktime->Enabled = false;
        blacktime->Interval = 0;
        tura->Picture->LoadFromFile("img/bialy_pion_maly.bmp");
        na_ruchu = true;
        return;
    }
}

void TForm1::sprawdz()
{
switch (etap_ruchu)
{
case 1:
if(A1.wypelnienie=='W') a1->Enabled=true;if(A3.wypelnienie=='W') a3->Enabled=true;if(A5.wypelnienie=='W') a5->Enabled=true; if(A7.wypelnienie=='W') a7->Enabled=true;
if(B2.wypelnienie=='W') b2->Enabled=true;if(B4.wypelnienie=='W') b4->Enabled=true;if(B6.wypelnienie=='W') b6->Enabled=true; if(B8.wypelnienie=='W') b8->Enabled=true;
if(C1.wypelnienie=='W') c1->Enabled=true;if(C3.wypelnienie=='W') c3->Enabled=true;if(C5.wypelnienie=='W') c5->Enabled=true; if(C7.wypelnienie=='W') c7->Enabled=true;
if(D2.wypelnienie=='W') d2->Enabled=true;if(D4.wypelnienie=='W') d4->Enabled=true;if(D6.wypelnienie=='W') d6->Enabled=true; if(D8.wypelnienie=='W') d8->Enabled=true;
if(E1.wypelnienie=='W') e1->Enabled=true;if(E3.wypelnienie=='W') e3->Enabled=true;if(E5.wypelnienie=='W') e5->Enabled=true; if(E7.wypelnienie=='W') e7->Enabled=true;
if(F2.wypelnienie=='W') f2->Enabled=true;if(F4.wypelnienie=='W') f4->Enabled=true;if(F6.wypelnienie=='W') f6->Enabled=true; if(F8.wypelnienie=='W') f8->Enabled=true;
if(G1.wypelnienie=='W') g1->Enabled=true;if(G3.wypelnienie=='W') g3->Enabled=true;if(G5.wypelnienie=='W') g5->Enabled=true; if(G7.wypelnienie=='W') g7->Enabled=true;
if(H2.wypelnienie=='W') h2->Enabled=true;if(H4.wypelnienie=='W') h4->Enabled=true;if(H6.wypelnienie=='W') h6->Enabled=true; if(H8.wypelnienie=='W') h8->Enabled=true;


if(A1.wypelnienie== 'R' || A1.wypelnienie=='E') a1->Enabled=false;if(A3.wypelnienie== 'R' || A3.wypelnienie=='E') a3->Enabled=false;if(A5.wypelnienie== 'R' || A5.wypelnienie=='E') a5->Enabled=false; if(A7.wypelnienie== 'R' || A7.wypelnienie=='E') a7->Enabled=false;
if(B2.wypelnienie== 'R' || B2.wypelnienie=='E') b2->Enabled=false;if(B4.wypelnienie== 'R' || B4.wypelnienie=='E') b4->Enabled=false;if(B6.wypelnienie== 'R' || B6.wypelnienie=='E') b6->Enabled=false; if(B8.wypelnienie== 'R' || B8.wypelnienie=='E') b8->Enabled=false;
if(C1.wypelnienie== 'R' || C1.wypelnienie=='E') c1->Enabled=false;if(C3.wypelnienie== 'R' || C3.wypelnienie=='E') c3->Enabled=false;if(C5.wypelnienie== 'R' || C5.wypelnienie=='E') c5->Enabled=false; if(C7.wypelnienie== 'R' || C7.wypelnienie=='E') c7->Enabled=false;
if(D2.wypelnienie== 'R' || D2.wypelnienie=='E') d2->Enabled=false;if(D4.wypelnienie== 'R' || D4.wypelnienie=='E') d4->Enabled=false;if(D6.wypelnienie== 'R' || D6.wypelnienie=='E') d6->Enabled=false; if(D8.wypelnienie== 'R' || D8.wypelnienie=='E') d8->Enabled=false;
if(E1.wypelnienie== 'R' || E1.wypelnienie=='E') e1->Enabled=false;if(E3.wypelnienie== 'R' || E3.wypelnienie=='E') e3->Enabled=false;if(E5.wypelnienie== 'R' || E5.wypelnienie=='E') e5->Enabled=false; if(E7.wypelnienie== 'R' || E7.wypelnienie=='E') e7->Enabled=false;
if(F2.wypelnienie== 'R' || F2.wypelnienie=='E') f2->Enabled=false;if(F4.wypelnienie== 'R' || F4.wypelnienie=='E') f4->Enabled=false;if(F6.wypelnienie== 'R' || F6.wypelnienie=='E') f6->Enabled=false; if(F8.wypelnienie== 'R' || F8.wypelnienie=='E') f8->Enabled=false;
if(G1.wypelnienie== 'R' || G1.wypelnienie=='E') g1->Enabled=false;if(G3.wypelnienie== 'R' || G3.wypelnienie=='E') g3->Enabled=false;if(G5.wypelnienie== 'R' || G5.wypelnienie=='E') g5->Enabled=false; if(G7.wypelnienie== 'R' || G7.wypelnienie=='E') g7->Enabled=false;
if(H2.wypelnienie== 'R' || H2.wypelnienie=='E') h2->Enabled=false;if(H4.wypelnienie== 'R' || H4.wypelnienie=='E') h4->Enabled=false;if(H6.wypelnienie== 'R' || H6.wypelnienie=='E') h6->Enabled=false; if(H8.wypelnienie== 'R' || H8.wypelnienie=='E') h8->Enabled=false;
break;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

case 2:
if(A1.wypelnienie=='E') a1->Enabled=true;if(A3.wypelnienie=='E') a3->Enabled=true;if(A5.wypelnienie=='E') a5->Enabled=true; if(A7.wypelnienie=='E') a7->Enabled=true;
if(B2.wypelnienie=='E') b2->Enabled=true;if(B4.wypelnienie=='E') b4->Enabled=true;if(B6.wypelnienie=='E') b6->Enabled=true; if(B8.wypelnienie=='E') b8->Enabled=true;
if(C1.wypelnienie=='E') c1->Enabled=true;if(C3.wypelnienie=='E') c3->Enabled=true;if(C5.wypelnienie=='E') c5->Enabled=true; if(C7.wypelnienie=='E') c7->Enabled=true;
if(D2.wypelnienie=='E') d2->Enabled=true;if(D4.wypelnienie=='E') d4->Enabled=true;if(D6.wypelnienie=='E') d6->Enabled=true; if(D8.wypelnienie=='E') d8->Enabled=true;
if(E1.wypelnienie=='E') e1->Enabled=true;if(E3.wypelnienie=='E') e3->Enabled=true;if(E5.wypelnienie=='E') e5->Enabled=true; if(E7.wypelnienie=='E') e7->Enabled=true;
if(F2.wypelnienie=='E') f2->Enabled=true;if(F4.wypelnienie=='E') f4->Enabled=true;if(F6.wypelnienie=='E') f6->Enabled=true; if(F8.wypelnienie=='E') f8->Enabled=true;
if(G1.wypelnienie=='E') g1->Enabled=true;if(G3.wypelnienie=='E') g3->Enabled=true;if(G5.wypelnienie=='E') g5->Enabled=true; if(G7.wypelnienie=='E') g7->Enabled=true;
if(H2.wypelnienie=='E') h2->Enabled=true;if(H4.wypelnienie=='E') h4->Enabled=true;if(H6.wypelnienie=='E') h6->Enabled=true; if(H8.wypelnienie=='E') h8->Enabled=true;


if(A1.wypelnienie== 'B' || A1.wypelnienie=='W') a1->Enabled=false;if(A3.wypelnienie== 'B' || A3.wypelnienie=='W') a3->Enabled=false;if(A5.wypelnienie== 'B' || A5.wypelnienie=='W') a5->Enabled=false; if(A7.wypelnienie== 'B' || A7.wypelnienie=='W') a7->Enabled=false;
if(B2.wypelnienie== 'B' || B2.wypelnienie=='W') b2->Enabled=false;if(B4.wypelnienie== 'B' || B4.wypelnienie=='W') b4->Enabled=false;if(B6.wypelnienie== 'B' || B6.wypelnienie=='W') b6->Enabled=false; if(B8.wypelnienie== 'B' || B8.wypelnienie=='W') b8->Enabled=false;
if(C1.wypelnienie== 'B' || C1.wypelnienie=='W') c1->Enabled=false;if(C3.wypelnienie== 'B' || C3.wypelnienie=='W') c3->Enabled=false;if(C5.wypelnienie== 'B' || C5.wypelnienie=='W') c5->Enabled=false; if(C7.wypelnienie== 'B' || C7.wypelnienie=='W') c7->Enabled=false;
if(D2.wypelnienie== 'B' || D2.wypelnienie=='W') d2->Enabled=false;if(D4.wypelnienie== 'B' || D4.wypelnienie=='W') d4->Enabled=false;if(D6.wypelnienie== 'B' || D6.wypelnienie=='W') d6->Enabled=false; if(D8.wypelnienie== 'B' || D8.wypelnienie=='W') d8->Enabled=false;
if(E1.wypelnienie== 'B' || E1.wypelnienie=='W') e1->Enabled=false;if(E3.wypelnienie== 'B' || E3.wypelnienie=='W') e3->Enabled=false;if(E5.wypelnienie== 'B' || E5.wypelnienie=='W') e5->Enabled=false; if(E7.wypelnienie== 'B' || E7.wypelnienie=='W') e7->Enabled=false;
if(F2.wypelnienie== 'B' || F2.wypelnienie=='W') f2->Enabled=false;if(F4.wypelnienie== 'B' || F4.wypelnienie=='W') f4->Enabled=false;if(F6.wypelnienie== 'B' || F6.wypelnienie=='W') f6->Enabled=false; if(F8.wypelnienie== 'B' || F8.wypelnienie=='W') f8->Enabled=false;
if(G1.wypelnienie== 'B' || G1.wypelnienie=='W') g1->Enabled=false;if(G3.wypelnienie== 'B' || G3.wypelnienie=='W') g3->Enabled=false;if(G5.wypelnienie== 'B' || G5.wypelnienie=='W') g5->Enabled=false; if(G7.wypelnienie== 'B' || G7.wypelnienie=='W') g7->Enabled=false;
if(H2.wypelnienie== 'B' || H2.wypelnienie=='W') h2->Enabled=false;if(H4.wypelnienie== 'B' || H4.wypelnienie=='W') h4->Enabled=false;if(H6.wypelnienie== 'B' || H6.wypelnienie=='W') h6->Enabled=false; if(H8.wypelnienie== 'B' || H8.wypelnienie=='W') h8->Enabled=false;
break;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

case 3:
if(A1.wypelnienie=='R') a1->Enabled=true;if(A3.wypelnienie=='R') a3->Enabled=true;if(A5.wypelnienie=='R') a5->Enabled=true; if(A7.wypelnienie=='R') a7->Enabled=true;
if(B2.wypelnienie=='R') b2->Enabled=true;if(B4.wypelnienie=='R') b4->Enabled=true;if(B6.wypelnienie=='R') b6->Enabled=true; if(B8.wypelnienie=='R') b8->Enabled=true;
if(C1.wypelnienie=='R') c1->Enabled=true;if(C3.wypelnienie=='R') c3->Enabled=true;if(C5.wypelnienie=='R') c5->Enabled=true; if(C7.wypelnienie=='R') c7->Enabled=true;
if(D2.wypelnienie=='R') d2->Enabled=true;if(D4.wypelnienie=='R') d4->Enabled=true;if(D6.wypelnienie=='R') d6->Enabled=true; if(D8.wypelnienie=='R') d8->Enabled=true;
if(E1.wypelnienie=='R') e1->Enabled=true;if(E3.wypelnienie=='R') e3->Enabled=true;if(E5.wypelnienie=='R') e5->Enabled=true; if(E7.wypelnienie=='R') e7->Enabled=true;
if(F2.wypelnienie=='R') f2->Enabled=true;if(F4.wypelnienie=='R') f4->Enabled=true;if(F6.wypelnienie=='R') f6->Enabled=true; if(F8.wypelnienie=='R') f8->Enabled=true;
if(G1.wypelnienie=='R') g1->Enabled=true;if(G3.wypelnienie=='R') g3->Enabled=true;if(G5.wypelnienie=='R') g5->Enabled=true; if(G7.wypelnienie=='R') g7->Enabled=true;
if(H2.wypelnienie=='R') h2->Enabled=true;if(H4.wypelnienie=='R') h4->Enabled=true;if(H6.wypelnienie=='R') h6->Enabled=true; if(H8.wypelnienie=='R') h8->Enabled=true;


if(A1.wypelnienie== 'E' || A1.wypelnienie=='W') a1->Enabled=false;if(A3.wypelnienie== 'E' || A3.wypelnienie=='W') a3->Enabled=false;if(A5.wypelnienie== 'E' || A5.wypelnienie=='W') a5->Enabled=false; if(A7.wypelnienie== 'E' || A7.wypelnienie=='W') a7->Enabled=false;
if(B2.wypelnienie== 'E' || B2.wypelnienie=='W') b2->Enabled=false;if(B4.wypelnienie== 'E' || B4.wypelnienie=='W') b4->Enabled=false;if(B6.wypelnienie== 'E' || B6.wypelnienie=='W') b6->Enabled=false; if(B8.wypelnienie== 'E' || B8.wypelnienie=='W') b8->Enabled=false;
if(C1.wypelnienie== 'E' || C1.wypelnienie=='W') c1->Enabled=false;if(C3.wypelnienie== 'E' || C3.wypelnienie=='W') c3->Enabled=false;if(C5.wypelnienie== 'E' || C5.wypelnienie=='W') c5->Enabled=false; if(C7.wypelnienie== 'E' || C7.wypelnienie=='W') c7->Enabled=false;
if(D2.wypelnienie== 'E' || D2.wypelnienie=='W') d2->Enabled=false;if(D4.wypelnienie== 'E' || D4.wypelnienie=='W') d4->Enabled=false;if(D6.wypelnienie== 'E' || D6.wypelnienie=='W') d6->Enabled=false; if(D8.wypelnienie== 'E' || D8.wypelnienie=='W') d8->Enabled=false;
if(E1.wypelnienie== 'E' || E1.wypelnienie=='W') e1->Enabled=false;if(E3.wypelnienie== 'E' || E3.wypelnienie=='W') e3->Enabled=false;if(E5.wypelnienie== 'E' || E5.wypelnienie=='W') e5->Enabled=false; if(E7.wypelnienie== 'E' || E7.wypelnienie=='W') e7->Enabled=false;
if(F2.wypelnienie== 'E' || F2.wypelnienie=='W') f2->Enabled=false;if(F4.wypelnienie== 'E' || F4.wypelnienie=='W') f4->Enabled=false;if(F6.wypelnienie== 'E' || F6.wypelnienie=='W') f6->Enabled=false; if(F8.wypelnienie== 'E' || F8.wypelnienie=='W') f8->Enabled=false;
if(G1.wypelnienie== 'E' || G1.wypelnienie=='W') g1->Enabled=false;if(G3.wypelnienie== 'E' || G3.wypelnienie=='W') g3->Enabled=false;if(G5.wypelnienie== 'E' || G5.wypelnienie=='W') g5->Enabled=false; if(G7.wypelnienie== 'E' || G7.wypelnienie=='W') g7->Enabled=false;
if(H2.wypelnienie== 'E' || H2.wypelnienie=='W') h2->Enabled=false;if(H4.wypelnienie== 'E' || H4.wypelnienie=='W') h4->Enabled=false;if(H6.wypelnienie== 'E' || H6.wypelnienie=='W') h6->Enabled=false; if(H8.wypelnienie== 'E' || H8.wypelnienie=='W') h8->Enabled=false;
break;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

case 4:
if(A1.wypelnienie=='E') a1->Enabled=true;if(A3.wypelnienie=='E') a3->Enabled=true;if(A5.wypelnienie=='E') a5->Enabled=true; if(A7.wypelnienie=='E') a7->Enabled=true;
if(B2.wypelnienie=='E') b2->Enabled=true;if(B4.wypelnienie=='E') b4->Enabled=true;if(B6.wypelnienie=='E') b6->Enabled=true; if(B8.wypelnienie=='E') b8->Enabled=true;
if(C1.wypelnienie=='E') c1->Enabled=true;if(C3.wypelnienie=='E') c3->Enabled=true;if(C5.wypelnienie=='E') c5->Enabled=true; if(C7.wypelnienie=='E') c7->Enabled=true;
if(D2.wypelnienie=='E') d2->Enabled=true;if(D4.wypelnienie=='E') d4->Enabled=true;if(D6.wypelnienie=='E') d6->Enabled=true; if(D8.wypelnienie=='E') d8->Enabled=true;
if(E1.wypelnienie=='E') e1->Enabled=true;if(E3.wypelnienie=='E') e3->Enabled=true;if(E5.wypelnienie=='E') e5->Enabled=true; if(E7.wypelnienie=='E') e7->Enabled=true;
if(F2.wypelnienie=='E') f2->Enabled=true;if(F4.wypelnienie=='E') f4->Enabled=true;if(F6.wypelnienie=='E') f6->Enabled=true; if(F8.wypelnienie=='E') f8->Enabled=true;
if(G1.wypelnienie=='E') g1->Enabled=true;if(G3.wypelnienie=='E') g3->Enabled=true;if(G5.wypelnienie=='E') g5->Enabled=true; if(G7.wypelnienie=='E') g7->Enabled=true;
if(H2.wypelnienie=='E') h2->Enabled=true;if(H4.wypelnienie=='E') h4->Enabled=true;if(H6.wypelnienie=='E') h6->Enabled=true; if(H8.wypelnienie=='E') h8->Enabled=true;


if(A1.wypelnienie== 'R' || A1.wypelnienie=='W') a1->Enabled=false;if(A3.wypelnienie== 'R' || A3.wypelnienie=='W') a3->Enabled=false;if(A5.wypelnienie== 'R' || A5.wypelnienie=='W') a5->Enabled=false; if(A7.wypelnienie== 'R' || A7.wypelnienie=='W') a7->Enabled=false;
if(B2.wypelnienie== 'R' || B2.wypelnienie=='W') b2->Enabled=false;if(B4.wypelnienie== 'R' || B4.wypelnienie=='W') b4->Enabled=false;if(B6.wypelnienie== 'R' || B6.wypelnienie=='W') b6->Enabled=false; if(B8.wypelnienie== 'R' || B8.wypelnienie=='W') b8->Enabled=false;
if(C1.wypelnienie== 'R' || C1.wypelnienie=='W') c1->Enabled=false;if(C3.wypelnienie== 'R' || C3.wypelnienie=='W') c3->Enabled=false;if(C5.wypelnienie== 'R' || C5.wypelnienie=='W') c5->Enabled=false; if(C7.wypelnienie== 'R' || C7.wypelnienie=='W') c7->Enabled=false;
if(D2.wypelnienie== 'R' || D2.wypelnienie=='W') d2->Enabled=false;if(D4.wypelnienie== 'R' || D4.wypelnienie=='W') d4->Enabled=false;if(D6.wypelnienie== 'R' || D6.wypelnienie=='W') d6->Enabled=false; if(D8.wypelnienie== 'R' || D8.wypelnienie=='W') d8->Enabled=false;
if(E1.wypelnienie== 'R' || E1.wypelnienie=='W') e1->Enabled=false;if(E3.wypelnienie== 'R' || E3.wypelnienie=='W') e3->Enabled=false;if(E5.wypelnienie== 'R' || E5.wypelnienie=='W') e5->Enabled=false; if(E7.wypelnienie== 'R' || E7.wypelnienie=='W') e7->Enabled=false;
if(F2.wypelnienie== 'R' || F2.wypelnienie=='W') f2->Enabled=false;if(F4.wypelnienie== 'R' || F4.wypelnienie=='W') f4->Enabled=false;if(F6.wypelnienie== 'R' || F6.wypelnienie=='W') f6->Enabled=false; if(F8.wypelnienie== 'R' || F8.wypelnienie=='W') f8->Enabled=false;
if(G1.wypelnienie== 'R' || G1.wypelnienie=='W') g1->Enabled=false;if(G3.wypelnienie== 'R' || G3.wypelnienie=='W') g3->Enabled=false;if(G5.wypelnienie== 'R' || G5.wypelnienie=='W') g5->Enabled=false; if(G7.wypelnienie== 'R' || G7.wypelnienie=='W') g7->Enabled=false;
if(H2.wypelnienie== 'R' || H2.wypelnienie=='W') h2->Enabled=false;if(H4.wypelnienie== 'R' || H4.wypelnienie=='W') h4->Enabled=false;if(H6.wypelnienie== 'R' || H6.wypelnienie=='W') h6->Enabled=false; if(H8.wypelnienie== 'R' || H8.wypelnienie=='W') h8->Enabled=false;
break;


}

}
 

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject* Sender)
{
sndPlaySound(NULL, SND_PURGE);
sndPlaySound("snd/angry.wav", SND_ASYNC | SND_LOOP);  //muzyka
Form1->FormStyle = fsNormal;
na_ruchu=true;
posuniecie=0;
etap_ruchu=1;
zdejmowanie=false;
wynik=false;
              plik.open("plik.txt", ios::out | ios::app);
  timeblack->Font->Color=clBlack;
  timewhite->Font->Color=clBlack;

    Gracz1->Enabled=true;
    Gracz2->Enabled=true;
    tura->Visible = false;
    Label1->Visible = false;
    Zapispartii1->Enabled=true;
    White_resing->Enabled=false;
    Red_resing->Enabled=false;
    Image1->Picture->LoadFromFile("img/bialy_pion_bmaly.bmp");
    Image2->Picture->LoadFromFile("img/czerwony_pion_bmaly.bmp");
    Wynik->Caption = "Wybierz tempo gry \n i imiona graczy";
    startgame->Enabled = false;
    newgame->Enabled = false;
    draw->Enabled = false;
    endmove->Enabled = false;
    endmove->Caption="Zdejmij zbite figury->OFF Nacisnij X";


    A1.wypelnienie = 'W';  A3.wypelnienie = 'W';  A5.wypelnienie = 'E';  A7.wypelnienie = 'R';
    B2.wypelnienie = 'W';  B4.wypelnienie = 'E';  B6.wypelnienie = 'R';  B8.wypelnienie = 'R';
    C1.wypelnienie = 'W';  C3.wypelnienie = 'W';  C5.wypelnienie = 'E';  C7.wypelnienie = 'R';
    D2.wypelnienie = 'W';  D4.wypelnienie = 'E';  D6.wypelnienie = 'R';  D8.wypelnienie = 'R';
    E1.wypelnienie = 'W';  E3.wypelnienie = 'W';  E5.wypelnienie = 'E';  E7.wypelnienie = 'R';
    F2.wypelnienie = 'W';  F4.wypelnienie = 'E';  F6.wypelnienie = 'R';  F8.wypelnienie = 'R';
    G1.wypelnienie = 'W';  G3.wypelnienie = 'W';  G5.wypelnienie = 'E';  G7.wypelnienie = 'R';
    H2.wypelnienie = 'W';  H4.wypelnienie = 'E';  H6.wypelnienie = 'R';  H8.wypelnienie = 'R';

    
    TIcon* appIcon1 = new TIcon;
    appIcon1->LoadFromFile("img/ikona.ico");
    Application->Icon = appIcon1;


    //------------------------------SZACHOWNICA----------------------------------//

    Board->Picture->LoadFromFile("img/szachownica.bmp");
    Board->Enabled = false;

    a1->Enabled = false; b1->Enabled = false; h1->Enabled = false; g1->Enabled = false; c1->Enabled = false;
    f1->Enabled = false; d1->Enabled = false; e1->Enabled = false; a2->Enabled = false; b2->Enabled = false;
    c2->Enabled = false; d2->Enabled = false; e2->Enabled = false; f2->Enabled = false; g2->Enabled = false;
    h2->Enabled = false; a3->Enabled = false; b3->Enabled = false; h3->Enabled = false; g3->Enabled = false;
    c3->Enabled = false; f3->Enabled = false; d3->Enabled = false; e3->Enabled = false; a4->Enabled = false;
    b4->Enabled = false; h4->Enabled = false; g4->Enabled = false; c4->Enabled = false; f4->Enabled = false;
    d4->Enabled = false; e4->Enabled = false; a5->Enabled = false; b5->Enabled = false; h5->Enabled = false;
    g5->Enabled = false; c5->Enabled = false; f5->Enabled = false; d5->Enabled = false; e5->Enabled = false;
    a6->Enabled = false; b6->Enabled = false; h6->Enabled = false; g6->Enabled = false; c6->Enabled = false;
    f6->Enabled = false; d6->Enabled = false; e6->Enabled = false; a7->Enabled = false; b7->Enabled = false;
    h7->Enabled = false; g7->Enabled = false; c7->Enabled = false; f7->Enabled = false; d7->Enabled = false;
    e7->Enabled = false; a8->Enabled = false; b8->Enabled = false; h8->Enabled = false; g8->Enabled = false;
    c8->Enabled = false; f8->Enabled = false; d8->Enabled = false; e8->Enabled = false;
    //------CZERWONE-----//

    a7->Picture->LoadFromFile("img/czerwony_pion.bmp");    b8->Picture->LoadFromFile("img/czerwony_pion.bmp");
    b6->Picture->LoadFromFile("img/czerwony_pion.bmp");    c7->Picture->LoadFromFile("img/czerwony_pion.bmp");
    d8->Picture->LoadFromFile("img/czerwony_pion.bmp");    d6->Picture->LoadFromFile("img/czerwony_pion.bmp");
    e7->Picture->LoadFromFile("img/czerwony_pion.bmp");    f8->Picture->LoadFromFile("img/czerwony_pion.bmp");
    f6->Picture->LoadFromFile("img/czerwony_pion.bmp");    g7->Picture->LoadFromFile("img/czerwony_pion.bmp");
    h8->Picture->LoadFromFile("img/czerwony_pion.bmp");    h6->Picture->LoadFromFile("img/czerwony_pion.bmp");


    //-------CZARNE------//

    a1->Picture->LoadFromFile("img/bialy_pion.bmp");    a3->Picture->LoadFromFile("img/bialy_pion.bmp");
    b2->Picture->LoadFromFile("img/bialy_pion.bmp");    c1->Picture->LoadFromFile("img/bialy_pion.bmp");
    c3->Picture->LoadFromFile("img/bialy_pion.bmp");    d2->Picture->LoadFromFile("img/bialy_pion.bmp");
    e1->Picture->LoadFromFile("img/bialy_pion.bmp");    e3->Picture->LoadFromFile("img/bialy_pion.bmp");
    f2->Picture->LoadFromFile("img/bialy_pion.bmp");    g1->Picture->LoadFromFile("img/bialy_pion.bmp");
    g3->Picture->LoadFromFile("img/bialy_pion.bmp");    h2->Picture->LoadFromFile("img/bialy_pion.bmp");


    //------------//
    a5->Picture=NULL;b4->Picture=NULL;c5->Picture=NULL;d4->Picture=NULL;e5->Picture=NULL;f4->Picture=NULL;g5->Picture=NULL;h4->Picture=NULL;
    tura->Picture->LoadFromFile("img/bialy_pion_maly.bmp");
    //---------zegary startowe-----------//
    timeblack->Caption = "00:00:00";
    timewhite->Caption = "00:00:00";

    int godzin, minut, sekund;
    AnsiString godz, min, sek;

    godzin = czasbialych / 3600;
    godz = IntToStr(godzin);
    if (godzin < 10) godz = "0" + godz;

    minut = (czasbialych - godzin * 3600) / 60;
    min = IntToStr(minut);
    if (minut < 10) min = "0" + min;

    sekund = czasbialych - godzin * 3600 - minut * 60;
    sek = IntToStr(sekund);
    if (sekund < 10) sek = "0" + sek;

    timewhite->Caption = godz + ":" + min + ":" + sek;

    int godzinC, minutC, sekundC;
    AnsiString godzC, minC, sekC;

    godzinC = czasczarnych / 3600;
    godzC = IntToStr(godzin);
    if (godzinC < 10) godzC = "0" + godzC;

    minutC = (czasczarnych - godzinC * 3600) / 60;
    minC = IntToStr(minutC);
    if (minutC < 10) minC = "0" + minC;

    sekundC = czasczarnych - godzinC * 3600 - minutC * 60;
    sekC = IntToStr(sekundC);
    if (sekundC < 10) sekC = "0" + sekC;

    timeblack->Caption = godzC + ":" + minC + ":" + sekC;

}
//--------------------------------------------------------------------------//

//---------------------------------ZEGAR---------------------------------//

void __fastcall TForm1::whitetimeTimer(TObject* Sender)
{
    if (whitetime->Enabled == true)
    {
        czasbialych--;
        int godzin, minut, sekund;
        AnsiString godz, min, sek;

        godzin = czasbialych / 3600;
        godz = IntToStr(godzin);
        if (godzin < 10) godz = "0" + godz;

        minut = (czasbialych - godzin * 3600) / 60;
        min = IntToStr(minut);
        if (minut < 10) min = "0" + min;

        sekund = czasbialych - godzin * 3600 - minut * 60;
        sek = IntToStr(sekund);
        if (sekund < 10) sek = "0" + sek;

        timewhite->Caption = godz + ":" + min + ":" + sek;
    }
      if(czasbialych<=10&&na_ruchu==true)
    {
     timewhite->Font->Color=clRed;
    }

    if (czasbialych == 0)
    {
        Wynik->Caption = "Uplynal czas bialych!!!";


            sndPlaySound(NULL, SND_PURGE);
            sndPlaySound("snd/fnaf.wav", SND_ASYNC);

    draw->Enabled = false;
    endmove->Enabled = false;
    newgame->Enabled = true;
    newgame->Cursor = crHandPoint;
    startgame->Enabled = false;
      White_resing->Enabled=false;
    Red_resing->Enabled=false;
    blacktime->Enabled = false;
    whitetime->Enabled = false;
    whitetime->Enabled = false;
    blacktime->Enabled = false;
    Application->MessageBoxA("Czerwone wygrywaja", "Koniec partii", MB_OK);


    a1->Enabled = false;  a3->Enabled = false;  a5->Enabled = false;  a7->Enabled = false;
    b2->Enabled = false;  b4->Enabled = false;  b6->Enabled = false;  b8->Enabled = false;
    c1->Enabled = false;  c3->Enabled = false;  c5->Enabled = false;  c7->Enabled = false;
    d2->Enabled = false;  d4->Enabled = false;  d6->Enabled = false;  d8->Enabled = false;
    e1->Enabled = false;  e3->Enabled = false;  e5->Enabled = false;  e7->Enabled = false;
    f2->Enabled = false;  f4->Enabled = false;  f6->Enabled = false;  f8->Enabled = false;
    g1->Enabled = false;  g3->Enabled = false;  g5->Enabled = false;  g7->Enabled = false;
    h2->Enabled = false;  h4->Enabled = false;  h6->Enabled = false;  h8->Enabled = false;

    plik << " 0-1" << endl;
    wynik = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::blacktimeTimer(TObject* Sender)
{
    if (blacktime->Enabled == true)
    {
        czasczarnych--;
        int godzin, minut, sekund;
        AnsiString godz, min, sek;

        godzin = czasczarnych / 3600;
        godz = IntToStr(godzin);
        if (godzin < 10) godz = "0" + godz;

        minut = (czasczarnych - godzin * 3600) / 60;
        min = IntToStr(minut);
        if (minut < 10) min = "0" + min;

        sekund = czasczarnych - godzin * 3600 - minut * 60;
        sek = IntToStr(sekund);
        if (sekund < 10) sek = "0" + sek;

        timeblack->Caption = godz + ":" + min + ":" + sek;
    }
     if(czasczarnych<=10&&na_ruchu==false)
    {
     timeblack->Font->Color=clRed;
    }
    if (czasczarnych == 0)
    {
        Wynik->Enabled = true;
        Wynik->Caption = "Uplynal czas czerwonych!!!";

        sndPlaySound(NULL, SND_PURGE);
        sndPlaySound("snd/fnaf.wav", SND_ASYNC);
        timewhite->Enabled = true;
    draw->Enabled = false;
    endmove->Enabled = false;
    newgame->Enabled = true;
    newgame->Cursor = crHandPoint;
    startgame->Enabled = false;
    White_resing->Enabled=false;
    Red_resing->Enabled=false;
    blacktime->Enabled = false;
    whitetime->Enabled = false;
    whitetime->Enabled = false;
    blacktime->Enabled = false;
    Application->MessageBoxA("Bia³e wygrywaja!", "Koniec partii", MB_OK);

    a1->Enabled = false;  a3->Enabled = false;  a5->Enabled = false;  a7->Enabled = false;
    b2->Enabled = false;  b4->Enabled = false;  b6->Enabled = false;  b8->Enabled = false;
    c1->Enabled = false;  c3->Enabled = false;  c5->Enabled = false;  c7->Enabled = false;
    d2->Enabled = false;  d4->Enabled = false;  d6->Enabled = false;  d8->Enabled = false;
    e1->Enabled = false;  e3->Enabled = false;  e5->Enabled = false;  e7->Enabled = false;
    f2->Enabled = false;  f4->Enabled = false;  f6->Enabled = false;  f8->Enabled = false;
    g1->Enabled = false;  g3->Enabled = false;  g5->Enabled = false;  g7->Enabled = false;
    h2->Enabled = false;  h4->Enabled = false;  h6->Enabled = false;  h8->Enabled = false;

    plik << " 1-0" << endl;
    wynik = true;

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startgameClick(TObject* Sender)
{
    plik.open("plik.txt", ios::out | ios::app);
    sndPlaySound(NULL, SND_PURGE);
    sndPlaySound("snd/ryba.wav", SND_ASYNC | SND_LOOP);
    Zapispartii1->Enabled=false;
    Form1->sprawdz();

    time_t now = time(0);
    plik << endl;
    char* date_time = ctime(&now);
    plik << date_time;

    string gracz1=Gracz1->Text.c_str();
    string gracz2=Gracz2->Text.c_str();
    plik <<gracz1<<" vs "<<gracz2<<endl;
    Gracz1->Enabled=false;
    Gracz2->Enabled=false;

     Zapispartii1->Enabled=false;

    tura->Visible = true;
    Label1->Visible = true;

    White_resing->Enabled=true;
    Red_resing->Enabled=true;

    endmove->Enabled = false;
    Wynik->Caption = "Partia w toku";
    startgame->Enabled = false;
    whitetime->Enabled = true;
    newgame->Enabled = false;

    draw->Cursor = crHandPoint;

    endmove->Cursor = crHandPoint;

    draw->Enabled = true;
    endmove->Enabled = true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::endmoveClick(TObject* Sender)
{
        if(zdejmowanie==true){zdejmowanie=false;endmove->Caption="Zdejmij zbite figury->OFF Nacisnij X";}
        else if(zdejmowanie==false){zdejmowanie=true;endmove->Caption="Zdejmij zbite figury->ON Nacisnij X";}
        if(etap_ruchu==2 || etap_ruchu==4){Application->MessageBoxA("POSTAW PIONKA", "B£¥D", MB_OK);return;}
        if(whitetime->Enabled==true||blacktime->Enabled==true)
        {
        whitetime->Enabled = false;
        whitetime->Interval = 0;
        blacktime->Enabled = false;
        blacktime->Interval = 0;   
        return;
        }
        if(etap_ruchu==1 && whitetime->Enabled==false && blacktime->Enabled==false)
        {
         whitetime->Enabled=true;
         whitetime->Interval = 1000;
         return;
        }
        if(etap_ruchu==3 && whitetime->Enabled==false && blacktime->Enabled==false)
        {
         blacktime->Enabled=true;
         blacktime->Interval=1000;
         return;
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N0005001Click(TObject* Sender)
{
    czasbialych = 30;
    czasczarnych = 30;
    timewhite->Caption = "00:00:30";
    timeblack->Caption = "00:00:30";
    Wynik->Caption = "W³¹cz zegar!";
    startgame->Enabled = true;
    startgame->Cursor = crHandPoint;
    endmove->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N001Click(TObject* Sender)
{
    czasbialych = 60;
    czasczarnych = 60;
    timewhite->Caption = "00:01:00";
    timeblack->Caption = "00:01:00";
    Wynik->Caption = "W³¹cz zegar!";
    startgame->Enabled = true;
    startgame->Cursor = crHandPoint;
    endmove->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N0005002Click(TObject* Sender)
{
    czasbialych = 300;
    czasczarnych = 300;
    timewhite->Caption = "00:05:00";
    timeblack->Caption = "00:05:00";
    Wynik->Caption = "W³¹cz zegar!";
    startgame->Enabled = true;
    startgame->Cursor = crHandPoint;
    endmove->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N0010001Click(TObject* Sender)
{
    czasbialych = 600;
    czasczarnych = 600;
    timewhite->Caption = "00:10:00";
    timeblack->Caption = "00:10:00";
    Wynik->Caption = "W³¹cz zegar!";
    startgame->Enabled = true;
    startgame->Cursor = crHandPoint;
    endmove->Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N0130001Click(TObject* Sender)
{
    czasbialych = 5400;
    czasczarnych = 5400;
    timewhite->Caption = "01:30:00";
    timeblack->Caption = "01:30:00";
    Wynik->Caption = "W³¹cz zegar!";
    startgame->Enabled = true;
    startgame->Cursor = crHandPoint;
    endmove->Enabled = false;
 
}
//---------------------------------------------------------------------------



//--------------------------------RUCHY--------------------------------//
void __fastcall TForm1::e1Click(TObject* Sender)
{
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = e1->Picture; posuniecie++; plik << " " << posuniecie << ": e1-"; etap_ruchu = 2; e1->Picture = NULL; E1.wypelnienie = 'E';
            break;
        case 2:
            e1->Picture = reka->Picture; plik << "e1 "; etap_ruchu = 3; reka->Picture = NULL; E1.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = e1->Picture; plik << "e1-"; etap_ruchu = 4; e1->Picture = NULL; E1.wypelnienie = 'E';
            break;
        case 4:
            e1->Picture->LoadFromFile("img/damka_czerwona.bmp"); plik << "e1 "; etap_ruchu = 1; reka->Picture = NULL; E1.wypelnienie = 'R';
            Form1->zegar();
            break;
        } Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        e1->Picture = NULL; E1.wypelnienie = 'E';
    }
    Form1->white_win_check();
    Form1->red_win_check();
}

void __fastcall TForm1::e3Click(TObject* Sender) {

    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = e3->Picture; posuniecie++; plik << " " << posuniecie << ": e3-"; etap_ruchu = 2; e3->Picture = NULL; E3.wypelnienie = 'E';
            break;
        case 2:
            e3->Picture = reka->Picture; plik << "e3 "; etap_ruchu = 3; reka->Picture = NULL; E3.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = e3->Picture; plik << "e3-"; etap_ruchu = 4; e3->Picture = NULL;E3.wypelnienie = 'E';
            break;
        case 4:
            e3->Picture = reka->Picture; plik << "e3 "; etap_ruchu = 1; reka->Picture = NULL; E3.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        e3->Picture = NULL; E3.wypelnienie = 'E';
    }
      Form1->white_win_check();
      Form1->red_win_check();
}

void __fastcall TForm1::e5Click(TObject* Sender) {

    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = e5->Picture; posuniecie++; plik << " " << posuniecie << ": e5-"; etap_ruchu = 2; e5->Picture = NULL; E5.wypelnienie = 'E';
            break;
        case 2:
            e5->Picture = reka->Picture; plik << "e5 "; etap_ruchu = 3; reka->Picture = NULL; E5.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = e5->Picture; plik << "e5-"; etap_ruchu = 4; e5->Picture = NULL; E5.wypelnienie = 'E';
            break;
        case 4:
            e5->Picture = reka->Picture; plik << "e5 "; etap_ruchu = 1; reka->Picture = NULL; E5.wypelnienie = 'R';
            Form1->zegar();
            break;
        }    Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        e5->Picture = NULL; E5.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::e7Click(TObject* Sender) {

    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = e7->Picture; posuniecie++; plik << " " << posuniecie << ": e7-"; etap_ruchu = 2; e7->Picture = NULL; E7.wypelnienie = 'E';
            break;
        case 2:
            e7->Picture = reka->Picture; plik << "e7 "; etap_ruchu = 3; reka->Picture = NULL; E7.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = e7->Picture; plik << "e7-"; etap_ruchu = 4; e7->Picture = NULL; E7.wypelnienie = 'E';
            break;
        case 4:
            e7->Picture = reka->Picture; plik << "e7 "; etap_ruchu = 1; reka->Picture = NULL; E7.wypelnienie = 'R';
            Form1->zegar();
            break;
        } Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        e7->Picture = NULL; E7.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}


void __fastcall TForm1::a1Click(TObject* Sender) {

    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = a1->Picture; posuniecie++; plik << " " << posuniecie << ": a1-"; etap_ruchu = 2; a1->Picture = NULL; A1.wypelnienie = 'E';
            break;
        case 2:
            a1->Picture = reka->Picture; plik << "a1 "; etap_ruchu = 3; reka->Picture = NULL; A1.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = a1->Picture; plik << "a1-"; etap_ruchu = 4; a1->Picture = NULL; A1.wypelnienie = 'E';
            break;
        case 4:
            a1->Picture->LoadFromFile("img/damka_czerwona.bmp"); plik << "a1 "; etap_ruchu = 1; reka->Picture = NULL; A1.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        a1->Picture = NULL; A1.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::a3Click(TObject* Sender) {

    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = a3->Picture; posuniecie++; plik << " " << posuniecie << ": a3-"; etap_ruchu = 2; a3->Picture = NULL; A3.wypelnienie = 'E';
            break;
        case 2:
            a3->Picture = reka->Picture; plik << "a3 "; etap_ruchu = 3; reka->Picture = NULL; A3.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = a3->Picture; plik << "a3-"; etap_ruchu = 4; a3->Picture = NULL; A3.wypelnienie = 'E';
            break;
        case 4:
            a3->Picture = reka->Picture; plik << "a3 "; etap_ruchu = 1; reka->Picture = NULL; A3.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        a3->Picture = NULL;A3.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
    }

void __fastcall TForm1::a5Click(TObject* Sender) {

    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = a5->Picture; posuniecie++; plik << " " << posuniecie << ": a5-"; etap_ruchu = 2; a5->Picture = NULL; A5.wypelnienie = 'E';
            break;
        case 2:
            a5->Picture = reka->Picture; plik << "a5 "; etap_ruchu = 3; reka->Picture = NULL; A5.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = a5->Picture; plik << "a5-"; etap_ruchu = 4; a5->Picture = NULL; A5.wypelnienie = 'E';
            break;
        case 4:
            a5->Picture = reka->Picture; plik << "a5 "; etap_ruchu = 1; reka->Picture = NULL; A5.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        a5->Picture = NULL; A5.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::a7Click(TObject* Sender) {

    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = a7->Picture; posuniecie++; plik << " " << posuniecie << ": a7-"; etap_ruchu = 2; a7->Picture = NULL; A7.wypelnienie = 'E';
            break;
        case 2:
            a7->Picture = reka->Picture; plik << "a7 "; etap_ruchu = 3; reka->Picture = NULL; A7.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = a7->Picture; plik << "a7-"; etap_ruchu = 4; a7->Picture = NULL; A7.wypelnienie = 'E';
            break;
        case 4:
            a7->Picture = reka->Picture; plik << "a7 "; etap_ruchu = 1; reka->Picture = NULL; A7.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        a7->Picture = NULL;A7.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}



void __fastcall TForm1::b2Click(TObject* Sender) {

    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = b2->Picture; posuniecie++; plik << " " << posuniecie << ": b2-"; etap_ruchu = 2; b2->Picture = NULL; B2.wypelnienie = 'E';
            break;
        case 2:
            b2->Picture = reka->Picture; plik << "b2 "; etap_ruchu = 3; reka->Picture = NULL; B2.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = b2->Picture; plik << "b2-"; etap_ruchu = 4; b2->Picture = NULL; B2.wypelnienie = 'E';
            break;
        case 4:
            b2->Picture = reka->Picture; plik << "b2 "; etap_ruchu = 1; reka->Picture = NULL; B2.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        b2->Picture = NULL; B2.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::b4Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = b4->Picture; posuniecie++; plik << " " << posuniecie << ": b4-"; etap_ruchu = 2; b4->Picture = NULL; B4.wypelnienie = 'E';
            break;
        case 2:
            b4->Picture = reka->Picture; plik << "b4 "; etap_ruchu = 3; reka->Picture = NULL;B4.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = b4->Picture; plik << "b4-"; etap_ruchu = 4; b4->Picture = NULL; B4.wypelnienie = 'E';
            break;
        case 4:
            b4->Picture = reka->Picture; plik << "b4 "; etap_ruchu = 1; reka->Picture = NULL; B4.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        b4->Picture = NULL; B4.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::b6Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = b6->Picture; posuniecie++; plik << " " << posuniecie << ": b6-"; etap_ruchu = 2; b6->Picture = NULL; B6.wypelnienie = 'E';
            break;
        case 2:
            b6->Picture = reka->Picture; plik << "b6 "; etap_ruchu = 3; reka->Picture = NULL; B6.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = b6->Picture; plik << "b6-"; etap_ruchu = 4; b6->Picture = NULL; B6.wypelnienie = 'E';
            break;
        case 4:
            b6->Picture = reka->Picture; plik << "b6 "; etap_ruchu = 1; reka->Picture = NULL;B6.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        b6->Picture = NULL; B6.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::b8Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = b8->Picture; posuniecie++; plik << " " << posuniecie << ": b8-"; etap_ruchu = 2; b8->Picture = NULL; B8.wypelnienie = 'E';
            break;
        case 2:
            b8->Picture->LoadFromFile("img/damka_biala.bmp"); plik << "b8 "; etap_ruchu = 3; reka->Picture = NULL; B8.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = b8->Picture; plik << "b8-"; etap_ruchu = 4; b8->Picture = NULL; B8.wypelnienie = 'E';
            break;
        case 4:
            b8->Picture = reka->Picture; plik << "b8 "; etap_ruchu = 1; reka->Picture = NULL; B8.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        b8->Picture = NULL; B8.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::c1Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = c1->Picture; posuniecie++; plik << " " << posuniecie << ": c1-"; etap_ruchu = 2; c1->Picture = NULL; C1.wypelnienie = 'E';
            break;
        case 2:
            c1->Picture = reka->Picture; plik << "c1 "; etap_ruchu = 3; reka->Picture = NULL; C1.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = c1->Picture; plik << "c1-"; etap_ruchu = 4; c1->Picture = NULL; C1.wypelnienie = 'E';
            break;
        case 4:
            c1->Picture->LoadFromFile("img/damka_czerwona.bmp"); plik << "c1 "; etap_ruchu = 1; reka->Picture = NULL; C1.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        c1->Picture = NULL; C1.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::c3Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = c3->Picture; posuniecie++; plik << " " << posuniecie << ": c3-"; etap_ruchu = 2; c3->Picture = NULL; C3.wypelnienie = 'E';
            break;
        case 2:
            c3->Picture = reka->Picture; plik << "c3 "; etap_ruchu = 3; reka->Picture = NULL; C3.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = c3->Picture; plik << "c3-"; etap_ruchu = 4; c3->Picture = NULL;C3.wypelnienie = 'E';
            break;
        case 4:
            c3->Picture = reka->Picture; plik << "c3 "; etap_ruchu = 1; reka->Picture = NULL; C3.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        c3->Picture = NULL; C3.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::c5Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = c5->Picture; posuniecie++; plik << " " << posuniecie << ": c5-"; etap_ruchu = 2; c5->Picture = NULL; C5.wypelnienie = 'E';
            break;
        case 2:
            c5->Picture = reka->Picture; plik << "c5 "; etap_ruchu = 3; reka->Picture = NULL; C5.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = c5->Picture; plik << "c5-"; etap_ruchu = 4; c5->Picture = NULL; C5.wypelnienie = 'E';
            break;
        case 4:
            c5->Picture = reka->Picture; plik << "c5 "; etap_ruchu = 1; reka->Picture = NULL; C5.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        c5->Picture = NULL; C5.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::c7Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = c7->Picture; posuniecie++; plik << " " << posuniecie << ": c7-"; etap_ruchu = 2; c7->Picture = NULL; C7.wypelnienie = 'E';
            break;
        case 2:
            c7->Picture = reka->Picture; plik << "c7 "; etap_ruchu = 3; reka->Picture = NULL; C7.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = c7->Picture; plik << "c7-"; etap_ruchu = 4; c7->Picture = NULL; C7.wypelnienie = 'E';
            break;
        case 4:
            c7->Picture = reka->Picture; plik << "c7 "; etap_ruchu = 1; reka->Picture = NULL; C7.wypelnienie = 'R';
            Form1->zegar();
            break;
        }    Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        c7->Picture = NULL; C7.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}



void __fastcall TForm1::d2Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = d2->Picture; posuniecie++; plik << " " << posuniecie << ": d2-"; etap_ruchu = 2; d2->Picture = NULL; D2.wypelnienie = 'E';
            break;
        case 2:
            d2->Picture = reka->Picture; plik << "d2 "; etap_ruchu = 3; reka->Picture = NULL; D2.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = d2->Picture; plik << "d2-"; etap_ruchu = 4; d2->Picture = NULL;D2.wypelnienie = 'E';
            break;
        case 4:
            d2->Picture = reka->Picture; plik << "d2 "; etap_ruchu = 1; reka->Picture = NULL; D2.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        d2->Picture = NULL; D2.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::d4Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = d4->Picture; posuniecie++; plik << " " << posuniecie << ": d4-"; etap_ruchu = 2; d4->Picture = NULL; D4.wypelnienie = 'E';
            break;
        case 2:
            d4->Picture = reka->Picture; plik << "d4 "; etap_ruchu = 3; reka->Picture = NULL; D4.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = d4->Picture; plik << "d4-"; etap_ruchu = 4; d4->Picture = NULL; D4.wypelnienie = 'E';
            break;
        case 4:
            d4->Picture = reka->Picture; plik << "d4 "; etap_ruchu = 1; reka->Picture = NULL; D4.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        d4->Picture = NULL; D4.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::d6Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = d6->Picture; posuniecie++; plik << " " << posuniecie << ": d6-"; etap_ruchu = 2; d6->Picture = NULL; D6.wypelnienie = 'E';
            break;
        case 2:
            d6->Picture = reka->Picture; plik << "d6 "; etap_ruchu = 3; reka->Picture = NULL; D6.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = d6->Picture; plik << "d6-"; etap_ruchu = 4; d6->Picture = NULL; D6.wypelnienie = 'E';
            break;
        case 4:
            d6->Picture = reka->Picture; plik << "d6 "; etap_ruchu = 1; reka->Picture = NULL;D6.wypelnienie = 'R';
            Form1->zegar();
            break;
        } Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        d6->Picture = NULL; D6.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::d8Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = d8->Picture; posuniecie++; plik << " " << posuniecie << ": d8-"; etap_ruchu = 2; d8->Picture = NULL; D8.wypelnienie = 'E';
            break;
        case 2:
            d8->Picture->LoadFromFile("img/damka_biala.bmp"); plik << "d8 "; etap_ruchu = 3; reka->Picture = NULL; D8.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = d8->Picture; plik << "d8-"; etap_ruchu = 4; d8->Picture = NULL; D8.wypelnienie = 'E';
            break;
        case 4:
            d8->Picture = reka->Picture; plik << "d8 "; etap_ruchu = 1; reka->Picture = NULL;D8.wypelnienie = 'R';
            Form1->zegar();
            break;
        } Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        d8->Picture = NULL; D8.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}


void __fastcall TForm1::f2Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = f2->Picture; posuniecie++; plik << " " << posuniecie << ": f2-"; etap_ruchu = 2; f2->Picture = NULL; F2.wypelnienie = 'E';
            break;
        case 2:
            f2->Picture = reka->Picture; plik << "f2 "; etap_ruchu = 3; reka->Picture = NULL; F2.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = f2->Picture; plik << "f2-"; etap_ruchu = 4; f2->Picture = NULL; F2.wypelnienie = 'E';
            break;
        case 4:
            f2->Picture = reka->Picture; plik << "f2 "; etap_ruchu = 1; reka->Picture = NULL; F2.wypelnienie = 'R';
            Form1->zegar();
            break;
        } Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        f2->Picture = NULL; F2.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::f4Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = f4->Picture; posuniecie++; plik << " " << posuniecie << ": f4-"; etap_ruchu = 2; f4->Picture = NULL; F4.wypelnienie = 'E';
            break;
        case 2:
            f4->Picture = reka->Picture; plik << "f4 "; etap_ruchu = 3; reka->Picture = NULL; F4.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = f4->Picture; plik << "f4-"; etap_ruchu = 4; f4->Picture = NULL; F4.wypelnienie = 'E';
            break;
        case 4:
            f4->Picture = reka->Picture; plik << "f4 "; etap_ruchu = 1; reka->Picture = NULL; F4.wypelnienie = 'R';
            Form1->zegar();
            break;
        }   Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        f4->Picture = NULL; F4.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::f6Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = f6->Picture; posuniecie++; plik << " " << posuniecie << ": f6-"; etap_ruchu = 2; f6->Picture = NULL; F6.wypelnienie = 'E';
            break;
        case 2:
            f6->Picture = reka->Picture; plik << "f6 "; etap_ruchu = 3; reka->Picture = NULL; F6.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = f6->Picture; plik << "f6-"; etap_ruchu = 4; f6->Picture = NULL; F6.wypelnienie = 'E';
            break;
        case 4:
            f6->Picture = reka->Picture; plik << "f6 "; etap_ruchu = 1; reka->Picture = NULL; F6.wypelnienie = 'R';
            Form1->zegar();
            break;
        } Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        f6->Picture = NULL; F6.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::f8Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = f8->Picture; posuniecie++; plik << " " << posuniecie << ": f8-"; etap_ruchu = 2; f8->Picture = NULL; F8.wypelnienie = 'E';
            break;
        case 2:
            f8->Picture->LoadFromFile("img/damka_biala.bmp"); plik << "f8 "; etap_ruchu = 3; reka->Picture = NULL; F8.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = f8->Picture; plik << "f8-"; etap_ruchu = 4; f8->Picture = NULL; F8.wypelnienie = 'E';
            break;
        case 4:
            f8->Picture = reka->Picture; plik << "f8 "; etap_ruchu = 1; reka->Picture = NULL; F8.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        f8->Picture = NULL; F8.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::g1Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = g1->Picture; posuniecie++; plik << " " << posuniecie << ": g1-"; etap_ruchu = 2; g1->Picture = NULL; G1.wypelnienie = 'E';
            break;
        case 2:
            g1->Picture = reka->Picture; plik << "g1 "; etap_ruchu = 3; reka->Picture = NULL; G1.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = g1->Picture; plik << "g1-"; etap_ruchu = 4; g1->Picture = NULL; G1.wypelnienie = 'E';
            break;
        case 4:
            g1->Picture->LoadFromFile("img/damka_czerwona.bmp"); plik << "g1 "; etap_ruchu = 1; reka->Picture = NULL; G1.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        g1->Picture = NULL; G1.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::g3Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = g3->Picture; posuniecie++; plik << " " << posuniecie << ": g3-"; etap_ruchu = 2; g3->Picture = NULL; G3.wypelnienie = 'E';
            break;
        case 2:
            g3->Picture = reka->Picture; plik << "g3 "; etap_ruchu = 3; reka->Picture = NULL; G3.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = g3->Picture; plik << "g3-"; etap_ruchu = 4; g3->Picture = NULL; G3.wypelnienie = 'E';
            break;
        case 4:
            g3->Picture = reka->Picture; plik << "g3 "; etap_ruchu = 1; reka->Picture = NULL; G3.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        g3->Picture = NULL; G3.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::g5Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = g5->Picture; posuniecie++; plik << " " << posuniecie << ": g5-"; etap_ruchu = 2; g5->Picture = NULL; G5.wypelnienie = 'E';
            break;
        case 2:
            g5->Picture = reka->Picture; plik << "g5 "; etap_ruchu = 3; reka->Picture = NULL; G5.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = g5->Picture; plik << "g5-"; etap_ruchu = 4; g5->Picture = NULL; G5.wypelnienie = 'E';
            break;
        case 4:
            g5->Picture = reka->Picture; plik << "g5 "; etap_ruchu = 1; reka->Picture = NULL; G5.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        g5->Picture = NULL; G5.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::g7Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = g7->Picture; posuniecie++; plik << " " << posuniecie << ": g7-"; etap_ruchu = 2; g7->Picture = NULL; G7.wypelnienie = 'E';
            break;
        case 2:
            g7->Picture = reka->Picture; plik << "g7 "; etap_ruchu = 3; reka->Picture = NULL; G7.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = g7->Picture; plik << "g7-"; etap_ruchu = 4; g7->Picture = NULL; G7.wypelnienie = 'E';
            break;
        case 4:
            g7->Picture = reka->Picture; plik << "g7 "; etap_ruchu = 1; reka->Picture = NULL; G7.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        g7->Picture = NULL; G7.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}



void __fastcall TForm1::h2Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = h2->Picture; posuniecie++; plik << " " << posuniecie << ": h2-"; etap_ruchu = 2; h2->Picture = NULL; H2.wypelnienie = 'E';
            break;
        case 2:
            h2->Picture = reka->Picture; plik << "h2 "; etap_ruchu = 3; reka->Picture = NULL; H2.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = h2->Picture; plik << "h2-"; etap_ruchu = 4; h2->Picture = NULL; H2.wypelnienie = 'E';
            break;
        case 4:
            h2->Picture = reka->Picture; plik << "h2 "; etap_ruchu = 1; reka->Picture = NULL; H2.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        h2->Picture = NULL; H2.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::h4Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = h4->Picture; posuniecie++; plik << " " << posuniecie << ": h4-"; etap_ruchu = 2; h4->Picture = NULL; H4.wypelnienie = 'E';
            break;
        case 2:
            h4->Picture = reka->Picture; plik << "h4 "; etap_ruchu = 3; reka->Picture = NULL; H4.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = h4->Picture; plik << "h4-"; etap_ruchu = 4; h4->Picture = NULL; H4.wypelnienie = 'E';
            break;
        case 4:
            h4->Picture = reka->Picture; plik << "h4 "; etap_ruchu = 1; reka->Picture = NULL; H4.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        h4->Picture = NULL; H4.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::h6Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = h6->Picture; posuniecie++; plik << " " << posuniecie << ": h6-"; etap_ruchu = 2; h6->Picture = NULL; H6.wypelnienie = 'E';
            break;
        case 2:
            h6->Picture = reka->Picture; plik << "h6 "; etap_ruchu = 3; reka->Picture = NULL; H6.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = h6->Picture; plik << "h6-"; etap_ruchu = 4; h6->Picture = NULL; H6.wypelnienie = 'E';
            break;
        case 4:
            h6->Picture = reka->Picture; plik << "h6 "; etap_ruchu = 1; reka->Picture = NULL; H6.wypelnienie = 'R';
            Form1->zegar();
            break;
        }  Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        h6->Picture = NULL; H6.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}

void __fastcall TForm1::h8Click(TObject* Sender) {
    if (zdejmowanie == false)
    {
        switch (etap_ruchu)
        {
        case 1:
            reka->Picture = h8->Picture; posuniecie++; plik << " " << posuniecie << ": h8-"; etap_ruchu = 2; h8->Picture = NULL; H8.wypelnienie = 'E';
            break;
        case 2:
            h8->Picture->LoadFromFile("img/damka_biala.bmp"); plik << "h8 "; etap_ruchu = 3; reka->Picture = NULL;H8.wypelnienie = 'W';
            Form1->zegar();
            break;
        case 3:
            reka->Picture = h8->Picture; plik << "h8-"; etap_ruchu = 4; h8->Picture = NULL; H8.wypelnienie = 'E';
            break;
        case 4:
            h8->Picture = reka->Picture; plik << "h8 "; etap_ruchu = 1; reka->Picture = NULL; H8.wypelnienie = 'R';
            Form1->zegar();
            break;
        } Form1->sprawdz();
    }
    if (zdejmowanie == true)
    {
        h8->Picture = NULL; H8.wypelnienie = 'E';
    }
      Form1->white_win_check();
        Form1->red_win_check();
}



//----------------------------WYNIK------------------------------//

void __fastcall TForm1::drawClick(TObject* Sender)
{
    White_resing->Enabled=false;
    Red_resing->Enabled=false;
    Zapispartii1->Enabled=false;
    Wynik->Caption = "REMIS";
    timewhite->Caption = "00:00:00";
    whitetime->Enabled = false;
    timeblack->Caption = "00:00:00";
    blacktime->Enabled = false;
    draw->Enabled = false;
    endmove->Enabled = false;
    newgame->Enabled = true;
    newgame->Cursor = crHandPoint;
    startgame->Enabled = false;

    blacktime->Enabled = false;
    whitetime->Enabled = false;
    timewhite->Caption = "00:00:00";
    timeblack->Caption = "00:00:00";
    Application->MessageBoxA("Gra zakonczona remisem!", "Koniec partii", MB_OK);
    a1->Enabled = false;  a3->Enabled = false;  a5->Enabled = false;  a7->Enabled = false;
    b2->Enabled = false;  b4->Enabled = false;  b6->Enabled = false;  b8->Enabled = false;
    c1->Enabled = false;  c3->Enabled = false;  c5->Enabled = false;  c7->Enabled = false;
    d2->Enabled = false;  d4->Enabled = false;  d6->Enabled = false;  d8->Enabled = false;
    e1->Enabled = false;  e3->Enabled = false;  e5->Enabled = false;  e7->Enabled = false;
    f2->Enabled = false;  f4->Enabled = false;  f6->Enabled = false;  f8->Enabled = false;
    g1->Enabled = false;  g3->Enabled = false;  g5->Enabled = false;  g7->Enabled = false;
    h2->Enabled = false;  h4->Enabled = false;  h6->Enabled = false;  h8->Enabled = false;

    plik << " 0.5-0.5" << endl;
    wynik = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Brazowy1Click(TObject* Sender)
{
    Board->Picture->LoadFromFile("img/szachownica.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zielony1Click(TObject* Sender)
{
    Board->Picture->LoadFromFile("img/czarna_szachownica.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Niebieski1Click(TObject* Sender)
{
    Board->Picture->LoadFromFile("img/niebieska_szachownica.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
/*if(Key=='x'||Key=='X')
{
  if(zdejmowanie==true){zdejmowanie=false;endmove->Caption="Zdejmij zbite figury->OFF Nacisnij X";}
        else if(zdejmowanie==false){zdejmowanie=true;endmove->Caption="Zdejmij zbite figury->ON Nacisnij X";}
        if(etap_ruchu==2 || etap_ruchu==4){Application->MessageBoxA("POSTAW PIONKA", "B£¥D", MB_OK);return;}
        if(whitetime->Enabled==true||blacktime->Enabled==true)
        {
        whitetime->Enabled = false;
        whitetime->Interval = 0;
        blacktime->Enabled = false;
        blacktime->Interval = 0;
        return;
        }
        if(etap_ruchu==1 && whitetime->Enabled==false && blacktime->Enabled==false)
        {
         whitetime->Enabled=true;
         whitetime->Interval = 1000;
         return;
        }
        if(etap_ruchu==3 && whitetime->Enabled==false && blacktime->Enabled==false)
        {
         blacktime->Enabled=true;
         blacktime->Interval=1000;
         return;
        }} */

}
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if(zdejmowanie==true&&(Key=='x'||Key=='X')){zdejmowanie=false;endmove->Caption="Zdejmij zbite figury->OFF Nacisnij X";}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (wynik == false && posuniecie!=0) {
    if(Application->MessageBoxA("czy na pewno zakonczyc partiê z nierostrzygniêtym wynikiem?","Potwierdz",
   MB_YESNO | MB_ICONQUESTION) == IDNO)
   {
    Action=caNone;
   }

   plik << "Partia nieroztrzygniêta"; }
    plik<<endl;
    plik<<endl;
    plik.close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zasadygry1Click(TObject *Sender)
{
ShellExecute(NULL, "open", "https://pl.wikipedia.org/wiki/Warcaby", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zapispartii1Click(TObject *Sender)
{
Form2->ShowModal();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::White_resingClick(TObject *Sender)
{
    Zapispartii1->Enabled=false;
    Wynik->Caption = "Wygrana czerwonych";
    draw->Enabled = false;
    endmove->Enabled = false;
    newgame->Enabled = true;
    newgame->Cursor = crHandPoint;
    startgame->Enabled = false;

    blacktime->Enabled = false;
    whitetime->Enabled = false;
    timewhite->Caption = "00:00:00";
    whitetime->Enabled = false;
    timeblack->Caption = "00:00:00";
    blacktime->Enabled = false;
    Application->MessageBoxA("Czerwone wygrywaja", "Koniec partii", MB_OK);
    White_resing->Enabled=false;
    Red_resing->Enabled=false;


    a1->Enabled = false;  a3->Enabled = false;  a5->Enabled = false;  a7->Enabled = false;    b2->Enabled = false;  b4->Enabled = false;  b6->Enabled = false;  b8->Enabled = false;
    c1->Enabled = false;  c3->Enabled = false;  c5->Enabled = false;  c7->Enabled = false;    d2->Enabled = false;  d4->Enabled = false;  d6->Enabled = false;  d8->Enabled = false;
    e1->Enabled = false;  e3->Enabled = false;  e5->Enabled = false;  e7->Enabled = false;    f2->Enabled = false;  f4->Enabled = false;  f6->Enabled = false;  f8->Enabled = false;
    g1->Enabled = false;  g3->Enabled = false;  g5->Enabled = false;  g7->Enabled = false;    h2->Enabled = false;  h4->Enabled = false;  h6->Enabled = false;  h8->Enabled = false;

    plik << " 0-1" << endl;
    wynik = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Red_resingClick(TObject *Sender)
{
    Zapispartii1->Enabled=false;
    Wynik->Caption = "Wygrana bialych";
    draw->Enabled = false;
    endmove->Enabled = false;
    newgame->Enabled = true;
    newgame->Cursor = crHandPoint;
    startgame->Enabled = false;


    blacktime->Enabled = false;
    whitetime->Enabled = false;
    timewhite->Caption = "00:00:00";
    whitetime->Enabled = false;
    timeblack->Caption = "00:00:00";
    blacktime->Enabled = false;
    Application->MessageBoxA("Bia³e wygrywaja!", "Koniec partii", MB_OK);
    White_resing->Enabled=false;
    Red_resing->Enabled=false;

    a1->Enabled = false;  a3->Enabled = false;  a5->Enabled = false;  a7->Enabled = false;    b2->Enabled = false;  b4->Enabled = false;  b6->Enabled = false;  b8->Enabled = false;
    c1->Enabled = false;  c3->Enabled = false;  c5->Enabled = false;  c7->Enabled = false;    d2->Enabled = false;  d4->Enabled = false;  d6->Enabled = false;  d8->Enabled = false;
    e1->Enabled = false;  e3->Enabled = false;  e5->Enabled = false;  e7->Enabled = false;    f2->Enabled = false;  f4->Enabled = false;  f6->Enabled = false;  f8->Enabled = false;
    g1->Enabled = false;  g3->Enabled = false;  g5->Enabled = false;  g7->Enabled = false;    h2->Enabled = false;  h4->Enabled = false;  h6->Enabled = false;  h8->Enabled = false;

    plik << " 1-0" << endl;
    wynik = true;
  
}
//--------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key=='x'||Key=='X')
{
        if(zdejmowanie==false){zdejmowanie=true;endmove->Caption="Zdejmij zbite figury->ON Nacisnij X";}
        if(etap_ruchu==2 || etap_ruchu==4){Application->MessageBoxA("POSTAW PIONKA", "B£¥D", MB_OK);return;}
        if(whitetime->Enabled==true||blacktime->Enabled==true)
        {
        whitetime->Enabled = false;
        whitetime->Interval = 0;
        blacktime->Enabled = false;
        blacktime->Interval = 0;
        return;
        }
        if(etap_ruchu==1 && whitetime->Enabled==false && blacktime->Enabled==false)
        {
         whitetime->Enabled=true;
         whitetime->Interval = 1000;
         return;
        }
        if(etap_ruchu==3 && whitetime->Enabled==false && blacktime->Enabled==false)
        {
         blacktime->Enabled=true;
         blacktime->Interval=1000;
         return;
        }}
}
//---------------------------------------------------------------------------

