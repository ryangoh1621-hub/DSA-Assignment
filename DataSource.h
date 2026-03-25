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

/**
 * @class DataSource
 * @brief A class to extract datasource
 *
 * @author Ryan
 * @version 01
 * @date 13/03/2026 Ryan
 *
 * @todo Implemenet of DataSource attributes
 * @todo Implemenet of DataSource with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 * @todo Implemenet input and output stream (completed)

 *
 * @bug None
 */

class DataSource
{
public:
    /** @brief Initialise a DataSource object of default and non default constructor
    *
    * @param DataSourcePath - the String value of excel
    * @param datafilesize - integer value for the vector size | read how many lines
    * @return void
    *
    */
    DataSource();
    DataSource(string dataSourcePath, int datafilesize);

    /** @brief Retrieve DataSource from m_DataSourcePath
     *
     * @return string of DataSourcePath
     *
     */
    string getDataSource();

    /** @brief Set DataSource
     *
     * @param DataSourcePath - set the m_DataSourcePath based on the data given
     *
     */
    void setDataSource(string dataSourcePath);

    /** @brief Retrieve DataSize from m_datafilesize
     *
     * @return int of datafilesize
     *
     */
    int getDataSize();

    /** @brief Set Datafilesize
     *
     * @param Datafilesize - set the m_datafilesize based on the data given
     *
     */
    void setDataSize(int size);

    /** @brief Retrieve DataSourcePathRecords  from m_DataSourcePathRecords
     *
     * @return string of DataSourcePathRecords
     *
     */
    void setRecord(const string& record);

    /** @brief Retrieve vector DataSourcePathRecords from m_DataSourcePathRecords
     *
     * @return string of datafilesize
     *
     */
    string getRecord(int index) const;

private:

    /** @brief creation of DataSource Attributes
    *
    * @param DataSourcePath - to contain a string of the data source path
    * @param DataSourcePathRecords - to contain a vector of string for data source path
    * @param datafilesize - to contain a integer of the data file size
    *
    */
    int
    string m_DataSourcePath;
    vector<string> m_DataSourcePathRecords;
    int m_datafilesize;
};


/** @brief output and input stream operator
*
* @param ostream - process of streaming to prompt
* @param istream - process of reading from an input file
*
*/
ostream & operator <<( ostream & os, const DataSource & datasource);
istream & operator >>( istream & input, DataSource & datasource);

#endif // DATASOURCE_H_INCLUDED
