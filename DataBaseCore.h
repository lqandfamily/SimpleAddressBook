/**
 * 核心数据持久化
 * @author lq
 * @date 2020/2/13
 * @version 0.20
 */
#ifndef DATABASE_CORE_H
#define DATABASE_CORE_H

#include <stdio.h>
#include "ArrayListCore.h"


/**
 * 从db文件中读取联系人信息存入数组
 * @version 0.20 没有实现分页读取
 * @param fileUrl
 * @param contactArr 目标数组
 * @return FILE_OPEN_ERROR
 *         MALLOC_ERROR
 *         FILE_CLOSE_ERROR
 */
int readContactsFromDB(char *fileUrl, ContactInfo *contactArr[], int *contactNum);

/**
 * 将所有联系人写入db文件中
 * @param fileUrl
 * @param contactArr 源数组
 * @return FILE_OPEN_ERROR
 *         FILE_WRITE_ERROR
 *         FILE_CLOSE_ERROR
 */
int writeContactsToDB(char *fileUrl, ContactInfo *contactArr[]);


/**
 * 从db文件中读取联系人信息存入数组
 * @version 0.20 没有实现分页读取
 * @param fileUrl
 * @param groupArr 目标数组
 * @return FILE_OPEN_ERROR
 *         MALLOC_ERROR
 *         FILE_CLOSE_ERROR
 *
 */
int readGroupsFromDB(char *fileUrl, Group *groupArr[], int *groupNum);

/**
 * 将所有联系人写入db文件中
 * @param fileUrl
 * @param groupArr 源数组
 * @return FILE_OPEN_ERROR
 *         FILE_WRITE_ERROR
 *         FILE_CLOSE_ERROR
 */
int writeGroupsToDB(char *fileUrl, Group *groupArr[]);

/**
 * 外部API，读取联系人和分组数据解析为数组
 * @note 默认选取Config.h中的数据文件路径
 * @param contactArr
 * @param groupArr
 * @return FILE_OPEN_ERROR
 *         MALLOC_ERROR
 *         FILE_CLOSE_ERROR
 */
int readAllFromDB(ContactInfo *contactArr[],Group *groupArr[], int *contactNum, int *groupNum);

/**
 * 外部API，存储联系人和分组数据
 * @note 默认选取Config.h中的数据文件路径
 * @param contactArr
 * @param groupArr
 * @return FILE_OPEN_ERROR
 *         FILE_WRITE_ERROR
 *         FILE_CLOSE_ERROR
 */
int writeAllToDB(ContactInfo *contactArr[],Group *groupArr[]);


#endif
