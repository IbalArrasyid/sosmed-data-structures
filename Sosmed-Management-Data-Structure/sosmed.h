#ifndef SOSMED_H_INCLUDED
#define SOSMED_H_INCLUDED

#include <stdio.h>
#include <iostream>

#define NIL NULL
#define info(PP) (PP)->info
#define next(PP) (PP)->next
#define child(PP) (PP)->child
#define first(LP) ((LP).first)

using namespace std;

struct paketInfotype {
   string paketID;
   string nama_platform;
   int kuotaMax;
};

struct userInfotype {
    string NIM;
    string nama;
    string email;
    int semester;
};

typedef struct elementUser *adrUser;

struct elementUser {
    userInfotype info;
    adrUser next;
};

typedef struct childPaket *adrChildPaket;

struct childPaket {
    adrUser node;
    adrChildPaket next;
};

typedef struct elementPaket *adrElementPaket;

struct elementPaket {
    paketInfotype info;
    adrElementPaket next;
    adrChildPaket child;
};

struct listPaket {
    adrElementPaket first;
};

struct listUser {
    adrUser first;
};

void printMenu(int &selection);
void createListPaket(listPaket& LP);
void createListUser(listUser& LU);
void createElementPaket(paketInfotype paket, adrElementPaket& PP);
void createElementUser(userInfotype user, adrUser& PU);
adrChildPaket createChildNode(adrUser PU);
void printMenu();

                            /** INSERT **/
// a. Insert element parent
void insertFirstP(listPaket &LP, adrElementPaket PP);
void insertLastP(listPaket& LP, adrElementPaket PP);
void insertAfterP(listPaket& LP, adrElementPaket Prec, adrElementPaket PP);
void handleAddPaket(listPaket& LP, paketInfotype& paket, adrElementPaket& tempAdr);
// b. Insert element child
void insertFirstU(listUser &LU, adrUser& PU);
void handleAddUser(listUser &LU, userInfotype &user, adrUser &tempAdr);
void insertLastU(listUser& LU, adrUser& PU);
void insertAfterU(listUser& LU, adrUser Prec, adrUser& PU);
// c. Insert element relation
void addUserToPaket(adrElementPaket PP, adrUser PU);
void handleAddPaketToNewUser(listPaket LP, listUser LU);
void handleAddPaketToUserFromList(listPaket LP, listUser LU);

                            /** DELETE **/
// d. delete element parent
void deletePaket(listPaket& LP, adrElementPaket PP, adrElementPaket prev);
void handleDeletePaketByIDpaket(listPaket& LP);
// e. Delete element child
void deleteUser(listUser& LU, adrUser PU, adrUser prev);
void handleDeleteUserByName(listUser& LU);
void handleDeleteUserByNIM(listUser& LU);
// f. Delete element relation
void deleteFirstChild(adrChildPaket &PC, adrElementPaket &PP);
void handleDeleteLanggananOnPaketByIDpaket(listPaket LP, listUser LU);

                            /** FIND **/
// g. Find element parent
adrElementPaket searchPaket(listPaket LP, string IDpaket, adrElementPaket& prev);
// h. Find element child
adrUser searchUser(listUser LU, string nama, adrUser& prev);
adrUser searchUserByNIM(listUser LU, string NIM, adrUser& prev);
// i. Find element relation
adrChildPaket searchRelation(adrElementPaket P, adrUser U, adrChildPaket& prev);

                            /** SHOW **/
// j. Show all data di list parent
void showPaket(adrElementPaket PP,int no);
void handleShowPaketByIDpaket(listPaket LP);
// k. Show all data di list child
void showUser(adrUser PU);
void showAllUser(listUser LU);
void handleShowUserByNIM(listUser LU);
// l. Show data child dari parent tertentu
void handleShowUserOnPaketByIDpaket(listPaket LP);
// m. Show setiap data parent beserta data child yang berelasi dengannya
void showAllPaket(listPaket LP,bool withUser);
// n. Show data child beserta data parent yang masing-masing child miliki
void handleShowLanggananOnPaketByIDpaket(listPaket LP);
// o. Show data parent yang berelasi dengan child tertentu
void handleShowPaketOnUser(listPaket LP, listUser LU);

                            /** COUNT **/
// p. Count relation dari setiap element parent
void countRelations(listPaket LP);
// q. Count relation yang dimiliki oleh child tertentu
int countSubscriptions(adrUser U, listPaket LP);
void handleCountSubcriptions(listUser LU, listPaket LP);
// r. Count element child yang tidak memiliki relasi
int countUnusedChild(listUser LU, listPaket LP);
void handleCountUnusedPaket(listPaket LP);
int countUnusedUsers(listUser LU, listPaket LP);
void handleCountUnusedUser(listUser LU, listPaket LP);


                            /** EDIT **/
// s. Edit relasi /mengganti child dari parent tertentu
void handleEditPaketLangganan(listPaket LP, listUser LU);


#endif // SOSMED_H_INCLUDED
