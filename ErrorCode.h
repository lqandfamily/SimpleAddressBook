/**
 * @author lq
 * @version 0.1
 * @date 2020/2/12
 * 程序返回状态码定义
 */

#ifndef ERROR_CODE_H
#define ERROR_CODE_H

#define SUCCESS 1           //操作成功
#define ERROR 0             //操作失败
#define NULL_POINT -1       //空指针
#define NAME_NULL -2        //姓名为NULL或''
#define NAME_EXIST -3       //姓名已经存在
#define PHONE_NULL -4       //电话为NULL或''
#define PHONE_EXIST -5      //电话已经存在
#define GROUP_NULL -6       //分组为NULL或''
#define ID_NOT_EXIST -7     //id不存在
#define RUN_OUT -9          //联系人容量溢出，无法添加
#define MALLOC_ERROR -10    //动态内存申请失败


#endif
