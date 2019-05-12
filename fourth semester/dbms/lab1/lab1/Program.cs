using System;
using System.Data;
using System.Data.SqlClient;


namespace lab1
{
    class Program
    {
        private static string _connStr = @"Server=127.0.0.1,1433;Database=StackOverflow;User Id=SA;Password=arDBMS20";
        
        public static void Main(string[] args)
        {
            var p = new Program();
            p.ConnectDb();
            Console.ReadLine();
        }

        public void ConnectDb()
        {
            SqlConnection connection = null;

            try
            {
                connection = new SqlConnection(_connStr);
                connection.Open();
                
                Console.WriteLine("Successfully connected to db!");
                Console.WriteLine(connection.ConnectionTimeout);
                Console.WriteLine(connection.ConnectionString);
                
                //read data from drug table based on sql command and sql data reader
                String selectStatement = "select * from Comments";
                SqlCommand command = new SqlCommand(selectStatement, connection);
                // Console.WriteLine(command.ExecuteScalar());
                
                SqlDataReader dataReader = command.ExecuteReader();

              
                while (dataReader.Read())
                {
                    Console.WriteLine(dataReader["CID"] + " " + dataReader["Content"]);
                 
                    // Console.WriteLine(dataReader.GetInt32(0) + " " + dataReader.GetValue(1));
                   
                }
                
                dataReader.Close();
                
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                throw;
            }
            finally
            {
                connection?.Close();
            }
        }
    }
}