import pyodbc

con = pyodbc.connect(Trusted_Connection='yes', driver = '{ODBC Driver 17 for SQL Server}',server = 'localhost' , database = 'StackOverflow')
print("connected")
con.close()