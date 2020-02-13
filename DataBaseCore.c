#include "DataBaseCore.h"

int openFile(char *fileUrl, char *mode, FILE **dbFile);

int closeFile(FILE *dbFile);

int readContactsFromDB(char *fileUrl, ContactInfo *contactArr[]){
    FILE *db;
    int i;
    char line[BUFFER_LENGTH];
    if(openFile(fileUrl,"r",&db)!=SUCCESS){
        return FILE_OPEN_ERROR;
    }

    int id;
    char name[20];
    char phoneNum[20];
    char address[20];
    int groupId;

    //动态内存申请
    ContactInfo *newContact = malloc(sizeof(ContactInfo));
    if(newContact == NULL){
        return MALLOC_ERROR;
    }

    fscanf(db,"%d",&id);
    fscanf(db,"%s",name);
    fscanf(db,"%s",phoneNum);
    fscanf(db,"%s",address);
    fscanf(db,"%d",&groupId);

    printf("************%d,%s,%s,%s,%d\n",id,name,phoneNum,address,groupId);

    if(closeFile(db)==FILE_CLOSE_ERROR){
        return FILE_CLOSE_ERROR;
    }
    return SUCCESS;
}

int addContactToDB(char *fileUrl, ContactInfo *contact) {
    FILE *db = NULL;

    if (openFile(fileUrl, "a",&db) != SUCCESS) {
        return FILE_OPEN_ERROR;
    }

    if (EOF == fprintf(db, "%d %s %s %s %d\n", contact->id, contact->name, contact->phoneNum, contact->address,
                       contact->groupId)) {
        return FILE_WRITE_ERROR;
    }

    if(closeFile(db)==FILE_CLOSE_ERROR){
        return FILE_CLOSE_ERROR;
    }
    return SUCCESS;
}

/**
 * 打开DB文件
 * @param fileUrl 文件全路径
 * @param mode 文件打开模式
 * @param dbFile File类型指针地址，用于接收打开的文件指针
 * @return FILE_OPEN_ERROR
 */
int openFile(char *fileUrl, char *mode, FILE **dbFile) {
    *dbFile = fopen(fileUrl, mode);
    if (*dbFile == NULL) {
        return FILE_OPEN_ERROR;
    }
    return SUCCESS;
}

/**
 * 关闭DB文件
 * @param dbFile
 * @return File_CLOSER_ERROR
 */
int closeFile(FILE *dbFile) {
    if (fclose(dbFile) != 0) {
        return FILE_CLOSE_ERROR;
    }
    return SUCCESS;
}