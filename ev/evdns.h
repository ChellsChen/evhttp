/**
 *   author       :   丁雪峰
 *   time         :   2016-01-12 01:42:47
 *   email        :   fengidri@yeah.net
 *   version      :   1.0.1
 *   description  :
 */
#ifndef  __EVDNS_H__
#define __EVDNS_H__

#pragma pack(push, 1)

//DNS header structure
//dns首部为12个固定的字节
struct DNS_HEADER
{
    unsigned short id;          // identification number

    unsigned char rd :1;        // recursion desired
    unsigned char tc :1;        // truncated message
    unsigned char aa :1;        // authoritive answer
    unsigned char opcode :4;    // purpose of message
    unsigned char qr :1;        // query/response flag

    unsigned char rcode :4;     // response code
    unsigned char cd :1;        // checking disabled
    unsigned char ad :1;        // authenticated data
    unsigned char z :1;         // its z! reserved
    unsigned char ra :1;        // recursion available

    unsigned short q_count;     // number of question entries
    unsigned short ans_count;   // number of answer entries
    unsigned short auth_count;  // number of authority entries
    unsigned short add_count;   // number of resource entries
};

//Constant sized fields of query structure
//问题部分：域名长度不定，查询类型和查询类是固定的，皆为2个字节
struct QUESTION
{
    unsigned short qtype;
    unsigned short qclass;
};

//Constant sized fields of the resource record structure
//资源纪录格式：查询类型(2字节)，查询类(2字节)，生存时间(4字节),  数据长度(2字节)
struct R_DATA
{
    unsigned short type;
    unsigned short _class;
    unsigned int ttl;
    unsigned short data_len;
};


//Pointers to resource record contents
// 资源纪录内容：
struct RES_RECORD
{
    unsigned char *name;          //查询名
    struct R_DATA *resource;      //资源纪录结构
    unsigned char *rdata;         //资源数据
};

//Structure of a Query
typedef struct
{
    unsigned char *name;
    struct QUESTION *ques;
} QUERY;

#pragma pack(pop)
#endif


