#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>


#include "csvwriter.h"

#ifdef __cplusplus
extern "C" {
#endif

CsvWriter *CsvWriter_new(const char *filePath, const char *delimiter, int append) {
	CsvWriter *csvWriter = malloc(sizeof(CsvWriter));
	if (filePath == NULL) {
        csvWriter->filePath_ = NULL;
    } else {
        int filePathLen = strlen(filePath);	
        csvWriter->filePath_ = malloc(filePathLen + 1);
        strcpy(csvWriter->filePath_, filePath);
    }
	csvWriter->rowIsNew_ = 1;
	csvWriter->append_ = append;
	csvWriter->fileHandler_ = NULL;
	csvWriter->errMsg_ = NULL;
	 if (delimiter == NULL) {
        csvWriter->delimiter_ = ',';
    } else if (_CsvWriter_delimiterIsAccepted(delimiter)) {
        csvWriter->delimiter_ = *delimiter;
    } else {
        csvWriter->delimiter_ = '\0';
    }
		
	return csvWriter;	
}

void CsvWriter_destroy(CsvWriter *csvWriter) {
	if (csvWriter == NULL) {
		return;
	}
	if (csvWriter->filePath_ != NULL) {
		free(csvWriter->filePath_);
	}
	if (csvWriter->fileHandler_ != NULL) {
		fclose(csvWriter->fileHandler_);
	}
	free(csvWriter);
}

int CsvWriter_nextRow(CsvWriter *csvWriter) {
	if (csvWriter->filePath_ != NULL && _CsvWriter_ensureFileIsOpen(csvWriter)) {
		return 1;
	}
	if (csvWriter->fileHandler_ != NULL) {
		fprintf(csvWriter->fileHandler_, "\n");
	} else {
		printf("\n");
	}
	csvWriter->rowIsNew_ = 1;
	
	return 0;
}

int CsvWriter_writeField(CsvWriter *csvWriter, char *field) {
	if (csvWriter->delimiter_ == '\0') {
		_CsvWriter_setErrorMessage(csvWriter, "Supplied delimiter is not supported");
		return 1;
	}
	if (csvWriter->filePath_ != NULL && _CsvWriter_ensureFileIsOpen(csvWriter)) {
		return 1;
	}
	if (field == NULL) {
		_CsvWriter_setErrorMessage(csvWriter, "NULL string was passed");
		return 1;
	}
	char *fieldPrefix = csvWriter->rowIsNew_ ? "" : ",";
	int complexField = (strchr(field, csvWriter->delimiter_) || strchr(field, '\n') || strchr(field, '\"')) ? 1 : 0;
	if (! complexField) {
		if (csvWriter->fileHandler_ != NULL) {
			fprintf(csvWriter->fileHandler_, "%s%s", fieldPrefix, field);
		} else {
			printf("%s%s", fieldPrefix, field);
		}
		csvWriter->rowIsNew_ = 0;
		return 0;
	}
	char buffer[1024];
	strcpy(buffer, "");
	int bufferIter = 0;
	int fieldIter;
	int repeatedOnQuotes = 0;
	int bufferWasWrittenOnce = 0;
	int bufferWasJustFlushed = 0;
	int repeatSchedulerIndex = -1;
	for (fieldIter = 0 ; field[fieldIter] != '\0' ; fieldIter++) {
		bufferWasJustFlushed = 0;
		buffer[bufferIter] = field[fieldIter];
		if (bufferIter == 1022) {
			buffer[1023] = '\0';
			if (! bufferWasWrittenOnce) {
				if (csvWriter->fileHandler_ != NULL) {
					fprintf(csvWriter->fileHandler_, "%s\"%s", fieldPrefix, buffer);
				} else {
					printf("%s\"%s", fieldPrefix, buffer);
				}
				bufferWasWrittenOnce = 1;
			} else {
				if (csvWriter->fileHandler_ != NULL) {
					fprintf(csvWriter->fileHandler_, "%s", buffer);
				} else {
					printf("%s", buffer);
				}
			}
			strcpy(buffer, "");
			bufferIter = -1;
			bufferWasJustFlushed = 1;
		}
		if (field[fieldIter] == '\"' && ! repeatedOnQuotes) {
			repeatSchedulerIndex = fieldIter;
			fieldIter--;
			repeatedOnQuotes = 1;			
		}
		if (repeatSchedulerIndex == fieldIter) {
			repeatedOnQuotes = 0;
		}
		bufferIter++;
	}
	if (! bufferWasJustFlushed) {
		buffer[bufferIter] = '\0';
		if (! bufferWasWrittenOnce) {
			if (csvWriter->fileHandler_ != NULL) {
				fprintf(csvWriter->fileHandler_, "%s\"%s", fieldPrefix, buffer);
			} else {
				printf("%s\"%s", fieldPrefix, buffer);
			}
			bufferWasWrittenOnce = 1;
		} else {
			if (csvWriter->fileHandler_ != NULL) {
				fprintf(csvWriter->fileHandler_, "%s", buffer);
			} else {
				printf("%s", buffer);
			}
		}
	}
	if (csvWriter->fileHandler_ != NULL) {
		fprintf(csvWriter->fileHandler_, "\"");
	} else {
		printf("\"");
	}
	
	csvWriter->rowIsNew_ = 0;
	return 0;
}

const char *CsvWriter_getErrorMessage(CsvWriter *csvWriter) {
	return csvWriter->errMsg_;
}

int _CsvWriter_delimiterIsAccepted(const char *delimiter) {
    char actualDelimiter = *delimiter;
    if (actualDelimiter == '\n' || actualDelimiter == '\r' || actualDelimiter == '\0' || actualDelimiter == '\"') {
        return 0;
    }
    return 1;
}

int _CsvWriter_ensureFileIsOpen(CsvWriter *csvWriter) {
	if (csvWriter->filePath_ == NULL) {
		_CsvWriter_setErrorMessage(csvWriter, "Supplied CSV file path is NULL");
		return 1;
	}
	if (csvWriter->fileHandler_ != NULL) {
		return 0;	
	}
	char *openType = csvWriter->append_ ? "a" : "w";
	csvWriter->fileHandler_ = fopen(csvWriter->filePath_, openType);
	if (csvWriter->fileHandler_ == NULL) {
		int errorNum = errno;
		const char *errStr = strerror(errorNum);
		char *errMsg = malloc(1024 + strlen(errStr));
		strcpy(errMsg, "");
		sprintf(errMsg, "Error opening CSV file for writing/appending: %s : %s", csvWriter->filePath_, errStr);
		_CsvWriter_setErrorMessage(csvWriter, errMsg);
		free(errMsg);		
		return 1;
	}
	return 0;
}

void _CsvWriter_setErrorMessage(CsvWriter *csvWriter, const char *errorMessage) {
    if (csvWriter->errMsg_ != NULL) {
        free(csvWriter->errMsg_);
    }
    int errMsgLen = strlen(errorMessage);
    csvWriter->errMsg_ = malloc(errMsgLen + 1);
    strcpy(csvWriter->errMsg_, errorMessage);
}

#ifdef __cplusplus
}
#endif

