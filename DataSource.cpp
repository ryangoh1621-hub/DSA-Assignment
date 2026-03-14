#include "DataSource.h"


DataSource::DataSource()
{
    m_DataSourcePath = "";
    m_datafilesize = 0;
}

DataSource::DataSource(string dataSourcePath, int datafilesize)
{
    m_DataSourcePath = dataSourcePath;
    m_datafilesize = datafilesize;
}
string DataSource::getDataSource()
{
    return m_DataSourcePath;
}
void DataSource::setDataSource(string dataSourcePath)
{
    m_DataSourcePath = dataSourcePath;
}

int DataSource::getDataSize(){return m_datafilesize;}
void DataSource::setDataSize(int size){m_datafilesize = size;}


    void DataSource::setRecord(const string& record)
    {
        m_DataSourcePathRecords.push_back(record);
    }
    string DataSource::getRecord(int index) const
    {
            return m_DataSourcePathRecords[index];
    }


ostream & operator <<( ostream & os, const DataSource & datasource)
{

}
istream & operator >>( istream & input, DataSource & datasource)
{
    const char DELIMITER = ' ';
    string tempStr;
    int counter = 0;
    while (getline(input, tempStr))  // keep reading until EOF
    {
        std::cout << "Data file of : " << tempStr << std::endl;
        counter++;
        datasource.setDataSize(counter);
        datasource.setRecord(tempStr);
    }
    return input;
}
