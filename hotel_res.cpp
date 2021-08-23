#include <iostream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

/***************************************************************************************************/
class hotel{
    public:
        map<int,int> rm;
        map<int,int> res;
        int search(int id){
            map<int, int>::iterator it;
            for(it=rm.begin();it!=rm.end();++it){
                if(it->second==id){
                    return 1;break;
                }
                else{
                    continue;
                }
            }
            return 0;
        }

        void del(int id){
            map<int, int>::iterator it;
            it=rm.find(id);
            rm.erase(it);
        }

        void bill(int id){
            map<int,int>::iterator it;
            it=res.find(id);
            res.erase(it);
        }
};
/***************************************************************************************************/

/***************************************************************************************************/
class rooms : public hotel{
    public:
        int roomid;
        int floor;
        int price;
        bool reserved;
        void insert(){
            rm.insert(pair<int,int>(roomid,price));
        }
};
/***************************************************************************************************/
class date{
    public:
        int day;
        int month;
        int year;
        public:
            date(){
                day=1;month=1;year=2020;
            }
            void defaultset(){
                day=1;month=1;year=2020;
            }
            void set(){
                cin>>day>>month>>year;
            }
            int getday(){
                return day;
            }
            int getmonth(){
                return month;
            }
            int getyear(){
                return year;
            }
};
/***************************************************************************************************/
class reservation:public hotel{
    public:
        int resid;
        int roomid;
        
        void reserveroom(){
            res.insert(pair<int,int>(resid,roomid));
        }
};
/***************************************************************************************************/
int main(){
    int choice=0;
    while(choice!=6){
        cout<<"1. Search rooms"<<endl;
        cout<<"2. Add room"<<endl;
        cout<<"3. Delete room"<<endl;
        cout<<"4. Reserve a Room"<<endl;
        cout<<"5. Generate Bill"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter Your Choice:"<<endl;
        cin>>choice;
        hotel hobj;
        rooms obj;
        reservation resobj;
    
        switch (choice){
            case 1:
                int ids;
                cout<<"Enter Room NO. u want to search: "<<endl;
                cin>>ids;
                if(hobj.search(ids)==1){
                    cout<<"Room is not Reserved!!"<<endl;
                }
                else{
                    cout<<"Room is Reserved"<<endl;
                }
                cout<<"Searching Complete!!"<<endl;
                break;

            case 2:
                
                int id;
                int p;
                cout<<"Enter the Room No."<<endl;
                cin>>id;
                cout<<"Enter the price of the room:";
                cin>>p;
                obj.roomid=id;
                obj.price=p;
                obj.insert();
                cout<<"Room inserted"<<endl;break;
            case 3:
                int id_del;
                cout<<"Enter the room no. u want to delete: "<<endl;
                cin>>id_del;
                hobj.del(id_del);
                cout<<"Room Deleted Successfully"<<endl;break;

            case 4:
                int id1;int id2;
                cout<<"Enter the registration ID:"<<endl;
                cin>>id1;
                cout<<"Enter the Room No.:"<<endl;
                cin>>id2;
                
                resobj.resid=id1;
                resobj.roomid=id2;
                
                resobj.reserveroom();
                break;

            case 5:
                int roomno;int days;int pr;
                cout<<"Enter room number: "<<endl;
                cin>>roomno;
                cout<<"enter days: ";
                cin>>days;
                cout<<"enter price: ";
                cin>>pr;
                obj.roomid=roomno;
                obj.price=pr;
                obj.insert();
                cout<<"Total Bill is:"<<pr*days<<"\t"<<"Thank You! Visit Again"<<endl;break;
            case 6:
                cout<<"Exited Succesfully"<<endl;break;

            default:
                cout<<"Invalid Input!!"<<endl;break;

        }
    }
}