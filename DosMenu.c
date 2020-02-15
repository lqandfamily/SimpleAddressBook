#include "DosMenu.h"

int mainMenu(int *menuIndex){
    while(1){
        puts(MAIN_MENU);
        loadFromFile();

        showAllContacts(menuIndex);

        if(*menuIndex == -1){
            return 0;
        }
    }
}

int showAllContacts(int *menuIndex){
    int i;

    ContactInfo **contacts = findAll();

    puts(ALL_CONTACTS);

    if(contacts[0]->id == END_ID_CODE){
        printf("There no contact, please to add\n");
        return SUCCESS;
    }

    printf("ID  NAME    PHONE          \n");
    for (i = 0; contacts[i]->id != END_ID_CODE; i++){
        printf("%-4d%-8s%-15s\n",contacts[i]->id,contacts[i]->name,contacts[i]->phoneNum);
    }

    puts(INPUT_MENU_INDEX);

    scanf("%d",menuIndex);
    if(*menuIndex == -1){
        return SUCCESS;
    }



    return SUCCESS;
}

int showAllGroups(int *menuIndex);

int showDetails(int *menuIndex);

int vagueSearch(int *menuIndex);

int deleteContact(int *menuIndex);

int modifyContact(int *menuIndex);

int loadFromFile(){

    if(loadFromDB() == ERROR){
        printf("ERROR:read file error!\n");
        return ERROR;
    }
    printf("SUCCESS:load success!\n");
    return SUCCESS;
}

int saveToFile(int *menuIndex);



int main(){
    int menuIndex = 999;
    mainMenu(&menuIndex);

    return 0;
}
