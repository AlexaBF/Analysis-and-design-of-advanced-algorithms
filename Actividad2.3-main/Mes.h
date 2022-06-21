//convierte Mes a numerico

#pragma once
#include <string>
using namespace std;

int Mes(string MES){
    int num;
    if(MES == "Jan"){
        num=1;
        return num;
    }else if(MES == "Feb"){
        num=2;
        return num;
    }else if(MES == "Mar"){
        num=3;
        return num;
    }else if(MES == "Apr"){
        num=4;
        return num;
    }else if(MES == "May"){
        num=5;
        return num;
    }else if(MES == "Jun"){
        num=6;
        return num;
    }else if(MES == "Jul"){
        num=7;
        return num;
    }else if(MES == "Aug"){
        num=8;
        return num;
    }else if(MES == "Sep"){
        num=9;
        return num;
    }else if(MES == "Oct"){
        num=10;
        return num;
    }else if(MES == "Nov"){
        num=11;
        return num;
    }else{
        num=12;
        return num;
    }
}


