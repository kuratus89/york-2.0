#include <bits/stdc++.h>
#include <cstdlib>
#include <thread>
#include "input/input.h"
using namespace std;





// variables
long long stage =0;// 0= screen calibrate
long long frame_time = 50;
bool clr_scr =0;
bool clr__scr =0;
vector<vector<char>> screen_char;

bool print_screen = 0;
long long x=3;
long long y=3;
bool fmc=1;
stack<pair<string,map<string ,long long>>> menu;
string screen;
vector<vector<char>> void_screen(x , vector<char> (y ,' '));
map<string, string> main_menu_data ={{"tittle","WELCOME TO YORK" },{"selecter","0"}};
map<string , string> alpha = {{"A","a"},{"B","b"},{"C","c"},{"D","d"},{"E","e"},{"F","f"},{"G","g"},{"H","h"},{"I","i"},{"J","j"},{"K","k"},{"L","l"},{"M","m"},{"N","n"},{"O","o"},{"P","p"},{"Q","q"},{"R","r"},{"S","s"},{"T","t"},{"U","u"},{"V","v"},{"W","w"},{"X","x"},{"Y","y"},{"Z","z"}};

string  conchtos(vector<vector<char>>scn){
    string s;
    for(auto vol:scn){
        for(auto val:vol)s.push_back(val);
        s.push_back('\n');
    }
    return s;    
}
vector<vector<char>> screenresize(long long x , long long y){
    vector<vector<char>> scr(x , vector<char> (y , ' '));
    for(long long i=0 ; i<y ; i++)scr[0][i]='-';
    for(long long i=0 ; i<y ; i++)scr[x-1][i]='-';
    for(long long i=0 ; i<x ; i++)scr[i][0]='|';
    for(long long i=0 ; i<x ; i++)scr[i][y-1]='|';
    return scr;
}
void clearscreen(bool type) {
    if(type){
        cout.flush();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }
    else {
        cout << "\033[H";
        // cout << "\033[2J\033[H";
        // printer(void_screen);
    }
}

void printer(vector<vector<char>> vec , bool hilou){
    string s=conchtos(vec);  
    if(s!=screen){
        screen =s;
        clearscreen(hilou);
        cout<<screen;
    }
}
void screen_size_limit(){
    clearscreen(1);
    cout<<"this game has been crashed due to limited screen size , please restart the game and claibrate bigger screen";
    this_thread::sleep_for(chrono::milliseconds(5000));
    exit(0);
}
vector<vector<char>> screen_maker(vector<string>&socho , bool vibo){
    vector<vector<char>> dominator = screenresize(x,y);
    long long xo=1;
    for(auto val:socho){
        if(xo+1==x){
            if(vibo)screen_size_limit();
            else continue;
        }
        long long yo=1;
        for(auto valo:val){
            if(yo+1==y){
                if(vibo)screen_size_limit();
                else continue;
            }
            dominator[xo][yo]=valo;
            yo++;
        }
        xo++;
    }
    return  dominator;
    
}

vector<vector<char>> screen_maker_advance(vector<vector<string>> &doflamingo , bool bulao){
    vector<vector<char>> dominator = screenresize(x,y);
    long long xo=1 , yo=1;
    for(auto valo:doflamingo){
        y=1;
        if(xo+1==x){
            if(bulao)screen_size_limit();
            else continue;
        } 
        for(auto val:valo){
            for(auto vol:val){
                if(yo+1==y){
                    if(bulao)screen_size_limit();
                    else break;
                }
                dominator[x][y]=vol;
                yo++;
            }
            y++;
        }
        x++;
    }
    return dominator;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cout << "\033[?25l";
    screen_char = screenresize(x,y);
    input::event e;
    string k="-";
    menu.push({("main_menu"), {{}}});
    menu.push({"screen_calibrate" , {{"sta",0}}});
    cout<<"Calibrate your screen"<<endl<<endl<<"controls-> w,a,s,d , enter , space"<<endl<<endl<<"press enter to start calibrate your screen";
                
    while (true) {
        if(menu.empty()){
            clearscreen(1);
            cout<<"exiting in 5 seconds"<<endl;
            // cout.flush();
            this_thread::sleep_for(chrono::milliseconds(5000));
            return 0;

        }
        if((clr_scr)&&(!print_screen)){
            clearscreen(1);
            clr_scr=0;
        }
        if(clr_scr&&print_screen){
            printer(screen_char , 1);
            clr_scr=0;
            print_screen=0;
        }
        if(clr__scr&&print_screen){
            // clearscreen(0);
            printer(screen_char,0);
            clr_scr=0;
            print_screen=0;
        }
        
        this_thread::sleep_for(chrono::milliseconds(frame_time));
        k="-";

        if (input::pollEvent(e)) {
            if (e.keycode == input::key::Q)break;

            if(e.keycode == input::key::W)k="w";
            if(e.keycode == input::key::A)k="a";
            if(e.keycode == input::key::S)k="s";
            if(e.keycode == input::key::D)k="d"; 
            if(e.keycode == input::key::Enter)k="ent"; 
            if(e.keycode == input::key::Space)k="spc"; 
            if(e.keycode == input::key::Num0)k='0';
            if(e.keycode == input::key::Num1)k='1';
            if(e.keycode == input::key::Num2)k='2';
            if(e.keycode == input::key::Num3)k='3';
            if(e.keycode == input::key::Num4)k='4';
            if(e.keycode == input::key::Num5)k='5';
            if(e.keycode == input::key::Num6)k='6';
            if(e.keycode == input::key::Num7)k='7';
            if(e.keycode == input::key::Num8)k='8';
            if(e.keycode == input::key::Num9)k='9';
            if(e.keycode == input::key::Backspace)k="back";
            if(e.keycode == input::key::A)k="a";
            if(e.keycode == input::key::B)k="b";
            if(e.keycode == input::key::C)k="c";
            if(e.keycode == input::key::D)k="d";
            if(e.keycode == input::key::E)k="e";
            if(e.keycode == input::key::F)k="f";
            if(e.keycode == input::key::G)k="g";
            if(e.keycode == input::key::H)k="h";
            if(e.keycode == input::key::I)k="i";
            if(e.keycode == input::key::J)k="j";
            if(e.keycode == input::key::K)k="k";
            if(e.keycode == input::key::L)k="l";
            if(e.keycode == input::key::M)k="m";
            if(e.keycode == input::key::N)k="n";
            if(e.keycode == input::key::O)k="o";
            if(e.keycode == input::key::P)k="p";
            if(e.keycode == input::key::Q)k="q";
            if(e.keycode == input::key::R)k="r";
            if(e.keycode == input::key::S)k="s";
            if(e.keycode == input::key::T)k="t";
            if(e.keycode == input::key::U)k="u";
            if(e.keycode == input::key::V)k="v";
            if(e.keycode == input::key::W)k="w";
            if(e.keycode == input::key::X)k="x";
            if(e.keycode == input::key::Y)k="y";
            if(e.keycode == input::key::Z)k="z";
            
            // cout<<(int)e.key<<endl;      
            // if(e.keycode == input::key::C){
            //     menu.pop();
            //     continue;
            // }
        
        }
        // cout<<k;
        if(menu.top().first=="screen_calibrate"){
            if(menu.top().second.count("sta")==0)menu.top().second["sta"]=1;
            if(menu.top().second["sta"]==0){
                if((k=="ent")||(k=="spc")){
                    menu.top().second["sta"]=1;
                    clr_scr=1;
                    print_screen=1;
                }
                
            }
            else {
                bool ud=0, ud2=0;
                if(menu.top().second.count("first_time")==0)menu.top().second["first_time"]=0;
                if(menu.top().second["first_time"]==0){
                    menu.top().second["first_time"]=1;
                    ud2=1;
                    ud=1;
                }
                
                // cout<<"1";
                if(k=="w"){
                    x = max(3LL , x-1);
                    ud=1;
                    ud2=1;
                }
                else if(k=="s"){
                    x++;
                    ud=1;
                }
                else if(k=="a"){
                    y = max(3LL , y-1);
                    ud=1;
                    ud2=1;
                }
                else if(k=="d"){
                    y++;
                    ud=1;

                }
                else if((k=="ent")||(k=="spc")){
                    menu.pop();
                    clearscreen(1);
                }
                
                if(ud){
                    screen_char =screenresize(x,y);
                    if(ud2)clr_scr=1;
                    else clr__scr=1;
                    print_screen=1;
                }
                
            }
        }
        else if(menu.top().first=="main_menu"){
            if(menu.top().second.count("selecter")==0)menu.top().second["selecter"]=0;            
            vector<string> schco;
            vector<string> opt = {"new_game" , "continue" , "load" , "settings" , "quit"};
            vector<string> options = {"New Game" ,"Continue" ,"Load", "Settings" , "Quit"};
            schco.push_back(main_menu_data["tittle"]);
            schco.push_back("");
            
            for(long long i=0 ; i<(long long)options.size() ; i++){
                if(i==menu.top().second["selecter"])schco.push_back("->"+options[i]);
                else schco.push_back(options[i]);
            }
            printer(screen_maker(schco,fmc),0);
            if(k=="w")menu.top().second["selecter"]--;
            if(k=="s")menu.top().second["selecter"]++;
            if(menu.top().second["selecter"]>=(long long )options.size())menu.top().second["selecter"]=0;
            if(menu.top().second["selecter"]<0)menu.top().second["selecter"] = (long long )options.size()-1;
            if((k=="spc")||(k=="ent"))menu.push({opt[menu.top().second["selecter"]] , {{}}});                        
        }
        else if(menu.top().first=="quit")break;

        else if(menu.top().first=="settings"){
            if(menu.top().second.count("is_result_yes_or_no")!=0){
                menu.top().second.erase("is_result_yes_or_no");
                bool ano;
                if(menu.top().second["result"]==0)ano=0;
                else if(menu.top().second["result"]==1)ano=1;
                else continue;
                long long data_type = menu.top().second["data_type"];
                if(data_type==1)fmc=ano;
            }
            if(menu.top().second.count("num_result")!=0){
                menu.top().second.erase("num_result");
                long long number = menu.top().second["result"];
                if(menu.top().second["data_type"]==1)frame_time=number;
            }
            if(menu.top().second.count("selecter")==0)menu.top().second["selecter"]=0;
            vector<string> colin;
            vector<string> opt = {"screen_calibrate", "num_selecter","yes_or_no_selecter", "quit"};
            vector<string> options= {"Screen calibration" , "Frame time","Force minimum screen size", "Quit"};
            colin.push_back("SETTINGS");
            for(long long i=0 ; i<((long long)options.size()) ; i++){
                if(i==menu.top().second["selecter"])colin.push_back("->"+options[i]);
                else colin.push_back(options[i]);
            }
            printer(screen_maker(colin,fmc) ,0);
            if(k=="w")menu.top().second["selecter"]--;
            if(k=="s")menu.top().second["selecter"]++;
            if(menu.top().second["selecter"]>=(long long )options.size())menu.top().second["selecter"]=0;
            if(menu.top().second["selecter"]<0)menu.top().second["selecter"] = (long long )options.size()-1;
            if((k=="ent")||(k=="spc")){
                long long sel =menu.top().second["selecter"];
                if(opt[sel]=="quit")menu.pop();
                else menu.push({opt[sel], {{}}});
                if(options[sel]=="Force minimum screen size"){
                    menu.top().second["value"]=fmc;
                    menu.top().second["value_type"]=1;
                }
                if(options[sel]=="Frame time"){
                    menu.top().second["value"]=frame_time;
                    menu.top().second["value_type"]=1;
                }
                
            }

            
        }
        else if(menu.top().first=="yes_or_no_selecter"){
            if(menu.top().second.count("selecter")==0)menu.top().second["selecter"]=0;
            vector<string> giuponico;
            if(menu.top().second.count("value")!=0){
                string current_data = "current value => ";
                if(menu.top().second["value"]==1)current_data+="Yes";
                else current_data+="No";
                giuponico.push_back(current_data);
                giuponico.push_back("");
            }
            giuponico.push_back("select option");
            giuponico.push_back("");
            vector<long long> opt = {1,0,-1};
            vector<string> options= {"Yes", "No" , "Cancel"};
            for(long long i=0 ; i<((long long)options.size()) ; i++){
                if(i==menu.top().second["selecter"])giuponico.push_back("->"+options[i]);
                else giuponico.push_back(options[i]);
            }
            printer(screen_maker(giuponico,fmc) ,0);
            if(k=="w")menu.top().second["selecter"]--;
            if(k=="s")menu.top().second["selecter"]++;
            if(menu.top().second["selecter"]>=(long long )options.size())menu.top().second["selecter"]=0;
            if(menu.top().second["selecter"]<0)menu.top().second["selecter"] = (long long )options.size()-1;
            if((k=="ent")||(k=="spc")){
                long long trans = opt[menu.top().second["selecter"]];
                long long data = menu.top().second["value_type"];
                menu.pop();
                if(trans==-1)continue;
                menu.top().second["result"]=trans;
                menu.top().second["is_result_yes_or_no"]=1;
                menu.top().second["data_type"]=data;
            }
        }
        else if(menu.top().first=="num_selecter"){
            vector<string> shaun_the_sheep;
            shaun_the_sheep.push_back("Enter Number");
            shaun_the_sheep.push_back("");
            if(menu.top().second.count("value")!=0){
                if(menu.top().second.count("num")==0)menu.top().second["num"]=menu.top().second["value"];
                string karela = "Current Value => ";
                karela+=to_string(menu.top().second["value"]);
                shaun_the_sheep.push_back(karela);
                shaun_the_sheep.push_back("");
            }
            if(menu.top().second.count("num")==0)menu.top().second["num"]=0;
            long long num = menu.top().second["num"];
            shaun_the_sheep.push_back(to_string(num));
            printer(screen_maker(shaun_the_sheep,fmc),0);
            if(k=="0")num = (num*10);
            // if(k=="6")cout<<"uwu";
            else if(k=="1")num=(num*10)+1;
            else if(k=="2")num=(num*10)+2;
            else if(k=="3")num=(num*10)+3;
            else if(k=="4")num=(num*10)+4;
            else if(k=="5")num=(num*10)+5;
            else if(k=="6")num=(num*10)+6;
            else if(k=="7")num=(num*10)+7;
            else if(k=="8")num=(num*10)+8;
            else if(k=="9")num=(num*10)+9;
            else if(k=="back")num/=10;
            else if((k=="ent")||(k=="spc")){
                long long data = menu.top().second["value_type"];
                menu.pop();
                menu.top().second["data_type"]=data;
                menu.top().second["num_result"]=1;
                menu.top().second["result"]=num;
            }
            menu.top().second["num"]=num;
         
        }

    }
    
}