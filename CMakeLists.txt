cmake_minimum_required(VERSION 3.15)
project(SimpleAddressBook C)

set(CMAKE_C_STANDARD 99)

add_executable(SimpleAddressBook ArrayListCore.c ArrayListCore.h ErrorCode.h Config.h TestArrayListCore.c DataBaseCore.c DataBaseCore.h TestDatabaseCore.c Domain.h UnionTest.c DosMenu.c DosMenu.h)