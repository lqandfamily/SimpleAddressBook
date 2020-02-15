/**
 * DOS菜单系统
 * @author lq
 * @date 2020/2/14
 * @version 0.3
 */

#ifndef DOS_MENU_H
#define DOS_MENU_H

#include "ArrayListCore.h"

char *MAIN_MENU = "**********SimpleAddressBook Software**********\n"
                  "1.show all contacts\n"
                  "2.show all groups\n"
                  "3.vague search\n"
                  "4.add\n"
                  "5.save to file\n"
                  "-1.exit";
char *ALL_CONTACTS = "**********ALL CONTACTS*********\n"
                     "*****input '-1' to exit, input index to show details*****";

char *CONTACT_DETAILS = "*********CONTACT DETAILS**********\n"
                        "-1.exit\n"
                        "1.modify\n"
                        "2.delete";
char *ALL_GROUPS = "**********ALL GROUPS**********\n"
                   "*****input '-1' to exit, input index to show  all contacts of the group******";

char *VAGUE_SEARCH = "**********VAGUE SEARCH**********\n"
                     "1.by name\n"
                     "2.by phoneNumber\n"
                     "3.by exact group name\n";

char *ADD_CONTACT = "**********ADD**********\n"
                    "if you want modify the item, please input text, input enter to not modify";

char *INPUT_MENU_INDEX = ">>>input menu index:";

int mainMenu();

int showAllContacts();

int showAllGroups();

int showContactsOfGroup(int groupId);

int showDetails(int id);

int vagueSearch();

int deleteContact(int id);

int modifyContact(int id);

int newContact();

int loadFromFile();

int saveToFile();

int inputMenuIndex(int *menuIndex, int maxMenuIndex);

#endif
