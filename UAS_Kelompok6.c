#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>


void underscore();
void mainMenu();
void case1();
void case2();
void case3();
void case4();
void case5();
int pilihMenu();
FILE* saldo;
FILE* bill;  
int totalHarga;
int totalHargaBitcoin, totalHargaDodgecoin, totalHargaEthereum, totalHargaLitecoin;
int listJumlah[4];
int listHarga[4] = {594000, 2, 32300, 1100}; //Bitcoin, Dodgecoin, Ethereum, Litecoin
int jumlahBitcoin, jumlahDodgecoin, jumlahEthereum, jumlahLitecoin;
int input;
int jumlah;
int totalSekarang; 

int main()
{
    mainMenu();
}


void mainMenu()
{
    underscore();
    printf("|                 1. Beli                        |\n");
    printf("|                 2. Bayar                       |\n");
    printf("|                 3. Top Up Saldo                |\n");
    printf("|                 4. Cek Saldo                   |\n");
    printf("|                 5. Check Coin                  |\n");
    printf("|                 6. Keluar                      |\n");
    underscore();
    input = pilihMenu();
    system("cls");
    switch(input)
    {
        case 1:
            case1();
            break;
        case 2:
            case2();
            break;
        case 3:
            case3();
            break;
        case 4:
            case4();
            break;
        case 5:
            case5(); 
            break;
        case 6:
            exit(0);
    }
}

void underscore()
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int pilihMenu()
{
    printf("Pilih Menu: ");
    scanf("%d", &input);
    return input;
}

int pilihJumlah()
{
    printf("Masukkan Jumlah: ");
    scanf("%d", &jumlah);
    return jumlah;
}

void case1()
{
    underscore();
    printf("          1. \33[3mBitcoin\33[0m       Rp%d\n", listHarga[0]);
    printf("          2. \33[3mDodgecoin\33[0m     Rp%d\n", listHarga[1]);
    printf("          3. \33[3mEthereum\33[0m      Rp%d\n", listHarga[2]);
    printf("          4. \33[3mLitecoin\33[0m      Rp%d\n", listHarga[3]);
    printf("          5. Keluar        \n");
    underscore();
    input = pilihMenu();
    switch(input)
    {
        case 1: 
        jumlah = pilihJumlah();
        listJumlah[0] += jumlah;
        totalSekarang = jumlah*listHarga[0];
        totalHargaBitcoin += totalSekarang;
        totalHarga += totalSekarang;
        system("cls");
        case1();
        break;

        case 2: 
        jumlah = pilihJumlah();
        listJumlah[1] += jumlah;
        totalSekarang = jumlah*listHarga[1];
        totalHargaDodgecoin += totalSekarang;
        totalHarga += totalSekarang;
        system("cls");
        case1();
        break;

        case 3: 
        jumlah = pilihJumlah();
        listJumlah[2] += jumlah;
        totalSekarang = jumlah*listHarga[2];
        totalHargaEthereum += totalSekarang;
        totalHarga += totalSekarang;
        system("cls");
        case1();
        break;

        case 4: 
        jumlah = pilihJumlah();
        listJumlah[3] += jumlah;
        totalSekarang = jumlah*listHarga[3];
        totalHargaLitecoin += totalSekarang;
        totalHarga += totalSekarang;
        system("cls");
        case1();
        break;

        case 5:
        system("cls");
        mainMenu();
        break; 
    }
}

void case2()
{
    printf("Total: Rp%d\n\n", totalHarga);
    printf("Rincian: \n");
    int i, temp1;
    int help = 0;
    for(i = 0; i <= 3; i++){
        if(listJumlah[i] >= 1){
            if(i == 0){
                printf("|\33[3mBitcoin\33[0m   %10d       %6d   %12d|\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
            } else if(i == 1){
                printf("|\33[3mDodgecoin\33[0m %10d       %6d   %12d|\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
            } else if(i == 2){
                printf("|\33[3mEthereum\33[0m  %10d       %6d   %12d|\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
            } else if(i == 3){
                printf("|\33[3mLitecoin\33[0m  %10d       %6d   %12d|\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
            }
        }
    }
    printf("\nMetode pembayaran: \n");
    printf("1. Tunai\n");
    printf("2. Saldo\n");
    printf("Pilih metode pembayaran: ");
    scanf("%d", &temp1);
    int *ptrTunai = &help; //untuk pass value jumlah uang keluar dari case 1 maupun case 2
    switch(temp1)
    {
        case 1:
            int help;
            printf("Masukkan jumlah uang: ");
            scanf("%d", &help);
            while(help - totalHarga < 0){
                system("cls");
                printf("Total: Rp%d\n", help);
                printf("Uang Anda tidak cukup.\n");
                printf("Masukkan jumlah uang: ");
                scanf("%d", &help);
            }
            printf("Kembalian: Rp%d\n", help - totalHarga);
            printf("Terima kasih telah belanja di KriptoShop.\n");
            //bill.txt
            bill = fopen("bill.txt", "w"); 
            fprintf(bill, "          KriptoShop Rajanya Kripto           \n\n");
            fprintf(bill, "-----------------------------------------------\n");//46-
            for(i = 0; i <= 3; i++){
                if(listJumlah[i] >= 1){
                    if(i == 0){
                        fprintf(bill, "Bitcoin   %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                    } else if(i == 1){
                        fprintf(bill, "Dodgecoin %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                    } else if(i == 2){
                        fprintf(bill, "Ethereum  %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                    } else if(i == 3){
                        fprintf(bill, "Litecoin  %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                    }
                }
            }
            fprintf(bill, "-----------------------------------------------\n\n");//46-
            fprintf(bill, "Total: %d\n", totalHarga);
            fprintf(bill, "Tunai: %d\n", help);
            fprintf(bill, "Kembalian: %d\n\n", help - totalHarga);
            fprintf(bill, "Terima kasih telah belanja di KriptoShop.\n");
            fclose(bill);
            mainMenu();
            break;

        case 2:
            saldo = fopen("saldo.txt", "r");
            fscanf(saldo, "%d", &temp1);
            fclose(bill);
            if(temp1 < totalHarga){
                printf("Saldo Anda tidak cukup. Silakan lakukan pembayaran melalui Tunai.\n");
                printf("Masukkan jumlah uang: ");
                scanf("%d", &help);
                while(help - totalHarga < 0){
                    system("cls");
                    printf("Uang Anda tidak cukup.\n");
                    printf("Masukkan jumlah uang: ");
                    scanf("%d", &help);
                }
                printf("Kembalian: Rp%d\n", help - totalHarga);
                printf("Terima kasih telah belanja di KriptoShop.\n");
                fprintf(bill, "-----------------------------------------------\n");//46-
                for(i = 0; i <= 3; i++){
                    if(listJumlah[i] >= 1){
                        if(i == 0){
                            fprintf(bill, "Bitcoin   %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                        } else if(i == 1){
                            fprintf(bill, "Dodgecoin %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                        } else if(i == 2){
                            fprintf(bill, "Ethereum  %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                        } else if(i == 3){
                            fprintf(bill, "Litecoin  %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                        }
                    }
                }
                fprintf(bill, "-----------------------------------------------\n\n");//46-
                fprintf(bill, "Total: %d\n", totalHarga);
                fprintf(bill, "Tunai: %d\n", help);
                fprintf(bill, "Kembalian: %d\n\n", help - totalHarga);
                fprintf(bill, "Terima kasih telah belanja di KriptoShop.\n");
                fclose(bill);
                mainMenu();
            } else {
                system("cls");
                temp1 -= totalHarga;
                saldo = fopen("saldo.txt", "w");
                fprintf(saldo, "%d", temp1);
                fclose(saldo);
                printf("Saldo Anda sudah otomatis dikurangi.\n");
                printf("Terima kasih telah belanja di KriptoShop.\n");
                //bill.txt
                bill = fopen("bill.txt", "w"); 
                fprintf(bill, "          KriptoShop Rajanya Kripto           \n\n");
                fprintf(bill, "-----------------------------------------------\n");//46-
                for(i = 0; i <= 3; i++){
                    if(listJumlah[i] >= 1){
                        if(i == 0){
                            fprintf(bill, "Bitcoin   %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                        } else if(i == 1){
                            fprintf(bill, "Dodgecoin %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                        } else if(i == 2){
                            fprintf(bill, "Ethereum  %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                        } else if(i == 3){
                            fprintf(bill, "Litecoin  %10d      %6d  %12d\n", listJumlah[i], listHarga[i], listHarga[i]*listJumlah[i]);
                        }
                    }
                }
                fprintf(bill, "-----------------------------------------------\n\n");//46-
                fprintf(bill, "Total: %d\n", totalHarga);
                fprintf(bill, "Saldo: %d\n", temp1);
                fprintf(bill, "Sisa Saldo: %d\n\n", temp1 - totalHarga);
                fprintf(bill, "Terima kasih telah belanja di KriptoShop.\n");
                fclose(bill);
                mainMenu();
            }
            break; 
    }
}

void countdown(int seconds) {
    for (int i = seconds; i > 0; i--) {
        printf("Kembali ke menu utama dalam %d detik...\r", i);
        Sleep(1000);  // Sleep for 1000 milliseconds (1 second)
    }
}

void case3() {
    int saldoSekarang;
    int topUp;
    saldo = fopen("saldo.txt", "r");
    if (saldo == NULL) {
        saldoSekarang = 0;
        printf("Masukkan jumlah yang ingin Anda Top Up: ");
        scanf("%d", &topUp);
        saldoSekarang += topUp;
        saldo = fopen("saldo.txt", "w");
        fprintf(saldo, "%d", saldoSekarang);
        fclose(saldo);
    } else {
        fscanf(saldo, "%d", &saldoSekarang);
        fclose(saldo);
        printf("Masukkan jumlah yang ingin Anda Top Up: ");
        scanf("%d", &topUp);
        saldoSekarang += topUp;
        saldo = fopen("saldo.txt", "w");
        fprintf(saldo, "%d", saldoSekarang);
        fclose(saldo);
    }
    countdown(3);  // Countdown 3 detik
    // Bersihkan layar dan kembali ke halaman utama
    system("cls");
    mainMenu();
}

void case4() {
    saldo = fopen("saldo.txt", "r");
    int sisaSaldo = 0;  // Inisialisasi nilai default
    if (saldo == NULL) {
        printf("Saldo Anda tidak ada atau ada masalah saat membuka file.\n");
        getchar();
    } else {
        if (fscanf(saldo, "%d", &sisaSaldo) != 1) {
            printf("Error reading saldo from file.\n");
            sisaSaldo = 0;  // Nilai default
        } else {
            printf("Saldo Anda tersisa: %d\n", sisaSaldo);
        }
        fclose(saldo);
        getchar();
    }
    system("pause");
    mainMenu();
}

void case5()
{
    underscore();
    printf("     Coin yang sudah Anda beli:\n");
    printf("     1. Bitcoin     Jumlah: %d\n", listJumlah[0]);
    printf("     2. Dodgecoin   Jumlah: %d\n", listJumlah[1]);
    printf("     3. Ethereum    Jumlah: %d\n", listJumlah[2]);
    printf("     4. Litecoin    Jumlah: %d\n", listJumlah[3]);
    underscore();
    
    printf("     5. Kembali\n");
    underscore();

    int choice;
    printf("Pilih opsi: ");
    scanf("%d", &choice);

    if (choice == 5) {
        system("cls");
        mainMenu();
        return;
    }

    system("cls");
    mainMenu();
}
