#include "WeatherRecord.h"
#include "additionalFunction.h"
#include "DataSource.h"
int main()
{

    //read and check how many files to read
    DataSource mydata;
    ifstream infile1( "data/data_source.txt" );

    if( !infile1 )
    {
        return -1;
    }
    infile1 >> mydata;

    //Creation of weatherRecords.
    WeatherRecord myRec;
    int choice;
    for(int i = 0; i < mydata.getDataSize(); i++)
    {
        string path = "data/"+mydata.getRecord(i);
        cout << path << endl;
        ifstream infile(path);
        infile >> myRec;
        infile.clear();
    }


    //Menu option
    cout << "Record Found: "<<myRec.GetTotalRecords() << endl;
    cout << "1. Calculate of Average windspeed" << endl;
    cout << "2. Average ambient Air Temperature" << endl;
    cout << "3. sPCC Caluclation" << endl;
    cout << "4. MAD Caluclation" << endl;
    cout << "5. Total solar radiation" << endl;
    cout << "6. Search by Month/Year" << endl;

    //cout << "7. Display All Records" << endl;
    cin >> choice;
   float ans = 1;
    //menu selection option
    if(choice == 1)
    {
        ans = myRec.averageWindSpeed();
        cout << ans << endl;
    }
    if(choice == 2)
    {
        ans = myRec.averageAirTemp();
        cout << ans << endl;
    }
    if(choice == 3)
    {
       cout << "Enter Month" << endl;
       cin >> choice;
       myRec.sPCCalculate(choice);

       //cout << ans << endl;
    }
    if(choice == 4)
    {
       cout << "Enter Year" << endl;
       cin >> choice;
       myRec.MADCalculate(choice);

    }
    if(choice == 5)
    {
       ans = myRec.TotalSR();
        cout << ans << endl;;
    }

    if(choice == 6)
    {
        cout << "Run option 6" << endl;
    }
    if(choice == 7)
    {
        cout << myRec << endl;
    }


    return 0;

}
