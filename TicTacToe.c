#include<stdio.h>
#include<stdlib.h>
int board[3][3];
void displayBoard();
void userTurn();
void comupterTurn();
int winnerCheck();
void playerOne();
void playerTwo();
int main()
{
    int i,j;
    int res=0,ch;
    int choice;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j]=0;
        }
    }
    printf("\n******* WELCOME TO TIC TAC TOE GAME *******\n");
    do
    {
        input:
        printf("ENTER\n1. PLAYER VS COMPUTER\n2. PLAYER VS PLAYER\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: while(res==0)
            {
                displayBoard();
                printf("\n");
                userTurn();
                res=winnerCheck();                
                if(res==0)
                {
                    comupterTurn();
                    res=winnerCheck();
                }
                printf("\n");
                if(res!=0)
                {
                    if(res==1)
                    {
                        printf("\nPLAYER WINS");
                    }
                    else if(res==-1)
                    {
                        printf("\nCOMPUTER WINS");
                    }
                    else if(res==2)
                    {
                        printf("\nGAME IS DRAW");
                    }
                }
            }
            break;
            case 2: while(res==0)
            {
                displayBoard();
                printf("\n");
                playerOne();
                res=winnerCheck();
                displayBoard();
                printf("\n");
                if(res==0)
                {
                    playerTwo();
                    res=winnerCheck();
                }
                printf("\n");
                if(res!=0)
                {
                    if(res==1)
                    {
                        printf("\nPLAYER 1 WINS");
                    }
                    else if(res==-1)
                    {
                        printf("\nPLAYER 2 WINS");
                    }
                    else if(res==2)
                    {
                        printf("\nGAME IS DRAW");
                    }
                }
            }
            break;
            default:printf("PLEASE ENTER A VALID CHOICE\n");
            goto input;
        }
        printf("\nDO YOU WANT TO PLAY AGAIN?\n");
        printf("PRESS 1 FOR ANOTHER GAME\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            res=0;
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    board[i][j]=0;
                }            
            }
            displayBoard();            
        }
        else
        {
            printf("\nTHANK YOU FOR PLAYING\n");
            break;
        }
    }while(choice==1);
    return 0;
}
void displayBoard()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        printf("       |       |       \n");
        for(j=0;j<3;j++)
        {
            if(board[i][j]==1)
            {
                printf("   X   ");
            }
            if(board[i][j]==-1)
            {
                printf("   O   ");
            }
            if(board[i][j]==0)
            {
                printf("       ");
            }
            if(j!=2)
            {
                printf("|");
            }
        }
        if(i!=2)
        {
            printf("\n_______|_______|_______\n");
        }
        else
        {
            printf("\n       |       |       \n");
        }
    }
}
void userTurn()
{
    int row,col;
    while(1)
    {
        while(1)
        {
            printf("\nENTER A ROW: ");
            scanf("%d",&row);
            if(row<=3 && row >=1)
            {
                break;
            }                
            else
            {
                printf("\nENTER A VALID ROW NUMBER");
            }                            
        }
        while(1)
        {
            printf("\nENTER A COLUMN: ");
            scanf("%d",&col);
            if(col<=3 && col >=1)
            {
                break;
            }                
            else
            {
                printf("\nENTER A VALID COLUMN");
            }                
        }
        if(board[row-1][col-1]!=0)
        {
            printf("\nSQUARE ALREADY OCCUPIED, SELECT ANOTHER SQUARE");
        }
        else
        {
            board[row-1][col-1]=1;
            break;
        }
    }
}
void comupterTurn()
{
    //Checking if there are already 2 O's in the row, column or diagonals, if yes, computer chooses the empty square
    int i,j,sum;
    for(i=0;i<3;i++)//Checking the condition for a row
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=board[i][j];
        }
        if(sum==-2)
        {
            for(j=0;j<3;j++)
            {
                if(board[i][j]==0)
                {
                    board[i][j]=-1;
                    return;
                }
            }
        }
    }
    for(i=0;i<3;i++)//Checking the condition for column
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=board[j][i];
        }
        if(sum==-2)
        {
            for(j=0;j<3;j++)
            {
                if(board[j][i]==0)
                {
                    board[j][i]=-1;
                    return;
                }
            }
        }
    }
    sum=0;//Checking the condition for one diagonal
    for(i=0;i<3;i++)
    {
        sum+=board[i][i];
    }
    if(sum==-2)
    {
        for(i=0;i<3;i++)
        {
            if(board[i][i]==0)
            {
                board[i][i]=-1;
                return;
            }
        }
    }
    sum=0;
    j=2;
    for(i=0;i<3;i++)//Checking the condition for another diagonal
    {
        sum+=board[i][j];
        j--;
    }
    if(sum==-2)
    {
        j=2;
        for(i=0;i<3;i++)
        {
            if(board[i][j]==0)
            {
                board[i][j]=-1;
                return;
            }
            j--;
        }
    }
    //Checking if there are already 2 X's in the row, column or diagonals, if yes, computer chooses the empty square
    for(i=0;i<3;i++)//Checking the condtion for row
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=board[i][j];
        }
        if(sum==2)
        {
            for(j=0;j<3;j++)
            {
                if(board[i][j]==0)
                {
                    board[i][j]=-1;
                    return;
                }
            }
        }
    }
    for(i=0;i<3;i++)//Checking the condition for column
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=board[j][i];
        }
        if(sum==2)
        {
            for(j=0;j<3;j++)
            {
                if(board[j][i]==0)
                {
                    board[j][i]=-1;
                    return;
                }
            }
        }
    }
    sum=0;
    for(i=0;i<3;i++)//Checking the condition for one diagonal
    {
        sum+=board[i][i];
    }
    if(sum==2)
    {
        for(i=0;i<3;i++)
        {
            if(board[i][i]==0)
            {
                board[i][i]=-1;
                return;
            }
        }
    }
    sum=0;
    j=2;
    for(i=0;i<3;i++)//Checking the conditon for another diagonal
    {
        sum+=board[i][j];
        j--;
    }
    if(sum==2)
    {
        j=2;
        for(i=0;i<3;i++)
        {
            if(board[i][j]==0)
            {
                board[i][j]=-1;
                return;
            }
            j--;
        }
    }
    //Checking if there is already 1 O in the row column or diagonal, if yes, computer chooses the empty square
     for(i=0;i<3;i++)//Checking the condtion for row
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=board[i][j];
        }
        if(sum==-1)
        {
            for(j=0;j<3;j++)
            {
                if(board[i][j]==0)
                {
                    board[i][j]=-1;
                    return;
                }
            }
        }
    }
    for(i=0;i<3;i++)//Checking the condition for column
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=board[j][i];
        }
        if(sum==-1)
        {
            for(j=0;j<3;j++)
            {
                if(board[j][i]==0)
                {
                    board[j][i]=-1;
                    return;
                }
            }
        }
    }
    sum=0;
    for(i=0;i<3;i++)//Checking the condition for one diagonal
    {
        sum+=board[i][i];
    }
    if(sum==-1)
    {
        for(i=0;i<3;i++)
        {
            if(board[i][i]==0)
            {
                board[i][i]=-1;
                return;
            }
        }
    }
    sum=0;
    j=2;
    for(i=0;i<3;i++)//Checking the conditon for another diagonal
    {
        sum+=board[i][j];
        j--;
    }
    if(sum==-1)
    {
        j=2;
        for(i=0;i<3;i++)
        {
            if(board[i][j]==0)
            {
                board[i][j]=-1;
                return;
            }
            j--;
        }
    }
    //Checking for available empty squares, if yes, computer chooses the square
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==0)
            {
                board[i][j]=-1;
                return;
            }
        }
    }
}
int winnerCheck()
{
    /*We check sum of each row, column and the diagonals
    If the sum is 3, user has won. If the sum is -3, computer has won*/
    int i,j,sum;
    for(i=0;i<3;i++)//Checking the condition in rows
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=board[i][j];
        }
        if(sum==3)
        {
            return 1;
        }
        if(sum==-3)
        {
            return -1;
        }
    }
    for(i=0;i<3;i++)//Checking the condition in columns
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=board[j][i];
        }
        if(sum==3)
        {
            return 1;
        }
        if(sum==-3)
        {
            return -1;
        }
    }
    sum=0;
    for(i=0;i<3;i++)//Checking the condition for one diagonal
    {
        sum+=board[i][i];
        if(sum==3)
        {
            return 1;
        }
        if(sum==-3)
        {
            return -1;
        }
    }
    sum=0;
    j=2;
    for(i=0;i<3;i++)//Checking the condition for another diagonal
    {
        sum+=board[i][j];
        if(sum==3)
        {
            return 1;
        }
        if(sum==-3)
        {
            return -1;
        }
        j--;
    }
    //Checking for draw condition(No free spaces and no winner)
    for(i=0;i<3;i++)//This loop checks for empty squares, if found returns 0
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==0)
            {
                return 0;
            }
        }
    }
    return 2;//If no squares are empty returns 2, indicating draw condition
}
void playerOne()
{
    int row,col;
    while(1)
    {
        while(1)
        {
            printf("\nPLAYER ONE'S TURN\nENTER A ROW: ");
            scanf("%d",&row);
            if(row<=3 && row >=1)
            {
                break;
            }                
            else
            {
                printf("\nENTER A VALID ROW NUMBER");
            }                            
        }
        while(1)
        {
            printf("\nENTER A COLUMN: ");
            scanf("%d",&col);
            if(col<=3 && col >=1)
            {
                break;
            }                
            else
            {
                printf("\nENTER A VALID COLUMN NUMBER");
            }                
        }
        if(board[row-1][col-1]!=0)
        {
            printf("\nSQUARE ALREADY OCCUPIED, SELECT ANOTHER SQUARE");
        }
        else
        {
            board[row-1][col-1]=1;
            break;
        }
    }
}
void playerTwo()
{
    int row,col;
    while(1)
    {
        while(1)
        {
            printf("\nPLAYER TWO'S TURN\nENTER A ROW: ");
            scanf("%d",&row);
            if(row<=3 && row >=1)
            {
                break;
            }                
            else
            {
                printf("\nENTER A VALID ROW NUMBER");
            }                            
        }
        while(1)
        {
            printf("\nENTER A COLUMN: ");
            scanf("%d",&col);
            if(col<=3 && col >=1)
            {
                break;
            }                
            else
            {
                printf("\nENTER A VALID COLUMN NUMBER");
            }                
        }
        if(board[row-1][col-1]!=0)
        {
            printf("\nSQUARE ALREADY OCCUPIED, SELECT ANOTHER SQUARE");
        }
        else
        {
            board[row-1][col-1]=-1;
            break;
        }
    }
}