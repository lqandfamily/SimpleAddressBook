/**
 * 数据结构
 * @author lq
 * @date 2020/2/14
 * @version 0.1
 */
#ifndef DOMAIN_H
#define DOMAIN_H

typedef struct {
    int id;
    char group[20];
} Group;

/**
 * @version 0.12 修改为GroupId进行外联的形式
 * @version 0.13 修改为内含Group的形式
 */
typedef struct {
    int id;                 //id，唯一标识，自动生成
    char name[20];          //姓名，唯一
    char phoneNum[20];      //电话，唯一
    char address[50];       //住址
    int groupId;
} ContactInfo;

#endif
