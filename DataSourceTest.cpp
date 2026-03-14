#include "DataSource.h"

int main()
{

    DataSource mydata;
    ifstream infile( "data/data_source.txt" );

    if( !infile )
    {
        return -1;
    }
    infile >> mydata;

    std::cout << mydata.getDataSize() << std::endl;
    std::cout << mydata.getDataSource() << std::endl;
    std::cout << mydata.getRecord(0) << std::endl;
    std::cout << mydata.getRecord(1) << std::endl;
    std::cout << mydata.getRecord(2) << std::endl;
    std::cout << mydata.getRecord(3) << std::endl;
    std::cout << mydata.getRecord(4) << std::endl;
    std::cout << mydata.getRecord(5) << std::endl;
    return 0;

}
