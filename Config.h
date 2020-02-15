/**
 * @author lq
 * @version 0.1
 * @date 2020/2/12
 * 外部配置类，可在这里配置一些选项
 */

#ifndef CONFIG_H
#define CONFIG_H

//联系人最大容量，超过无法添加
#define MAX_CONTACT 100
//分组最大容量，超过无法添加
#define MAX_GROUP 50

//数据库存储文件及文件名定义
#define CONTACTS_DB_FILE_URL "C:\\Users\\blue\\CLionProjects\\SimpleAddressBook\\db\\contacts.db"
#define GROUPS_DB_FILE_URL "C:\\Users\\blue\\CLionProjects\\SimpleAddressBook\\db\\groups.db"

//菜单系统中索引的边界
#define MIN_MENU_INDEX -1
#define MAX_MENU_INDEX 65536



#endif
