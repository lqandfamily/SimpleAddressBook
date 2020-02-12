/**
 * @author lq
 * @version 0.1
 * @date 2020/2/12
 * 实现了通过核心数组实现联系人的信息存储
 */

#ifndef ARRAY_LIST_CORE_H
#define ARRAY_LIST_CORE_H

#include <stdlib.h>
#include <string.h>
#include "ErrorCode.h"
#include "Config.h"

#define END_ID_CODE -2         //最后一个联系人结束的id标记

typedef struct {
    int id;                 //id，唯一标识，自动生成
    char name[20];          //姓名，唯一
    char phoneNum[20];      //电话，唯一
    char address[50];       //住址
    char group[20];         //分组
} ContactInfo;

/**
 * 销毁核心数组
 * @return ERROR
 */
int destroy();

/**
 * 初始化
 * @warning 该方法只能在初始化时调用一次，否则返回ERROR
 * @return ERROR
 */
int init();

/**
 * 通过完整的ContactInfo添加联系人
 * @param contactInfo
 * @return RUN_OUT
 */
int add(ContactInfo *contactInfo);

/**
 * 通过给定信息添加联系人
 * 其中name和PhoneNum必须在已有信息中不存在，否则无法添加
 * @param name 必须
 * @param phoneNum 必须
 * @param address 可选，若无传入NULL或''
 * @param group 可选，若无传入NULL或''
 * @return NAME_NULL
 *         NAME_EXIST
 *         PHONE_NULL
 *         PHONE_EXIST
 *         RUN_OUT
 */
int addByInfo(char *name,char *phoneNum, char *address, char *group);

/**
 * 删除联系人，唯一途径是通过id
 * @param id
 * @return ID_NOT_EXIST
 */
int del(int id);

/**
 * 查找所有联系人
 * @return 返回所有联系人数组的首地址，无则返回NULL
 */
ContactInfo **findAll();

/**
 * 通过姓名模糊查找联系人
 * @param name
 * @return 返回所有符合条件联系人数组的首地址，无则返回NULL
 */
ContactInfo **findByName(char *name);

/**
 * 通过绝对姓名精确查找联系人，用于添加联系人时的唯一性验证
 * @param absoluteName
 * @return 返回符合条件的唯一联系人，无则返回NULL
 */
ContactInfo *findByAbsoluteName(char *absoluteName);

/**
 * 通过号码模糊查找联系人
 * @param phoneNum
 * @return 返回所有符合条件联系人数组的首地址，无则返回NULL
 */
ContactInfo **findByPhoneNum(char *phoneNum);

/**
 * 通过绝对h号码精确查找联系人，用于添加联系人时的唯一性验证
 * @param absolutePhoneNum
 * @return 返回符合条件的唯一联系人，无则返回NULL
 */
ContactInfo *findByAbsolutePhoneNum(char *absolutePhoneNum);

/**
 * 通过分组查找联系人，非模糊查询
 * @param group
 * @return 返回所有符合条件联系人数组的首地址，无则返回NULL
 */
ContactInfo **findByGroup(char *group);

/**
 * 通过id修改姓名
 * @param id
 * @param name 不为NULL或''，且唯一
 * @return NAME_NULL
 *         NAME_EXIST
 *         ID_NOT_EXIST
 */
int altName(int id, char *name);

/**
 * 通过id修改电话号码
 * @param id
 * @param phoneNum 不为NULL或''，且唯一
 * @return PHONE_NULL
 *         PHONE_EXIST
 *         ID_NOT_EXIST
 */
int altPhone(int id, char *phoneNum);

/**
 * 通过id修改地址
 * @param id
 * @param address 不为NULL
 * @return ID_NOT_EXIST
 *         ADDRESS_NULL
 */
int altAddress(int id, char *address);

/**
 * 通过id修改分组
 * @param id
 * @param address 不为NULL或''
 * @return ID_NOT_EXIST
 *         GROUP_NULL
 */
int altGroup(int id, char *group);

#endif
