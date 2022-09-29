#include<iostream>
#include<string.h>
#include"header.h"
#include<fstream>
#include<ctime>
using namespace std;
/***LOGIN PAGE***/
void Login::user_login()
{
    int flag=0,counts=0;

    time_t settime = time(NULL);

    while (flag!=1)
    {
        cout<<"Enter the desired choice:\n";
            cout<<"Login \n";
            cout<<"Register(available only once per user)\n";
        getline(cin, choice);

        if (choice=="register"||choice=="Register"||choice=="REGISTER")
        {

            if(counts!=0)
            {
                cout<<"registered once.login to continue\n";
            }
            else
            {

            counts++;
            ofstream fp("Login_page.txt");
            if (!fp.is_open())
            {
                cout<<"could not open file\n";

            }
               cout <<"New Username: ";
            getline(cin, reg_name);
            cout<<"New Password: ";
            getline(cin, reg_password);
            fp<<reg_name;
            fp<<'\n';
            fp<<reg_password;
            fp.close();
            }
        }
        if (choice=="login"||choice=="Login"||choice=="LOGIN")
        {
            ifstream fp1("Login_page.txt");
            if (!fp1.is_open())
            {
                cout<<"could not open file\n";

            }
            getline(fp1, Name, '\n');
            getline(fp1, password, '\n');
            fp1.close();
            while (1)
            {

                cout<<"\n\n\n"
                    <<"Enter Username: ";
                getline(cin, Name1);
                cout<<"Enter Password: ";
                getline(cin, password1);
                if (Name1==Name && password1==password)
                {
                    cout<<"Login Successful\n";
                     cout   <<"Welcome, ";
                      cout  <<Name1<<endl;
                        flag=1;
                    break;
                }
                else
                {
                cout<<"incorrect name or password\n";
                ofstream fp2("incorrectlogin.txt",std::ios_base::app);
                fp2<<"\nAttempted User:"<<Name1;
                fp2<<"\n Used password:"<<password1;
                fp2<<"\nAttempted Time:"<<ctime(&settime);
                fp2<<"\n";
                fp2.close();

}
            }

        }
    }
}

/***DEFAULT CONSTRUCTOR***/
Team::Team()
{
    int i;
    for(i=0;i<12;i++)
    {
   strcpy(p_name[i],"player");
     p_run[i]=0;
    p_status[i]=0;
    p_ball[i]=0;
    }
     p_num=0;
    Extra_run=0;
    strcpy(team_name,"country");

}
/***INITIALISING TEAM***/
int Team::Init()
{
    int i;
    cout<<"enter team name";
    cin>>team_name;
    cout<<"enter number of players";
    cin>>p_num;
    for(i=0;i<p_num;i++)
    {
      cout<<"player"<<" "<<i<<":";
      cout<<"enter players name";
      cin>>p_name[i];
    }
    return p_num;
}
/*** GET TOTAL RUNS ***/
int Team::get_Total()
{
  int local=0;
  for(int i=1;i<=p_num;i++)
  local += p_run[i];
  local += Extra_run;

  return local;
}
/***SUBSTITUTE PLAYER***/
void Team::Out(int out_player,int type,int new_player)
{
p_status[out_player]=type;
p_status[new_player]=1;
}
/***CLASS MYSCORE***/
/***CONSTRUCTOR INITIALISING DATA MEMBERS***/
Score::Score()
{
player1=0;
player2=0;
extra=0;
Over=0;
Out=0;
Max_out=10;
Ball_count=0;
Max_out=team1.Init();
cout<<"\nEnter no of Overs in one Innings: ";
cin>>Max_Over;
cout<<"\n\nChoose opening Batsman(player number from 1-11):";
while(1)
    {
    cout<<"\n batsman 1:";
    cin>>player1;
    team1.Set_Status(player1,1);
    cout<<"batsman 2:";
    cin>>player2;
    team1.Set_Status(player2,1);
    if(player1>11 || player2>11 || player1==player2)
      cout<<"Invalid Entry Try Again!!";
    else break;
    }
}
char* SHOW_STATUS(int i){
switch (i)
{
    case 0:  return "YET TO PLAY";
    case 1:  return "CURRENTLY PLAYING";
    case 2:  return "BOWLED OUT";
    case 3:  return "CAUGHT OUT";
    case 4:  return "RUN OUT";
    default: return "UNKNOWN";
}
}


void Score::show(void)
{
int option;
cout<<""<<endl;
cout<<""<<team1.get_t_name()<<"'s Score:  "<<endl;
for(int i=0;i<Max_out;i++)
   {

    cout<<team1.get_name(i);
    cout<<"'s STATUS:";
    cout<<SHOW_STATUS(team1.get_status(i))<<endl;
    cout<<endl;
   }
cout<<"\nExtra";
cout<<team1.get_extra()<<endl;
cout<<"Over "<<Over<<"."<<Ball_count<<"  Wicket "<<Out<<endl;
cout<<" TOTAL SCORE : "<<team1.get_Total()<<endl;

          cout<<"\nChoose option:\n";
          cout<<"\n(1).Dot Ball\n";
          cout<<"\n(2).Extra\n";
          cout<<"\n(3).Wicket\n";
          cout<<"\n(4).Four \n";
          cout<<"\n(5).Six\n";
          cout<<"\n(6).Exit\n";

cin>>option;
switch (option){
    case 1:    dot_ball(); break;
    case 2:    extra1();  break;
    case 3:    wicket();  break;
    case 4:    add_four();break;
    case 5:    add_six();break;
    case 6:   return;
    default: cout<<"\nInvalid input\n";

    }
}
/***DOT BALL***/
void Score::dot_ball(void){
if(Ball_count==6){over_complete();return;}
cout<<"\t Dot Ball \n";
Ball_count++;
team1.Set_Ball(player1);
show();
}
/***EXTRA RUNS***/
void Score::extra1(void){
if(Ball_count==6){over_complete();return;}
cout<<"\tExtra Run\n";
cout<<"Number of extra runs to add?";
cin>>extra;
team1.Set_Extra(extra);
Ball_count++;
show();
}
/***ADD A FOUR TO THE TOTAL***/
void Score::add_four(void)
{
    if(Ball_count==6){over_complete();return;}
    Ball_count++;
    team1.Set_Extra(4);
    show();
}
/***ADD A SIX TO THE TOTAL***/
void Score::add_six(void)
{
    if(Ball_count==6){over_complete();return;}
    Ball_count++;
    team1.Set_Extra(6);
    show();

}

/***OVER COMPLETION CHECK***/
void Score::over_complete(void)
{
cout<<"Over Complete\n";
Over++;
Ball_count=0;
int temp = player1;
player1=player2;
player2=temp;
if(Over==Max_Over)
{

cout<<"Innings Complete\n";
return;
}
else
{
     show();
}
}
/***WICKET***/
void Score::wicket(void)
{
int out_type,new_player;
cout<<"\tWicket\n";
cout<<"\nType of wicket? ((1):Bould(2):Caught:(3):Run out)";
cin>>out_type;
Out++;
Ball_count++;
team1.Set_Ball(player1);
if(Out>=Max_out)
{
cout<<"Innings Complete\n";
team1.Set_Status(player1,out_type+1);
return;
}
cout<<"\nNew Batsmans no: ";
cin>>new_player;
team1.Out(player1,out_type+1,new_player);
player1=new_player;
if(Ball_count==6){over_complete();return;}
show();
}

