#include <iostream>
#include <string>
#include <thread>
#include<unistd.h>
#include <nlohmann/json.hpp>
#include <bits/stdc++.h>
using namespace std;

using json = nlohmann::json;

static int MIL = 0;
static int IGN_TYPE = 0;
static int FUEL_STATUS = 0;


string rand_MIL() 
{
    const char* colour[2] = { "On", "Off" };
    MIL = !MIL;
    return colour[MIL];
}

int DistanceWithMIL(){
    return rand() % 50;
}

string IgnitionType() 
{
    const char* colour[2] = { "spark", "compression" };
    IGN_TYPE = !IGN_TYPE;
    return colour[IGN_TYPE];
}

string FuelStatus() 
{
    const char* colour[2] = { "low", "full" };
    FUEL_STATUS = !FUEL_STATUS;
    return colour[FUEL_STATUS];
}

int EngineLoad(){
    return rand() % 100;
}

int CoolantTemperature(){
    int max = 95,min = 85;
    int randNum = rand()%(max-min + 1) + min;
    return randNum;
}

int FuelPressure(){
    int max = 420,min = 410;
    int randNum = rand()%(max-min + 1) + min;
    return randNum;
}

int EngineSpeed(){
    int max = 2000,min = 1000;
    int randNum = rand()%(max-min + 1) + min;
    return randNum;
}


int MAF(){
    int max = 12,min = 10;
    int randNum = rand()%(max-min + 1) + min;
    return randNum;
}

void create_json()
{
    char buffer[10240];
    json t = json::object();;
    t["MIL"]=rand_MIL();
    t["DistanceWithMIL"]=DistanceWithMIL();
    t["IgnitionType"]=IgnitionType();
    t["FuelStatus"]=FuelStatus();
    t["EngineLoad"]=EngineLoad();
    t["CoolantTemperature"]=CoolantTemperature();
    t["FuelPressure"]=FuelPressure();
    t["EngineSpeed"]=EngineSpeed();
    t["MAF"]=MAF();

    //string jsonString = t.dump();
    string jsonString = json(t.dump()).dump();
    //cout<<jsonString;

    snprintf(buffer, sizeof(buffer), "curl -X GET -H \"Content-type: application/json\" -H \"Accept: application/json\" -d %s http://20.81.75.92:3000", jsonString.c_str());
    //cout<<buffer;

    system(buffer);

}


void task1()
{
    int i = 0;
    for(i=0;i<5;i++)
    {
        // std::cout << "MIL : " << rand_MIL()<<endl;
        // std::cout << "DistanceWithMIL : " << DistanceWithMIL()<<endl;
        // std::cout << "IgnitionType : " << IgnitionType()<<endl;
        // std::cout << "FuelStatus : " << FuelStatus()<<endl;
        // std::cout << "EngineLoad : " << EngineLoad()<<endl;
        // std::cout << "CoolantTemperature : " << CoolantTemperature()<<endl;
        // std::cout << "FuelPressure : " << FuelPressure()<<endl;
        // std::cout << "EngineSpeed : " << EngineSpeed()<<endl;
        // std::cout << "MAF : " << MAF()<<endl;
        
        //std::cout << "************************"<<endl;
        create_json();
        //std::cout << "************************"<<endl;
        sleep(1);
    }
}

int main()
{
    // // create JSON objects
    // json j_no_init_list = json::object();
    // json j_empty_init_list = json::object({});
    // json j_list_of_pairs = json::object({ {"one", 1}, {"two", 2} });

    // // serialize the JSON objects
    // std::cout << j_no_init_list << '\n';
    // std::cout << j_empty_init_list << '\n';
    // std::cout << j_list_of_pairs << '\n';

    // // example for an exception
    // try
    // {
    //     // can only create an object from a list of pairs
    //     json j_invalid_object = json::object({{ "one", 1, 2 }});
    // }
    // catch (json::type_error& e)
    // {
    //     std::cout << e.what() << '\n';
    // }

    std::thread t1(task1);
    t1.join();
}
