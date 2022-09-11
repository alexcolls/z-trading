#include <csvwriter.h>
#include <NexowFunctions.h>

CsvWriter *csvWriter;

void main() {

    assetList("FX28");
    BarPeriod = 1;

    asset("EUR/USD");

    csvWriter = CsvWriter_new("Book1.csv", ",", 0);

    string data[2];

    data[0] = strf("%f", wdate());
    data[1] = strf("%f", price());

    //printf("\n%s , %s", data[0], data[1]);

    int i;
    for (i = 0; i < 2; i++)
    {
        if (CsvWriter_writeField(csvWriter, data[i])) {
            printf("Error: %s\n", CsvWriter_getErrorMessage(csvWriter));
            return 1;
        }   
    }
    CsvWriter_destroy(csvWriter);

    
}