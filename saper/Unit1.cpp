//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include<time.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
bool game_over=0;
int miny=10;
int zostalo=miny;
int ile=0;
class Pole
{
public:
        bool mina;
        bool spotted;
        bool odkryte;
        int liczba;

};

AnsiString sekundy;
int sek=0;

bool spoty[64];
Pole tab[8][8];
TImage *Images[64];
bool spotornot=0;

void __fastcall TForm1::uzu()
{
        Images[0] = Image1;
        Images[1] = Image2;
        Images[2] = Image3;
        Images[3] = Image4;
        Images[4] = Image5;
        Images[5] = Image6;
        Images[6] = Image7;
        Images[7] = Image8;
        Images[8] = Image9;
        Images[9] = Image10;
        Images[10] = Image11;
        Images[11] = Image12;
        Images[12] = Image13;
        Images[13] = Image14;
        Images[14] = Image15;
        Images[15] = Image16;
        Images[16] = Image17;
        Images[17] = Image18;
        Images[18] = Image19;
        Images[19] = Image20;
        Images[20] = Image21;
        Images[21] = Image22;
        Images[22] = Image23;
        Images[23] = Image24;
        Images[24] = Image25;
        Images[25] = Image26;
        Images[26] = Image27;
        Images[27] = Image28;
        Images[28] = Image29;
        Images[29] = Image30;
        Images[30] = Image31;
        Images[31] = Image32;
        Images[32] = Image33;
        Images[33] = Image34;
        Images[34] = Image35;
        Images[35] = Image36;
        Images[36] = Image37;
        Images[37] = Image38;
        Images[38] = Image39;
        Images[39] = Image40;
        Images[40] = Image41;
        Images[41] = Image42;
        Images[42] = Image43;
        Images[43] = Image44;
        Images[44] = Image45;
        Images[45] = Image46;
        Images[46] = Image47;
        Images[47] = Image48;
        Images[48] = Image49;
        Images[49] = Image50;
        Images[50] = Image51;
        Images[51] = Image52;
        Images[52] = Image53;
        Images[53] = Image54;
        Images[54] = Image55;
        Images[55] = Image56;
        Images[56] = Image57;
        Images[57] = Image58;
        Images[58] = Image59;
        Images[59] = Image60;
        Images[60] = Image61;
        Images[61] = Image62;
        Images[62] = Image63;
        Images[63] = Image64;
}

//-----------------------------------------------------------------------------
void zaminuj()
{
        srand( time( NULL ) );
        for(int i=0;i<miny;i++)
        {
                int li=rand()%8;
                int a=li;
                li=rand()%8;
                int b=li;
                if(tab[a][b].mina==1)
                {
                        i--;
                }
                else
                {
                        tab[a][b].mina=1;
                }
        }

        for(int i=0;i<8;i++)
        {
                for(int j=0;j<8;j++)
                {
                        if(tab[i][j].mina==1)
                        {
                             int a=i;
                             int b=j;
                                if(((a-1)>=0) && ((a-1)<8) && ((b-1)>=0) && ((b-1)<8)) tab[a-1][b-1].liczba++;
                                if(((a-1)>=0) && ((a-1)<8) && ((b)>=0) && ((b)<8)) tab[a-1][b].liczba++;
                                if(((a-1)>=0) && ((a-1)<8) && ((b+1)>=0) && ((b+1)<8)) tab[a-1][b+1].liczba++;
                                if(((a)>=0) && ((a)<8) && ((b-1)>=0) && ((b-1)<8)) tab[a][b-1].liczba++;
                                if(((a)>=0) && ((a)<8) && ((b+1)>=0) && ((b+1)<8)) tab[a][b+1].liczba++;
                                if(((a+1)>=0) && ((a+1)<8) && ((b-1)>=0) && ((b-1)<8)) tab[a+1][b-1].liczba++;
                                if(((a+1)>=0) && ((a+1)<8) && ((b)>=0) && ((b)<8)) tab[a+1][b].liczba++;
                                if(((a+1)>=0) && ((a+1)<8) && ((b+1)>=0) && ((b+1)<8)) tab[a+1][b+1].liczba++;
                        }
                }
        }
}
//-----------------------------------------------------------------------------
void odkryj(TObject *Sender)
{
        TImage* cos=static_cast<TImage*>(Sender);

        int nr=cos->Tag;
        int a,b;
        a=(nr-1)/8;
        b=(nr-1)%8;
        tab[a][b].odkryte=1;
        if(game_over==1) cos->Picture->LoadFromFile("explo.bmp");
        else
        {
              if(tab[a][b].mina==1) cos->Picture->LoadFromFile("mina.bmp");
                else
                {
                       ile++;

                       if(tab[a][b].liczba==0) cos->Picture->LoadFromFile("puste.bmp");
                       else if(tab[a][b].liczba==1) cos->Picture->LoadFromFile("jeden.bmp");
                       else if(tab[a][b].liczba==2) cos->Picture->LoadFromFile("dwa.bmp");
                       else if(tab[a][b].liczba==3) cos->Picture->LoadFromFile("trzy.bmp");
                       else if(tab[a][b].liczba==4) cos->Picture->LoadFromFile("cztery.bmp");
                       else if(tab[a][b].liczba==5) cos->Picture->LoadFromFile("piec.bmp");
                       else if(tab[a][b].liczba==6) cos->Picture->LoadFromFile("szesc.bmp");
                       else if(tab[a][b].liczba==7) cos->Picture->LoadFromFile("siedem.bmp");
                       else if(tab[a][b].liczba==8) cos->Picture->LoadFromFile("osiem.bmp");
                }
        }
        
        

}
void __fastcall TForm1::pomoz(int ATag)
{
    for(int i = 0; i < 64; ++i)
    {
        int a,b;
        a=i/8;
        b=i%8;
        if (Images[i]->Tag == ATag && tab[a][b].mina==1)Images[i]->Picture->LoadFromFile("mina.bmp");
    }
}
void __fastcall TForm1::open_mines()
{
     for(int i=1;i<=64;i++)
     {
        pomoz(i);
     }
}
void __fastcall TForm1::FindImageByTag(int ATag)
{
    for(int i = 0; i < 64; ++i)
    {
        if (Images[i]->Tag == ATag)
            odkryj(Images[i]);
    }
}
TImage* __fastcall szukaj(int ATag)
{
    for(int i = 0; i < 64; ++i)
    {
        if (Images[i]->Tag == ATag) return Images[i];
    }
    return NULL;
}

void multi(int a, int b)
{
        if(!(a<0 || b<0 || a>7 || b>7))
        {
            if(tab[a][b].odkryte==0)
            {
               if(tab[a][b].liczba==0)
               {
                   tab[a][b].odkryte=1;
                   if((a-1)>=0 && (b-1)>=0)
                   {
                      if(tab[a-1][b-1].odkryte==0)multi(a-1,b-1);
                   }

                   if((a-1)>=0 && (b+1)<8)
                   {
                       if(tab[a-1][b+1].odkryte==0) multi(a-1,b+1);
                   }
                   
                   if((a-1)>=0)
                   {
                      if(tab[a-1][b].odkryte==0) multi(a-1,b);
                   }

                   if((b-1)>=0)
                   {
                       if(tab[a][b-1].odkryte==0) multi(a,b-1);
                   }

                   if((b+1)<8)
                   {
                       if(tab[a][b+1].odkryte==0) multi(a,b+1);
                   }

                   if((a+1)<8 && (b-1)>=0)
                   {
                       if(tab[a+1][b-1].odkryte==0) multi(a+1,b-1);
                   }
                   
                   if((a+1)<8)
                   {
                         if(tab[a+1][b].odkryte==0) multi(a+1,b);
                   }
                   
                   if((a+1)<8 && (b+1)<8)
                   {
                        if(tab[a+1][b+1].odkryte==0) multi(a+1,b+1);
                   }
               }
               else
               {
                        tab[a][b].odkryte=1;
               }
                
            }
        }
}

void __fastcall TForm1::restart()
{
        for(int i=0;i<64;i++) spoty[i]=0;
        zostalo=10;
        Label2->Caption="10";
        game_over=0;
        Image65->Picture->LoadFromFile("mandant.bmp");
        Timer1->Enabled=1;
        Timer2->Enabled=1;
        sek=0;
        zostalo=10;
        ile=0;
        for(int i=0;i<8;i++)
        {
             for(int j=0;j<8;j++)
             {
                tab[i][j].mina=0;
                tab[i][j].spotted=0;
                tab[i][j].odkryte=0;
                tab[i][j].liczba=0;
             }
        }
        TImage* img;
        for(int i=1;i<=64;i++)
        {
            img=szukaj(i);
            img->Picture->LoadFromFile("okno.bmp");
        }
        zaminuj();
        uzu();
}

void __fastcall TForm1::Image1Click(TObject *Sender)
{
     TImage* cos=static_cast<TImage*>(Sender);
     int nr=cos->Tag;
     int a,b;
     a=(nr-1)/8;
     b=(nr-1)%8;

     if(tab[a][b].mina==1)
     {
        
        Timer1->Enabled=0;
        Timer2->Enabled=0;
        open_mines();
        game_over=1;
        odkryj(Sender);
        Image65->Picture->LoadFromFile("martwy.bmp");
        Application->MessageBox("Przegra³eœ!","Przegrana!",MB_OK | MB_ICONWARNING);
        restart();

     }
     else if(tab[a][b].liczba!=0)
     {
         odkryj(Sender);
         if(ile>=54)
         {
                Timer1->Enabled=0;
                Timer2->Enabled=0;
             Image65->Picture->LoadFromFile("wygrana.bmp");
             Application->MessageBox("Wygra³eœ!","Wygrana!",MB_OK | MB_ICONWARNING);
             restart();
         }
          
     }
     else if(tab[a][b].odkryte==0)
     {
        int ite=0;
        multi(a,b);
        int pomo=ile;
        for(int i=0;i<8;i++)
        {
                for(int j=0;j<8;j++)
                {
                    ite++;
                    if(tab[i][j].odkryte==1) FindImageByTag(ite);
                }
        }
        ile-=pomo;
        if(ile>=54)
        {
                Timer1->Enabled=0;
                Timer2->Enabled=0;
             Image65->Picture->LoadFromFile("wygrana.bmp");
             Application->MessageBox("Wygrales!","Wygrana!",MB_OK | MB_ICONWARNING);
             restart();
        }
         
     }

     //Image65->Picture->LoadFromFile("mandant.bmp");
}

AnsiString ostatnie;
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        ostatnie=IntToStr(zostalo);
        Label2->Caption=ostatnie;
        zaminuj();
        uzu();
        sekundy=IntToStr(sek);
        Label1->Caption=sekundy;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
                TImage* abc=static_cast<TImage*>(Sender);
                int li=abc->Tag;
                int wie=(li-1)/8;
                int kol=(li-1)%8;
                if(tab[wie][kol].odkryte==0)
                {
                             int t=abc->Tag;
                        t--;
                        if(Button==mbRight && spoty[t]==0)
                        {
                                if(zostalo<1)
                                {
                                        zostalo--;
                                        Label2->Caption="0";
                                }
                                else
                                {
                                        zostalo--;
                                        ostatnie=IntToStr(zostalo);
                                        Label2->Caption=ostatnie;
                        }

                        TImage* cos=static_cast<TImage*>(Sender);
                        int be=cos->Tag;
                        int a=(be-1)/8;
                        int b=(be-1)%8;
                        if(tab[a][b].odkryte==0)
                        {
                                spoty[t]=1;
                                cos->Picture->LoadFromFile("spotted.bmp");
                        }

                         
                        }
                else if(Button==mbRight && spoty[t]==1)
                {
                        if(zostalo<0)
                        {
                            zostalo++;
                            Label2->Caption="0";
                        }
                        else
                        {
                            zostalo++;
                            ostatnie=IntToStr(zostalo);
                            Label2->Caption=ostatnie;
                        }

                        TImage* cos=static_cast<TImage*>(Sender);
                        int be=cos->Tag;
                        int a=(be-1)/8;
                        int b=(be-1)%8;
                        if(tab[a][b].odkryte==0)
                        {
                                spoty[t]=0;
                            cos->Picture->LoadFromFile("okno.bmp");
                        }
                }

                }
               

}
//---------------------------------------------------------------------------
bool jakie=0;
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        sekundy=IntToStr(sek);
        sek++;
        Label1->Caption=sekundy;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image65Click(TObject *Sender)
{
        restart();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
             if(jakie==0)
        {
             Image65->Picture->LoadFromFile("klik.bmp");
             jakie=1;
        }

        else
        {
            Image65->Picture->LoadFromFile("mandant.bmp");
            jakie=0;
        }

}
//---------------------------------------------------------------------------

