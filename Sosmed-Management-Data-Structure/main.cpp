#include "sosmed.h"
using namespace std;

int main()
{
    cout<<"================================================================="<<endl;
    cout<<"=              System free paid-subs untuk mahasiswa            ="<<endl;
    cout<<"================================================================="<<endl;
    cout<<"=                          Created BY                           ="<<endl;
    cout<<"=               Muhammad Iqbal Arrasyid (1304221038)            ="<<endl;
    cout<<"=                   Ahmad NurFaozi (1304212125)                 ="<<endl;
    cout<<"=                  Tugas Besar : Struktur Data                  ="<<endl;
    cout<<"================================================================="<<endl<<endl<<endl;
    system("PAUSE");
    system("CLS");
    listPaket LP;
    listUser LU;
    paketInfotype paket;
    userInfotype user;

    adrElementPaket tempAdr;
    adrUser tempAdrUser;
//    bool stop = false;

    createListPaket(LP);
    createListUser(LU);


    // Predefined ID for debug purpose
    paket.paketID = "ID1";
    paket.nama_platform = "Adobe";
    paket.kuotaMax = 5;
    createElementPaket(paket, tempAdr);
    insertLastP(LP, tempAdr);


    paket.paketID = "ID2";
    paket.nama_platform = "JetBrains";
    paket.kuotaMax = 7;
    createElementPaket(paket, tempAdr);
    insertLastP(LP, tempAdr);

    paket.paketID = "ID3";
    paket.nama_platform = "Autodesk";
    paket.kuotaMax = 10;
    createElementPaket(paket, tempAdr);
    insertLastP(LP, tempAdr);

    paket.paketID = "ID4";
    paket.nama_platform = "AWS";
    paket.kuotaMax = 10;
    createElementPaket(paket, tempAdr);
    insertLastP(LP, tempAdr);

    paket.paketID = "ID5";
    paket.nama_platform = "Azure";
    paket.kuotaMax = 8;
    createElementPaket(paket, tempAdr);
    insertLastP(LP, tempAdr);

    paket.paketID = "ID6";
    paket.nama_platform = "Cisco";
    paket.kuotaMax = 15;
    createElementPaket(paket, tempAdr);
    insertLastP(LP, tempAdr);

    user.NIM = "1304212125";
    user.nama = "Ahmad";
    user.email = "ahmad@gmail.com";
    user.semester = 3;
    createElementUser(user,tempAdrUser);
    insertLastU(LU,tempAdrUser);

    user.NIM = "1304221038";
    user.nama = "Iqbal";
    user.email = "Iqbal@gmail.com";
    user.semester = 3;
    createElementUser(user,tempAdrUser);
    insertLastU(LU,tempAdrUser);

    user.NIM = "1304213273";
    user.nama = "Sarah";
    user.email = "sarah@gmail.com";
    user.semester = 4;
    createElementUser(user,tempAdrUser);
    insertLastU(LU,tempAdrUser);

    user.NIM = "1304328179";
    user.nama = "Aisyah";
    user.email = "Aisyah@gmail.com";
    user.semester = 5;
    createElementUser(user,tempAdrUser);
    insertLastU(LU,tempAdrUser);

    int selection;
    printMenu(selection);
    while(selection != -1){
        switch(selection) {
        case 1:
            handleAddPaket(LP,paket,tempAdr);
            break;
        case 2:
            handleAddUser(LU, user, tempAdrUser);
            break;
        case 3:
            handleDeletePaketByIDpaket(LP);
            break;
        case 4:
            handleDeleteUserByNIM(LU);
            break;
        case 5:
            showAllPaket(LP,false);
            break;
        case 6:
            handleShowPaketByIDpaket(LP);
            break;
        case 7:
            handleShowUserByNIM(LU);
            break;
        case 8:
            handleAddPaketToNewUser(LP, LU);
            break;
        case 9:
            handleAddPaketToUserFromList(LP, LU);
            break;
        case 10:
            showAllUser(LU);
            break;
        case 11:
            showAllPaket(LP,true);
            break;
        case 12:
            handleDeleteLanggananOnPaketByIDpaket(LP, LU);
            break;
        case 13:
            handleShowLanggananOnPaketByIDpaket(LP);
            break;
        case 14:
            handleShowPaketOnUser(LP, LU);
            break;
        case 15:
            handleShowUserOnPaketByIDpaket(LP);
            break;
        case 16:
            countRelations(LP);
            break;
        case 17:
            handleCountSubcriptions(LU, LP);
            break;
        case 18:
            handleCountUnusedPaket(LP);
            break;
        case 19:
            handleCountUnusedUser(LU, LP);
            break;
        case 20:
            handleEditPaketLangganan(LP, LU);
            break;
        default:
            cout << "Masukan yang benar" << endl;
        }
        cout<<endl;
        system("PAUSE");
        system("CLS");
        printMenu(selection);
    }
    cout << "Terima Kasih Telah Menggunakan Aplikasi ini :)" << endl;

    return 0;
}
