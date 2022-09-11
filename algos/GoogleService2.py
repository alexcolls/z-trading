from GoogleService import Create_Service
import pandas as pd
import numpy as np

CLIENT_SECRET_FILE = 'dev/GS_trader1.json'
API_SERVICE_NAME = 'sheets'
API_VERSION = 'v4'
SCOPES = ["https://spreadsheets.google.com/feeds",
             "https://www.googleapis.com/auth/spreadsheets",
             "https://www.googleapis.com/auth/drive.file",
             "https://www.googleapis.com/auth/drive"]
gsheetId = '1cVvvx84XN5v_VPxPmACLJvfr7uXz9Vm1uwLeYJ1MLqw'

service = Create_Service(CLIENT_SECRET_FILE, API_SERVICE_NAME, API_VERSION, SCOPES)

def Export_Data_To_Sheets():
    URL = r'https://files.digital.nhs.uk/publicationimport/pub20xxx/pub20188/ccg-pres-data-oct-dec-2015-un-dat.csv'
    df = pd.read_csv(URL)
    df.replace(np.nan, '', inplace=True)

    response_date = service.spreadsheets().values().append(
        spreadsheetId=gsheetId,
        valueInputOption='RAW',
        range='DF1!A1',
        body=dict(
            majorDimension='ROWS',
            values=df.T.reset_index().T.values.tolist())
    ).execute()


    URL2 = r'https://raw.githubusercontent.com/franciscadias/data/master/kc_house_data.csv'
    df2 = pd.read_csv(URL2)
    df2.replace(np.nan, '', inplace=True)

    response_date = service.spreadsheets().values().append(
        spreadsheetId=gsheetId,
        valueInputOption='RAW',
        range='DF2!A1',
        body=dict(
            majorDimension='ROWS',
            values=df2.T.reset_index().T.values.tolist())
    ).execute()

Export_Data_To_Sheets()