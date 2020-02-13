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

#define KIND_CONTACT 1
#define KIND_GROUP 2

/**
 * 从db文件中读取联系人信息存入数组
 * @version 0.20 没有实现分页读取
 * @param fileUrl
 * @param desArr 目标数组
 * @param kind 读取类型，可选KIND_CONTACT,KIND_GROUP
 * @return FILE_OPEN_ERROR
 *         MALLOC_ERROR
 */
int readFromDB(char *fileUrl, ContactInfo **desArr, int kind);

/**
 * 将所有联系人写入db文件中
 * @param fileUrl
 * @param srcArr 源数组
 * @param kind 读取类型，可选KIND_CONTACT,KIND_GROUP
 * @return FILE_OPEN_ERROR
 *         FILE_WRITE_ERROR
 */
int writeToDB(char *fileUrl, ContactInfo **srcArr, int kind);



#endif
