#include<bits/stdc++.h>
using namespace std;
class game
{
    int board[4][4];
    int i1,i2;
    int score;
public:
    game()
    {
        score=0;
    }
    void display();
    void initialise();
    int check_gen_val_on_right_position(int,int);
    void value_gen_board();
    void instruction();
    int index_gen(int );
    int game_start();
    void move_left();
    void move_leftsum();
    void move_right();
    void move_rightsum();
    void move_up();
    void move_upsum();
    void move_down();
    void move_downsum();
};
int game :: index_gen(int x)
{
    return rand()%x;
}
int game :: check_gen_val_on_right_position(int i1,int i2)
{
    int flag=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[i1][i2]==0)
            {
                board[i1][i2]=2;
                flag=1;
            }
        }
    }
    return flag;
}
void game :: value_gen_board()
{
    game g;
    i1=g.index_gen(4);
    i2=g.index_gen(4);
    int flag=check_gen_val_on_right_position(i1,i2);
    while(flag==0)
    {
        i1=g.index_gen(4);
        i2=g.index_gen(4);
        flag=check_gen_val_on_right_position(i1,i2);
    }
    int i3=g.index_gen(4);
    int i4=g.index_gen(4);
    while(i1==i3 && i2==i4)
    {
        i3=g.index_gen(4);
        i4=g.index_gen(4);
    }
    flag=check_gen_val_on_right_position(i3,i4);
    while(flag==0)
    {
        i3=g.index_gen(4);
        i4=g.index_gen(4);
        flag=check_gen_val_on_right_position(i3,i4);
    }
    board[i3][i4]=2;
}
void game::initialise()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            board[i][j]=0;
    }
    value_gen_board();
}
void game::display()
{
    cout<<"\t\t\t\t  2048 GAME"<<endl<<endl<<endl;
    cout<<"\t\t\t\t SCORE = "<<score<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"\t\t    |";
        for(int j=0;j<4;j++)
        {
            cout<<"    "<<board[i][j]<<"    |";
        }
        cout<<endl<<endl;
        cout<<"\t\t    "<<"-----------------------------------------"<<endl<<endl;
    }
}
void game :: move_left()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[i][j]!=0)
            {
                for(int k=j-1;k>=0;k--)
                {
                    if(board[i][k]==0)
                    {
                        board[i][k]=board[i][k+1];
                        board[i][k+1]=0;
                    }
                    else
                        break;
                }
            }
        }
    }
}
void game::move_leftsum()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[i][j]!=0)
            {
                if(board[i][j]==board[i][j+1])
                {
                    board[i][j]+=board[i][j+1];
                    score+=board[i][j];
                    board[i][j+1]=0;
                }
            }
        }
    }
}
void game :: move_right()
{
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            if(board[i][j]!=0)
            {
                for(int k=j+1;k<4;k++)
                {
                    if(board[i][k]==0)
                    {
                        board[i][k]=board[i][k-1];
                        board[i][k-1]=0;
                    }
                    else
                        break;
                }
            }
        }
    }
}
void game::move_rightsum()
{
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            if(board[i][j]!=0)
            {
                if(board[i][j]==board[i][j-1])
                {
                    board[i][j]+=board[i][j-1];
                    score+=board[i][j];
                    board[i][j-1]=0;
                }
            }
        }
    }
}
void game :: move_up()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[j][i]!=0)
            {
                for(int k=j-1;k>=0;k--)
                {
                    if(board[k][i]==0)
                    {
                        board[k][i]=board[k+1][i];
                        board[k+1][i]=0;
                    }
                    else
                        break;
                }
            }
        }
    }
}
void game::move_upsum()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(board[j][i]!=0)
            {
                if(board[j][i]==board[j+1][i])
                {
                    board[j][i]+=board[j+1][i];
                    score+=board[j][i];
                    board[j+1][i]=0;
                }
            }
        }
    }
}
void game :: move_down()
{
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            if(board[j][i]!=0)
            {
                for(int k=j+1;k<4;k++)
                {
                    if(board[k][i]==0)
                    {
                        board[k][i]=board[k-1][i];
                        board[k-1][i]=0;
                    }
                    else
                        break;
                }
            }
        }
    }
}
void game::move_downsum()
{
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
        {
            if(board[j][i]!=0)
            {
                if(board[j][i]==board[j-1][i])
                {
                    board[j][i]+=board[j-1][i];
                    score+=board[j][i];
                    board[j-1][i]=0;
                }
            }
        }
    }
}
int game::game_start()
{
    cout<<"\tenter  i->instruction about game"<<endl;
    char ch;
    cin>>ch;
    if(ch=='i')
    {
        cout<<"\t enter a->move left"<<endl;
        cout<<"\t enter d->move right"<<endl;
        cout<<"\t enter w->move up"<<endl;
        cout<<"\t enter s->move down"<<endl;
    }
    char choice;
    cin>>choice;
    while(choice=='a'||choice=='s'||choice=='d'||choice=='w')
    {
        switch(choice)
        {
        case 'a':
            move_left();
            move_leftsum();
            move_left();
            value_gen_board();
            display();
            break;
        case 'd':
            move_right();
            move_rightsum();
            move_right();
            value_gen_board();
            display();
            break;
        case 'w':
            move_up();
            move_upsum();
            move_up();
            value_gen_board();
            display();
            break;
        case 's':
            move_down();
            move_downsum();
            move_down();
            value_gen_board();
            display();
            break;
        }

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(board[i][j]==2048)
                {
                    cout<<"\t\t\t\t !!!! you are the winner of game!!!!";
                    return 0;
                }
            }
        }
        cout<<"enter choice"<<endl;
        cin>>choice;
    }
    return 0;
}
int main()
{
    game g;
    srand(time(0));
    g.initialise();
    g.display();
    int k=g.game_start();
    return k;
}
