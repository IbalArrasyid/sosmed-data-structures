#include "sosmed.h"

void createListPaket(listPaket& LP){
    LP.first = NULL;
}

void createListUser(listUser& LU){
    LU.first = NULL;
}

void createElementPaket(paketInfotype paket, adrElementPaket& PP){
    PP = new elementPaket;
    info(PP) = paket;
    next(PP) = NULL;
    child(PP) = NULL;
}

void createElementUser(userInfotype user, adrUser& PU){
    PU = new elementUser;
    info(PU) = user;
    next(PU) = NULL;
}

adrChildPaket createChildNode(adrUser PU){
    adrChildPaket PC = new childPaket;
    PC->node = PU;
    PC->next = NULL;
    return PC;
}

void insertFirstP(listPaket &LP, adrElementPaket PP){
    if(LP.first != NULL) {
        next(PP) = first(LP);
        first(LP) = PP;
    }else{
        first(LP) = PP;
        next(PP) = NULL;
    }
}

void insertLastP(listPaket& LP, adrElementPaket PP) {
    if (LP.first == NULL) {
        LP.first = PP;
    } else {
        adrElementPaket temp = LP.first;
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = PP;
    }
    next(PP) = NULL;
}

void insertAfterP(listPaket& LP, adrElementPaket Prec, adrElementPaket PP) {
    if (Prec == NULL) {
        cout << "Cannot insert after a NULL pointer." << endl;
        return;
    }

    next(PP) = next(Prec);
    next(Prec) = PP;
}



void showPaket(adrElementPaket PP,int no){
    cout << "No| "<< no << endl;
    cout << "ID Paket: " << info(PP).paketID << endl;
    cout << "Platform: " << info(PP).nama_platform << endl;
    cout << "Kuota Maksimal: " << info(PP).kuotaMax << endl;
    cout << endl;
}

void showUser(adrUser PU){
    cout << "NIM: " << info(PU).NIM << endl;
    cout << "Nama: " << info(PU).nama << endl;
    cout << "Email: " << info(PU).email << endl;
    cout << "Semester: " << info(PU).semester << endl;
    cout << endl;
}

void showAllPaket(listPaket LP,bool withUser){
    int i = 0;
    if (first(LP) != NULL) {
        adrElementPaket P = first(LP);
        do {
            showPaket(P,i+1);
            if(withUser && P->child != NULL) {
                adrChildPaket tempChild = child(P);
                cout << "Claim by:" << endl;
                while((tempChild) != NULL) {
                    showUser(tempChild->node);
                    tempChild = next(tempChild);
                }
                cout << endl;
            }
            P = next(P);
            i++;
        } while (P != NULL);
    } else {
        cout << "List Kosong" << endl;
    }
}

adrElementPaket searchPaket(listPaket LP, string IDpaket, adrElementPaket& prev){
    prev = NULL;
    adrElementPaket P = first(LP);
    if (P != NULL) {
        do {
            if (info(P).paketID == IDpaket) {
                return P;
            }
            prev = P;
            P = next(P);
        } while (P != NULL);
    }
    return NULL;
}

void deletePaket(listPaket& LP, adrElementPaket PP, adrElementPaket prev){
    if (prev == NULL) {
        first(LP) = next(PP);
    } else {
        next(prev) = next(PP);
    }

    delete PP;
}

void deleteUser(listUser& LU, adrUser PU, adrUser prev){
    if (prev == NULL){
        first(LU) = next(PU);
    } else {
        next(prev) = next(PU);
    }

    delete PU;
}

void insertFirstU(listUser &LU, adrUser& PU){
    if (LU.first == NULL)
    {
        LU.first = PU;
    }
    else
    {
        PU->next = LU.first;
        LU.first = PU;
    }
}

void insertLastU(listUser& LU, adrUser& PU) {
    if (LU.first == NULL) {
        LU.first = PU;
    } else {
        adrUser temp = LU.first;
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = PU;
    }
    next(PU) = NULL;
}

void insertAfterU(listUser& LU, adrUser Prec, adrUser& PU) {
    if (Prec == NULL) {
        cout << "Cannot insert after a NULL pointer." << endl;
        return;
    }

    next(PU) = next(Prec);
    next(Prec) = PU;
}


adrUser searchUser(listUser LU, string nama, adrUser& prev){
    prev = NULL;
    adrUser P = first(LU);
    if (P != NULL) {
        do {
            if (info(P).nama == nama) {
                return P;
            }
            prev = P;
            P = next(P);
        } while (P != NULL);
    }
    return NULL;
}

adrUser searchUserByNIM(listUser LU, string NIM, adrUser& prev){
    prev = NULL;
    adrUser P = first(LU);
    if (P != NULL) {
        do {
            if (info(P).NIM == NIM) {
                return P;
            }
            prev = P;
            P = next(P);
        } while (P != NULL);
    }
    return NULL;
}

void addUserToPaket(adrElementPaket PP, adrUser PU){
    if(PP->child == NULL){
        PP->child = createChildNode(PU);
    } else {
        adrChildPaket tempChild = PP->child;
        while(next(tempChild) != NULL){
            tempChild = next(tempChild);
        }
        next(tempChild) = createChildNode(PU);
    }
}

void showAllUser(listUser LU){
    adrUser P = first(LU);
    if (first(LU) != NULL) {
       while(P != NULL) {
          showUser(P);
          P = next(P);
       };
    } else {
        cout << "List Kosong" << endl;
    }
}

void deleteFirstChild(adrChildPaket &PC, adrElementPaket &PP){
    if(PC == NULL) {
        cout <<  "Graph Kosong"<< endl;
    }

    adrChildPaket P = PC;
    PP->child = P->next;
    P->next = NULL;

}

void printMenu(int &selection){
    cout << endl;
    cout << "================== MENU =========================" << endl;
    cout << "= 1.  Tambah Paket                              =" << endl;
    cout << "= 2.  Tambah User                               =" << endl;
    cout << "= 3.  Hapus Paket dengan ID                     =" << endl;
    cout << "= 4.  Hapus User dengan NIM                     =" << endl;
    cout << "= 5.  Tampilkan Semua Paket                     =" << endl;
    cout << "= 6.  Tampilkan Data paket dengan ID            =" << endl;
    cout << "= 7.  Tampilkan Data user dengan NIM            =" << endl;
    cout << "= 8.  Daftarkan Paket Ke User Baru              =" << endl;
    cout << "= 9.  Daftarkan Paket Ke User Dari List User    =" << endl;
    cout << "= 10. Lihat Daftar User                         =" << endl;
    cout << "= 11. Lihat Paket dan User                      =" << endl;
    cout << "= 12. Hapus User Pada Paket X                   =" << endl;
    cout << "= 13. Lihat Daftar User Pada Paket X            =" << endl;
    cout << "= 14. Lihat Daftar Paket Pada User X            =" << endl;
    cout << "= 15. Cari User dengan ID pada Paket X          =" << endl;
    cout << "= 16. Tampilkan Jumlah relasi dari setiap paket =" << endl;
    cout << "= 17. Tampilkan Jumlah relasi dari user X       =" << endl;
    cout << "= 18. Tampilkan Jumlah Paket Kosong             =" << endl;
    cout << "= 19. Tampilkan Jumlah User Kosong              =" << endl;
    cout << "= 20. Edit Data Langganan Paket                 =" << endl;
    cout << "= -1. EXIT                                      =" << endl;
    cout << "=================================================" << endl;
    cout << endl;
    cout << "Masukan Pilihan : ";
    cin >> selection;
    cout << endl;
}

void handleAddPaket(listPaket& LP, paketInfotype& paket, adrElementPaket& tempAdr){
    createElementPaket(paket,tempAdr);
    cout << "Masukan ID paket : ";
    cin >> paket.paketID;
    tempAdr = searchPaket(LP, paket.paketID,tempAdr);
    while (tempAdr != NULL){
        cout << "ID paket tidak tersedia, masukan kembali ID paket:\n";
        cout << "Masukan ID paket : ";
        cin >> paket.paketID;
        tempAdr = searchPaket(LP, paket.paketID, tempAdr);
    }
    cout << "Masukan Nama Platform : ";
    cin >> paket.nama_platform;
    cout << "Masukan Maksimum Kuota : ";
    cin >> paket.kuotaMax;
    cout << "\n[Sukses!!]" << endl;
    createElementPaket(paket, tempAdr);
    insertLastP(LP, tempAdr);
}

void handleAddUser(listUser &LU, userInfotype &user, adrUser &tempAdr){
    cout << "Masukan NIM : ";
    cin >> user.NIM;
    tempAdr = searchUserByNIM(LU, user.NIM, tempAdr);
    while (tempAdr != NULL){
        cout << "NIM tidak tersedia, masukan kembali NIM :\n";
        cout << "Masukan NIM : ";
        cin >> user.NIM;
        tempAdr = searchUserByNIM(LU, user.NIM, tempAdr);
    }
    cout << "Masukan Nama User : ";
    cin >> user.nama;
    cout << "Masukan Email User : ";
    cin >> user.email;
    cout << "Masukan Semester User : ";
    cin >> user.semester;
    cout << "\n[Sukses!!]" << endl;
    createElementUser(user, tempAdr);
    insertLastU(LU, tempAdr);
}

void handleDeletePaketByIDpaket(listPaket& LP) {
    string IDpaket;
    adrElementPaket prev;
    adrElementPaket target;

    cout << "Masukan ID Paket: ";
    cin >> IDpaket;

    target = searchPaket(LP, IDpaket, prev);

    if (target != NULL) {
        if (target->child != NULL) {
            cout << "Gagal menghapus paket, karena memiliki relasi..\n";
        } else {
            cout << "Data ditemukan, menghapus..." << endl;
            deletePaket(LP, target, prev);
            cout << "\n[Selesai!!]" << endl;
        }
    } else {
        cout << "\nID Paket Tidak Ditemukan" << endl << endl;
    }
}


void handleDeleteUserByName(listUser& LU){
    string nama;
    adrUser prev;
    adrUser target;
    cout << "Masukan nama user: ";
    cin >> nama;
    target = searchUser(LU, nama, prev);
    if(target != NULL){
        cout << "Data ditemukan, menghapus..." << endl;
        deleteUser(LU,target,prev);
        cout << "\n[Selesai!!]" << endl;
    } else {
        cout << "\nNama User Tidak Ditemukan" << endl << endl;
    }
}

void handleDeleteUserByNIM(listUser& LU){
    string NIM;
    adrUser prev;
    adrUser target;
    cout << "Masukan NIM user: ";
    cin >> NIM;
    target = searchUserByNIM(LU, NIM, prev);
    if(target != NULL){
        cout << "Data ditemukan, menghapus..." << endl;
        deleteUser(LU,target,prev);
        cout << "\n[Selesai!!]" << endl;
    } else {
        cout << "\nNama User Tidak Ditemukan" << endl << endl;
    }
}

void handleShowPaketByIDpaket(listPaket LP){
    string IDpaket;
    adrElementPaket prev;
    adrElementPaket target;

    cout << "Masukan ID: ";
    cin >> IDpaket;
    target = searchPaket(LP,IDpaket,prev);
    if(target != NULL) {
        cout << "Data ditemukan, berikut adalah data dari paket tersebut:" << endl;
        showPaket(target,1);
    } else {
        cout << "\nID Tidak Ditemukan" << endl << endl;
    }
}

void handleShowUserByNIM(listUser LU){
    string NIM;
    adrUser prev;
    adrUser target;

    cout << "Masukan NIM: ";
    cin >> NIM;
    target = searchUserByNIM(LU, NIM, prev);
    if(target != NULL) {
        cout << "Data ditemukan, berikut adalah data dari user tersebut:" << endl;
        showUser(target);
    } else {
        cout << "\nNIM Tidak Ditemukan" << endl << endl;
    }
}

void handleAddPaketToNewUser(listPaket LP, listUser LU)
{
    string IDpaket;
    adrElementPaket prev;
    adrElementPaket target;
    adrUser prevUser;
    adrUser targetUser;
    userInfotype user;
    adrUser userElTemp;
    cout << "Masukan ID Paket: ";
    cin >> IDpaket;
    target = searchPaket(LP, IDpaket, prev);

    if (target != NULL)
    {
        int userCount = 0;

        adrChildPaket tempChild = child(target);
        while (tempChild != NULL)
        {
            userCount++;
            tempChild = next(tempChild);
        }
        int emptySlot = info(target).kuotaMax - userCount;
        int userAmount;

        cout << "Masukan Jumlah User, Batas maksimum " << emptySlot << " : ";
        cin >> userAmount;

        if (userAmount <= emptySlot)
        {
            for (int i = 0; i < userAmount; i++)
            {
                cout << "\nMasukan Nama User " << to_string(i + 1) << " : ";
                cin >> user.nama;
                cout << "Masukan NIM User " << to_string(i + 1) << " : ";
                cin >> user.NIM;
                cout << "Masukan Email User " << to_string(i + 1) << " : ";
                cin >> user.email;
                cout << "Masukan Semester User " << to_string(i + 1) << " : ";
                cin >> user.semester;
                if (user.semester > 4){
                    cout << "Alert! Paket ini hanya untuk mahasiswa tahun 1 & 2\n";
                    return;
                }
                targetUser = searchUserByNIM(LU, user.NIM, prevUser);
                if (targetUser == NULL)
                {
                    createElementUser(user, userElTemp);
                    insertLastU(LU, userElTemp);
                    targetUser = userElTemp;
                }

                addUserToPaket(target, targetUser);
                cout << "\n[Sukses!!]" << endl;
            }
        }
        else
        {
            cout << "\nJumlah User Melebihi Kuota" << endl;
        }
    }
    else
    {
        cout << "\nID tidak terdaftar" << endl;
    }
}

void handleAddPaketToUserFromList(listPaket LP, listUser LU)
{
    string IDpaket;
    adrElementPaket prev;
    adrElementPaket target;
    adrUser prevUser;
    adrUser targetUser;
    userInfotype user;
    cout << "Masukan ID Paket: ";
    cin >> IDpaket;
    target = searchPaket(LP, IDpaket, prev);

    if (target != NULL)
    {
        int userCount = 0;

        adrChildPaket tempChild = child(target);
        while (tempChild != NULL)
        {
            userCount++;
            tempChild = next(tempChild);
        }
        int emptySlot = info(target).kuotaMax - userCount;
        int userAmount;

        cout << "Masukan Jumlah User, Batas maksimum " << emptySlot << " : ";
        cin >> userAmount;

        if (userAmount <= emptySlot)
        {
            for (int i = 0; i < userAmount; i++)
            {
                cout << "\nMasukan Nama User " << to_string(i + 1) << " : ";
                cin >> user.nama;
                targetUser = searchUser(LU, user.nama, prevUser);
                if (targetUser == NULL)
                {
                    cout << "User belum terdaftar di List-User\n";
                    cout << "\n";
                    return;
                }else {
                    if (targetUser->info.semester > 3){
                        cout << "Alert! Paket ini hanya untuk mahasiswa tahun 1 & 2" << endl;
                        return;
                    }
                    addUserToPaket(target, targetUser);
                    cout << "\n[Sukses!!]" << endl;
                }
            }
        }
        else
        {
            cout << "\nJumlah User Melebihi Kuota" << endl;
        }
    }
    else{
        cout << "\nID tidak terdaftar" << endl;
    }
}

void handleDeleteLanggananOnPaketByIDpaket(listPaket LP, listUser LU){
    string IDpaket;
    string NIM;
    cout << "Masukan ID Paket: ";
    cin >> IDpaket;
    cout << "Masukan NIM User: ";
    cin >> NIM;

    adrUser prevUser;
    adrUser targetUser = searchUserByNIM(LU, NIM, prevUser);
    if (targetUser == NULL){
        cout << "\nUser tidak ditemukan.." << endl;
        return;
    }

    adrElementPaket prev;
    adrElementPaket target = searchPaket(LP, IDpaket, prev);

    if(target != NULL) {

        cout << "Data paket ditemukan, menghapus..." << endl;
        if (target->child != NULL){
            adrChildPaket C = target->child;

            if (C->node == targetUser){
                deleteFirstChild(C, target);
                cout << "\n[Sukses!!]" << endl;
                return;
            }

            while(C->next != NULL){
                if (C->next->node == targetUser){
                    C->next = C->next->next;
                    delete targetUser;
                    cout << "\n[Sukses!!]" << endl;
                    return;
                }
                C = C->next;
            }
            cout << "\n[Gagal!!] User tidak berlangganan pada paket ini.." << endl;
        } else {
            cout << "\n[Gagal!!] Paket belum memiliki pelanggan..";
            return;
        }
    } else {
        cout << "\nPaket tidak ditemukan.." << endl;
    }
}


void handleShowLanggananOnPaketByIDpaket(listPaket LP){
    string IDpaket;
    cout << "Masukan ID Paket: ";
    cin >> IDpaket;
    adrElementPaket prev;
    adrElementPaket target;
    target = searchPaket(LP, IDpaket, prev);
    if(target != NULL) {
        if(child(target) == NULL) {
            cout << "\nUser Kosong, Silahkan tambahkan pada menu." << endl;
            return;
        }
        adrChildPaket tempChild = child(target);
        while(tempChild != NULL) {
            showUser(tempChild->node);
            tempChild = next(tempChild);
        }
    }
}

// o. Show data parent yang berelasi dengan child tertentu
void handleShowPaketOnUser(listPaket LP, listUser LU) {
    string targetNIM;
    cout << "Masukan NIM User: ";
    cin >> targetNIM;
    adrUser targetUser;
    adrChildPaket relation;
    adrUser Prev;
    adrChildPaket PrevChild;

    targetUser = searchUserByNIM(LU, targetNIM, Prev);
    if (targetUser != NULL) {
        cout << "Paket dengan NIM " << targetUser->info.NIM << ":" << endl;

        adrElementPaket P = first(LP);
        while (P != NULL) {
            relation = searchRelation(P, targetUser, PrevChild);
            if (relation != NULL) {
                showPaket(P, 1);
            }
            P = next(P);
        }
        cout << "\nKosong, Silahkan tambahkan pada menu.." << endl;
    } else {
        cout << "\nUser tidak ditemukan.." << endl;
    }
}

void handleShowUserOnPaketByIDpaket(listPaket LP){
    string IDpaket;
    string namaUser;
    cout << "Masukan ID Paket: ";
    cin >> IDpaket;
    adrElementPaket prev;
    adrElementPaket target;
    target = searchPaket(LP,IDpaket,prev);
    if(target != NULL) {
        cout << "Masukan nama user: ";
        cin >> namaUser;
        adrChildPaket tempChild = child(target);
        while(tempChild != NULL) {
            if(info(tempChild->node).nama != namaUser) {
                tempChild = next(tempChild);
            } else {
                showUser(tempChild->node);
                return;
            }
        }
        cout << "\nUser tidak ditemukan.." << endl;
    }
}

void handleCountUnusedPaket(listPaket LP){
    int counter = 0;
    adrElementPaket temp = first(LP);
    if(first(LP) == NULL) {
        cout << "Data kosong";
        return;
    }
    do {
        if(child(temp) == NULL) {
            counter ++;
            showPaket(temp,counter);
        }
        temp = next(temp);
    } while(temp != NULL);
    cout << "Jumlah Paket yang masih kosong : " << counter << endl;
}

int countUnusedUsers(listUser LU, listPaket LP) {
    int count = 0;

    adrUser tempUser = first(LU);
    while (tempUser != NULL) {
        // Check if the user is not a child in any package
        bool hasRelations = false;

        adrElementPaket tempPackage = first(LP);
        while (tempPackage != NULL) {
            adrChildPaket tempChild = child(tempPackage);
            while (tempChild != NULL) {
                if (tempChild->node == tempUser) {
                    hasRelations = true;
                    break;
                }
                tempChild = next(tempChild);
            }

            if (hasRelations) {
                break;
            }

            tempPackage = next(tempPackage);
        }

        if (!hasRelations) {
            count++;
            showUser(tempUser);
        }

        tempUser = next(tempUser);
    }

    return count;
}

void handleCountUnusedUser(listUser LU, listPaket LP){
    int unusedCount = countUnusedUsers(LU, LP);
    if (unusedCount == 0) {
        cout << "Semua user memiliki paket langganan.." << endl;
    } else {
        cout << "Jumlah user yang tidak memiliki paket langganan: " << unusedCount << endl;
    }
}

// i. Find element relation
adrChildPaket searchRelation(adrElementPaket P, adrUser U, adrChildPaket& prev) {
    adrChildPaket C = child(P);
    prev = NIL;

    while (C != NIL && C->node != U) {
        prev = C;
        C = next(C);
    }

    return C;
}



// p. Count relation dari setiap element parent
void countRelations(listPaket LP) {
    adrElementPaket P = first(LP);

    while (P != NIL) {
        int relationCount = 0;

        adrChildPaket C = child(P);
        while (C != NIL) {
            relationCount++;
            C = next(C);
        }

        cout << "Package: " << info(P).paketID << " - Jumlah Subscribers: " << relationCount << endl;

        P = next(P);
    }
}

// q. Count relation yang dimiliki oleh child tertentu
int countSubscriptions(adrUser U, listPaket LP) {
    int count = 0;

    adrElementPaket P = first(LP);

    while (P != NIL) {
        adrChildPaket C = child(P);
        while (C != NIL) {
            if (C->node == U) {
                count++;
            }
            C = next(C);
        }
        P = next(P);
    }

    return count;
}

void handleCountSubcriptions(listUser LU, listPaket LP){
    adrUser prevUser;
    string targetNIM;
    cout << "\nMasukan NIM user: ";
    cin >> targetNIM;
    adrUser targetUser = searchUserByNIM(LU, targetNIM, prevUser);
    if (targetUser != NIL) {
        int subscriptionCount = countSubscriptions(targetUser, LP);
        cout << "User dengan NIM " << targetNIM << " memiliki " << subscriptionCount << " subscriptions." << endl;
    } else {
        cout << "\nUser tidak ditemukan.." << endl;
    }
}

// r. Count element child yang tidak memiliki relasi
int countUnusedChild(listUser LU, listPaket LP) {
    int count = 0;

    adrUser U = first(LU);

    while (U != NIL) {
        if (countSubscriptions(U, LP) == 0) {
            count++;
        }
        U = next(U);
    }

    return count;
}

// s. Edit relasi /mengganti child dari parent tertentu
void handleEditPaketLangganan(listPaket LP, listUser LU) {
    string IDpaket, oldNIM, newNIM;
    cout << "Masukan ID Paket: ";
    cin >> IDpaket;
    adrElementPaket targetPaket;
    adrUser oldUser, newUser;
    adrElementPaket Prev;
    adrUser PrevUser;
    adrChildPaket PrevChild;

    targetPaket = searchPaket(LP, IDpaket, Prev);
    if (targetPaket != NULL) {
        if (targetPaket->child == NULL){
            cout << "\nPaket tidak memiliki subscribes.." << endl << endl;;
            return;
        }
        cout << "\nMasukan NIM lama: ";
        cin >> oldNIM;
        cout << "Masukan NIM baru: ";
        cin >> newNIM;
        cout << endl;
        oldUser = searchUserByNIM(LU, oldNIM, PrevUser);
        newUser = searchUserByNIM(LU, newNIM, PrevUser);

        if (oldUser != NULL && newUser != NULL) {
            adrChildPaket relation = searchRelation(targetPaket, oldUser, PrevChild);

            if (relation != NULL) {
                deleteFirstChild(relation, targetPaket);
                addUserToPaket(targetPaket, newUser);

                cout << "Sukses edit subscribes.." << endl;
            } else {
                cout << "User dengan NIM lama " << oldNIM << " tidak ada dalam list paket.." << endl;
            }
        } else {
            cout << "NIM user lama atau baru tidak ditemukan.." << endl;
        }
    } else {
        cout << "Paket tidak ditemukan.." << endl;
    }
}
