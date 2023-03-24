
#ifndef QTDEMO01_COMPUTEIP_H
#define QTDEMO01_COMPUTEIP_H
#include <arpa/inet.h>
#include <stdio.h>
#include "window.h"


class ComputeIP
{
public:
    unsigned int version; //1
    unsigned int headerLength; //2
    unsigned int dsf; //3
    unsigned int tl; //4
    unsigned int iden; //5
    unsigned int flags; //6
    unsigned int offset; //7
    unsigned int ttl; //8
    unsigned int protocol; //9
    unsigned int src; //10
    unsigned int dest; //11
    unsigned int checksum;

    unsigned int part1;
    unsigned int part2;
    unsigned int part3;
    unsigned int part4;
    unsigned int part5;
    unsigned int part6;
    unsigned int part7;
    unsigned int part8;
    unsigned int part9;
    unsigned int temp;
    ComputeIP()
    {
        version = 4;
        headerLength = 5;
        dsf = 0;
        tl = 40;
        iden = 0x150a;
        flags = 0x40;
        offset = 0;
        ttl = 128;
        protocol = 6;
        inet_pton(AF_INET,"176.1.168.192",&src);
        inet_pton(AF_INET,"32.137.106.39",&dest);
    }

    void compute(window *w)
    {
        //接下来需要将上述11个字段进行转换
        part1 = (version << 12) + (headerLength << 8) + dsf;
        part2 = tl;
        part3 = iden;
        part4 = (flags << 13) + offset;
        part5 = (ttl << 8) + protocol;
        part6 = src >> 16;
        part7 = src << 16 >> 16;
        part8 = dest >> 16;
        part9 = dest << 16 >> 16;




        temp = part1 + part2 +part3 + part4 +
                            part5 + part6 + part7 + part8 + part9;

        char buf2[1024];
        ::snprintf(buf2, 1024,
                       "分析IP数据包\n"
                               "分成16位字段如下\n"
                               "版本(4) + 首部长度(4) + 区分服务(8)：%x\n"
                               "总长度(16):%x\n"
                               "标识(16):%x\n"
                               "标志(3) + 片偏移(13):%x\n"
                               "生存时间(8) + 协议(8):%x\n"
                               "源地址第一部分(8) + 源地址第二部分(8):%x\n"
                               "源地址第三部分(8) + 源地址第四部分(8):%x\n"
                               "目的地址第一部分(8) + 目的地址第二部分(8):%x\n"
                               "目的地址第三部分(8) + 目的地址第四部分(8):%x\n"
                               "字段之和为:%x\n"
                               "将超出16位部分与剩余部分累加取反得到上述校验和\n",
                   part1,part2,part3,part4,part5,part6,part7,part8, part9,temp);
        w->ui->textEdit->setText(QString(buf2));

        while ((temp & 0xffff0000) != 0)
        {
            unsigned int a = (temp & 0xffff0000) >> 16;
            temp = (temp & 0x0000ffff) + a;
        }
        checksum = (~temp)&0x0000ffff;
    }
};

#endif //QTDEMO01_COMPUTEIP_H
