#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *Produksi;
FILE *LuasPanen;
FILE *Produktivitas;

typedef struct{
    char province[50]; float p2020, p2021, p2022, p2023;
}Production;

typedef struct{
    char province[50]; float hS2020, hS2021, hS2022, hS2023;
}HarvestSize; 

typedef struct{
    char province[50]; float pV2020, pV2021, pV2022, pV2023;
}Productivity;

int readHVSize(){
    float average2020 = 0,average2021 = 0,average2022 = 0,average2023 = 0;
    void main();
    LuasPanen = fopen("LuasPanen.txt", "r");

    if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    HarvestSize hvsize[40];
    int read = 0;
    int records = 0; 
    do {
        read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
        if (read == 5) {
            records++;
        }
        if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(LuasPanen));
    fclose(LuasPanen);

    printf("\nSHOWING DATA FROM %d PROVINCES\n\n", records);
    for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n2021\t: %.2f ha\n2022\t: %.2f ha\n2023\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2020,
               hvsize[i].hS2021,
               hvsize[i].hS2022,
               hvsize[i].hS2023);
               average2020 += hvsize[i].hS2020;average2021 += hvsize[i].hS2021;average2022 += hvsize[i].hS2022;average2023 += hvsize[i].hS2023;
    }
    printf("\n===========================\n");
    printf("2020 Average: %.2f ha\n2021 Average: %.2f ha\n2022 Average: %.2f ha\n2023 Average: %.2f ha\n", average2020/34, average2021/34, average2022/34, average2023/34);
    system("pause");
    main();
    return 0;
}
void swapHS(HarvestSize *a, HarvestSize *b){
    HarvestSize temp = *a;
    *a = *b;
    *b = temp;
}
int HaAlphabet(){
    void main();
    void sortedHarvestArea();
    int method;
    printf("1. Ascending\n2. Descending\nChoose: ");
    scanf("%d", &method);
    if(method == 1){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(strcmp(hvsize[j].province, hvsize[j+1].province)>0){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n2021\t: %.2f ha\n2022\t: %.2f ha\n2023\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2020,
               hvsize[i].hS2021,
               hvsize[i].hS2022,
               hvsize[i].hS2023);
        printf("\n");
        }
    system("pause");
    main();
    }
    else if(method == 2){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(strcmp(hvsize[j].province, hvsize[j+1].province)<0){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n2021\t: %.2f ha\n2022\t: %.2f ha\n2023\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2020,
               hvsize[i].hS2021,
               hvsize[i].hS2022,
               hvsize[i].hS2023);
        printf("\n");
        }
    system("pause");
    main();
    }
    else{
        printf("There is no other way bruh");
        sortedHarvestArea();
    }
}
int HaByAreaOfYear(int year){
    void main();
    int ascdesc;
    if(year == 2020){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(LuasPanen)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(LuasPanen)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(LuasPanen));
            fclose(LuasPanen);
        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose: "); 
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(hvsize[j].hS2020 > hvsize[j+1].hS2020){
                        swapHS(&hvsize[j],&hvsize[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(hvsize[j].hS2020 < hvsize[j+1].hS2020){
                        swapHS(&hvsize[j],&hvsize[j+1]);
                    }
                }
            }
            break;
            default:
                printf("Choose correctly mate!");
                HaByAreaOfYear(year);
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2020\t: %.2f", 
               hvsize[i].province, 
               hvsize[i].hS2020
               );
        printf("\n");
        }
    system("pause");
    }
    else if(year == 2021){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(LuasPanen)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(LuasPanen)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(LuasPanen));
            fclose(LuasPanen);
        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose: ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(hvsize[j].hS2021 > hvsize[j+1].hS2021){
                        swapHS(&hvsize[j],&hvsize[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(hvsize[j].hS2021 < hvsize[j+1].hS2021){
                        swapHS(&hvsize[j],&hvsize[j+1]);
                    }
                }
            }
            break;
            default:
                printf("Choose correctly mate!");
                HaByAreaOfYear(year);
            break;

        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2021\t: %.2f ha", 
               hvsize[i].province, 
               hvsize[i].hS2021
               );
        printf("\n");
        }
    system("pause");
    }
    else if(year == 2022){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(LuasPanen)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(LuasPanen)){
                printf("Error reading file.\n");
                return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose: "); int ascdesc;
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(hvsize[j].hS2022 > hvsize[j+1].hS2022){
                        swapHS(&hvsize[j],&hvsize[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(hvsize[j].hS2022 < hvsize[j+1].hS2022){
                        swapHS(&hvsize[j],&hvsize[j+1]);
                    }
                }
            }
            break;
            default:
                printf("Choose correctly mate!");
                HaByAreaOfYear(year);
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2022\t: %.2f ha", 
               hvsize[i].province, 
               hvsize[i].hS2022);
        printf("\n");
        }
    system("pause");

    }
    else if(year == 2023){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(LuasPanen)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(LuasPanen)){
                printf("Error reading file.\n");
                return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose: ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(hvsize[j].hS2023 > hvsize[j+1].hS2023){
                        swapHS(&hvsize[j],&hvsize[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(hvsize[j].hS2023 < hvsize[j+1].hS2023){
                        swapHS(&hvsize[j],&hvsize[j+1]);
                    }
                }
            }
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2023\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2023);
        printf("\n");
        }
    system("pause");

    }
    else{
        printf("No such data exist");
    }
    main();
}
void sortedHarvestArea(){
    int switcher, choice;
    printf("Based on what do you want to sort the data?\n");
    printf("+---+-----------------------------------------------+\n");
    printf("|   |                    SORT BY                    |\n");
    printf("+---+-----------------------------------------------+\n");
    printf("| 1 |               Province Alphabet               |\n");
    printf("| 2 |               Harvest Area size               |\n");
    printf("+---+-----------------------------------------------+\n");
    printf("Choose: ");
    scanf("%d", &switcher);
    switch(switcher){
        case(1):
            HaAlphabet();
        break;
        case(2):
            printf("Which year is supposed to be the anchor?\n1. 2020\n2. 2021\n3. 2022\n4. 2023\nChoose: ");
            scanf("%d", &choice);
        switch(choice){
            case(1):
                HaByAreaOfYear(2020);
            break;
            case(2):
                HaByAreaOfYear(2021);
            break;
            case(3):
                HaByAreaOfYear(2022);
            break;
            case(4):
                HaByAreaOfYear(2023);
            break;
            default:
                printf("So sorry but we only have data in the periode of 2020-2023");
                sortedHarvestArea();
            break;
        }
        break;
        default:
        printf("Choose wisely bro!");
        sortedHarvestArea();
        break;
    }
}
int readproduction(){
    void main();
    float average2020 = 0,average2021 = 0,average2022 = 0,average2023 = 0;
    Produksi = fopen("Produksi.txt", "r");

    if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    Production prdctn[40];
    int read = 0;
    int records = 0;
    do{
        read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prdctn[records].province, 
                      &prdctn[records].p2023,
                      &prdctn[records].p2022,
                      &prdctn[records].p2021,
                      &prdctn[records].p2020);
        if (read == 5){
            records++;
        }
        if (read != 5 && !feof(Produksi)){
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(Produksi)){
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(Produksi));
    fclose(Produksi);

    printf("\nSHOWING DATA FROM %d PROVINCES\n\n", records);
    for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ton\n2021\t: %.2f ton\n2022\t: %.2f ton\n2023\t: %.2f ton\n", 
               prdctn[i].province, 
               prdctn[i].p2020,
               prdctn[i].p2021,
               prdctn[i].p2022,
               prdctn[i].p2023);
               average2020 += prdctn[i].p2020;average2021 += prdctn[i].p2021;average2022 += prdctn[i].p2022;average2023 += prdctn[i].p2023;
    }
    printf("\n===========================\n");
    printf("2020 Average: %.2f ton\n2021 Average: %.2f ton\n2022 Average: %.2f ton\n2023 Average: %.2f ton\n", average2020/34, average2021/34, average2022/34, average2023/34);
    system("pause");
    main();
    return 0;
}
void swapProd(Production *a, Production *b){
    Production temp = *a;
    *a = *b;
    *b = temp;
}
int prodAlphabet(){
    void main();
    void sortedProduction();
    int method;
    printf(">> 1. Ascending\n>> 2. Descending\nChoose : ");
    scanf("%d", &method);
    if(method == 1){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(strcmp(prod[j].province, prod[j+1].province)>0){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n2021\t: %.2f ha\n2022\t: %.2f ha\n2023\t: %.2f ha\n", 
               prod[i].province, 
               prod[i].p2020,
               prod[i].p2021,
               prod[i].p2022,
               prod[i].p2023);
        printf("\n");
        }
    system("pause");
    main();
    }
    else if(method == 2){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(strcmp(prod[j].province, prod[j+1].province)<0){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n2021\t: %.2f ha\n2022\t: %.2f ha\n2023\t: %.2f ha\n", 
               prod[i].province, 
               prod[i].p2020,
               prod[i].p2021,
               prod[i].p2022,
               prod[i].p2023);
        printf("\n");
        }
    system("pause");
    main();
    }
    else{
        printf("There is no other way bruh");
        sortedProduction();
    }
}
int prodByAmount(int year){
    int ascdesc;
    void main();
    if(year == 2020){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produksi)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produksi)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produksi));
            fclose(Produksi);
        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose : ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prod[j].p2020 > prod[j+1].p2020){
                        swapProd(&prod[j],&prod[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prod[j].p2020 < prod[j+1].p2020){
                        swapProd(&prod[j],&prod[j+1]);
                    }
                }
            }
            break;
            default:
                printf("Choose correctly mate!");
                HaByAreaOfYear(year);
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2020\t: %.2f", 
               prod[i].province, 
               prod[i].p2020
               );
        printf("\n");
        }
    system("pause");
    }
    else if(year == 2021){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produksi)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produksi)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produksi));
            fclose(Produksi);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose : ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prod[j].p2021 > prod[j+1].p2021){
                        swapProd(&prod[j],&prod[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prod[j].p2021 < prod[j+1].p2021){
                        swapProd(&prod[j],&prod[j+1]);
                    }
                }
            }
            break;
            default:
                printf("Choose correctly mate!");
                HaByAreaOfYear(year);
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2021\t: %.2f ha", 
               prod[i].province, 
               prod[i].p2021
               );
        printf("\n");
        }
    system("pause");
    }
    else if(year == 2022){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produksi)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produksi)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produksi));
        fclose(Produksi);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose : ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prod[j].p2022 > prod[j+1].p2022){
                        swapProd(&prod[j],&prod[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prod[j].p2022 < prod[j+1].p2022){
                        swapProd(&prod[j],&prod[j+1]);
                    }
                }
            }
            break;
            default:
                printf("Choose correctly mate!");
                HaByAreaOfYear(year);
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2022\t: %.2f ha", 
               prod[i].province, 
               prod[i].p2022);
        printf("\n");
        }
    system("pause");

    }
    else if(year == 2023){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
            printf("Error opening file.\n");
            return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produksi)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produksi)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produksi));
        fclose(Produksi);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose : ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prod[j].p2023 > prod[j+1].p2023){
                    swapProd(&prod[j],&prod[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prod[j].p2023 < prod[j+1].p2023){
                    swapProd(&prod[j],&prod[j+1]);
                    }
                }
            }
            break;
            default:
                printf("Choose correctly mate!");
                HaByAreaOfYear(year);
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2023\t: %.2f ha\n", 
               prod[i].province, 
               prod[i].p2023);
        printf("\n");
        }
    system("pause");

    }
    else{
        printf("No such data exist");
    }
    main();
}
void sortedProduction(){
    int switcher, choice;
    printf("+---+-----------------------------------------------+\n");
    printf("|   |                    SORT BY                    |\n");
    printf("+---+-----------------------------------------------+\n");
    printf("| 1 |               Province Alphabet               |\n");
    printf("| 2 |               Production Amount               |\n");
    printf("+---+-----------------------------------------------+\n");
    scanf("%d", &switcher);
    switch(switcher){
        case(1):
            prodAlphabet();
        break;
        case(2):
            printf(">> Which year is supposed to be the anchor? <<\n");
            printf("+----+------+\n");
            printf("| No | Year |\n");
            printf("+---+------+\n");
            printf("| 1 | 2020 |\n");
            printf("| 2 | 2021 |\n");
            printf("| 3 | 2022 |\n");
            printf("| 4 | 2023 |\n");
            printf("+---+------+\n");
            printf("Choose: ");
            scanf("%d", &choice);
        switch(choice){
            case(1):
                prodByAmount(2020);
            break;
            case(2):
                prodByAmount(2021);
            break;
            case(3):
                prodByAmount(2022);
            break;
            case(4):
                prodByAmount(2023);
            break;
            default:
                printf("So sorry but we only have data in the periode of 2020-2023");
                sortedProduction();
            break;
        }
        break;
        default:
        printf("Choose wisely bro!");
        sortedProduction();
        break;
    }
}
void swapPrdctvt(Productivity *a, Productivity *b){
    Productivity temp = *a;
    *a = *b;
    *b = temp;
}
int readproductivity(){
    void main();
    float average2020 = 0,average2021 = 0,average2022 = 0,average2023 = 0;
    Produktivitas = fopen("Produktivitas.txt", "r");

    if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    Productivity prdctvt[40];
    int read = 0;
    int records = 0;
    do{
        read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
        if (read == 5) {
            records++;
        }
        if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
        }
    }while (!feof(Produktivitas));
    fclose(Produktivitas);

    printf("\nSHOWING DATA FROM %d PROVINCES\n\n", records);
    for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ku/ha\n2021\t: %.2f ku/ha\n2022\t: %.2f ku/ha\n2023\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2020,
               prdctvt[i].pV2021,
               prdctvt[i].pV2022,
               prdctvt[i].pV2023);
            average2020 += prdctvt[i].pV2020;average2021 += prdctvt[i].pV2021;average2022 += prdctvt[i].pV2022;average2023 += prdctvt[i].pV2023;
    }
    printf("\n===========================\n");
    printf("2020 Average: %.2f ha\n2021 Average: %.2f ha\n2022 Average: %.2f ha\n2023 Average: %.2f ha\n", average2020/34, average2021/34, average2022/34, average2023/34);
    system("pause");
    main();
}
int prdvtyAlphabet(){
    void main();
    void sortedProductivity();
    int method;
    printf("1. Ascending\n2. Descending\nChoose: ");
    scanf("%d", &method);
    if(method == 1){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(strcmp(prdctvt[j].province, prdctvt[j+1].province)>0){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n2021\t: %.2f ha\n2022\t: %.2f ha\n2023\t: %.2f ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2020,
               prdctvt[i].pV2021,
               prdctvt[i].pV2022,
               prdctvt[i].pV2023);
        printf("\n");
        }
    system("pause");
    main();
    }
    else if(method == 2){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(strcmp(prdctvt[j].province, prdctvt[j+1].province)<0){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n2021\t: %.2f ha\n2022\t: %.2f ha\n2023\t: %.2f ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2020,
               prdctvt[i].pV2021,
               prdctvt[i].pV2022,
               prdctvt[i].pV2023);
        printf("\n");
        }
    system("pause");
    main();
    }
    else{
        printf("There is no other way bruh");
        sortedProductivity();
    }
}
int prdvtyByValue(int year){
    int ascdesc;
    void main();
    if(year == 2020){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produktivitas)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produktivitas)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produktivitas));
        fclose(Produktivitas);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose: ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prdctvt[j].pV2020 > prdctvt[j+1].pV2020){
                        swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prdctvt[j].pV2020 < prdctvt[j+1].pV2020){
                        swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                    }
                }
            }
            break;
            default:
                printf("So sorry but we only have data in the periode of 2020-2023");
                sortedProduction();
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2020\t: %.2f", 
               prdctvt[i].province, 
               prdctvt[i].pV2020
               );
        printf("\n");
        }
    system("pause");
    }
    else if(year == 2021){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produktivitas)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produktivitas)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produktivitas));
        fclose(Produktivitas);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose: ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prdctvt[j].pV2021 > prdctvt[j+1].pV2021){
                        swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prdctvt[j].pV2021 < prdctvt[j+1].pV2021){
                        swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                    }
                }
            }
            break;
            default:
                printf("So sorry but we only have data in the periode of 2020-2023");
                sortedProduction();
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2021\t: %.2f ha", 
               prdctvt[i].province, 
               prdctvt[i].pV2021
               );
        printf("\n");
        }
    system("pause");
    }
    else if(year == 2022){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produktivitas)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produktivitas)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produktivitas));
        fclose(Produktivitas);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose: ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prdctvt[j].pV2022 > prdctvt[j+1].pV2022){
                        swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prdctvt[j].pV2022 > prdctvt[j+1].pV2022){
                        swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                    }
                }
            }
            break;
            default:
                printf("So sorry but we only have data in the periode of 2020-2023");
                sortedProduction();
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2022\t: %.2f ha", 
               prdctvt[i].province, 
               prdctvt[i].pV2022);
        printf("\n");
        }
    system("pause");

    }
    else if(year == 2023){
        Produktivitas = fopen("Produksi.txt", "r");

        if (Produktivitas == NULL){
            printf("Error opening file.\n");
            return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produktivitas)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produktivitas)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produktivitas));
        fclose(Produktivitas);

        printf("Do you want it:\n1. Ascending\n2. Descending\n"); 
        printf("Choose: ");
        scanf("%d", &ascdesc);
        switch(ascdesc){
            case(1):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j < records-1; j++){
                    if(prdctvt[j].pV2023 > prdctvt[j+1].pV2023){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                    }
                }
            }
            break;
            case(2):
            for(int i = 0; i < records-1; i++){
                for(int j = 0; j > records-1; j++){
                    if(prdctvt[j].pV2023 > prdctvt[j+1].pV2023){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                    }
                }
            }
            break;
            default:
                printf("So sorry but we only have data in the periode of 2020-2023");
                sortedProduction();
            break;
        }
        for (int i = 0; i < records; i++){
        printf("=======================\n");
            printf("Province: %s\n2023\t: %.2f ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2023);
        printf("\n");
        }
    system("pause");

    }
    else{
        printf("No such data exist");
    }
    main();
}
void sortedProductivity(){
    int switcher, choice;
    printf("Based on what do you want to sort the data?\n1. Provinces Alphabet\n2. Production amount\nChoose:");
    scanf("%d", &switcher);
    switch(switcher){
        case(1):
            prdvtyAlphabet();
        break;
        case(2):
            printf("Which year is supposed to be the anchor?\n1. 2020\n2. 2021\n3. 2022\n4. 2023\nChoose: ");
            scanf("%d", &choice);
        switch(choice){
            case(1):
                prdvtyByValue(2020);
            break;
            case(2):
                prdvtyByValue(2021);
            break;
            case(3):
                prdvtyByValue(2022);
            break;
            case(4):
                prdvtyByValue(2023);
            break;
            default:
                printf("So sorry but we only have data in the periode of 2020-2023");
                sortedProductivity();
            break;
        }
        break;
        default:
        printf("Choose wisely bro!");
        sortedProductivity();
        break;
    }
}
int searchSpecificProvince(){
    void main();
    char provName[40];
    system("cls");
    printf("List of 34 Provinces across Indonesia");
    printf("\n[1]. ACEH\n[2]. SUMATERA UTARA\n[3]. SUMATERA BARAT\n[4]. RIAU\n[5]. JAMBI\n[6]. SUMATERA SELATAN\n[7]. BENGKULU\n[8]. LAMPUNG\n[9]. KEP. BANGKA BELITUNG\n[10]. KEP. RIAU\n[11]. DKI JAKARTA");
    printf("\n[12]. JAWA BARAT\n[13]. JAWA TENGAH\n[14]. DI YOGYAKARTA\n[15]. JAWA TIMUR\n[16]. BANTEN\n[17]. BALI\n[18]. NUSA TENGGARA BARAT\n[19]. NUSA TENGGARA TIMUR\n[20]. KALIMANTAN BARAT\n[21]. KALIMANTAN TENGAH");
    printf("\n[22]. KALIMANTAN SELATAN\n[23]. KALIMANTAN TIMUR\n[24]. KALIMANTAN UTARA\n[25]. SULAWESI UTARA\n[26]. SULAWESI TENGAH\n[27]. SULAWESI SELATAN\n[28]. SULAWESI TENGGARA\n[29]. GORONTALO\n[30]. SULAWESI BARAT");
    printf("\n[31]. MALUKU\n[32]. MALUKU UTARA\n[33]. PAPUA BARAT\n[34]. PAPUA");
    printf("\nInsert Province Name: "); getchar();
    fgets(provName, sizeof(provName), stdin);

    size_t len = strlen(provName);
    if (len > 0 && provName[len - 1] == '\n') {
        provName[len - 1] = '\0';
    }
    for (int i = 0; provName[i]; i++) {
        provName[i] = toupper((unsigned char)provName[i]);
    }
    LuasPanen = fopen("LuasPanen.txt", "r");

    if (LuasPanen == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    HarvestSize hvsize[40];
    int read1 = 0;
    int records1 = 0;
    do {
        read1 = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records1].province, 
                      &hvsize[records1].hS2023,
                      &hvsize[records1].hS2022,
                      &hvsize[records1].hS2021,
                      &hvsize[records1].hS2020);
        if (read1 == 5) {
            records1++;
        }
        if (read1 != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(LuasPanen));
    fclose(LuasPanen);
    //WATES KANG
    for(int i = 0; i < records1; i++){
        if(strcmp(provName, hvsize[i].province) == 0){
            printf("=======================\n");
            printf("Province: %s\n2020\t: %.2f ha\n2021\t: %.2f ha\n2022\t: %.2f ha\n2023\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2020,
               hvsize[i].hS2021,
               hvsize[i].hS2022,
               hvsize[i].hS2023);
        }
    }

    Produksi = fopen("Produksi.txt", "r");

    if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    Production prdctn[40];
    int read2 = 0;
    int records2 = 0;
    do{
        read2 = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prdctn[records2].province, 
                      &prdctn[records2].p2023,
                      &prdctn[records2].p2022,
                      &prdctn[records2].p2021,
                      &prdctn[records2].p2020);
        if (read2 == 5){
            records2++;
        }
        if (read2 != 5 && !feof(Produksi)){
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(Produksi)){
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(Produksi));
    fclose(Produksi);
    //WATES KANG
    for(int i = 0; i < records2; i++){
        if(strcmp(provName, prdctn[i].province) == 0){
            printf("=======================\n");
            printf("Province: %s\n2020\t: %.2f ton\n2021\t: %.2f ton\n2022\t: %.2f ton\n2023\t: %.2f ton\n", 
               prdctn[i].province, 
               prdctn[i].p2020,
               prdctn[i].p2021,
               prdctn[i].p2022,
               prdctn[i].p2023);
        }
    }
    Produktivitas = fopen("Produktivitas.txt", "r");

    if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    Productivity prdctvt[40];
    int read3 = 0;
    int records3 = 0;
    do{
        read3 = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records3].province, 
                      &prdctvt[records3].pV2023,
                      &prdctvt[records3].pV2022,
                      &prdctvt[records3].pV2021,
                      &prdctvt[records3].pV2020);
        if (read3 == 5) {
            records3++;
        }
        if (read3 != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
        }
    }while (!feof(Produktivitas));
    fclose(Produktivitas);
    for(int i = 0; i < records3; i++){
        if(strcmp(provName, prdctvt[i].province) == 0){
            printf("=======================\n");
            printf("Province: %s\n2020\t: %.2f ku/ha\n2021\t: %.2f ku/ha\n2022\t: %.2f ku/ha\n2023\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2020,
               prdctvt[i].pV2021,
               prdctvt[i].pV2022,
               prdctvt[i].pV2023);
        }
    }
    printf("=======================\n");
    system("pause");
    main();
}
int compareHA(int year, float total){
    void main();
    float prov;
    LuasPanen = fopen("LuasPanen.txt", "r");
    if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    HarvestSize hvsize[40];
    int read = 0;
    int records = 0;
    do {
        read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
        if (read == 5) {
            records++;
        }
        if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(LuasPanen));
    fclose(LuasPanen);
    
    char provName[40];
    printf("List of 34 Provinces across Indonesia");
    printf("\n1. ACEH\n2. SUMATERA UTARA\n3. SUMATERA BARAT\n4. RIAU\n5. JAMBI\n6. SUMATERA SELATAN\n7. BENGKULU\n8. LAMPUNG\n9. KEP. BANGKA BELITUNG\n10. KEP. RIAU\n11. DKI JAKARTA");
    printf("\n12. JAWA BARAT\n13. JAWA TENGAH\n14. DI YOGYAKARTA\n15. JAWA TIMUR\n16. BANTEN\n17. BALI\n18. NUSA TENGGARA BARAT\n19. NUSA TENGGARA TIMUR\n20. KALIMANTAN BARAT\n21. KALIMANTAN TENGAH");
    printf("\n22. KALIMANTAN SELATAN\n23. KALIMANTAN TIMUR\n24. KALIMANTAN UTARA\n25. SULAWESI UTARA\n26. SULAWESI TENGAH\n27. SULAWESI SELATAN\n28. SULAWESI TENGGARA\n29. GORONTALO\n30. SULAWESI BARAT");
    printf("\n31. MALUKU\n32. MALUKU UTARA\n33. PAPUA BARAT\n34. PAPUA");
    printf("\nInsert Province Name: "); getchar();
    fgets(provName, sizeof(provName), stdin);
    size_t len = strlen(provName);
    if (len > 0 && provName[len - 1] == '\n') {
        provName[len - 1] = '\0';
    }
    for (int i = 0; provName[i]; i++) {
        provName[i] = toupper((unsigned char)provName[i]);
    }
    LuasPanen = fopen("LuasPanen.txt", "r");

    if (LuasPanen == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    if(year == 2020){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, hvsize[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2020:%.2f ha", hvsize[i].province,hvsize[i].hS2020);
                prov = hvsize[i].hS2020;
            }
        }
    }
    else if(year == 2021){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, hvsize[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2021:%.2f ha", hvsize[i].province,hvsize[i].hS2021);
                prov = hvsize[i].hS2021;
            }
        }
    }
    else if(year == 2022){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, hvsize[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2022:%.2f ha", hvsize[i].province,hvsize[i].hS2022);
                prov = hvsize[i].hS2022;
            }
        }
    }
    else if(year == 2023){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, hvsize[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2023:%.2f ha", hvsize[i].province,hvsize[i].hS2023);
                prov = hvsize[i].hS2023;
            }
        }
    }
    printf("\n==================================================================");
    printf("\nIndonesia total: %.2f ha", total);
    printf("\n==================================================================");
    printf("\nRatio of %s to Indonesia = (%.2f/%.2f) ha\n", provName, prov/prov, total/prov);
    system("pause");
    main();
}
int totalHA(int year){
    void main();
    int ascdesc;
    float total = 0;
    if(year == 2020){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(LuasPanen)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(LuasPanen)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(LuasPanen));
            fclose(LuasPanen);
        for (int i = 0; i < records; i++){ 
            total += hvsize[i].hS2020;
        }
        printf("===============================================\n");
        printf("Indonesia Total Harvest Area in %d is: '%.2f ha'\n", year, total);
        system("pause");
    }
    else if(year == 2021){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(LuasPanen)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(LuasPanen)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(LuasPanen));
            fclose(LuasPanen);
        for (int i = 0; i < records; i++){
            total += hvsize[i].hS2021;
        }
        printf("===============================================\n");
        printf("Indonesia Total Harvest Area in %d is: '%.2f ha'\n", year, total);
        system("pause");
    }
    else if(year == 2022){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(LuasPanen)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(LuasPanen)){
                printf("Error reading file.\n");
                return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for (int i = 0; i < records; i++){
            total += hvsize[i].hS2022;
        }
        printf("===============================================\n");
        printf("Indonesia Total Harvest Area in %d is: '%.2f ha'\n", year, total);
        system("pause");
    }
    else if(year == 2023){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(LuasPanen)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(LuasPanen)){
                printf("Error reading file.\n");
                return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for (int i = 0; i < records; i++){
            total += hvsize[i].hS2023;
        }
        printf("===============================================\n");
        printf("Indonesia Total Harvest Area in %d is: '%.2f ha'\n", year, total);
        system("pause");
    }
    else{
        printf("No such data exist");
    }
    char choice; getchar();
    printf("Do you want to compare a province to total data?(y/n): ");
    scanf("%c", &choice);
    if(choice == 'y'){
        compareHA(year,total);
    }
    else if(choice == 'n'){
        main();
    }
    else{
        main();
    }
}
int totalHarvestArea(){
    int choose;
    printf("Which year data do you want to see?");
    printf("\n1. 2020\n2. 2021\n3. 2022\n4. 2023\n");
    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case(1):
            totalHA(2020);
        break;
        case(2):
            totalHA(2021);
        break;
        case(3):
            totalHA(2022);
        break;
        case(4):
            totalHA(2023);
        break;
        default:
            printf("Invalid Choice");
            totalHarvestArea();
        break;
    }

}
int compareProd(int year, float total){
    void main();
    float prov;
    Produksi = fopen("Produksi.txt", "r");
    if (Produksi == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    Production prod[40];
    int read = 0;
    int records = 0;
    do {
        read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
        if (read == 5) {
            records++;
        }
        if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(Produksi));
    fclose(Produksi);
    
    char provName[40];
    printf("List of 34 Provinces across Indonesia");
    printf("\n1. ACEH\n2. SUMATERA UTARA\n3. SUMATERA BARAT\n4. RIAU\n5. JAMBI\n6. SUMATERA SELATAN\n7. BENGKULU\n8. LAMPUNG\n9. KEP. BANGKA BELITUNG\n10. KEP. RIAU\n11. DKI JAKARTA");
    printf("\n12. JAWA BARAT\n13. JAWA TENGAH\n14. DI YOGYAKARTA\n15. JAWA TIMUR\n16. BANTEN\n17. BALI\n18. NUSA TENGGARA BARAT\n19. NUSA TENGGARA TIMUR\n20. KALIMANTAN BARAT\n21. KALIMANTAN TENGAH");
    printf("\n22. KALIMANTAN SELATAN\n23. KALIMANTAN TIMUR\n24. KALIMANTAN UTARA\n25. SULAWESI UTARA\n26. SULAWESI TENGAH\n27. SULAWESI SELATAN\n28. SULAWESI TENGGARA\n29. GORONTALO\n30. SULAWESI BARAT");
    printf("\n31. MALUKU\n32. MALUKU UTARA\n33. PAPUA BARAT\n34. PAPUA");
    printf("\nInsert Province Name: "); getchar();
    fgets(provName, sizeof(provName), stdin);
    size_t len = strlen(provName);
    if (len > 0 && provName[len - 1] == '\n') {
        provName[len - 1] = '\0';
    }
    for (int i = 0; provName[i]; i++) {
        provName[i] = toupper((unsigned char)provName[i]);
    }
    Produksi = fopen("Produksi.txt", "r");

    if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    if(year == 2020){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, prod[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2020:%.2f ton", prod[i].province,prod[i].p2020);
                prov = prod[i].p2020;
            }
        }
    }
    else if(year == 2021){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, prod[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2021:%.2f ton", prod[i].province,prod[i].p2021);
                prov = prod[i].p2021;
            }
        }
    }
    else if(year == 2022){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, prod[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2022:%.2f ton", prod[i].province,prod[i].p2022);
                prov = prod[i].p2022;
            }
        }
    }
    else if(year == 2023){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, prod[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2023:%.2f ton", prod[i].province,prod[i].p2023);
                prov = prod[i].p2023;
            }
        }
    }
    printf("\n==================================================================");
    printf("\nIndonesia total: %.2f ton", total);
    printf("\n==================================================================");
    printf("\nRatio of %s to Indonesia = (%.2f/%.2f) ton\n", provName, prov/prov, total/prov);
    system("pause");
    main();
}
int totalProd(int year){
    void main();
    int ascdesc;
    float total = 0;
    if(year == 2020){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produksi)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produksi)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produksi));
            fclose(Produksi);
        for (int i = 0; i < records; i++){ 
            total += prod[i].p2020;
        }
        printf("===============================================\n");
        printf("Indonesia Total Production of Corn in %d is: '%.2f ton'\n", year, total);
        system("pause");
    }
    else if(year == 2021){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produksi)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produksi)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produksi));
            fclose(Produksi);
        for (int i = 0; i < records; i++){
            total += prod[i].p2021;
        }
        printf("===============================================\n");
        printf("Indonesia Total Production of Corn in %d is: '%.2f ton'\n", year, total);
        system("pause");
    }
    else if(year == 2022){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produksi)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produksi)){
                printf("Error reading file.\n");
                return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for (int i = 0; i < records; i++){
            total += prod[i].p2022;
        }
        printf("===============================================\n");
        printf("Indonesia Total Production of Corn in %d is: '%.2f ton'\n", year, total);
        system("pause");
    }
    else if(year == 2023){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produksi)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produksi)){
                printf("Error reading file.\n");
                return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for (int i = 0; i < records; i++){
            total += prod[i].p2023;
        }
        printf("===============================================\n");
        printf("Indonesia Total Production of Corn in %d is: '%.2f ton'\n", year, total);
        system("pause");
    }
    else{
        printf("No such data exist");
    }
    char choice; getchar();
    printf("Do you want to compare a province to total data?(y/n): ");
    scanf("%c", &choice);
    if(choice == 'y'){
        compareProd(year,total);
    }
    else if(choice == 'n'){
        main();
    }
    else{
        main();
    }
}
int totalProduction(){
    int choose;
    printf("Which year data do you want to see?");
    printf("\n1. 2020\n2. 2021\n3. 2022\n4. 2023\n");
    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case(1):
            totalProd(2020);
        break;
        case(2):
            totalProd(2021);
        break;
        case(3):
            totalProd(2022);
        break;
        case(4):
            totalProd(2023);
        break;
        default:
            printf("Invalid Choice");
            totalProduction();
        break;
    }
}
int comparePrdctvt(int year,float total){
    void main();
    float prov;
    Produktivitas = fopen("Produktivitas.txt", "r");
    if (Produktivitas == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    Productivity prdctvt[40];
    int read = 0;
    int records = 0;
    do {
        read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
        if (read == 5) {
            records++;
        }
        if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(Produktivitas));
    fclose(Produktivitas);
    
    char provName[40];
    printf("List of 34 Provinces across Indonesia");
    printf("\n1. ACEH\n2. SUMATERA UTARA\n3. SUMATERA BARAT\n4. RIAU\n5. JAMBI\n6. SUMATERA SELATAN\n7. BENGKULU\n8. LAMPUNG\n9. KEP. BANGKA BELITUNG\n10. KEP. RIAU\n11. DKI JAKARTA");
    printf("\n12. JAWA BARAT\n13. JAWA TENGAH\n14. DI YOGYAKARTA\n15. JAWA TIMUR\n16. BANTEN\n17. BALI\n18. NUSA TENGGARA BARAT\n19. NUSA TENGGARA TIMUR\n20. KALIMANTAN BARAT\n21. KALIMANTAN TENGAH");
    printf("\n22. KALIMANTAN SELATAN\n23. KALIMANTAN TIMUR\n24. KALIMANTAN UTARA\n25. SULAWESI UTARA\n26. SULAWESI TENGAH\n27. SULAWESI SELATAN\n28. SULAWESI TENGGARA\n29. GORONTALO\n30. SULAWESI BARAT");
    printf("\n31. MALUKU\n32. MALUKU UTARA\n33. PAPUA BARAT\n34. PAPUA");
    printf("\nInsert Province Name: "); getchar();
    fgets(provName, sizeof(provName), stdin);
    size_t len = strlen(provName);
    if (len > 0 && provName[len - 1] == '\n') {
        provName[len - 1] = '\0';
    }
    for (int i = 0; provName[i]; i++) {
        provName[i] = toupper((unsigned char)provName[i]);
    }
    Produktivitas = fopen("Produktivitas.txt", "r");

    if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    if(year == 2020){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, prdctvt[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2020:%.2f ku/ha", prdctvt[i].province,prdctvt[i].pV2020);
                prov = prdctvt[i].pV2020;
            }
        }
    }
    else if(year == 2021){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, prdctvt[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2021:%.2f ku/ha", prdctvt[i].province,prdctvt[i].pV2021);
                prov = prdctvt[i].pV2021;
            }
        }
    }
    else if(year == 2022){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, prdctvt[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2022:%.2f ku/ha", prdctvt[i].province,prdctvt[i].pV2022);
                prov = prdctvt[i].pV2022;
            }
        }
    }
    else if(year == 2023){
        for (int i = 0; i < records; i++){
            if(strcmp(provName, prdctvt[i].province) == 0){
                printf("\n==================================================================");
                printf("\nProvince:%s\n2023:%.2f ku/ha", prdctvt[i].province,prdctvt[i].pV2023);
                prov = prdctvt[i].pV2023;
            }
        }
    }
    printf("\n==================================================================");
    printf("\nIndonesia total: %.2f ku/ha", total);
    printf("\n==================================================================");
    printf("\nRatio of %s to Indonesia = (%.2f/%.2f) ku/ha\n", provName, prov/prov, total/prov);
    system("pause");
    main();
}
int totalPrdtvty(int year){
    void main();
    int ascdesc;
    float total = 0;
    if(year == 2020){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produktivitas)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produktivitas)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produktivitas));
            fclose(Produksi);
        for (int i = 0; i < records; i++){ 
            total += prdctvt[i].pV2020;
        }
        printf("===============================================\n");
        printf("Indonesia Total Production of Corn in %d is: '%.2f ku/ha'\n", year, total);
        system("pause");
    }
    else if(year == 2021){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produktivitas)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produktivitas)){
                printf("Error reading file.\n");
                return 1;
            }
            }while(!feof(Produktivitas));
            fclose(Produktivitas);
        for (int i = 0; i < records; i++){
            total += prdctvt[i].pV2021;
        }
        printf("===============================================\n");
        printf("Indonesia Total Production of Corn in %d is: '%.2f ku/ha'\n", year, total);
        system("pause");
    }
    else if(year == 2022){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produktivitas)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produktivitas)){
                printf("Error reading file.\n");
                return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produksi);

        for (int i = 0; i < records; i++){
            total += prdctvt[i].pV2022;
        }
        printf("===============================================\n");
        printf("Indonesia Total Production of Corn in %d is: '%.2f ku/ha'\n", year, total);
        system("pause");
    }
    else if(year == 2023){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do{
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if(read == 5) {
            records++;
            }
            if(read != 5 && !feof(Produktivitas)) {
                printf("File format incorrect.\n");
                return 1;
            }
            if(ferror(Produktivitas)){
                printf("Error reading file.\n");
                return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for (int i = 0; i < records; i++){
            total += prdctvt[i].pV2023;
        }
        printf("===============================================\n");
        printf("Indonesia Total Production of Corn in %d is: '%.2f ku/ha'\n", year, total);
        system("pause");
    }
    else{
        printf("No such data exist");
    }
    char choice;getchar();
    printf("Do you want to compare a province to total data?(y/n): ");
    scanf("%c", &choice);
    if(choice == 'y'){
        comparePrdctvt(year,total);
    }
    else if(choice == 'n'){
        main();
    }
    else{
        main();
    }
}
int totalProductivity(){
    int choose;
    printf("Which year data do you want to see?");
    printf("\n1. 2020\n2. 2021\n3. 2022\n4. 2023\n");
    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case(1):
            totalPrdtvty(2020);
        break;
        case(2):
            totalPrdtvty(2021);
        break;
        case(3):
            totalPrdtvty(2022);
        break;
        case(4):
            totalPrdtvty(2023);
        break;
        default:
            printf("Invalid Choice");
            totalProductivity();
        break;
    }
}
int HighHarvest(int year){
    void main();
    if(year == 2020){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(hvsize[j].hS2020 < hvsize[j+1].hS2020){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2020);
        printf("\n");
        }
    }
    else if(year == 2021){
         LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(hvsize[j].hS2021 < hvsize[j+1].hS2021){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2021\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2021);
        printf("\n");
        }
    }
    else if(year == 2022){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(hvsize[j].hS2022 < hvsize[j+1].hS2022){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2022\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2022);
        printf("\n");
        }
    }
    else if(year == 2023){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(hvsize[j].hS2023 < hvsize[j+1].hS2023){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2023\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2023);
        printf("\n");
        }
    }
    system("pause");
    main();
}
int LowHarvest(int year){
    void main();
    if(year == 2020){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(hvsize[j].hS2020 > hvsize[j+1].hS2020){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2020);
        printf("\n");
        }
    }
    else if(year == 2021){
         LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(hvsize[j].hS2021 > hvsize[j+1].hS2021){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2021\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2021);
        printf("\n");
        }
    }
    else if(year == 2022){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(hvsize[j].hS2022 > hvsize[j+1].hS2022){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2022\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2022);
        printf("\n");
        }
    }
    else if(year == 2023){
        LuasPanen = fopen("LuasPanen.txt", "r");

        if (LuasPanen == NULL) {
        printf("Error opening file.\n");
        return 1;
        }
        HarvestSize hvsize[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(LuasPanen, "%49[^,],%f,%f,%f,%f\n", 
                      hvsize[records].province, 
                      &hvsize[records].hS2023,
                      &hvsize[records].hS2022,
                      &hvsize[records].hS2021,
                      &hvsize[records].hS2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(LuasPanen)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(LuasPanen)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(LuasPanen));
        fclose(LuasPanen);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(hvsize[j].hS2023 > hvsize[j+1].hS2023){
                    swapHS(&hvsize[j],&hvsize[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2023\t: %.2f ha\n", 
               hvsize[i].province, 
               hvsize[i].hS2023);
        printf("\n");
        }
    }
    system("pause");
    main();
}
int HighLowHarvest(int year){
    int choice;
    printf("Do you want to see the\n1. Highest\n2. Lowest\nChoose: ");
    scanf("%d", &choice);
    switch(choice){
        case(1):
            HighHarvest(year);
        break;
        case(2):
            LowHarvest(year);
        break;
        default:
            HighLowHarvest(year);
        break;
    }
}
int HarvestAreaHighLow(){
    int choose;
    printf("Which year data do you want to see?");
    printf("\n1. 2020\n2. 2021\n3. 2022\n4. 2023\n");
    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case(1):
            HighLowHarvest(2020);
        break;
        case(2):
            HighLowHarvest(2020);
        break;
        case(3):
            HighLowHarvest(2020);
        break;
        case(4):
           HighLowHarvest(2020);
        break;
        default:
            printf("Invalid Choice");
            HarvestAreaHighLow();
        break;
    }
}
int HighProd(int year){
    void main();
    if(year == 2020){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prod[j].p2020 < prod[j+1].p2020){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ton\n", 
               prod[i].province, 
               prod[i].p2020);
        printf("\n");
        }
    }
    else if(year == 2021){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prod[j].p2021 < prod[j+1].p2021){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2021\t: %.2f ton\n", 
               prod[i].province, 
               prod[i].p2021);
        printf("\n");
        }
    }
    else if(year == 2022){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prod[j].p2022 < prod[j+1].p2022){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2022\t: %.2f tom\n", 
               prod[i].province, 
               prod[i].p2022);
        printf("\n");
        }
    }
    else if(year == 2023){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prod[j].p2023 < prod[j+1].p2023){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2023\t: %.2f ton\n", 
               prod[i].province, 
               prod[i].p2023);
        printf("\n");
        }
    }
    system("pause");
    main();
}
int LowProd(int year){
    void main();
    if(year == 2020){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prod[j].p2020 > prod[j+1].p2020){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ton\n", 
               prod[i].province, 
               prod[i].p2020);
        printf("\n");
        }
    }
    else if(year == 2021){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prod[j].p2021 > prod[j+1].p2021){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2021\t: %.2f ton\n", 
               prod[i].province, 
               prod[i].p2021);
        printf("\n");
        }
    }
    else if(year == 2022){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prod[j].p2022 > prod[j+1].p2022){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2022\t: %.2f ton\n", 
               prod[i].province, 
               prod[i].p2022);
        printf("\n");
        }
    }
    else if(year == 2023){
        Produksi = fopen("Produksi.txt", "r");

        if (Produksi == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Production prod[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produksi, "%49[^,],%f,%f,%f,%f\n", 
                      prod[records].province, 
                      &prod[records].p2023,
                      &prod[records].p2022,
                      &prod[records].p2021,
                      &prod[records].p2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produksi)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produksi)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produksi));
        fclose(Produksi);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prod[j].p2023 > prod[j+1].p2023){
                    swapProd(&prod[j],&prod[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2023\t: %.2f ton\n", 
               prod[i].province, 
               prod[i].p2023);
        printf("\n");
        }
    }
    system("pause");
    main();
}
int HighLowProd(int year){
    int choice;
    printf("Do you want to see the\n1. Highest\n2. Lowest\nChoose: ");
    scanf("%d", &choice);
    switch(choice){
        case(1):
            HighProd(year);
        break;
        case(2):
            LowProd(year);
        break;
        default:
            HighLowProd(year);
        break;
    }
}
int ProductionHighLow(){
    int choose;
    printf("Which year data do you want to see?");
    printf("\n1. 2020\n2. 2021\n3. 2022\n4. 2023\n");
    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case(1):
            HighLowProd(2020);
        break;
        case(2):
            HighLowProd(2020);
        break;
        case(3):
            HighLowProd(2020);
        break;
        case(4):
           HighLowProd(2020);
        break;
        default:
            printf("Invalid Choice");
            ProductionHighLow();
        break;
    }
}
int HighPrdctvt(int year){
     void main();
    if(year == 2020){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prdctvt[j].pV2020 < prdctvt[j+1].pV2020){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2020);
        printf("\n");
        }
    }
    else if(year == 2021){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prdctvt[j].pV2021 < prdctvt[j+1].pV2021){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2021\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2021);
        printf("\n");
        }
    }
    else if(year == 2022){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prdctvt[j].pV2022 < prdctvt[j+1].pV2022){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2022\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2022);
        printf("\n");
        }
    }
    else if(year == 2023){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prdctvt[j].pV2023 < prdctvt[j+1].pV2023){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2023\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2023);
        printf("\n");
        }
    }
    system("pause");
    main();
}
int LowPrdctvt(int year){
    void main();
    if(year == 2020){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prdctvt[j].pV2020 > prdctvt[j+1].pV2020){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2020\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2020);
        printf("\n");
        }
    }
    else if(year == 2021){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prdctvt[j].pV2021 > prdctvt[j+1].pV2021){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2021\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2021);
        printf("\n");
        }
    }
    else if(year == 2022){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prdctvt[j].pV2022 > prdctvt[j+1].pV2022){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2022\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2022);
        printf("\n");
        }
    }
    else if(year == 2023){
        Produktivitas = fopen("Produktivitas.txt", "r");

        if (Produktivitas == NULL){
        printf("Error opening file.\n");
        return 1;
        }
        Productivity prdctvt[40];
        int read = 0;
        int records = 0;
        do {
            read = fscanf(Produktivitas, "%49[^,],%f,%f,%f,%f\n", 
                      prdctvt[records].province, 
                      &prdctvt[records].pV2023,
                      &prdctvt[records].pV2022,
                      &prdctvt[records].pV2021,
                      &prdctvt[records].pV2020);
            if (read == 5) {
            records++;
            }
            if (read != 5 && !feof(Produktivitas)) {
            printf("File format incorrect.\n");
            return 1;
            }
            if (ferror(Produktivitas)) {
            printf("Error reading file.\n");
            return 1;
            }
        }while(!feof(Produktivitas));
        fclose(Produktivitas);

        for(int i = 0; i < records-1; i++){
            for(int j = 0; j < records-1; j++){
                if(prdctvt[j].pV2023 > prdctvt[j+1].pV2023){
                    swapPrdctvt(&prdctvt[j],&prdctvt[j+1]);
                }
            }
        }
        for (int i = 0; i < 1; i++){
        printf("=======================\n");
        printf("Province: %s\n2023\t: %.2f ku/ha\n", 
               prdctvt[i].province, 
               prdctvt[i].pV2023);
        printf("\n");
        }
    }
    system("pause");
    main();
}
int HighLowPrdctvt(int year){
    int choice;
    printf("Do you want to see the\n1. Highest\n2. Lowest\nChoose: ");
    scanf("%d", &choice);
    switch(choice){
        case(1):
            HighPrdctvt(year);
        break;
        case(2):
            LowPrdctvt(year);
        break;
        default:
            HighLowPrdctvt(year);
        break;
    }
}
void ProductivityHighLow(){
    int choose;
    printf("Which year data do you want to see?");
    printf("\n1. 2020\n2. 2021\n3. 2022\n4. 2023\n");
    printf("Choose: ");
    scanf("%d", &choose);
    switch(choose){
        case(1):
            HighLowPrdctvt(2020);
        break;
        case(2):
            HighLowPrdctvt(2020);
        break;
        case(3):
            HighLowPrdctvt(2020);
        break;
        case(4):
           HighLowPrdctvt(2020);
        break;
        default:
            printf("Invalid Choice");
            ProductivityHighLow();
        break;
    }
}
void main(){
    int switcher, choice;
    // system("cls");
    printf("\n                          +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+\n");
    printf("                            |D| |A| |T| |A|   |O| |F|   |T| |H| |E|\n");
    printf("                            +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+\n");
    printf("    +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+\n");
    printf("    |H| |A| |R| |V| |E| |S| |T|   |A| |R| |E| |A|   |P| |R| |O| |D| |U| |C| |T| |I| |O| |N|\n");
    printf("    +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+\n");
    printf("             +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-++-+\n");
    printf("             |A| |N| |D|   |P| |R| |O| |D| |U| |C| |T| |I| |V| |I| |T| |Y|   |O||F|\n");
    printf("             +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-++-+\n");
    printf("            +-++-++-++-+   +-++-++-++-++-+   +-++-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+\n");
    printf("            |C||O||R||N|   |B||A||S||E||D|   |O||N|   |P| |R| |O| |V| |I| |N| |C| |E|\n");
    printf("            +-++-++-++-+   +-++-++-++-++-+   +-++-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+\n");
    printf("\033[1;32m\nHello there! Please select what do you want to do today\n\033[0m");
    printf("  +--------------------------------+\n");
    printf("  |           .: MENU :.           |\n");
    printf("  +--------------------------------+\n");
    printf("  |  1. See the Raw Data & Average |\n");
    printf("  |  2. See the Sorted Data        |\n");
    printf("  |  3. Search for the data of a   |\n");
    printf("  |    - specific province         |\n");
    printf("  |  4. See Indonesia's Total Data |\n");
    printf("  |  5. Highest & Lowest           |\n");
    printf("  |  6. Exit                       |\n");
    printf("  +--------------------------------+\n");
    printf(">>> Insert Choice : ");
    scanf("%d", &switcher);
    switch(switcher){
        case(1):
            printf("+--------------------------------+\n");
            printf("\033[1;33m|            RAW DATA            |\033[0m\n");
            printf("+--------------------------------+\n");
            printf("\033[1;31m1. See the Raw Data of the Corn Harvest Area     \033[0m\n");
            printf("\033[1;33m2. See the Raw Data of the Production of Corn          \033[0m\n");
            printf("\033[1;32m3. See the Raw Data of the Productivity of Corn               \033[0m\n");
            printf("\033[1;34m4. Return\n\033[0m");
            printf(">>> Choose : ");
            scanf("%d", &choice);
            switch(choice){
                case(1):
                    readHVSize();
                break;
                case(2):
                    readproduction();
                break;
                case(3):
                    readproductivity();
                break;
                case(4):
                    main();
                break;
                default:
                    printf("Invalid Choice");
                    main();
                break;
            }
        break;
        case(2):
            printf("+----------------+\n");
            printf("|\033[1;33m  SORTED DATA   \033[0m|\n");
            printf("+----------------+\n");
            printf("\033[1;31m1. See the Sorted Data of the Corn Harvest Area\033[0m\n");
            printf("\033[1;33m2. See the Sorted Data of the Production of Corn\033[0m\n");
            printf("\033[1;32m3. See the Sorted Data of the Productivity of Corn\033[0m\n");
            printf("\033[1;37m4.Return\033[0m\n");
            printf("Choose: ");
            scanf("%d", &choice);
            switch(choice){
                case(1):
                    sortedHarvestArea();
                break;
                case(2):
                    sortedProduction();
                break;
                case(3):
                    sortedProductivity();
                break;
                case(4):
                    main();
                default:
                    printf("Invalid Choice");
                    main();
                break;
            }
        break;
        case(3):
            searchSpecificProvince();
        break;
        case(4):
            printf("=====================\nSee Total\n=====================");
            printf("\n1. Total of the Corn Harvest Area\n2. Total of the Production of Corn\n3. Total of the Productivity of Corn\n4. Return\n");
            printf("Choose: ");
            scanf("%d", &choice);
            switch(choice){
                case(1):
                    totalHarvestArea();
                break;
                case(2):
                    totalProduction();
                break;
                case(3):
                    totalProductivity();
                break;
                case(4):
                    main();
                default:
                    printf("Invalid Choice");
                    main();
                break;
            }
        break;
        case(5):
            printf("=====================\nSee Highs\n=====================\n");
            printf("=====================\nSee Lows\n=====================\n");
            printf("+-----------------------------------------+\n");
            printf("| 1. Highs & Lows of Harvest Area         |\n");
            printf("+-----------------------------------------+\n");
            printf("+-----------------------------------------+\n");
            printf("| 2. Highs & Lows of Production of Corn   |\n");
            printf("+-----------------------------------------+\n");
            printf("+-----------------------------------------+\n");
            printf("| 3. Highs & Lows of Productivity of Corn |\n");
            printf("+-----------------------------------------+\n");
            printf("Choose: ");
            scanf("%d", &choice);
            switch(choice){
                case(1):
                    HarvestAreaHighLow();
                break;
                case(2):
                    ProductionHighLow();
                break;
                case(3):
                    ProductivityHighLow();
                break;
                case(4):
                    main();
                default:
                    printf("Invalid Choice");
                    main();
                break;
            }
        break;
        case(6):
            printf("=====================BYE-BYE!!!!!!=====================");
        break;
        default:
            printf("Invalid Choice");
            main();
        break;
    }
    return;
}