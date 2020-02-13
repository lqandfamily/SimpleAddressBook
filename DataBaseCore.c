#include "DataBaseCore.h"

int openFile(char *fileUrl, char *mode, FILE **dbFile);

int closeFile(FILE *dbFile);

int readContactsFromDB(char *fileUrl, ContactInfo *contactArr[]) {
    FILE *db;
    int i, flag;
    if (openFile(fileUrl, "r", &db) != SUCCESS) {
        return FILE_OPEN_ERROR;
    }


    i = 0;
    while (1) {
        //动态内存申请
        ContactInfo *newContact = malloc(sizeof(ContactInfo));
        if (newContact == NULL) {
            return MALLOC_ERROR;
        }
        flag = fscanf(db, "%d", &newContact->id);
        if (flag == EOF) {
            contactArr[i] = getEndContact();
            return SUCCESS;
        }

        fscanf(db, "%s", newContact->name);
        fscanf(db, "%s", newContact->phoneNum);
        fscanf(db, "%s", newContact->address);
        fscanf(db, "%d", &newContact->groupId);

        contactArr[i] = newContact;

        i++;
        //联系人数组用尽
        if (i >= MAX_CONTACT - 1) {
            contactArr[i] = getEndContact();
            return RUN_OUT;
        }

//        //此段为调试用代码
//        printf("************%d,%s,%s,%s,%d\n", newContact->id, newContact->name, newContact->phoneNum,
//               newContact->address, newContact->groupId);

    }
}

int writeContactsToDB(char *fileUrl, ContactInfo *contactArr[]) {
    int i;
    FILE *db = NULL;

    if (openFile(fileUrl, "a", &db) != SUCCESS) {
        return FILE_OPEN_ERROR;
    }

    for (i = 0; contactArr[i]->id != END_ID_CODE; i++) {

        if (EOF ==
            fprintf(db, "%d %s %s %s %d\n", contactArr[i]->id, contactArr[i]->name, contactArr[i]->phoneNum,
                    contactArr[i]->address,
                    contactArr[i]->groupId)) {
            return FILE_WRITE_ERROR;
        }
    }

    if (closeFile(db) == FILE_CLOSE_ERROR) {
        return FILE_CLOSE_ERROR;
    }
    return SUCCESS;
}

int delContactInDB(char *fileUrl, int id) {
    FILE *db = NULL;

    if (openFile(fileUrl, "w+", &db) != SUCCESS) {
        return FILE_OPEN_ERROR;
    }

    if (closeFile(db) == FILE_CLOSE_ERROR) {
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