#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CsvWriter {
	char *filePath_;
	char delimiter_;
	int append_;
	int rowIsNew_;
	FILE *fileHandler_;
	char *errMsg_;
} CsvWriter;

// Public
CsvWriter *CsvWriter_new(const char *filePath, const char *delimiter, int append);
void CsvWriter_destroy(CsvWriter *csvWriter);
int CsvWriter_nextRow(CsvWriter *csvWriter);
int CsvWriter_writeField(CsvWriter *csvWriter, char *field);
const char *CsvWriter_getErrorMessage(CsvWriter *csvWriter);

// Private
int _CsvWriter_delimiterIsAccepted(const char *delimiter);
int _CsvWriter_ensureFileIsOpen(CsvWriter *csvWriter);
void _CsvWriter_setErrorMessage(CsvWriter *csvWriter, const char *errorMessage);


#ifdef __cplusplus
}
#endif

#endif