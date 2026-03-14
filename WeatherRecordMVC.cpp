#include "WeatherRecord.h"
#include "additionalFunction.h"
#include "DataSource.h"
int main()
{
    DataSource mydata;
 ifstream infile1( "data/data_source.txt" );

    if( !infile1 )
    {
        return -1;
    }
    infile1 >> mydata;

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

        //cout << "Records: "<<mydata.getRecord(0) << endl;
        //cout << "Records: "<<mydata.getRecord(1) << endl;
        //ifstream infile("Metdata-Jan-Dec2016.csv");
        //if( !infile )
        //{
        //    return -1;
        //}
        //infile >> myRec;
    //ifstream infile( "MetData-31-3.csv" ); //infile is an object on runtime stack | open file
    //ifstream infile("MetData_Mar01-2014-Mar01-2015-ALL.csv");



    //Menu option
    cout << "Record Found: "<<myRec.GetTotalRecords() << endl;
    cout << "1. Calculate of Average windspeed" << endl;
    cout << "2. Average ambient Air Temperature" << endl;
    cout << "3. standard deviations for the windspeed" << endl;
    cout << "4. standard deviations for the ambient Air Temprature" << endl;
    cout << "5. Total solar radiation" << endl;
    cout << "6. Search by Month/Year" << endl;
    cout << "7. Display All Records" << endl;
    cin >> choice;

    //menu selection option
    if(choice == 1)
    {
        float ans =  averageWindSpeed(myRec);
        cout << ans << endl;
    }
    if(choice == 2)
    {
        float ans =  averageAmbientAirTemp(myRec);
        cout << ans << endl;
    }
    if(choice == 3)
    {
        float ans = SDWindSpeed(myRec);
        cout << ans << endl;
    }
    if(choice == 4)
    {
        float ans = SDambientAirTemp(myRec);
        cout << ans << endl;
    }
    if(choice == 5)
    {
        float ans = TotalSolarRadiation(myRec);
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
