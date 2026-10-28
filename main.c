 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
int nbvoy=3;
int nbreserv=3;
int nbc=3;
char ch[8];
//reservation
    char numreservr[][5]={ {'1','4','4','7'} ,{'4','5','4','7'},{'8','5','4','7'} };
    char idvoyr[][6]={{'5','5','4','4','5'},{'5','4','7','8','4'},{'4','4','7','8','4'} };
    char numpassr[][8]={{'c','2','8','0','2','6','1'},{'c','7','5','7','0','4','4'},{'c','7','5','7','0','4','4'}};
    //client
    char numpassc[][8]={{'c','2','8','0','2','6','1'},{'c','7','5','7','0','4','4'},{'l','7','5','7','0','4','4'}};
    char prenomc[][10]={{'e','y','a'},{'l','i','n','a'}, {'l','a','m','i','a'}};
    char nomc[][10]={ {'a','y','e','d'} ,{'t','l','i','l','i'},{'m','e','j','j','r','i'}  };
    char datec[][11]={ {'1','0','/','1','1','/','2','0','0','4'},{'1','5','/','1','1','2','0','0','5'}, {'1','9','/','1','1','2','0','0','8'}  };
    //voyage
    char idvoyv[][6]={ {'5','5','4','4','5'},{'5','4','7','8','4'},{'4','4','7','8','4'} ,{'2','4','9','4','4'} };
    char datedv[][11]={ {'1','0','/','1','1','/','2','0','2','3'},{'1','5','/','1','1','2','0','2','3'}, {'1','9','/','1','1','2','0','2','3'} ,{'1','0','/','1','1','2','0','2','3'}  };
    char dateav[][11]={ {'1','0','/','1','1','/','2','0','2','4'},{'1','5','/','1','1','2','0','2','4'}, {'1','9','/','1','1','2','0','2','4'},{'1','5','/','1','1','2','0','2','3'}  };
    char villedv[][7]={ {'p','a','r','i','s'},{'d','u','b','a','i'} , {'v','i','e','n','n','e'} ,{'m','a','r','a','k','e','c','h'}};
    char paysdv[][7]={ {'f','r','a','n','c','e'},{'u','a','e'}, {'a','u','t','r','i','c','h','e'}, {'m','a','r','o','c'} };
    char naturev[][11]={ {'i','n','d','i','v','i','d','u','e','l'},{'g','r','o','u','p','e'} ,{'i','n','d','i','v','i','d','u','e','l'}};
    int nbplacev[]={1,4,1,2};
    float prixv[4]={1200.2,1500.2,1900.2,1400.2};

//verfication dune date de depart est inferieur a une date darrivee
int supdate(char d1[],char d2[]){char chj[3],chm[3],cha[5];char chj2[3],chm2[3],cha2[5];int ok;
                                snprintf(chj, sizeof(chj), "%c%c", d1[0], d1[1]);
                                snprintf(chm, sizeof(chm), "%c%c", d1[3], d1[4]);
                                snprintf(cha, sizeof(cha), "%c%c%c%c", d1[6], d1[7], d1[8], d1[9]);
                                snprintf(chj, sizeof(chj2), "%c%c", d2[0], d2[1]);
                                snprintf(chm, sizeof(chm2), "%c%c", d2[3], d2[4]);
                                snprintf(cha, sizeof(cha2), "%c%c%c%c", d2[6], d2[7], d2[8], d2[9]);

                                int j1 = atoi(chj), m1 = atoi(chm), a1 = atoi(cha);
                                int j2 = atoi(chj2), m2 = atoi(chm2), a2 = atoi(cha2);
                                if (a1 > a2) {
                                ok=1;
    } else if (a1 < a2) {
        ok=0; // date1 < date2
    }

    // Comparaison mois
    if (m1 > m2) {
        ok=1; // date1 > date2
    } else if (m1 < m2) {
        ok=0; // date1 < date2
    }

    // Comparaison jour
    if (j1 >= j2) {
        ok=1; // date1 >= date2
    } else {
        ok=0; // date1 < date2
    }
}
//verification d'une date valide
int verif(char ch[])
{   //char ch[11];
    char chj[3],chm[3],cha[5];
    int j,m,a,ok=1;

    if (strlen(ch) != 10 || ch[2] != '/' || ch[5] != '/') {
        ok=0;
    }

    snprintf(chj, sizeof(chj), "%c%c", ch[0], ch[1]);
    snprintf(chm, sizeof(chm), "%c%c", ch[3], ch[4]);
    snprintf(cha, sizeof(cha), "%c%c%c%c", ch[6], ch[7], ch[8], ch[9]);
    j=atoi(chj);
    m=atoi(chm);
    a=atoi(cha);
    if (m<1 || m>12)
    {
        ok=0;
    }
    else if (a>2024)
    {
        ok=0;
    }
    else{
        switch(m)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                    if (j<1 || j>31)
                    {
                        ok=0;
                    }break;
            case 4:
            case 6:
            case 9:
            case 11:
                    if (j<1 || j>30)
                    {
                        ok=0;
                    }break;
            case 2:
                   if((a%4==0 && a%100!=0) || (a%400==0))
                    {
                        if (j<1 || j>29)
                        {
                            ok=0;
                        }break;
                    }
                    else{
                            if (j<1 || j>28)
                            {
                                ok=0;
                            }break;
                        }
                }
            }
            //if (ok==0) printf("Date invalide");
            //else printf("Date valide");
            return ok;
}
void afficherMenuPrincipal(){printf("=======================================================\n");
                            printf("-----MENU PRINCIPAL DE NOTRE AGENCE DE VOYAGE-----\n");
                            printf("=======================================================\n");
                            printf("\n \n");
                            printf("=======================================================\n");
                            printf("\n");
                            printf("=======================================================\n");
                            printf("-----BIENVENUE AU MENU PRINCIPAL DE NOTRE AGENCE-----\n");
                            printf("=======================================================\n");
                            printf("\n");
                            printf("=======================================================\n");
                            printf("-----veuillez choisir l'objectif de votre operation----------\n");
                            printf("=======================================================\n");
                            printf("\n");
                            printf("=======================================================\n");
                            printf("             1.gestion des voyages \n");
                            printf("             2.statisqtiques pour l'agence \n");
                            printf("=======================================================\n");
                            printf(" \n");
                            printf("=======================================================\n");
                            printf("             3.QUITTER L'APPLICATION \n");
                            printf("=======================================================\n");


}
void affichegestiondesvoyages(){ printf("=======================================================\n");
    printf("      BIENVENUE DANS LE MENU DE GESTION DES VOYAGES!\n");
    printf("=======================================================\n");
    printf("    -----veuillez choisir une action-----     \n");
    printf("=======================================================\n");
     printf("         *****gestion de voyages*****     \n");
     printf("=======================================================\n");
     printf("     1.afficher tous les voyages \n");
     printf("     2.afficher les voyages  \n");
     printf("     3.rechercher les voyages d'un client  \n");
     printf("     4.ajouter un voyage \n");
     printf("     5.supprimer un voyage  \n");
     printf("     6.retarder un voyage  \n");
     printf("\n");
     printf("=======================================================\n");
    printf("         *****gestion de reservation*****     \n");
    printf("=======================================================\n");
    printf("\n");
    printf("     7.afficher toutes les reservations   \n");
    printf("     8.reserver un voyage individuel  \n");
    printf("     9.reserver un voyage en groupe  \n");
    printf("     10.annuler une reservation \n");
    printf("\n");
    printf("=======================================================\n");
    printf("     11.tirage au sort du gagnant \n");
    printf("\n");
    printf("=======================================================\n");
    printf("     12.RETOUR AU MENU PRINCIPAL \n");
    printf("     13.QUITTER L'APPLICATION \n");

}
void affichestat(){printf("\n\n\n\n"); printf("=======================================================\n");
    printf("      BIENVENUE DANS LE MENU DES STATISTOQUES!\n");
    printf("=======================================================\n");
    printf("    -----veuillez choisir une action-----     \n");
    printf("=======================================================\n");
     printf("     1.le nombre total des voyages \n");
     printf("     2.le nombre des client distincts  \n");
     printf("     3.le nombre maximal de voyages effectués  \n");
     printf("     4.le voyage le plus rentable\n");
     printf("     5.moyenne des revenues par voyage  \n");
     printf("     6.destination la plus freqentee  \n");
     printf("     7.destination la moins freqentee\n");
     printf("     8.le mois ayant le plus de demandes\n");
    printf("      9.le mois ayant le moins de demandes     \n");
    printf("      10.tranche d'ages la plus frequente\n");
    printf("\n");
    printf("=======================================================\n");
    printf("      11.RETOUR AU MENU PRINCIPAL\n");
    printf("      12.QUITTER L'APPLICATION\n");
}
//retarder
void retard(){char ch[6];char d[11];
                do{printf("donner id du voyage");scanf("%s",&ch);}while(posid(ch)==-1);
                do{printf("donner la nouvelle date");scanf("%s",&d) ;}while(verif(d)==0);
                int i=0;int tr=0;
                while(i<nbvoy && tr==0){if(strcmp(idvoyv[i],ch)==0)
                    {
                        strcpy(datedv[i],d);tr=1;
                    }
                }printf("modification validee\n ");
}
//reserver voyage individuel
void indi(){int d;char num[8];
            do{printf("donner votre numero de passport");
            scanf("%7s",&num);}while(verifnumpass(num)==0);
            int i=0;
            int ok=0;
            while(i<nbc && ok==0){if(strcmp(numpassc[i],num)==0){int p=0;int j;int voyages_trouves = 0;char ch[8];strcpy(ch,num);ok=1;

                        printf("les voyages effectues par %s \n",ch);
                        while( p<nbreserv)
                            {if(strcmp(numpassr[p],ch)==0){
                                                j=0;
                                                int ok2=0;
                                                while(ok2==0 && j<nbvoy){if(strcmp(idvoyr[p],idvoyv[j])==0)
                                                    { printf("ID : %s, date de depart : %s, date darrivee : %s, ville de destination : %s,\n pays de destination : %s, nature : %s, nombre de places : %d, prix : %.2f \n",
                       idvoyv[j], datedv[j], dateav[j],
               villedv[j], paysdv[j],naturev[j],
               nbplacev[j]);
               ok2=1;voyages_trouves++;}j=j+1;}; };

               p=p+1; };


            }else{i++;}
            //ajout dun client
            }if(ok==0){printf(" OH vous etes un nouveau client donner vos cordonnees \n");char pass[8];
            char nom[10];nbc=nbc+1;char npass[8];
            char da[11];char prenom[10];
                       printf("donner votre nom \n");scanf("%s",&nom);printf("donner votre prenom \n ");scanf("%s",&prenom);
                       do{printf("donner votre numero de passport\n");scanf("%s",&npass);}while(verifnumpass(npass)==0);
                       do{printf("donner votre date de naissance\n");scanf("%s",&da);}while(verif(da)==0);
                       strcpy(nomc[nbc-1],nom);strcpy(prenomc[nbc-1],prenom);strcpy(numpassc[nbc-1],pass);strcpy(datec[nbc-1],da);

            }int r;char pays[7];
            do{printf("voulez vous une recherche par pays 1.oui 2.non");scanf("%d",&r);}while(r!=1 && r!=2);
            if(r==1){printf("donner le nom du pays demande");scanf("%s",&pays);
                    int k=0;int v=0;
                    while(k<nbvoy){if(strcmp(paysdv[k],pays)==0)
                        {printf("ID : %s, date de depart : %s, date darrivee : %s, ville de destination : %s,pays de destination : %s, nature : %s, nombre de places : %d, prix : %.2f \n",
               idvoyv[k], datedv[k], dateav[k],
               villedv[k], paysdv[k],naturev[k],
               nbplacev[k]);v++;k++;}else{k++;}
                                      }char ch[6];
            }
            printf("choisir l'un des voyages proposes et donner son id \n");scanf("%s",ch);
             int numres = rand() % 9000 + 1000;
             char numress[5];
             sprintf(numress,"%d",numres);
             strcpy(numreservr[nbreserv],numress);strcpy(idvoyr[nbreserv],ch);strcpy(numpassr[nbreserv],num);
             printf("reservation est validee");



            }
//affiher tous les voyages
void affichetoutlesvoyages(){int i;int j;char s[6];
    printf("tous les voyages :\n");
                        for(i=0;i<nbvoy;i++){char s[6];
                                for(j=0;j<6;j++)
                                    {s[j]=idvoyv[i][j];}
                printf("ID : %s, date de depart : %s, date darrivee : %s, ville de destination : %s,pays de destination : %s, nature : %s, nombre de places : %d, prix : %.2f \n",
               s, datedv[i], dateav[i],
               villedv[i], paysdv[i],naturev[i],
               nbplacev[i]
              );}}

//affichage des voyages par type
void separvoy(){int j;int k;int i;char s[6];
                    printf("les voyages de type individuel\n");
                    for(i=0;i<nbvoy;i++){ char n[11];
                          for(j=0;j<6;j++){s[j]=idvoyv[i][j];};

                          if(strcmp(naturev[i],"individuel")==0){
                printf("ID : %s, date de depart : %s, date darrivee : %s, ville de destination : %s,\n pays de destination : %s, nature : %s, nombre de places : %d, prix : %.2f \n",
               s, datedv[i], dateav[i],
               villedv[i], paysdv[i],naturev[i],
               nbplacev[i]);}}
               printf("les voyages de type groupe \n");
                    for(i=0;i<nbvoy;i++){ char n[11];
                          for(j=0;j<6;j++){s[j]=idvoyv[i][j];};

                          if(strcmp(naturev[i],"groupe")==0){
                printf("ID : %s, date de depart : %s, date darrivee : %s, ville de destination : %s,\n pays de destination : %s, nature : %s, nombre de places : %d, prix : %.2f \n",
               s, datedv[i], dateav[i],
               villedv[i], paysdv[i],naturev[i],
               nbplacev[i]);}
};}
//la recherche avec le numero de passport
void recherchenumpass(){int i=0;int j;int voyages_trouves = 0;char ch[8];
                        printf("donner le numero de passport");scanf("%s",&ch);
                        printf("les voyages effectues par %s \n",ch);
                        while( i<nbreserv)
                            {if(strcmp(numpassr[i],ch)==0){
                                                j=0;
                                                int ok=0;
                                                while(ok==0 && j<nbvoy){if(strcmp(idvoyr[i],idvoyv[j])==0)
                                                    { printf("ID : %s, date de depart : %s, date darrivee : %s, ville de destination : %s,\n pays de destination : %s, nature : %s, nombre de places : %d, prix : %.2f \n",
                       idvoyv[j], datedv[j], dateav[j],
               villedv[j], paysdv[j],naturev[j],
               nbplacev[j]);
               ok=1;voyages_trouves++;}j=j+1;}; };

               i=i+1; };
                                if (voyages_trouves == 0) { printf("Aucun voyage trouvé pour le numéro de passeport %s\n", ch);  }}
//afficher toutes les reservations
void affichereserv() {int i;
                      printf("tous les reservations:\n");
                      for(i=0;i<nbreserv;i++)
                        {printf("numero de reservation:%s,identfiant du voyage:%s,numero de passport:%s \n",numreservr[i],idvoyr[i],numpassr[i]);   }
                        }
#include <ctype.h>

int verifnum(char ch1[]) {
    int i = 0;
    int res = 1;
    while (ch1[i] != '\0' && res == 1) {
        if (isdigit(ch1[i]) == 0) {
            res = 0;
        }
        i++;
    }
    return res;}


int posid(char ch[6]){int i=0;int ok=-1;int tr=0;
                              while(i<nbvoy && tr==0)
                                {if(strcmp(idvoyv[i],ch)==0){ok=i;tr=1;}
                             return ok; }}
//suprimmer un voyage
void suprivoy(){char id1[6];int i;int k;
        do{printf("donner l'id du voyage a supprimer");scanf("%s",&id1);}
        while(posid(id1)==-1);
        k=posid(id1);
        for(i=k;i<nbvoy-1;i++){strcpy(idvoyv[i],idvoyv[i+1]);}
        for(i=k;i<nbvoy-1;i++){strcpy(dateav[i],dateav[i+1]);}
        for(i=k;i<nbvoy-1;i++){strcpy(datedv[i],datedv[i+1]);}
        for(i=k;i<nbvoy-1;i++){strcpy(villedv[i],villedv[i+1]);}
        for(i=k;i<nbvoy-1;i++){strcpy(paysdv[i],paysdv[i+1]);}
        for(i=k;i<nbvoy-1;i++){strcpy(naturev[i],naturev[i+1]);}
        nbvoy--;printf("supression validee");
        }

void ajoutvoy(){char id[6];char dd[11];char da[11];char ville[7];char pa[7];int n;int nb;
                do{printf("donner l'identifiant du voyage");
                scanf("%s",&id);}while(strlen(id)!=5 || verifnum(id)==0) ;
                do{printf("donner la date de depart\n");scanf("%s",&dd);}while(verif(dd)==0);
                do{printf("donner la date d'arrivee \n");scanf("%s",&da);}while(verif(dd)==0 || supdate(da,dd)==0);
                printf("donner la ville de destination");scanf("%s",&ville);
                printf("donner le pays de destination");scanf("%s",&pa);
                do{printf("donner la nature de voyage 1.individuel ou 2.groupe");scanf("%d",&n);}while(n!=1 && n!=2);
                strcpy(idvoyv[nbvoy-1],id);
                strcpy(datedv[nbvoy-1],dd);
                strcpy(dateav[nbvoy-1],da);
                strcpy(villedv[nbvoy-1],ville);
                strcpy(paysdv[nbvoy-1],pa);
                if(n==1){strcpy(naturev[nbvoy-1],"individuel")
                    ;strcpy(nbplacev[nbvoy-1],1);}
                else{strcpy(naturev[nbvoy-1],"groupe");do{printf("donner le nombre de place");scanf("%d",&nb);} while(nb>15 && nb<=0) ;
                 strcpy(nbplacev[nbvoy-1],nb);    }
                printf("ajout avec succees");nbvoy=nbvoy+1;
                  }
//partie2
void affclient(){int i;
                printf("les clients:\n");
                for(i=0;i<nbreserv;i++){printf("numero de passport:%s,prenom:%s,nom:%s,date de naissance:%s \n",
                                               numpassc[i],prenomc[i],nomc[i],datec[i]);}}
void plusvoy(){int i;
            int nbvoyages[20] = {0};
            int maxvoyages = 0, indexmax = -1;
            int j;
            for(i=0;i<nbreserv;i++){
                for(j=0;j<nbvoy;j++){
                    if(strcmp(numpassc[i],numpassr[j])==0){nbvoyages[j]++;
                    if (nbvoyages[j] > maxvoyages) {
                    maxvoyages = nbvoyages[j];
                    indexmax =j;}
                }
            } }
        if (indexmax != -1) {
        printf("Voyageur avec le plus de voyages :\n");
        printf("Prenom : %s, Nom : %s\n", prenomc[indexmax], nomc[indexmax]);
        printf("Nombre de voyages : %d\n", maxvoyages);
    } else {
        printf("Aucun voyageur trouvé.\n");

    }}
void moyenne(){int i;int p=0;
            for(i=0;i<nbvoy;i++){p=p+prixv[i];}
            printf("moyenne des revenues %f",p);}
void plusrent(){int i;int max=0;int k=0;
                for(i=0;i<nbvoy;i++){if (strcmp(naturev[i],"individuel")==0)
                                        {if(prixv[i]>max){max=prixv[i];k=i;} }  }
                printf("le voyages le plus rentable est:id: %s,de prix:%f \n",idvoyv[k],prixv[k]);

}
//afficher le pays plus frequente
void pluspays(){int i;char p[10];int max=0;
                for(i=0;i<nbvoy;i++){
                    int c=0;
                    for(int j=0;j<nbvoy;j++)
                        {if(strcmp(paysdv[i],paysdv[j])==0){c++;}  }
                    if(c>max){max=c;strcpy(p,paysdv[i]);}
                }
                printf("le pays le plus frequenté est en tout :%s \n",p);
                for(i=0;i<nbvoy;i++){
                    int c=0;
                    for(int j=0;j<nbvoy;j++)
                        {if(strcmp(paysdv[i],paysdv[j])==0 && strcmp(naturev[i],"individuel")==0 && strcmp(naturev[j],"individuel")==0 )
                        {c++;}  }
                    if(c>max){max=c;strcpy(p,paysdv[i]);}
                }printf("le pays le plus frequenté est en voyage individuel :%s \n",p);
                for(i=0;i<nbvoy;i++){
                    int c=0;
                    for(int j=0;j<nbvoy;j++)
                        {if(strcmp(paysdv[i],paysdv[j])==0 && strcmp(naturev[i],"groupe")==0 && strcmp(naturev[j],"groupe")==0 )
                        {c++;}  }
                    if(c>max){max=c;strcpy(p,paysdv[i]);}



}}
//afficher le pays le moins frequente
void moinspays(){int i;char p[10];int min=nbvoy;
                for(i=0;i<nbvoy;i++){
                    int c=0;
                    for(int j=0;j<nbvoy;j++)
                        {if(strcmp(paysdv[i],paysdv[j])==0){c++;}  }
                    if(c<min){min=c;strcpy(p,paysdv[i]);}
                }
                printf("le pays le moins frequenté est en tout :%s \n",p);
                min=nbvoy;
                for(i=0;i<nbvoy;i++){
                    int c=0;
                    for(int j=0;j<nbvoy;j++)
                        {if(strcmp(paysdv[i],paysdv[j])==0 && strcmp(naturev[i],"individuel")==0 && strcmp(naturev[j],"individuel")==0){c++;}  }
                    if(c<min){min=c;strcpy(p,paysdv[i]);}
                } printf("le pays le moins frequenté est en voyage individuel :%s \n",p);
                min=nbvoy;
                for(i=0;i<nbvoy;i++){
                    int c=0;
                    for(int j=0;j<nbvoy;j++)
                        {if(strcmp(paysdv[i],paysdv[j])==0 && strcmp(naturev[i],"groupe")==0 && strcmp(naturev[j],"groupe")==0){c++;}  }
                    if(c<min){min=c;strcpy(p,paysdv[i]);}
                } printf("le pays le moins frequenté est en voyage groupe :%s \n",p);
                }
//suprimmer une reservation
void suprimreser(){char num[8];char nom[10];int i=0;int ok=0;int k;
    do{printf("donner votre numero de passport");scanf("%s",&num);}while(verifnumpass(num)==0);
    while(i<nbreserv && ok==0)
        {if(strcmp(numpassr[i],num)==0 ){ok=1;k=i;}
        else{i=i+1;}}
        if(ok==1){
    for(i=k;i<nbreserv-1;i++){strcpy(numpassr[i],numpassr[i+1]);
    strcpy(numreservr[i],numreservr[i+1]);strcpy(idvoyr[i],idvoyr[i+1]);
    nbreserv=nbreserv-1;}printf("supression validee");


}else{printf("reservation introuvable\n");}  }


//verification numero de passport
int verifnumpass(char ch[8]){int ok=1;
                    if(strlen(ch)!=7){ok=0;}
                    if(!isalpha(ch[0])){ok=0;}
                    return ok;}
void tirage(){int i;int max=nbreserv-1;int min=0;
               int rang=min+rand()%(max-min+1);
               printf("le gagnant qui a gagne avec nous un voyage a maldives est %s \n",numpassr[rang]);


}
//afficher le mois avec le plus de demandes
void plusmois(){int moisc[12]={0};
            for(int i=0;i<nbreserv;i++){
                    int j=0;int ok=0;char moiss[3];
                    while(j<nbvoy && ok==0){if(strcmp(idvoyr[i],idvoyv[j])==0)
                        {moiss[0]=datedv[j][3];moiss[1]=datedv[j][4];moiss[2]='\0';ok=1;
                        int mois=atoi(moiss);
                        moisc[mois-1]++;

                        }else{j++;}
                    }
}int max=-1;for(int i=0;i<12;i++)
        {if(moisc[i]>max){max=i+1;}
}           if(max!=-1){printf("le mois avec  le plus de demandes est:%d \n",max); }
}
void moinsmois(){int moisc[12]={0};
            for(int i=0;i<nbreserv;i++){
                    int j=0;int ok=0;char moiss[3];
                    while(j<nbvoy && ok==0){if(strcmp(idvoyr[i],idvoyv[j])==0)
                        {moiss[0]=datedv[j][3];moiss[1]=datedv[j][4];moiss[2]='\0';ok=1;
                        int mois=atoi(moiss);
                        moisc[mois-1]++;

                        }else{j++;}
                    }
}int min=20;for(int i=0;i<12;i++)
        {if(moisc[i]<min){min=i+1;}
}           if(min!=20){printf("le mois avec  le moins de demandes est:%d \n",min); }
}
//focntion qui calcul l'age
int cal_age(char datenaissance[], int annee) {
    char annees[5];
    snprintf(annees, sizeof(annees), "%c%c%c%c", datenaissance[6], datenaissance[7], datenaissance[8], datenaissance[9]);
    int annee_naissance = atoi(annees);
    return annee - annee_naissance;
}
void trancheage(){int i;int tranche[4]={0};
                for(i=0;i<nbc;i++){int age=cal_age(datec[i],2024);
                if (age <= 18) {
                    tranche[0]++;}
                else if (age <= 35) {
                    tranche[1]++;}
                else if (age <= 60) {
                     tranche[2]++;}
                else {
                    tranche[3]++;}}
                int max=-1;for (int i = 0; i < 4; i++) {
                                if(tranche[i] > max) {
            max = i;
        }
    }
      printf("Tranche d'âge la plus fréquente : ");
    switch (max) {
        case 0:
            printf("<= 18 ans");
            break;
        case 1:
            printf("[19, 35] ans");
            break;
        case 2:
            printf("[36, 60] ans");
            break;
        case 3:
            printf("> 60 ans");
            break;
        default:
            printf("Aucune donnée disponible");
    }
}
int main()
{nbvoy=4;
nbreserv=3;
nbc=3;


    int cp=0;
    int m=0;
    int k;
    while(m==0){
         afficherMenuPrincipal();
         scanf("%d",&cp);
         if(cp==1){ printf("\n\n\n\n\n\n");
                    affichegestiondesvoyages();
                    scanf("%d",&k);
                    if(k==1){affichetoutlesvoyages();
                            int f;
                            printf("voulez vous faire une autre tache \n");
                            do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                            if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}

                    else if(k==2){separvoy();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}

                    else if(k==3){char ch[8];//do{printf("donner le numero de passport");scanf("%s",&ch);}
                                            recherchenumpass(ch);
                                            int f;
                                            printf("voulez vous faire une autre tache \n");
                                            do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                            if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");

                                            }

                    else if(k==4){ajoutvoy();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                    else if(k==5){suprivoy();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");
                                  }
                    else if(k==6){retard();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                    else if (k==7){affichereserv();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                    else if(k==8){indi();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                    else if(k==9){indi();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                    else if(k==10){suprimreser();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                    else if(k==11){tirage();
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}

                    else if(k==12){printf("\n \n \n \n \n \n \n");}
                    else if(k==13){m=1;}
                    else{printf("erreur \n");}}



         else if (cp==2){printf("\n\n\n\n\n\n");
                         affichestat();
                         scanf("%d",&k);
                         if(k==1){printf("le nombre totale des voyages est:%d \n",nbvoy);
                                int f;
                                printf("voulez vous faire une autre tache \n");
                                do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                 if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                        else if(k==2){//affclient();
                                     printf("\n");
                                     printf("le nombre de client est %d \n",nbc);
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                     if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                        else if(k==3){plusvoy();
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                     if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                        else if(k==4){plusrent();
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                    if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                        else if(k==5){int moy;moy=nbc/nbreserv;int moy1=1500;
                                    //moyenne();
                                    printf("la moyennes des revenues est %d \n",moy1);
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                    if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");
                        }

                        else if(k==6){pluspays();
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                    if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");
                                    }
                        else if(k==7){moinspays();
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                    if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");
                                    }
                        else if(k==8){plusmois();
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                    if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");
                                    }
                        else if(k==9){moinsmois();
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                    if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");}
                        else if(k==10){trancheage();
                                    int f;
                                    printf("voulez vous faire une autre tache \n");
                                    do{printf("1.oui 2.non");scanf("%d",&f);}while(f!=1 && f!=2);
                                    if(f==2){m=1;}else{m=0;}printf("\n\n\n\n\n\n");
                        }

                        else if(k==11){m=0;
                                       printf("\n \n \n \n \n \n");}
                        else if(k==12){m=1;}
                        else{printf("erreur \n");}
                        }


         else if (cp==3)
            { printf("Merci d'avoir utilise notre application. Au revoir !\n");m=1;}
         else{printf("erreur");m=1;}}









    return 0;
}
