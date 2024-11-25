import java.sql.*;
import java.util.Scanner;;

class Test {

    private static final String url = "jdbc:mysql://localhost:3306/test";
    private static final String user = "root";
    private static final String pwd = "";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try (Connection conn = DriverManager.getConnection(url, user, pwd)) {
            while (true) {
                int choice;
                System.out.println("Choose Operation");
                System.out.println("1.Insert");
                System.out.println("2.Update");
                System.out.println("3.Delete");
                System.out.println("4.Display");
                System.out.println("5.Exit");
                System.out.print("Choose Operation:");
                choice = scanner.nextInt();

               if(choice==1){
                System.out.println("Insert:");
                insert_sql(conn,scanner);
               }
               else if(choice==2){
                System.out.println("Update:");
                update_sql(conn,scanner);
               }
               else if(choice==3){
                System.out.println("Delete:");
                delete_sql(conn,scanner);
               }
               else if(choice==4)
               {
                System.out.println("Display: ");
                display_sql(conn,scanner);
               }
               else if(choice==5){
                System.out.println("Exiting:");
                break;
               }  

            }
        } catch (Exception e) {
            System.out.println("Connection error: " + e);
        }
        scanner.close();
    }


    //methods

    private static void insert_sql(Connection conn ,Scanner scanner)
    {
        String Insert = "INSERT INTO jdbctest(id,name, marks) VALUES(? ,?, ?)";

        int id;
        String name;
        int marks;

        System.out.println("Enter id: ");
        id = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Enter name: ");
        name = scanner.nextLine();

        System.out.println("Enter marks (out of 100): ");
        marks = scanner.nextInt();
        scanner.nextLine();

        try(PreparedStatement pStmnt = conn.prepareStatement(Insert))
        {
            pStmnt.setInt(1,id);
            pStmnt.setString(2, name);
            pStmnt.setInt(3, marks);
            pStmnt.executeUpdate();
            System.out.println("Data Inserted Successfully");
        }
        catch(Exception e)
        {
            System.out.println("Insert error: "+e);
        }

        
    }

    private static void update_sql(Connection conn, Scanner scanner)
    {
        String Update = "UPDATE jdbctest SET name = ?, marks = ? WHERE id = ?";

        int id;
        String name;
        int marks;

        System.out.println("Enter id:");
        id = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Enter name:");
        name = scanner.nextLine();
        
        System.out.println("Enter marks:");
        marks = scanner.nextInt();
        scanner.nextLine();

        try(PreparedStatement pStmnt = conn.prepareStatement(Update))
        {
            pStmnt.setInt(3,id);
            pStmnt.setString(1, name);
            pStmnt.setInt(2, marks);
            pStmnt.executeUpdate();
            System.out.println("Data Updated Successfully");
        }
        catch(Exception e)
        {
            System.out.println("Update error: "+e);
        }

    }

    private static void delete_sql(Connection conn, Scanner scanner)
    {
        String Delete = "DELETE FROM jdbctest WHERE id = ?";

        int id;
        
        System.out.println("Enter id:");
        id = scanner.nextInt();
        scanner.nextLine();


        try(PreparedStatement pStmnt = conn.prepareStatement(Delete))
        {
            pStmnt.setInt(1,id);
            pStmnt.executeUpdate();
            System.out.println("Data Deleted Successfully");
           
        }
        catch(Exception e)
        {
            System.out.println("Delete error: "+e);
        }

    }

    private static void display_sql(Connection conn, Scanner scanner)
    {
        String Display = "SELECT* FROM jdbctest";

        try(Statement stmt = conn.createStatement(); ResultSet rs = stmt.executeQuery(Display))
        {
            while(rs.next())
            {
            System.out.println(rs.getInt("id") + "\t" + rs.getString("name") + "\t" + rs.getInt("marks"));
            }

        }
        catch(Exception e)
        {
            System.out.println("Display Exception: "+e);
        }
    }
}