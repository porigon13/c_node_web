// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <stdlib.h>
#include "send.hpp"
namespace umagurui
{

Transmit::Transmit()
{
  
}

void Transmit::send(int color_id,int position)
{
    // Send send;
    char id='0'+position;
        
        if(color_id==0)
        {
            char string[4];
            sprintf(string,"%c%c",id,eraser);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
        else if(color_id == 1)
        {
            char string[4];
            sprintf(string,"%c%c",id,red);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
        else if(color_id == 2)
        {
            char string[4];
            sprintf(string,"%c%c",id,blue);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
        else if(color_id == 3)
        {
            char string[4];
            sprintf(string,"%c%c",id,green);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
        else if(color_id ==4)
        {
            char string[4];
            sprintf(string,"%c%c",id,yellow);
            sendto(DstAddrsock, string, sizeof(string)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
        }
}

void Transmit::init(char ip[])
{
    SrcAddr.sin_family = AF_INET;
    SrcAddr.sin_port = htons(12346);
    SrcAddr.sin_addr.s_addr = inet_addr(ip);

    DstAddr.sin_family = AF_INET;
    DstAddr.sin_port = htons(12345);
    DstAddr.sin_addr.s_addr = inet_addr(ip);
    //送り元
    Srcsock = socket(AF_INET, SOCK_DGRAM, 0);
    //送り先
    DstAddrsock = socket(AF_INET, SOCK_DGRAM, 0);
    char str[8] = "_______";
        // CSType_delay_ms(10);
    sendto(DstAddrsock, "1eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "2eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "3eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "4eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "5eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "6eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "7eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "8eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "9eraser", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "1pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "2pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "3pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "4pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "5pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "6pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "7pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "8pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    sendto(DstAddrsock, "9pink__", sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));


}

void Transmit::rpm(int power,int num)
{
    int digit=0;
    integer = power;
    while(integer != 0)
    {
        integer /= 10;
        digit++;
    }
    char Power[digit];
    char str[digit+3];
    snprintf(Power,10,"%d",power);
    sprintf(str,"P%d%d",num,power);
    sendto(DstAddrsock, str, sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
}

void Transmit::pitch(float angle,int num)
{
    integer = angle;
    while(integer != 0)
    {
        integer /= 10;
        digit++;
    }
    char Angle[digit+3];
    char str[digit+6];
    snprintf(Angle,10,"%2f",angle);
    sprintf(str,"A%d%2f",num,angle);
    sendto(DstAddrsock, str, sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    digit = 0;
}

void Transmit::yaw(float angle,int num)
{
    integer = angle;
    while(integer != 0)
    {
        integer /= 10;
        digit++;
    }
    char Angle[digit+3];
    char str[digit+6];
    snprintf(Angle,10,"%2f",angle);
    sprintf(str,"Y%d%2f",num,Angle);
    sendto(DstAddrsock, str, sizeof(str)-1, 0, (struct sockaddr *)&DstAddr, sizeof(DstAddr));
    digit =0;
}
}
// int Send::position(const int n)
// {
//    for(int i=0;i<=9;i++)
//    {
//     if(i==n)
//     {
//         return i;
//     }
//    }
// }