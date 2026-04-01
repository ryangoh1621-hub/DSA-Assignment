#include "WeatherRecord.h"
//#include "WeatherRecordMap.h"
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
    //WeatherRecord myRec;
    WeatherRecord myRec;
    int choice;
    int inputMonth;
    int inputYear;

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
    cout << "1. Calculate of average wind speed" << endl;
    cout << "2. Average ambient Air Temperature" << endl;
    cout << "3. sPCC Caluclation" << endl;
    cout << "4. MAD Caluclation" << endl;
    cout << "5. Exit the Programme" << endl;

    cin >> choice;

    //menu selection option
    if(choice == 1)
    {

        cout << "Please enter a month: " << endl;
        cin >> inputMonth;
        cout << "Please enter a year: " << endl;
        cin >> inputYear;
        cout << dateConversion(inputMonth) << " " << inputYear << ":" << endl;
        if(isnan(myRec.averageWindSpeed(inputMonth, inputYear)))
        {
            cout << "No Data: " << endl;
        }
        else
        {
            cout << "Average Speed: " << myRec.averageWindSpeed(inputMonth, inputYear)<< " km/h"<< endl;
            cout << "Sample stdev: " << myRec.SampleStdev(inputMonth, inputYear) << endl;
        }

    }
    if(choice == 2)
    {

        cout << "Please enter a year: " << endl;
        cin >> inputYear;
        for(int month = 0; month < 12; month++)
        {
            if(isnan(myRec.averageAirTemp(month+1, inputYear)))
            {
                cout << dateConversion(month+1) << ":" << "No Data: " << endl;
            }
            else
            {
                cout << dateConversion(month+1) << ":" << " Average: " << myRec.averageAirTemp(month+1, inputYear) << " Degree C" << endl;

            }
        }

    }
    if(choice == 3)
    {
        cout << "Enter Month" << endl;
        cin >> inputMonth;
        myRec.sPCCalculate(inputMonth);
    }
    if(choice == 4)
    {
        cout << "Enter Year" << endl;
        cin >> choice;
        myRec.MADCalculate(choice);

    }
    if(choice == 5)
    {
        cout << "The Program has exited" << endl;
        return 0;
    }

    return 0;

}
