/**
 * 实现了通过核心数组实现联系人的信息存储
 * @author lq
 * @version 0.10
 * @version 0.12 修改为GroupId进行外联的形式
 * @version 0.33 本版作废，修改为内含Group的形式，阿西吧
 * @date 2020/2/12
 */

#ifndef ARRAY_LIST_CORE_H
#define ARRAY_LIST_CORE_H

#include <stdlib.h>
#include <string.h>
#include "ErrorCode.h"
#include "Config.h"
#include "Domain.h"
#include "DataBaseCore.h"

#define END_ID_CODE -2         //最后一个联系人结束的id标记



/**
 * 结束联系人标志
 */
ContactInfo *getEndContact();

/**
 * 结束分组标志
 */
Group *getEndGroup();

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
 * 添加分组
 * @param group
 * @return 成功返回新添加的Group的id
 *         GROUP_EXIST
 */
int addGroup(char *group);

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
 * 查找所有分组
 * @return 返回所有分组数组的首地址，无则返回NULL
 */
Group **findGroups();

/**
 * 根据组名查找对应的id
 * @param group
 * @return 找到返回id，失败返回GROUP_NOT_EXIST
 */
int getGroupId(char *group);

/**
 * 根据Id获取对应的分组名称
 * @param id
 * @return 不存在返回NULL
 */
char *getGroupName(int id);

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
 * 根据id获取联系人
 * @param id
 * @return 失败为NULL
 */
ContactInfo *getContactById(int id);

/**
 * 通过分组名查找联系人，非模糊查询
 * @param group
 * @return 返回所有符合条件联系人数组的首地址，无则返回NULL
 */
ContactInfo **findByGroup(char *group);


/**
 * 通过groupId查找联系人
 * @param groupId
 * @return 返回所有符合条件联系人数组的首地址，无则返回NULL
 */
ContactInfo **findByGroupId(int groupId);

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

/**
 * 数据持久化
 * @return ERROR
 */
int saveToDB();

/**
 * 从db文件中加载数据
 * @note 通过加载数据的方式无需调用init方法
 * @return ERROR
 */
int loadFromDB();


#endif
