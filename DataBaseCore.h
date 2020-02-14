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
 */
int readContactsFromDB(char *fileUrl, ContactInfo *contactArr[]);

/**
 * 将所有联系人写入db文件中
 * @param fileUrl
 * @param contactArr 源数组
 * @return FILE_OPEN_ERROR
 *         FILE_WRITE_ERROR
 */
int writeContactsToDB(char *fileUrl, ContactInfo *contactArr[]);


/**
 * 从db文件中读取联系人信息存入数组
 * @version 0.20 没有实现分页读取
 * @param fileUrl
 * @param groupArr 目标数组
 * @return FILE_OPEN_ERROR
 *         MALLOC_ERROR
 */
int readGroupsFromDB(char *fileUrl, Group *groupArr[]);

/**
 * 将所有联系人写入db文件中
 * @param fileUrl
 * @param groupArr 源数组
 * @return FILE_OPEN_ERROR
 *         FILE_WRITE_ERROR
 */
int writeGroupsToDB(char *fileUrl, Group *groupArr[]);


#endif
