#include "WeatherRecord.h"

WeatherRecord::WeatherRecord()
{
    //Default consutrctor alr done by their class
}

WeatherRecord::WeatherRecord(const WindlogType & windlogType) //non-Default consturctor with struct type
    : wind_data(windlogType) {}

void WeatherRecord::WindRecordInsert(const WindRecType& record) //Insert to Vector function
{
    wind_data.Insert(record, wind_data.Size());
}

void WeatherRecord::WindRecordRemove(int pos) //Delete function from Vector
{
    wind_data.Remove(pos);
}

WindRecType WeatherRecord::GetWindRecord(int pos) const //Get Vector Record
{
    return wind_data[pos];
}

int WeatherRecord::GetTotalRecords() const //return Size() of vector
{
    return wind_data.Size();
}


double WeatherRecord::averageWindSpeed()
{
    Vector<double> avgWS;
    for (int i = 0; i < GetTotalRecords(); ++i)
    {
        avgWS.Insert(GetWindRecord(i).getWAST().GetWindSpeed(), avgWS.Size());
    }

    return average(avgWS); // reuse your helper function
}

double WeatherRecord::averageAirTemp()
{
    Vector<double> avgAT;
    for (int i = 0; i < GetTotalRecords(); ++i)
    {
        avgAT.Insert(GetWindRecord(i).getWAST().GetambientAir(), avgAT.Size());
    }

    return average(avgAT); // reuse your helper function
}
void WeatherRecord::sPCCalculate(int option)
{

    Vector<double> WS;
    Vector<double> AT;
    Vector<double> SR;

    for (int i = 0; i < GetTotalRecords(); ++i)
    {
        if(GetWindRecord(i).getDate().GetMonth() == option)
        {
            WS.Insert(GetWindRecord(i).getWAST().GetWindSpeed(), WS.Size());
            AT.Insert(GetWindRecord(i).getWAST().GetambientAir(), AT.Size());
            SR.Insert(GetWindRecord(i).getWAST().GetsolarRadiation(), SR.Size());
        }
    }

    double S_T = sPCC(WS,AT);
    double S_R = sPCC(WS,SR);
    double T_R = sPCC(AT,SR);


    std::cout << "Sample Pearson Correlation Coefficient for Month : " << option <<std::endl;
    std::cout << "S_T: " << S_T <<std::endl;
    std::cout << "S_R: " << S_R <<std::endl;
    std::cout << "T_R: " << T_R <<std::endl;

}
void WeatherRecord::MADCalculate(int year)
{
    std::cout << "Year: " << year <<std::endl;




    for(int cycle = 0; cycle < 12; cycle++)
    {
    Vector<double> WS;
    Vector<double> AT;
    Vector<double> SR;

        for (int i = 0; i < GetTotalRecords(); ++i)
        {
            if(GetWindRecord(i).getDate().GetMonth() == cycle && GetWindRecord(i).getDate().GetYear() == year)
            {
                WS.Insert(GetWindRecord(i).getWAST().GetWindSpeed(), WS.Size());
                AT.Insert(GetWindRecord(i).getWAST().GetambientAir(), AT.Size());
                SR.Insert(GetWindRecord(i).getWAST().GetsolarRadiation(), SR.Size());
            }
        }
        if(WS.Size() != 0 || AT.Size() != 0 || SR.Size()!= 0)
        {
                std::cout << "Month: " << cycle << " | "<< roundUpDec(average(WS))<< "(" << roundUpDec(SD(WS)) << "," << roundUpDec(MAD(WS)) << ")"
              << roundUpDec(average(AT))<< "(" << roundUpDec(SD(AT)) << "," << roundUpDec(MAD(AT)) << "), "
              << roundUpDec(sum(SR)) << std::endl;
        }
        else{
                //std::cout << "No data for the month of :" << cycle << endl;
        }
    }





}

double WeatherRecord::TotalSR()
{
    Vector<double> totalSR;
    for (int i = 0; i < GetTotalRecords(); ++i)
    {
        totalSR.Insert(GetWindRecord(i).getWAST().GetsolarRadiation(), totalSR.Size());
    }
    return sum(totalSR);
}
ostream& operator<<(ostream& os, const WeatherRecord& rec) //Display all Record result
{
    for (int i = 0; i < rec.GetTotalRecords(); ++i)
    {
        const WindRecType& w = rec.GetWindRecord(i);
        os << "Date: " << w.getDate().GetDay() << "/" << w.getDate().GetMonth() << "/" << w.getDate().GetYear()
           << " " << "Time: " << w.getTime().GetHour() << ":" << w.getTime().GetMin() << ":" << w.getTime().GetSec() << " "
           << "|windspeed: " << w.getWAST().GetWindSpeed()
           << "|ambient air: " << w.getWAST().GetambientAir()
           << "|solar radiation: " << w.getWAST().GetsolarRadiation() << endl;
    }
    return os;
}

istream & operator >>( istream & input, WeatherRecord & rec ) //input file to Vector
{
    //Creation of different type of Delimiter
    const char DELIMITER = ',';
    const char DELIMITER2 = '/';
    const char DELIMITER3 = ':';
    const char DELIMITER4 = ' ';

    // create an temporary storage to read header & their position
    string headerwast;
    int WASTCount;
    string headerspeed;
    int WSCount;
    string headerambient;
    int AACount;
    string headersolarradiation;
    int SRCount;
    string extra;

    //Create temp storge to store Temp data after extraction
    string tempStr;
    string temp1;

    //Loop to extra titles
    for(int i = 0; i < 18; i++) //read title and store interest
    {
        if(i <= 16)
        {
            getline(input, extra, DELIMITER);
            if(extra == "WAST")
            {
                headerwast = extra; //WAST Title
                WASTCount = i; //WAST Position
                cout << "headerwast:" << WASTCount << endl;
            }
            else if(extra == "S")
            {
                headerspeed = extra; //windspeed title
                WSCount = i; //windspeed position
                cout << "headerspeed:" << WSCount << endl;
            }
            else if(extra == "T")
            {
                headerambient = extra; //ambient title
                AACount = i; //ambient position
                cout << "headerambient:" << AACount << endl;
            }
            else if(extra == "SR")
            {
                headersolarradiation = extra; //solar radiation title
                SRCount = i; //solar radiation poisiton
                cout << "headersolarradiation:" << SRCount << endl;
            }
        }
        else
        {
            getline(input, extra);  //to check last row before moving next col
            if(extra == "WAST")
            {
                headerwast = extra;
                WASTCount = i;
            }
            else if(extra == "S")
            {
                headerspeed = extra;
                WSCount = i;
            }
            else if(extra == "T")
            {
                headerambient = extra;
                AACount = i;
                cout << "last: headerambient:" << AACount << endl;
            }
            else if(extra == "SR")
            {
                headersolarradiation = extra;
                SRCount = i;
            }
        }
    }


    //create a dummy record to store struct
    int asd = 0;
    while(getline(input, tempStr, DELIMITER)) //read first line and check if next line is valid
    {
        WindRecType dummyrec;
        //std::cout << "Hi im here " << asd++ << std::endl;
        //loop content based on position & store valid
        for(int i = 0; i <= 17; i++)
        {

            if (tempStr.empty())
            {
                // Skip this field or the whole record
                // std::cout << "skipping " << asd << std::endl;
                break;
            }
            else
            {
                if(i == WASTCount)
                {
                    istringstream tempDate(tempStr);

                    // First split into date and time
                    std::string datePart, timePart;
                    getline(tempDate, datePart, DELIMITER4);  // "31/3/2016"
                    getline(tempDate, timePart);       // "9:00"
                    //std::cout << datePart << timePart << std::endl;
                    // Now split datePart by '/'
                    istringstream dateStream(datePart);
                    getline(dateStream, temp1, DELIMITER2);   // "31"
                    dummyrec.getDate().SetDay(stoi(temp1));
                    getline(dateStream, temp1, DELIMITER2);   // "3"
                    dummyrec.getDate().SetMonth(stoi(temp1));
                    getline(dateStream, temp1);        // "2016"
                    dummyrec.getDate().SetYear(stoi(temp1));

                    // Split timePart by ':'
                    istringstream timeStream(timePart);
                    getline(timeStream, temp1, DELIMITER3);   // "9"
                    dummyrec.getTime().SetHour(stoi(temp1));
                    getline(timeStream, temp1);        // "00"
                    dummyrec.getTime().SetMin(stoi(temp1));
                }
                else if(i == WSCount)
                {
                    try
                    {
                        // Windspeed: force integer
                        dummyrec.getWAST().SetWindSpeed(std::stoi(tempStr));
                    }
                    catch (const std::invalid_argument& e)
                    {
                        std::cerr << "Invalid windspeed value: " << tempStr << std::endl;
                    }
                    catch (const std::out_of_range& e)
                    {
                        std::cerr << "Windspeed out of range: " << tempStr << std::endl;
                    }
                }
                else if(i == AACount)
                {
                    try
                    {
                        // Ambient air: force float
                        dummyrec.getWAST().SetambientAir(std::stof(tempStr));
                    }
                    catch (const std::invalid_argument& e)
                    {
                        std::cerr << "Invalid ambient air value: " << tempStr << std::endl;
                    }
                    catch (const std::out_of_range& e)
                    {
                        std::cerr << "Ambient air out of range: " << tempStr << std::endl;
                    }
                }
                else if(i == SRCount)
                {
                    try
                    {
                        // Solar radiation: force integer
                        dummyrec.getWAST().SetsolarRadiation(std::stoi(tempStr));
                    }
                    catch (const std::invalid_argument& e)
                    {
                        std::cerr << "Invalid solar radiation value: " << tempStr << std::endl;
                    }
                    catch (const std::out_of_range& e)
                    {
                        std::cerr << "Solar radiation out of range: " << tempStr << std::endl;
                    }
                }

                if(i < 16)
                {
                    getline(input, tempStr, DELIMITER); //Read next line & loop again
                }
                else if(i == 16)
                {
                    getline(input, tempStr); //read last line
                }
            }
        }
        if(tempStr.empty())
        {

        }
        else
        {
            rec.WindRecordInsert(dummyrec);
        } // Insert record into the vector}


    }
    return input;
}


