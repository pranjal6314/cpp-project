#include<iostream>
#include<fstream>//for file handling
#include<string>
using namespace std;
class shopping{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu(); //functiom
        void administrator();
        void buyer();
        void add();
        void edit();
        void remove1();
        void list();
        void receipt();
};
void shopping :: menu(){ //scope resolution
    m:
    int choice ;
    string email;
    string password;
//display
    cout<<"\t\t\t\t\t.............................\n";
    cout<<"\t\t\t\t\t     SuperMarket Main Menu ๐   \n";
    cout<<"\t\t\t\t\t                               \n";
    cout<<"\t\t\t\t\t.............................\n";
    cout<<"\t\t\t\t\t                               \n";
     
     //menu 

    cout<<"\t\t\t| 1) Administrator๐คต   \n";
    cout<<"\t\t\t|                     \n";
    cout<<"\t\t\t| 2) Buyer ๐        \n";
    cout<<"\t\t\t|                    \n";
    cout<<"\t\t\t| 3) Exit โ         \n";
    cout<<"\t\t\t|                    \n";
    cout<<"\n\t\t\t Please select!โ๏ธ : ";
    cin>>choice;


    switch(choice){
        case 1:
            cout<<"\t\t\t Please Login ๐ค \n";
            cout<<"\t\t\t Enter Email ๐ง  \n";
            cin>>email;
            cout<<"\t\t\t Password ๐     \n";
            cin>>password;

            //for admin
            if(email=="admin@gmail.com" && password=="1234@"){
                    administrator();
            }
            else{
                cout<<"Invalid email/password !๐ ";
            }
            break;
        case 2:{
            buyer();
        }
        case 3:{
            exit(0);
        }
        default :
            cout<<"Please select form given options!โ๏ธ";

    }
//jumping statement ,jump to main menu
goto m;

}

void shopping::administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Aministrator Menu";
    cout<<"\n\n\n\t\t____1)Add the Product_____โ";
    cout<<"\n\t\t\t                               ";
    cout<<"\n\n\n\t\t____2)Modify the Product__โ๏ธ";
    cout<<"\n\t\t\t                               ";
    cout<<"\n\n\n\t\t____3)Delete the Product__โ";
    cout<<"\n\t\t\t                               ";
    cout<<"\n\n\n\t\t____4)Back to main menu___๐";
    
    cout<<"\n\n\t Please enter your choice โ๏ธ: ";
    cin>>choice;
    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            remove1();
            break;
        case 4:
            menu();
            break;
        default :
            cout<<" Invaild choice!โ";
            
    }
    goto m;
    

}

void shopping::buyer(){
    n:
    int choice;
    cout<<"\t\t\t ___Buyer___ \n";
    cout<<"\t\t\t______________ \n";
    cout<<"                \n";
    cout<<"\t\t\t 1)Buy product ๐\n";
    // cout<<"                   \n";
    cout<<"\t\t\t 2)Go back ๐   \n";
    cout<<"\t\t\t Enter your choiceโ๏ธ : ";
    cin>>choice;
    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"Invaild choice! โ";
    }
    goto n;
}   
void shopping ::add(){
    m:
    fstream data; //object of fstream class
    //data name of object
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\n\t\t Add new product โ";
    cout<<"\n\n\t Product code of new product is ๐ท๏ธ: ";
    cin>>pcode;
    cout<<"\n\n\t Name of product ๐: ";
    cin>>pname;
    cout<<"\n\n\t Price of product ๐ต: ";
    cin>>price;
    cout<<"\n\n\t Discount on product(%) ๐บ: ";
    cin>>dis;

    //open a file because we have to store these detail in a fail for user 
    data.open("database.txt,ios::in");//ios::in open file in reading mode
    if(!data){ //if file not exit
        data.open("database.txt",ios::app|ios::out);//app stands for append mode and out stands for write mode
        //writing inside file
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
      //closeing the file 
       data.close();
    }
       else{ //if file exit
       //so we reading form file
        data>>c>>n>>p>>d; //intializing index of file
        while(!data.eof()){ //eof is end of file
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

       
       if(token==1){
        goto m;//checking duplicate product  ,if  prodcut code entered by the adminis. is already exist then enter other  product code

       }else{
        //product code is unique not dulicate 
         data.open("database.txt",ios::app|ios::out);//app stands for append mode and out stands for write mode
        //writing inside file
        data<<" "<<pcode<<" "<<pname<<" "<<dis<<"\n";
      //closeing the file 
       data.close();
       }
       }
        cout<<"\n\n\t Record Inserted!๐";
    }

void shopping::edit(){
    fstream data,data1; //object
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the recordโ๏ธ";
    cout<<"\n\t\t\t Product code ๐ท๏ธ: ";
    cin>>pkey;
    cout<<"++++++++++"<<pcode<<"++++++++++++";
    data.open("database.txt,ios::in");

    if(!data){
        cout<<"\n\n File doesn't exist!โ";
    }
    else{
        //here we save our edited data and rename it to the original file
        data1.open("database1.txt",ios::app|ios::out); 
       //writing data in file
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product new code ๐ท๏ธ: ";
                cin>>c;
                cout<<"\n\n\t Name of the product ๐: ";
                cin>>n;
                cout<<"\n\n\t Enter the price ๐ต: ";
                cin>>p;
                cout<<"\n\n\t Discount on product(%) ๐บ: ";
                cin>>d;
                //entring new values by help of data1 object
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t Record edited successfully๐. ";
                token++;
            }
            else{
                cout<<"________________________________________________________________________________________________________";
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";


                    
            }
            //writing this for increment purpose ,for while loop
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        //renaming data file to original file
        remove("database.txt");//remove all the list inside the file
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found!โ";
        }
    }

}

void shopping::remove1(){
    fstream data ,data1;
    int pkey;
    int token =0;
    cout<<"\n\n\t__Delete Product__";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    // data.open("database.txt",ios::in);
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"file doesn't exist!โ";
    }
    else{
            data1.open("database1.txt,ios::app|ios::out");
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==pkey){
                    cout<<"\n\n\t Product deleted succesfully๐.";
                    token++;
                }
                else{
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");
            if(token==0){
                cout<<"\n\n Record not found!โ";
            }
    }

}

void shopping :: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|____________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|____________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
            cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
            data>>pcode >>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt(){
    
    fstream data;
    int arrc[100]; //c =codes
    int arrq[100]  ;    //q= quntity
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total =0;
    cout<<"\n\n\t _____RECEIPT_____๐งพ";
    data.open("database.txt",ios::in);
    if(!data){

        cout<<"\n\n Empty database๐ฅด";
    }
    else{
        data.close();
        list();
        cout<<"\n___________________________________\n";
        cout<<"\n|                                 |\n";
        cout<<"\n        Please place the order     \n";
        cout<<"\n|                                 |\n";
        cout<<"\n___________________________________\n";
        do{
            m:
            cout<<"\n\n Enter the product code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity : ";
            cin>>arrq[c];
            for(int i=0;i<<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product code . Please try again!โ";
                    goto m;
                }
                }
                c++;
                cout<<"\n\n Do you want to buy another product ?if yes then press y else n !";
                cin>>choice;
             
        }while(choice=='y');

            
            cout<<"\n\n\t\t_____________RECEIPT__________๐งพ\n";
            cout<<"\nProduct No\t product quantity\t price \tamount \t amount with discount \n";
            for(int i=0;i<c;i++){
                data.open("database.txt",ios::in);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof()){
                    if(pcode==arrc[i]){
                        amount=price*arrq[i];
                        dis=amount- (amount*dis/100);
                        total=total+dis;
                        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<amount<<"\t\t"<<dis;

                    }
                    data>>pcode>>pname>>price>>dis;
                }
            }
            data.close();

        }
        cout<<"\n\n________________________";
        cout<<"\n total amount ๐ฟ: "<<total;
        cout<<"\n Thanks for visiting out market ๐";

    }


int main(){
    //object of class
    shopping s;
    s.menu();
}



