#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<iostream>
#include<string.h>
using namespace std;

class Login
{
    string command,Name, password,Name1, password1,reg_name, reg_password,choice;
public:
   void user_login();
};
class Team
{
    char team_name[20];
    char p_name[12][20];
    int p_run[12];
    int p_status[12];
    int p_ball[12];
    int p_num;
    int Extra_run;
public:
       Team();
       int Init();
       int get_Total(void);
       void Add_Run(int player_num,int run);
       void Out(int out_player,int type,int new_player);
       void Set_Status(int player,int status){p_status[player]=status;};
       char* get_name(int i){return p_name[i];}
       int get_run(int i){return p_run[i];}
       int get_status(int i){return p_status[i];}
       int get_extra(void){return Extra_run;}
       int get_ball(int i){return p_ball[i];}
       char* get_t_name(){return team_name;}
       void Set_Ball(int player){p_ball[player]++;}
       void Set_Extra(int run){Extra_run+=run;};

};

class Score
{
    int player1;
    int player2;
    int Ball_count;
    int Over;
    int Max_Over;
    int Out;
    int Max_out;
    Team team1;
    int extra;
    int add_f;
public:
    Score();

    void dot_ball(void);
    void add_run(void);
    void wicket(void);
    void extra1(void);
    void over_complete(void);
    void Add_six(void);
    void add_four(void);
    void add_six(void);
    void show(void);



};






#endif // HEADER_H_INCLUDED



