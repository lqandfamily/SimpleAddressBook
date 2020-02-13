/**
 * 核心数据持久化
 * @author lq
 * @date 2020/2/13
 * @version 0.20
 */
#ifndef DATABASE_CORE_H
#define DATABASE_CORE_H

/**
 * 打开/关闭文件
 * 读取文件（*分页）
 * 写入文件（尾部）
 * 修改/删除信息（随机）
 *
 *
 *
 */

#include <stdio.h>
#include "ArrayListCore.h"

#define BUFFER_LENGTH 1024

/**
 * 从db文件中读取联系人信息存入数组
 * @version 0.20 没有实现分页读取
 * @param fileName
 * @param contactArr
 * @return
 */
int readContactsFromDB(char *fileUrl, ContactInfo *contactArr[]);

/**
 * 将新增的联系人写入db文件中
 * @param fileUrl
 * @param contact
 * @return FILE_OPEN_ERROR
 *         FILE_WRITE_ERROR
 */
int addContactToDB(char *fileUrl, ContactInfo *contact);

/**
 * 从DB文件中删除联系人
 * @param fileUrl
 * @param id
 * @return FILE_OPEN_ERROR
 *         FILE_WRITE_ERROR
 */
int delContactInDB(char *fileUrl, int id);


#endif
