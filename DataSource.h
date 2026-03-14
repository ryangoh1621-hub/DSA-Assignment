#ifndef DATASOURCE_H_INCLUDED
#define DATASOURCE_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using std::string;
using std::ostream;
using std::istream;
using std::ifstream;
using std::vector;
class DataSource
{
public:

    DataSource();
    DataSource(string dataSourcePath, int datafilesize);

    string getDataSource();
    void setDataSource(string dataSourcePath);

    int getDataSize();
    void setDataSize(int size);

    void setRecord(const string& record);
    string getRecord(int index) const;

private:
    string m_DataSourcePath;
    vector<string> m_DataSourcePathRecords;
    int m_datafilesize;
};

ostream & operator <<( ostream & os, const DataSource & datasource);
istream & operator >>( istream & input, DataSource & datasource);

#endif // DATASOURCE_H_INCLUDED
