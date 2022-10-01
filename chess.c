#include "chess.h"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// makra pre vycistenie konzoly a uspanie
#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#else
#include <unistd.h>
#define CLEAR_SCREEN() system("clear")
#define SLEEP(sleepMs) usleep(sleepMs * 1000)
#endif


// Definicia globalnej sachovnice
int chessboard[L][L];
char panak='a';
// Funkcia na vykreslenie sachovnice (pracuje s globalnou sachovnicou)
void print_chessboard(){
   // TODO: dokoncit funkciu na zobrazovanie aktualneho stavu sachovnice v konzole
   CLEAR_SCREEN();
   char p='a';
   int o=8;
   printf("            CIERNY\n\n");
   for (int r=0; r<9;r++)
   {
       for(int c=0;c<9;c++)
       {
           if (c==0)
           {
               if (r==8)
               {
                   printf("   ");
               }
               else
               {
                  printf(" %i ",o);
                  o--;
               }


           }

           else if(r==8)
           {

               //for(p = 'a'; p <= 'h'; ++p)
                    printf(" %c ", p);
                     p=p+1;


           }
           else
           {
             printf("[%c]",(chessboard[r][c]));
           }

       }
       printf("\n");
   }

printf("\n            BIELY\n\n");
}

// Funkcia na pociatocne rozostavenie figurok na sachovnici
void init_chessboard()
{
    // TODO: dokoncit funkciu na pociatocne rozostavenie figurok na sachovnici
    for(int i=1; i<9;i++)
    {
        for(int j =1; j<9;j++)
        {
            if(i==1)
            {
                chessboard[i][j]=B_PAWN;
            }
            else if(i==6)
            {
                chessboard[i][j]=W_PAWN;
            }
            else if (i!=7 || 1 !=0 || i != 1 || i!=6)
            {
                chessboard[i][j]=EMPTY_SQUARE;
            }
        }
    }

chessboard[0][1]=B_ROOK;
chessboard[0][2]=B_KNIGHT;
chessboard[0][3]=B_BISHOP;
chessboard[0][4]=B_QUEEN;
chessboard[0][5]=B_KING;
chessboard[0][6]=B_BISHOP;
chessboard[0][7]=B_KNIGHT;
chessboard[0][8]=B_ROOK;

chessboard[7][1]=W_ROOK;
chessboard[7][2]=W_KNIGHT;
chessboard[7][3]=W_BISHOP;
chessboard[7][4]=W_QUEEN;
chessboard[7][5]=W_KING;
chessboard[7][6]=W_BISHOP;
chessboard[7][7]=W_KNIGHT;
chessboard[7][8]=W_ROOK;


}


// Funkcia, ktora overi tah figurkou [srow,scol]-->[trow,tcol] a v pripade,
// ze je platny, tak ho aj zrealizuje.
//
// VSTUP:
//      srow - riadok povodneho policka
//      scol - stlpec povodneho policka
//      trow - riadok noveho policka
//      tcol - stlpec noveho policka
//      p_id - ID hraca (pozri chess.h)
//
// VYSTUP:
//      V pripade platneho/zrealizovaneho tahu funkcia vrati 1.
//      V pripade, ze bol tah neplatny funkcia vrati 0.

int checkmove(int srow, int scol, int trow, int tcol,int p_id)
{
    int x;
    int y;
    if (p_id%2!=0)
    {
       if (chessboard[srow][scol]==B_PAWN)
       {
           return 0;
       }
       if (chessboard[srow][scol]==B_ROOK)
       {
           return 0;
       }
       if (chessboard[srow][scol]==B_KNIGHT)
       {
           return 0;
       }
       if (chessboard[srow][scol]==B_BISHOP)
       {
           return 0;
       }
       if (chessboard[srow][scol]==B_QUEEN)
       {
           return 0;
       }
       if (chessboard[srow][scol]==B_KING)
       {
           return 0;
       }
       if (chessboard[srow][scol]==EMPTY_SQUARE)
       {
           return 0;
       }
    }

    if (p_id%2==0)
    {
       if (chessboard[srow][scol]==W_PAWN)
       {
           return 0;
       }
       if (chessboard[srow][scol]==W_ROOK)
       {
           return 0;
       }
       if (chessboard[srow][scol]==W_KNIGHT)
       {
           return 0;
       }
       if (chessboard[srow][scol]==W_BISHOP)
       {
           return 0;
       }
       if (chessboard[srow][scol]==W_QUEEN)
       {
           return 0;
       }
       if (chessboard[srow][scol]==W_KING)
       {
           return 0;
       }
       if (chessboard[srow][scol]==EMPTY_SQUARE)
       {
           return 0;
       }
    }

    // biely
    if (chessboard[srow][scol]==W_PAWN)
    {
        if(trow<0 || trow>8)
        {
            return 0;
        }
        else if ((tcol==scol+1 && trow==srow-1) && chessboard[trow][tcol]!=EMPTY_SQUARE)
        {
           panak=W_PAWN;
            return 1;
        }
        else if ((tcol==scol-1 && trow==srow-1) && chessboard[trow][tcol]!=EMPTY_SQUARE)
        {
           panak=W_PAWN;
            return 1;
        }
        else if((trow<srow && tcol==scol) && chessboard[trow][tcol]!=EMPTY_SQUARE)
        {
            return 0;
        }
       else if((trow-srow==1 || trow-srow!=-1))
       {
           return 0;
       }

        else if(tcol-scol !=0)
        {
            return 0;
        }
        else
        {
            panak=W_PAWN;
            return 1;
        }
        }

    if (chessboard[srow][scol]==W_ROOK)
    {
      if (trow!=srow && tcol!=scol)
      {
          return 0;
      }

      else if(trow<0 || trow>8)
        {
            return 0;
        }
    else if(tcol<0 || tcol>8)
        {
            return 0;
        }
    else if (chessboard[trow][tcol]==W_PAWN || chessboard[trow][tcol]==W_KING || chessboard[trow][tcol]==W_QUEEN || chessboard[trow][tcol]==W_BISHOP || chessboard[trow][tcol]==W_ROOK ||chessboard[trow][tcol]==W_KNIGHT)
      {
          return 0;
      }
    else if (chessboard[trow][tcol]==B_PAWN || chessboard[trow][tcol]==B_KNIGHT || chessboard[trow][tcol]==B_ROOK || chessboard[trow][tcol]==B_BISHOP || chessboard[trow][tcol]==B_KING || chessboard[trow][tcol]==B_QUEEN)
        {
            panak=W_ROOK;
            return 1;
        }
    else if (tcol==scol && trow<srow )
        {
            x=srow;
            y=scol;
            while(x>trow)
            {
                x=x-1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=W_ROOK;
            return 1;
        }
        else
        {
            return 0;
        }
        }
     else if (tcol==scol && trow>srow )
        {
            x=srow;
            y=scol;
            while(x<trow)
            {
                x=x+1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=W_ROOK;
            return 1;
        }
        else
        {
            return 0;
        }
        }
     else if (tcol>scol && trow==srow )
        {
            x=srow;
            y=scol;
            while(y<tcol)
            {
                y=y+1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=W_ROOK;
            return 1;
        }
        else
        {
            return 0;
        }
        }
    else if (tcol<scol && trow==srow )
        {
            x=srow;
            y=scol;
            while(y>tcol)
            {
                y=y-1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=W_ROOK;
            return 1;
        }

        }
    else
    {
        return 1;
    }
    }

    if (chessboard[srow][scol]==W_BISHOP)
    {
      if (trow==srow || tcol==scol)
      {
          return 0;
      }
      else if (chessboard[trow][tcol]==W_PAWN || chessboard[trow][tcol]==W_KING || chessboard[trow][tcol]==W_QUEEN || chessboard[trow][tcol]==W_BISHOP || chessboard[trow][tcol]==W_ROOK ||chessboard[trow][tcol]==W_KNIGHT)
      {
          return 0;
      }
      else if (tcol>scol && chessboard[srow-1][scol+1]==W_PAWN)
      {
          return 0;
      }
      else if (tcol<scol && chessboard[srow-1][scol-1]==W_PAWN)
      {
          return 0;
      }
      else if(trow<0 || trow>8)
        {
            return 0;
        }
    else if(tcol<0 || tcol>8)
        {
            return 0;
        }
         else if (chessboard[trow][tcol]==B_PAWN || chessboard[trow][tcol]==B_KNIGHT || chessboard[trow][tcol]==B_ROOK || chessboard[trow][tcol]==B_BISHOP || chessboard[trow][tcol]==B_KING || chessboard[trow][tcol]==B_QUEEN)
        {
            panak=W_BISHOP;
            return 1;
        }
    else if(tcol<scol && trow<srow)
    {
        x=srow;
        y=scol;
        while (x>trow && y>tcol)
        {
            x=x-1;
            y=y-1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=W_BISHOP;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol>scol && trow<srow)
    {
        x=srow;
        y=scol;
        while (x>trow && y<tcol)
        {
            x=x-1;
            y=y+1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=W_BISHOP;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol<scol && trow>srow)
    {
        x=srow;
        y=scol;
        while (x<trow && y>tcol)
        {
            x=x+1;
            y=y-1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=W_BISHOP;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol>scol && trow>srow)
    {
        x=srow;
        y=scol;
        while (x<trow && y<tcol)
        {
            x=x+1;
            y=y+1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=W_BISHOP;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    }

    if (chessboard[srow][scol]==W_QUEEN)
    {
        if (trow==srow-2 && tcol==scol-1)
    {

        return 0;
    }
    else if (trow==srow-2 && tcol==scol+1)
    {

        return 0;
    }
    else if (trow==srow-1 && tcol==scol+2)
    {

        return 0;
    }
    else if (trow==srow+2 && tcol==scol+1)
    {

        return 0;
    }
    else if (chessboard[trow][tcol]==W_PAWN || chessboard[trow][tcol]==W_KING || chessboard[trow][tcol]==W_QUEEN || chessboard[trow][tcol]==W_BISHOP || chessboard[trow][tcol]==W_ROOK ||chessboard[trow][tcol]==W_KNIGHT)
      {
          return 0;
      }

     else if (chessboard[trow][tcol]==B_PAWN || chessboard[trow][tcol]==B_KNIGHT || chessboard[trow][tcol]==B_ROOK || chessboard[trow][tcol]==B_BISHOP || chessboard[trow][tcol]==B_KING || chessboard[trow][tcol]==B_QUEEN)
        {
            panak=W_QUEEN;
            return 1;
        }
      else if(tcol<scol && trow<srow)
    {
        x=srow;
        y=scol;
        while (x>trow && y>tcol)
        {
            x=x-1;
            y=y-1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=W_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol>scol && trow<srow)
    {
        x=srow;
        y=scol;
        while (x>trow && y<tcol)
        {
            x=x-1;
            y=y+1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=W_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol<scol && trow>srow)
    {
        x=srow;
        y=scol;
        while (x<trow && y>tcol)
        {
            x=x+1;
            y=y-1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=W_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol>scol && trow>srow)
    {
        x=srow;
        y=scol;
        while (x<trow && y<tcol)
        {
            x=x+1;
            y=y+1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=W_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
     else if (tcol==scol && trow<srow )
        {
            x=srow;
            y=scol;
            while(x>trow)
            {
                x=x-1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=W_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
        }
     else if (tcol==scol && trow>srow )
        {
            x=srow;
            y=scol;
            while(x<trow)
            {
                x=x+1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=W_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
        }
     else if (tcol>scol && trow==srow )
        {
            x=srow;
            y=scol;
            while(y<tcol)
            {
                y=y+1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=W_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
        }
    else if (tcol<scol && trow==srow )
        {
            x=srow;
            y=scol;
            while(y>tcol)
            {
                y=y-1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=W_QUEEN;
            return 1;
        }

        }


    }

     if (chessboard[srow][scol]==W_KING)
    {

    if((trow>srow+1 || tcol>scol+1 || trow<srow-1 || tcol<scol-1))
       {
           return 0;
       }
    else if(chessboard[trow][tcol]==W_PAWN || chessboard[trow][tcol]==W_KNIGHT || chessboard[trow][tcol]==W_ROOK || chessboard[trow][tcol]==W_BISHOP || chessboard[trow][tcol]==W_QUEEN)
    {
        return 0;
    }

    else if(trow<0 || trow>8)
        {
            return 0;
        }


    else if(tcol<0 || tcol>8)
        {
            return 0;
        }
        else
        {
            panak=W_KING;
            return 1;
        }
    }

    if (chessboard[srow][scol]==W_KNIGHT)
    {
    if (chessboard[trow][tcol]==W_PAWN || chessboard[trow][tcol]==W_KING || chessboard[trow][tcol]==W_QUEEN || chessboard[trow][tcol]==W_BISHOP || chessboard[trow][tcol]==W_ROOK ||chessboard[trow][tcol]==W_KNIGHT)
      {
          return 0;
      }
    if (trow==srow-2 && tcol==scol-1)
    {
        panak=W_KNIGHT;
        return 1;
    }
    if (trow==srow+2 && tcol==scol-1)
    {
        panak=W_KNIGHT;
        return 1;
    }
    else if (trow==srow-2 && tcol==scol+1)
    {
        panak=W_KNIGHT;
        return 1;
    }
    else if (trow==srow-1 && tcol==scol+2)
    {
        panak=W_KNIGHT;
        return 1;
    }
    else if (trow==srow+2 && tcol==scol+1)
    {
        panak=W_KNIGHT;
        return 1;
    }


        else
        {
            return 0;
        }
    }










    //cierny
    if (chessboard[srow][scol]==B_PAWN)
    {
        if(trow<0 || trow>8)
        {
            return 0;
        }
        else if ((tcol==scol+1 && trow==srow+1) && chessboard[trow][tcol]!=EMPTY_SQUARE)
        {
           panak=B_PAWN;
            return 1;
        }
        else if ((tcol==scol-1 && trow==srow+1) && chessboard[trow][tcol]!=EMPTY_SQUARE)
        {
           panak=B_PAWN;
            return 1;
        }
        else if((trow>srow && tcol==scol) && chessboard[trow][tcol]!=EMPTY_SQUARE)
        {
            return 0;
        }
       else if((trow-srow==-1 || trow-srow!=1))
       {
           return 0;
       }

        else if(tcol-scol !=0)
        {
            return 0;
        }
        else
        {
            panak=B_PAWN;
            return 1;
        }
        }

    if (chessboard[srow][scol]==B_ROOK)
    {
      if (trow!=srow && tcol!=scol)
      {
          return 0;
      }

      else if(trow<0 || trow>8)
        {
            return 0;
        }
    else if(tcol<0 || tcol>8)
        {
            return 0;
        }
    else if (chessboard[trow][tcol]==B_PAWN || chessboard[trow][tcol]==B_KNIGHT || chessboard[trow][tcol]==B_ROOK || chessboard[trow][tcol]==B_BISHOP || chessboard[trow][tcol]==B_KING || chessboard[trow][tcol]==B_QUEEN)
        {
            return 0;
        }
         else if (chessboard[trow][tcol]==W_PAWN || chessboard[trow][tcol]==W_KNIGHT || chessboard[trow][tcol]==W_ROOK || chessboard[trow][tcol]==W_BISHOP || chessboard[trow][tcol]==W_KING || chessboard[trow][tcol]==W_QUEEN)
        {
            panak=B_ROOK;
            return 1;
        }
    else if (tcol==scol && trow<srow )
        {
            x=srow;
            y=scol;
            while(x>trow)
            {
                x=x-1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=B_ROOK;
            return 1;
        }
        else
        {
            return 0;
        }
        }
     else if (tcol==scol && trow>srow )
        {
            x=srow;
            y=scol;
            while(x<trow)
            {
                x=x+1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=B_ROOK;
            return 1;
        }
        else
        {
            return 0;
        }
        }
     else if (tcol>scol && trow==srow )
        {
            x=srow;
            y=scol;
            while(y<tcol)
            {
                y=y+1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=B_ROOK;
            return 1;
        }
        else
        {
            return 0;
        }
        }
    else if (tcol<scol && trow==srow )
        {
            x=srow;
            y=scol;
            while(y>tcol)
            {
                y=y-1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=B_ROOK;
            return 1;
        }

        }
        else
        {
            panak=B_ROOK;
            return 1;
        }
    }

    if (chessboard[srow][scol]==B_BISHOP)
    {
      if (trow==srow || tcol==scol)
      {
          return 0;
      }
      else if (chessboard[trow][tcol]==B_PAWN || chessboard[trow][tcol]==B_KING || chessboard[trow][tcol]==B_QUEEN || chessboard[trow][tcol]==B_BISHOP || chessboard[trow][tcol]==B_ROOK ||chessboard[trow][tcol]==B_KNIGHT)
      {
          return 0;
      }
      else if (tcol>scol && chessboard[srow+1][scol+1]==B_PAWN)
      {
          return 0;
      }
      else if (tcol<scol && chessboard[srow+1][scol-1]==B_PAWN)
      {
          return 0;
      }
      else if(trow<0 || trow>8)
        {
            return 0;
        }
    else if(tcol<0 || tcol>8)
        {
            return 0;
        }
        else if (chessboard[trow][tcol]==W_PAWN || chessboard[trow][tcol]==W_KNIGHT || chessboard[trow][tcol]==W_ROOK || chessboard[trow][tcol]==W_BISHOP || chessboard[trow][tcol]==W_KING || chessboard[trow][tcol]==W_QUEEN)
        {
            panak=B_BISHOP;
            return 1;
        }
        else if(tcol<scol && trow<srow)
    {
        x=srow;
        y=scol;
        while (x>trow && y>tcol)
        {
            x=x-1;
            y=y-1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=B_BISHOP;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol>scol && trow<srow)
    {
        x=srow;
        y=scol;
        while (x>trow && y<tcol)
        {
            x=x-1;
            y=y+1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=B_BISHOP;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol<scol && trow>srow)
    {
        x=srow;
        y=scol;
        while (x<trow && y>tcol)
        {
            x=x+1;
            y=y-1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=B_BISHOP;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol>scol && trow>srow)
    {
        x=srow;
        y=scol;
        while (x<trow && y<tcol)
        {
            x=x+1;
            y=y+1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=B_BISHOP;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    }

    if (chessboard[srow][scol]==B_QUEEN)
    {
        if (trow==srow-2 && tcol==scol-1)
    {

        return 0;
    }
    else if (trow==srow-2 && tcol==scol+1)
    {

        return 0;
    }
    else if (trow==srow-1 && tcol==scol+2)
    {

        return 0;
    }
    else if (trow==srow+2 && tcol==scol+1)
    {

        return 0;
    }
    else if (chessboard[trow][tcol]==B_PAWN || chessboard[trow][tcol]==B_KNIGHT || chessboard[trow][tcol]==B_ROOK || chessboard[trow][tcol]==B_BISHOP || chessboard[trow][tcol]==B_KING || chessboard[trow][tcol]==B_QUEEN)
        {
            return 0;
        }
    else if (chessboard[trow][tcol]==W_PAWN || chessboard[trow][tcol]==W_KNIGHT || chessboard[trow][tcol]==W_ROOK || chessboard[trow][tcol]==W_BISHOP || chessboard[trow][tcol]==W_KING || chessboard[trow][tcol]==W_QUEEN)
        {
            panak=B_QUEEN;
            return 1;
        }

      else if(tcol<scol && trow<srow)
    {
        x=srow;
        y=scol;
        while (x>trow && y>tcol)
        {
            x=x-1;
            y=y-1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=B_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol>scol && trow<srow)
    {
        x=srow;
        y=scol;
        while (x>trow && y<tcol)
        {
            x=x-1;
            y=y+1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=B_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol<scol && trow>srow)
    {
        x=srow;
        y=scol;
        while (x<trow && y>tcol)
        {
            x=x+1;
            y=y-1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=B_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(tcol>scol && trow>srow)
    {
        x=srow;
        y=scol;
        while (x<trow && y<tcol)
        {
            x=x+1;
            y=y+1;
            if (chessboard[x][y]!=EMPTY_SQUARE)
            {
                return 0;
            }
        }
        if (x==trow && y==tcol)
        {
            panak=B_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
     else if (tcol==scol && trow<srow )
        {
            x=srow;
            y=scol;
            while(x>trow)
            {
                x=x-1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=B_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
        }
     else if (tcol==scol && trow>srow )
        {
            x=srow;
            y=scol;
            while(x<trow)
            {
                x=x+1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=B_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
        }
     else if (tcol>scol && trow==srow )
        {
            x=srow;
            y=scol;
            while(y<tcol)
            {
                y=y+1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=B_QUEEN;
            return 1;
        }
        else
        {
            return 0;
        }
        }
    else if (tcol<scol && trow==srow )
        {
            x=srow;
            y=scol;
            while(y>tcol)
            {
                y=y-1;
                if (chessboard[x][y]!=EMPTY_SQUARE)
                {
                    return 0;
                }
            }
            if (x==trow && y==tcol)
        {
            panak=B_QUEEN;
            return 1;
        }

        }
    }





     if (chessboard[srow][scol]==B_KING)
    {

    if((trow>srow+1 || tcol>scol+1 || trow<srow-1 || tcol<scol-1))
       {
           return 0;
       }
    else if(chessboard[trow][tcol]==B_PAWN || chessboard[trow][tcol]==B_KNIGHT || chessboard[trow][tcol]==B_ROOK || chessboard[trow][tcol]==B_BISHOP || chessboard[trow][tcol]==B_QUEEN)
    {
        return 0;
    }
    else if(trow<0 || trow>8)
        {
            return 0;
        }


    else if(tcol<0 || tcol>8)
        {
            return 0;
        }
        else
        {
            panak=B_KING;
            return 1;
        }
    }

    if (chessboard[srow][scol]==B_KNIGHT)
    {
    if (chessboard[trow][tcol]==B_PAWN || chessboard[trow][tcol]==B_KING || chessboard[trow][tcol]==B_QUEEN || chessboard[trow][tcol]==B_BISHOP || chessboard[trow][tcol]==B_ROOK ||chessboard[trow][tcol]==B_KNIGHT)
      {
          return 0;
      }
    else if (trow==srow-2 && tcol==scol-1) //toto je asi bullshit (aj pri bielom)
    {
        panak=B_KNIGHT;
        return 1;
    }
    else if (trow==srow+2 && tcol==scol-1)
    {
        panak=B_KNIGHT;
        return 1;
    }
    else if (trow==srow-2 && tcol==scol+1)
    {
        panak=B_KNIGHT;
        return 1;
    }
    else if (trow==srow-1 && tcol==scol+2)
    {
        panak=B_KNIGHT;
        return 1;
    }
    else if (trow==srow+2 && tcol==scol+1)
    {
        panak=B_KNIGHT;
        return 1;
    }


        else
        {
            return 0;
        }
    }








    }


int move(int srow, int scol, int trow, int tcol, int p_id)
{
    if (checkmove(srow, scol, trow, tcol,p_id)==1)
    {
        chessboard[trow][tcol]=panak;
        chessboard[srow][scol]=EMPTY_SQUARE;
    }
    // TODO: dokoncit funkciu na overenie a realizaciu tahu figurkou
    // Rady:
    //  1. Najprv skontrolujte vsetky dolezite podmienky pre platnost tahu:
    //       * su suradnice policok mimo sachovnice?
    //       * nachadza sa policku [srow,scol] figurka?
    //       * patri naozaj vybrana figurka na policku [srow,scol] hracovi p_id?
    //       * plati, ze [srow,scol] != [trow,tcol]?
    //       * je policko [srow,scol] platnym tahom figurky daneho typu?
    //       * ine ...
    //
    //  2. V pripade, ze su podmienky platnosti tahu splnene, zrealizujte tah, t.j.
    //     posunte figurku z policka [srow,scol] na [trow,tcol].
    //
    //  Pozn. 1 nezabudajte, ze figurka moze brat ine figurky protihraca.
    //  Pozn. 2 neimplementujte celu logiku v tejto funkcii, ale volajte z nej
    //        dalsie pomocne funkcie.

    return 0; // tento riadok je tu len kvoli kompilacii
}


