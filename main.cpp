#include <iostream>
#include <string.h>

using namespace std;

class formular_inscriere
{
protected:
    char nume[20];
    float medie_bac;
public:
    formular_inscriere(float mb=0)
    {
        medie_bac=mb;
        strcpy(nume,"");
    }

    void citire_formular_inscriere();
    void afisare_formular_inscriere();
};

void formular_inscriere::citire_formular_inscriere()
{
    cout<<"introdu numele canditatului: "<<endl;
    cin>>nume;
    cout<<"introdu media bac: "<<endl;
    cin>>medie_bac;

}
void formular_inscriere::afisare_formular_inscriere()
{
    cout<<"numele canditatului: "<<nume<<endl;
    cout<<"media bac: "<<medie_bac<<endl;

}

class dosar
{
    int nr_inregistrare;
    formular_inscriere Formular;
public:

    void citire_dosar();
    void afisare_dosar();

};
void dosar::citire_dosar()
{

    cout<<"introdu nr inregistrare"<<endl;
    cin>>nr_inregistrare;

    Formular.citire_formular_inscriere();
}
void dosar::afisare_dosar()
{

    cout<<"nr inregistrare"<<nr_inregistrare<<endl;

    Formular.afisare_formular_inscriere();

}


class candidat
{
    dosar Dosar; //formular inscriere- nume,medie bac
    char legitimatie[20];

public:

    void citire_candidat()
    {
        Dosar.citire_dosar();
        cout<<"introdu legitimatia: "<<endl;
        cin>>legitimatie;

        cout<<"TIP INVATAMANT"<<endl;

    }
    void afisare_candidat()
    {
        Dosar.afisare_dosar();
        cout<<"legitimatia: "<<legitimatie<<endl;

        cout<<"TIP INVATAMANT"<<endl;


    }

    friend istream& operator>>(istream& in,candidat &ob)
    {
        ob.citire_candidat();
        return in;
    }
    friend ostream& operator<<(ostream& out,candidat &ob)
    {
        ob.afisare_candidat();
        return out;
    }
};

class admitere_ID_nu_a_2_a_facultate
{
    float nota_matematica;
public:

    void afisare_admitere_ID_nu_a_2_a_facultate();
    void citire_admitere_ID_nu_a_2_a_facultate();

};
void admitere_ID_nu_a_2_a_facultate::afisare_admitere_ID_nu_a_2_a_facultate()
{
    cout<<"introdu nota mate: "<<endl;
    cin>>nota_matematica;
}
void admitere_ID_nu_a_2_a_facultate::citire_admitere_ID_nu_a_2_a_facultate()
{
    cout<<"nota mate: "<<nota_matematica<<endl;

}
class a2a_facultate
{
    char program_studii_absolvit[10];
    float media_de_absolvire;
public:

    void citire_a2a_facultate();
    void afisare_a2a_facultate();
};
void a2a_facultate::citire_a2a_facultate()
{
    cout<<"introdu program_studii_absolvit :"<<endl;
    cin>>program_studii_absolvit;
     cout<<"introdu media_de_absolvire :"<<endl;
     cin>>media_de_absolvire;
}
void a2a_facultate::afisare_a2a_facultate()
{
      cout<<"program_studii_absolvit :"<<program_studii_absolvit<<endl;
    cout<<"media_de_absolvire :"<<media_de_absolvire<<endl;


}
class proba_de_concurs
{
    float MA,nota_proba_scrisa;



};
int main()
{
    int nr;
    candidat c;
    c.citire_candidat();
    c.afisare_candidat();
    cout<<"LA CE DAU ADMITEREA?"<<endl;
    cout<<"1:admitere_ID_nu_a_2_a_facultate "<<endl;
    cout<<"2:a2a_facultate "<<endl;
    cin>>nr;
    if(nr==1)
    {
        admitere_ID_nu_a_2_a_facultate admitere;
        admitere.citire_admitere_ID_nu_a_2_a_facultate();
        admitere.afisare_admitere_ID_nu_a_2_a_facultate();
    }
    else if(nr==2)
    {
        a2a_facultate ad;
        ad.citire_a2a_facultate();
        ad.afisare_a2a_facultate();
    }



    return 0;
}
