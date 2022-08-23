#include<iostream>
using namespace std;

int main(){
    int quant;
    char choice;
    int Qrooms=0;
    //variabels will hold quantity of these food items
    int Qpasta=0,Qburger=0,Qnoodles=0,Qshake=0,Qchicken=0;


    // variabels store values of the number of food items that have been sold
    int Srooms=0,Spasta=0,Snoodles=0,Sburger=0,Sshake=0,Schicken=0;

    //variables which store price of total price of each these food items and rooms
    int total_rooms=0,total_pasta=0,total_burger=0,total_noodles=0,total_shake=0,total_chicken=0;

    cout<<"\n\t Quantity of items we have ";
    cout<<"\n Rooms avaliable";
    cin>>Qrooms;
    cout<<"\n Quantity of pasta";
    cin>>Qpasta;
    
    cout<<"\n Quantity of noodles";
    cin>>Qnoodles;
    
    cout<<"\n Quantity of burger";
    cin>>Qburger;
    cout<<"\n Quantity of shake";
    cin>>Qshake;
    
    cout<<"\n Quantity of chicken-roll";
    cin>>Qchicken;

    jump:
    cout<<"\n\t\t\t Please select from the menu option .";
    cout<<"\n\n 1)Romms";
    cout<<"\n 2)Pasta";
    cout<<"\n 3)burger";
    cout<<"\n 4)noodles";
    cout<<"\n 5)shake";
    cout<<"\n 6)chicken-roll";

    cout<<"\n 7)Information regarding sales and collecton .";
    cout<<"\n 8)Exit";

    cout<<"\n\n Please Enter your choice : ";
    cin>>choice;
    // if(!isdigit(choice)){
    //     cout<<"\n\t Please select the number ";
        
    // }

    switch(choice){
        case '1':
            cout<<"\n\nEnter number of rooms you want : ";
            cin>>quant;
            if(quant<=Qrooms-Srooms){
                Srooms=Srooms+quant;
                total_rooms=total_rooms+quant*1200;
                cout<<"\n\n\t "<<quant<<"  room/rooms have been alloted to you";
            }else{
                cout<<"\n\n\t only "<<Qrooms-Srooms<<" Rooms remaining in hotel .";
                
            }
            break;
        case '2':
            cout<<"\n\nEnter pasta quantity : ";
            cin>>quant;
            if(quant<=Qpasta-Spasta){
                Spasta=Spasta+quant;
                total_pasta=total_pasta+quant*25;
                cout<<"\n\n\t "<<quant<<" pasta is the order!";
            }else{
                cout<<"\n\n\t only "<<Qpasta-Spasta<<" pasta remaining in hotel .";
                
            }
            break;
        case '3':
            cout<<"\n\nEnter burger quantity : ";
            cin>>quant;
            if(quant<=Qburger-Sburger){
                Sburger=Sburger+quant;
                total_burger=total_burger+quant*25;
                cout<<"\n\n\t "<<quant<<" burger is the order!";
            }else{
                cout<<"\n\n\t only "<<Qburger-Sburger<<" burger remaining in hotel .";
                
            }
            break;
        case '4':
            cout<<"\n\nEnter noodles quantity : ";
            cin>>quant;
            if(quant<=Qnoodles-Snoodles){
                Snoodles=Snoodles+quant;
                total_noodles=total_noodles+quant*25;
                cout<<"\n\n\t "<<quant<<" noodles is the order!";
            }else{
                cout<<"\n\n\t only "<<Qnoodles-Snoodles<<" noodles remaining in hotel .";
                
            }
            break;
        
        case '5':
            cout<<"\n\nEnter shake quantity : ";
            cin>>quant;
            if(quant<=Qshake-Sshake){
                Sshake=Sshake+quant;
                total_shake=total_shake+quant*25;
                cout<<"\n\n\t "<<quant<<" shake is the order!";
            }else{
                cout<<"\n\n\t only "<<Qshake-Sshake<<" shake remaining in hotel .";
                
            }
            break;
        case '6':
            cout<<"\n\nEnter chicken-roll quantity : ";
            cin>>quant;
            if(quant<=Qchicken-Schicken){
                Schicken=Schicken+quant;
                total_chicken=total_chicken+quant*25;
                cout<<"\n\n\t "<<quant<<" chicken-roll is the order!";
            }else{
                cout<<"\n\n\t only "<<Qchicken-Schicken <<" remaining in hotel .";
                
            }
            break;

            case '7':
                cout<<"\n\t\tDetails of sales and collection ";
                cout<<"\n\n Number of rooms we had : "<<Qrooms;
                cout<<"\n\n Number of rooms we gave for rent "<<Srooms;
                cout<<"\n\n Remaining rooms : "<<Qrooms -Srooms;
                cout<<"\n\n Total rooms collection for the day :"<<total_rooms;


                cout<<"\n\n Number of pastas we had : "<<Qpasta;
                cout<<"\n\n Number of pastas we  sold "<<Spasta;
                cout<<"\n\n Remaining pastas : "<<Qpasta -Spasta;
                cout<<"\n\n Total pasta collection for the day :"<<total_pasta;


                cout<<"\n\n Number of burgers we had : "<<Qburger;
                cout<<"\n\n Number of burgers we  sold "<<Sburger;
                cout<<"\n\n Remaining burgers : "<<Qburger -Sburger;
                cout<<"\n\n Total burger collection for the day :"<<total_burger;


                cout<<"\n\n Number of noodles we had : "<<Qnoodles;
                cout<<"\n\n Number of noddles we  sold "<<Snoodles;
                cout<<"\n\n Remaining noddles : "<<Qnoodles -Snoodles;
                cout<<"\n\n Total noodles collection for the day :"<<total_noodles;

                cout<<"\n\n Number of shakes we had : "<<Qshake;
                cout<<"\n\n Number of shakes we  sold "<<Sshake;
                cout<<"\n\n Remaining shakes : "<<Qshake -Sshake;
                cout<<"\n\n Total shake collection for the day :"<<total_shake;

                cout<<"\n\n Number of chicken-roll we had : "<<Qchicken;
                cout<<"\n\n Number of chicken-roll we  sold "<<Schicken;
                cout<<"\n\n Remaining chicken-roll : "<<Qchicken -Qchicken;
                cout<<"\n\n Total chicken-roll collection for the day :"<<total_chicken;



                cout<<"\n\n\n Total collection for the day : "<<total_rooms+total_pasta+total_burger+total_noodles+total_shake+total_chicken;
                break;
                
            case '8':
                exit(0);
            default :
                    system("cls");
                    cout<<"\n\t Please select the numbets mentioned above !";
                    goto jump;
                    
            
                    
    }


    
}
