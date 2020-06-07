#include "BudgetManager.h"


using namespace std;

void BudgetManager::addIncome()
{
    Income income;
    income = getDetailsOfIncome();
    incomes.push_back(income);

    for (int i=0; i<incomes.size(); i++)
    {
        cout<<"UserId "<<incomes[i].getUserId()<<endl;
        cout<<"Income Id "<<incomes[i].getIncomeId()<<endl;
          cout<<"Income date "<<dateManager.convertDateToStr(incomes[i].getIncomeDate())<<endl;
            cout<<"Income Amount"<<incomes[i].getAmount()<<endl;
              cout<<"Income Item "<<incomes[i].getItem()<<endl;
    }


}

Income BudgetManager::getDetailsOfIncome()
{
    Income income;
    char sign;
    string amountStr;
    float amount;

    income.setUserId(ID_LOGGED_USER);

    if (incomes.empty() == true)
      income.setIncomeId(1);
    else
       income.setIncomeId(incomes.back().getIncomeId() + 1);

    system("cls");
    cout<<"Czy przychod dotyczy dnia dzisiejszego? Jezeli tak wpisz 't', jezeli nie wcisnij dowolny klawisz"<<endl;
    sign = getchar();
    if (sign == 't')
        income.setIncomeDate(dateManager.getTodayDate());
    else
    {
        income.setIncomeDate(dateManager.getDate());
    }
    cin.ignore();

    cout<<"Podaj czego dotyczy przychod"<<endl;
    income.setItem(AuxiliaryMethods::getLine());

    do
    {
        cout<<"Podaj wysokosc przychodu"<<endl;
        amountStr = AuxiliaryMethods::getLine();
    }
    while ((checkAmount (amountStr))==false);

    income.setAmount(convertStringToFloat(amountStr));
    return income;

}

bool BudgetManager::checkAmount (string amount)
{
    for (int i=0; i<amount.length(); i++)
    {
        if (((amount[i]<='9')&&(amount[i]>='0'))|| ((amount[i]=='.') || (amount [i] == ',')));
        else
        {
            cout<<"Nieprawidlowa wartosc"<<endl;
            return false;
        }
    }
    return true;
}

float  BudgetManager::convertStringToFloat(string amount)
{
    float amountF;
    char* endChar;

    for (int i=0; i<amount.length(); i++)
    {
        if (amount[i]==',')
            amount[i] = '.';
    }
    const char * amountChar = amount.c_str();
    amountF = strtof(amountChar, &endChar);
    //setprecision(2);
    cout<<"Przychod wynosi "<<amountF<<endl;
    return amountF;

}



/*    void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout<<"Dodano adresata"<<endl;
    else
        cout<<"Cos poszlo nie tak"<<endl;
    system("pause");

}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;

    adresat.ustawId((plikZAdresatami.pobierzIdOstatniegoAdresata()+1));

    adresat.ustawIdUzytkkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}
*/
