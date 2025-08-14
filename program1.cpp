#include <iostream>
using namespace std;

class Train
{
private:
    int trainNo;
    string trainName;
    string source;
    string destination;
    string trainTime;
    static int trainCount;

public:
    Train()
    {
        trainCount = 0;
        trainCount++;
    }
    ~Train()
    {
        trainCount--;
    }

    void input_TrainDetails()
    {
        cout<<endl<<"Add "<<trainCount<<" Train Details : "<< endl;
        cout << "Enter Train Number : ";
        cin >> trainNo;
        cin.ignore();
        cout << "Enter Train Name : ";
        getline(cin, trainName);
        cout << "Enter Source: ";
        getline(cin, source);
        cout << "Enter Destination: ";
        getline(cin, destination);
        cout << "Enter Train Time: ";
        getline(cin, trainTime);
    }
    void display_TrainDetails()
    {
        cout<<endl<<"Details of "<<trainCount<<" Train"<<endl;
        cout << "Enter Train Number : " << trainNo << endl;
        cout << "Enter Train Name : " << trainName << endl;
        cout << "Enter Source : " << source << endl;
        cout << "Enter destination : " << destination << endl;
        cout << "Enter Train Time : " << trainTime << endl;
        trainCount++;
    }
    int get_TrainNumber()
    {
        return trainNo;
    }
};
int Train::trainCount = 1;

class RailwayStation
{
private:
    Train t[100];
    int totaltrain = 0;

public:
    void add_train()
    {
        t[totaltrain].input_TrainDetails();
        totaltrain++;
    }
    void displayAllTrains()
    {
        for (int i = 0; i < totaltrain; i++)
        {
            t[i].display_TrainDetails();
        }
    }
    void searchTrain(int num)
    {
        for (int i = 0; i < totaltrain; i++)
        {
            bool found = false;
            if (t[i].get_TrainNumber() == num)
            {
                t[i].display_TrainDetails();
                found = true;
                break;
            }
            if(!found)
            {
                cout<<"Train Not Found!!"<<endl;
            }
            
        }
    }
};
int main()
{
    RailwayStation rs;
    int num,choice,n;
    
    do
    {
        cout<<endl<<"---------------- Railway Station System ---------------- "<<endl;
        cout<<"1 : Add train "<<endl;
        cout<<"2 : Dispaly All train "<<endl;
        cout<<"3 : Search train "<<endl;
        cout<<"4 : Exit "<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            rs.add_train();
            break;
        case 2:
            rs.displayAllTrains();
            break;
        case 3:
            cout<<"Enter Train Number : ";
            cin>>num;
            rs.searchTrain(num);
            break;
        case 4:
            cout<<"You are Exit!!";
            break;
        default:
            cout<<"Invalid Choice";
            break;
        }
    }while (choice!=4);
    

    return 0;
}